/**@file ODBCResultSet.cpp
* @brief Implements ResultSet functionality for ODBC connectivity.
* 
* $Header: ODBCResultSet.cpp
* 
* NAME: ODBCResultSet
* 
* BASE CLASSES: ADBC::ResultSet
* 
* PURPOSE: This class implements ResultSet functionality for ODBC connectivity.
* 
* AUTHOR: Gurudutt Mallapur and Nitesh Sahu
* 
* $Revision: 1.12 $
* 
* $Log: ODBCResultSet.cpp,v $
* Revision 1.12  2005/09/02 11:41:03  Jignesh.Kanchanlal
* Ready for Final Release
*
* Revision 1.2  2005/08/12 12:07:26  Jignesh.Kanchanlal
* Last Version Before Integration
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

///////////////////////////////////////////////////////////////
/// Includes

#include<time.h>

#include<string>
#include <fstream>
#include <iostream>

//#include <cstring>

#include <dbaccess/Common.h>
#include <dbaccess/ODBCTypes.h>

#include <dbaccess/ODBCError.h>

//#include <common/GeneralException.h>

#include <dbaccess/ODBCResultSet.h>

#ifdef ALOGGER
#include <logger/Logger.h>
#endif

namespace dbaccess {

int noCaseCompare(const string & s1, const string& s2); 
	
//Do NOT change order in initialization list
ODBCResultSet::ODBCResultSet(HENV env,HDBC conn,HSTMT stmt,ODBCError *eptr)  
: err_(eptr ), 
  hEnv_(env), hConn_(conn), hStmt_(stmt), colMap_(0), rc_(SQL_SUCCESS) 
{
	getColMetaData();

//#ifdef ALOGGER		
//	logger::Logger::getInstance("Logfile.txt", logger::Logger::LevelError);	
//#endif
}

ODBCResultSet::~ODBCResultSet() 
{
 delete [] colMap_; 
}

//Modifier Functions
//Fetch next row into ResultSet
bool ODBCResultSet::next() 
{
 rc_=SQLFetch(hStmt_);
 setError(__FILE__,__FUNCTION__,__LINE__,hStmt_,dbaccess::Types::ODBC::STMT_HDL);
 return (SQL_SUCCEEDED(rc_));
}

//Metadeta functions
//gets the number of columns in the ResultSet, returns zero otherwise.
 int ODBCResultSet::getColCount()const
{
 SQLSMALLINT colCount=0;

 rc_ = SQLNumResultCols(hStmt_,&colCount);
 setError(__FILE__,__FUNCTION__,__LINE__,hStmt_,dbaccess::Types::ODBC::STMT_HDL);
 
#ifdef ALOGGER
 sprintf(logBuff_,"colcount = %d", colCount );
 (logger::Logger::getInstance()).debug( __FILE__,__LINE__, __FUNCTION__,logBuff_); 
#endif

 return colCount;
}

//Gets the column's data-type no. as specified by ODBC/Database.
 int ODBCResultSet::getColumnType(int colNum) const
{
SQLSMALLINT colType[BUFSIZ] = { 0, 0, 0, 0, };
 
	rc_ = SQLColAttribute(hStmt_,colNum,SQL_DESC_TYPE,NULL,NULL,NULL,colType);
	setError(__FILE__,__FUNCTION__,__LINE__,hStmt_,dbaccess::Types::ODBC::STMT_HDL);

    //logError(__FILE__,__FUNCTION__,__LINE__);
#ifdef ALOGGER	
	sprintf(logBuff_,"coltype = %d\n", colType[0]);
	(logger::Logger::getInstance()).debug(__FILE__,__LINE__,__FUNCTION__,logBuff_);
#endif

return colType[0];
}
//Get the columntype name
std::string ODBCResultSet::getColumnTypeName(int colNum) const
{
	SQLCHAR colName[BUFSIZ] = { "" };
	SQLSMALLINT colNameLen=0;

	rc_ = SQLColAttribute(hStmt_,colNum,SQL_DESC_TYPE_NAME,colName,BUFSIZ,&colNameLen,NULL);
	setError(__FILE__,__FUNCTION__,__LINE__,hStmt_,dbaccess::Types::ODBC::STMT_HDL);

#ifdef ALOGGER
	sprintf(logBuff_,"colName = %s\n", colName);
	(logger::Logger::getInstance()).debug(__FILE__,__LINE__,__FUNCTION__,logBuff_);
#endif

 return std::string((char *)colName);
}


#ifdef ALOGGER
/* logError is used to log the return status from ODBC function calls to the logfile. 
Dumps (odbc) Error, Warning, Success message to the logfile 
*/
RETCODE ODBCResultSet::logError(const char *file,const char * fname,const size_t lnum) const
{ 
  RETCODE errVal=0;  
  
  char* fileName = __FILE__;
  //char * fileName = myGetFileName(file);

  //NOTE: Do not change the state of rc_ in this function 
  // as rc_ is to be used to store the success/fail status 
  // of ODBC function calls used by methods of ODBCResultSet
  //use errVal to get SQLError() or other ODBC calls return status.
  if( rc_!= SQL_SUCCESS) 
  {
   errVal = SQLError(hEnv_,hConn_,hStmt_,(SQLCHAR *)status_,NULL,(SQLCHAR *)msg_,BUFSIZ,NULL);  
  }

  switch(rc_)
  {
  case SQL_SUCCESS :
					sprintf(logBuff_,"Success \n");	
					(logger::Logger::getInstance()).info(fileName,lnum,fname,logBuff_);				
					break;
  case SQL_SUCCESS_WITH_INFO :					  						
				sprintf(logBuff_,"%s", msg_);
				(logger::Logger::getInstance()).warn(fileName,lnum,fname,logBuff_);				
				break;  
  default:		
			sprintf(logBuff_,"%s", msg_);
			(logger::Logger::getInstance()).error(fileName,lnum,fname,logBuff_);				
			break;
  }	
  return errVal;
}
#endif

RETCODE ODBCResultSet::getData(unsigned int colNum,DataTypes type,
									 unsigned int buffLength,void * retVal) const
{
SDWORD cbData = 0;

/*Upon each SQLGetData() call, if the data available for return is 
  greater than or equal to BufferLength, truncation occurs. 
  Truncation is indicated by a function return code of SQL_SUCCESS_WITH_INFO 
  coupled with a SQLSTATE denoting data truncation. 
  The application can call SQLGetData() again, with the same ColumnNumber value, 
  to get subsequent data from the same unbound column starting at the point of truncation.
  To obtain the entire column, the application repeats such calls until the function 
  returns SQL_SUCCESS. The next call to SQLGetData() returns SQL_NO_DATA_FOUND 
*/

//Will allow only 3200 times the record to be fetched.
//The reason for doing this is a specific open source driver available on linux.
//The driver can be found at : http://home.fnal.gov/~dbox/oracle/odbc/
//

int maxAllowed = 0; 
do {
rc_= SQLGetData(hStmt_,colNum,type,retVal,buffLength,&cbData);
++maxAllowed; //The counter is incremented.
}while(rc_ == SQL_SUCCESS && maxAllowed < 3200);

setError(__FILE__,__FUNCTION__,__LINE__,hStmt_,dbaccess::Types::ODBC::STMT_HDL);

return rc_;
}

//getxxx() functions
 double ODBCResultSet::getDouble(int colNum) const 
{
 double dVal;
 getData(colNum,DT_DOUBLE,sizeof(dVal),&dVal);
 return dVal;
}
double ODBCResultSet::getDouble(std::string colName) const
{
 return getDouble(getColNum(colName));  
}

 bool ODBCResultSet::getBool(int colNum)const  
{
 bool bVal;
 getData(colNum,DT_BOOL,sizeof(bVal),&bVal);
 return bVal;
}

 bool ODBCResultSet::getBool(std::string colName)const 
{
 return getBool(getColNum(colName));  
}
	

 float ODBCResultSet::getFloat(int colNum)const 
{
 float fVal;
 getData(colNum,DT_FLOAT,sizeof(fVal),&fVal);
 return fVal;
}
 float ODBCResultSet::getFloat (std::string colName)const
{
 return getFloat(getColNum(colName));
}

 int ODBCResultSet::getInt(int colNum)const  
{
 return getLong(colNum);
}
 int ODBCResultSet::getInt(std::string colName)const 
{
 return getInt(getColNum(colName));
}

 long ODBCResultSet::getLong(int colNum)const  
{
 long lVal;
 getData(colNum,DT_LONG,sizeof(lVal),&lVal);
 return lVal;
}
 long ODBCResultSet::getLong(std::string colName)const  
{
 return getLong(getColNum(colName));
}
 short ODBCResultSet::getShort(int colNum)const 
{
 short sVal;
 getData(colNum,DT_SHORT,sizeof(sVal),&sVal);
 return sVal;
}
short ODBCResultSet::getShort(std::string colName)const 
{
 return getShort(getColNum(colName));
}

 std::string ODBCResultSet::getString(int colNum)const
{ 
 std::string str;
 char buff[BUFSIZ] = "";

 getData(colNum,DT_STRING,BUFSIZ,buff);
 str = buff;
 return str;
}

std::string ODBCResultSet::getString(std::string colName)const 
{ 
 return getString(getColNum(colName));
}

std::string ODBCResultSet::getDate(int colNum)const  
{
 SQL_DATE_STRUCT dtVal;
 
 dtVal.day=1; dtVal.month=1; dtVal.year=1900;

 getData(colNum,DT_DATE,sizeof(dtVal),&dtVal);
 
 if( dtVal.day==1 && dtVal.month==1 && dtVal.year==1900)
     return "";
 
 char buf[256];

sprintf(buf, "%d-%d-%d", dtVal.day, dtVal.month, dtVal.year);

#ifdef ALOGGER
   logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, buf);
#endif	

 
 struct tm d;
 
 d.tm_mday = dtVal.day;
 d.tm_mon = dtVal.month - 1;
 d.tm_year = dtVal.year - 1900;
 
 strftime ( buf, 256, "%d-%b-%Y", &d);
 
#ifdef ALOGGER
   logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, buf);
#endif	


 return std::string(buf);

}


//Use aliases for unnamed columns to access by colName
 int ODBCResultSet::getColNum(std::string colName) const
{
 int colNum;
 colNum = getBaseColNum(colName);

 if( colNum != -1 ) 
 {
  return colNum;
 }
 else {
#ifdef ALOGGER
  sprintf(logBuff_,"Not found column name=%s/column %d in base table : ", colName.c_str(), colNum);
  logger::Logger::getInstance().info(__FILE__,__LINE__,__FUNCTION__, logBuff_ );
#endif
 }
 colNum = getAliasColNum(colName);
 if( colNum != -1 )			
 {
  return colNum;
 }
 else 
 {
#ifdef ALOGGER
  sprintf(logBuff_,"Not found column name=%s/column %d in alias list of table : ", colName.c_str(), colNum);
  logger::Logger::getInstance().info(__FILE__,__LINE__,__FUNCTION__, logBuff_ );
#endif
 } 

 return -1;
}
//Get the colName in string format for a given colNum in the ResultSet
std::string ODBCResultSet::getColName(int col) const 
{
return std::string((char *)colMap_[col].baseColName_);
}

//Get the colName in string format for a given colNum in the base table
int ODBCResultSet::getBaseColNum(std::string colName)const
{
 int colCount = getColCount();
 for(int i=0; i < colCount; i++ ) 
 {
   std::string baseColName(colMap_[i].baseColName_);

   if (noCaseCompare(colName, baseColName) == 0 )
     return colMap_[i].colNum_;
// 	 if( stricmp(colName.c_str(),colMap_[i].baseColName_) == 0 )
// 		 return colMap_[i].colNum_;
 }	 
 return -1;
}

//Get the alias in string format for a given colNum in the query	
int ODBCResultSet::getAliasColNum(std::string colName)const
{
 int colCount = getColCount();
 for(int i=0; i < colCount; i++ ) 
 {
   std::string aliasColName = colMap_[i].aliasColName_;

   //	 if( stricmp(colName.c_str(),colMap_[i].aliasColName_) == 0 )
   if(noCaseCompare(colName, aliasColName)== 0)
     return colMap_[i].colNum_;
 }	 
 return -1;
}

//Fills up the colMap_ object with column metadata for a given ResultSet
bool ODBCResultSet::getColMetaData()
{
 SQLSMALLINT colCount = getColCount();
 colMap_ = new ColMap[colCount];
 if( !colMap_ ) 
 {
  return false;
 }
 for(int i=0; i < colCount; i++) 
 {		
  //fill up ColMap info
  colMap_[i].colNum_ = i+1;
  rc_ = SQLColAttribute(hStmt_,i+1,SQL_DESC_BASE_COLUMN_NAME,colMap_[i].baseColName_,sizeof(colMap_[i].baseColName_),NULL,NULL);  
  setError(__FILE__,__FUNCTION__,__LINE__,hStmt_,dbaccess::Types::ODBC::STMT_HDL);
  rc_ = SQLColAttribute(hStmt_,i+1,SQL_DESC_NAME,colMap_[i].aliasColName_,sizeof(colMap_[i].aliasColName_),NULL,NULL);
  setError(__FILE__,__FUNCTION__,__LINE__,hStmt_,dbaccess::Types::ODBC::STMT_HDL);
#ifdef ALOGGER
  sprintf(logBuff_,"ColNum = %d -> Table Col Name = %s -> Alias Col Name = %s", colMap_[i].colNum_,colMap_[i].baseColName_,colMap_[i].aliasColName_);
  (logger::Logger::getInstance()).info(logBuff_);
#endif
 }
 return true;
}

//Get the base table name in the query related to this ResultSet
std::string ODBCResultSet::getBaseTableName() const
{
	unsigned char baseTableName[BUFSIZ];
	SQLSMALLINT len=0;
	rc_ = SQLColAttribute(hStmt_,1,SQL_DESC_BASE_TABLE_NAME,baseTableName,sizeof(baseTableName),&len,NULL);
	setError(__FILE__,__FUNCTION__,__LINE__,hStmt_,dbaccess::Types::ODBC::STMT_HDL);
	return std::string((char *)baseTableName);
}

//Get the alias table name in the query related to this ResultSet
std::string ODBCResultSet::getAliasTableName() const
{
	unsigned char aliasTableName[BUFSIZ];
	SQLSMALLINT len=0;
	rc_ = SQLColAttribute(hStmt_,1,SQL_DESC_TABLE_NAME,aliasTableName,sizeof(aliasTableName),&len,NULL);
	setError(__FILE__,__FUNCTION__,__LINE__,hStmt_,dbaccess::Types::ODBC::STMT_HDL);
	return std::string((char *)aliasTableName);
}
//sets the error related info by calling the ODBCError::setError()
void ODBCResultSet::setError(const char * fileName,const char * funcName,const long lineNum, SQLHANDLE hdl,dbaccess::Types::ODBC::HANDLE_TYPE hType) const
{
 static_cast<ODBCError*>(ODBCResultSet::err_)->setError(hdl,hType);	
#ifdef ALOGGER
 logError(fileName,funcName,lineNum);
#endif
}
//get the fetch direction for the ResultSet
int ODBCResultSet::getFetchDirection() const 
{ 
//In later versions this should choose from the different fetch directions
// like FORWARD_ONLY, BACKWARD, ... etc
 return dbaccess::Types::ODBC::FORWARD_ONLY; 
}

//Get the ResultSetType as specified in ADBC::dbaccess::Types::ODBC::SCROLL_TYPE
int ODBCResultSet::getResultSetType() const 
{ 
 //In later versions this should choose from the different SCROLL_TYPE's
 // like FORWARD_ONLY, SCROLL_SENSITIVE, SCROLL_INSENSITIVE
 return dbaccess::Types::ODBC::FORWARD_ONLY;
}// returns ResultSetType


//To be implemented in next version  

// Modifier functions
bool ODBCResultSet::absolute(int row) { return false; }
bool ODBCResultSet::relative(int rows) {return false; }
bool ODBCResultSet::afterLast() {return false; }
bool ODBCResultSet::beforeFirst() {return false; }
bool ODBCResultSet::previous() { return false;}
bool ODBCResultSet::first() { return false;}
bool ODBCResultSet::last() { return false;}
bool ODBCResultSet::close() {return false; }

bool ODBCResultSet::setFetchDirection(int direction) {return false; }

//const member functions
bool ODBCResultSet::isAfterLast() const  { return false;}
bool ODBCResultSet::isBeforeFirst() const  { return false;}
bool ODBCResultSet::isFirst()const  { return false;}
bool ODBCResultSet::isLast()const  { return false;}


// gets the current rowNum
int  ODBCResultSet::getRowNum()const  { return -1;}

int ODBCResultSet::getRowCount()const 
{
 // There is no general method of implementing this method
 // "select count(*) ..." is suggested as an alternative
 // for select statement
//Use to implement : SQLGetDiagField(SQL_HANDLE_STMT, hStmt_, 0, SQL_DIAG_ROW_COUNT, &recNum, 0, NULL);
 return -1;
}

int noCaseCompare(const string & s1, const string& s2) 
{
  string::const_iterator it1=s1.begin();
  string::const_iterator it2=s2.begin();

  //has the end of at least one of the strings been reached?
  while ( (it1!=s1.end()) && (it2!=s2.end()) ) 
    { 
      if(::toupper(*it1) != ::toupper(*it2)) //letters differ?
	// return -1 to indicate 'smaller than', 1 otherwise
	return (::toupper(*it1) < ::toupper(*it2)) ? -1 : 1; 
      //proceed to the next character in each string
      ++it1;
      ++it2;
    }
  size_t size1=s1.size(), size2=s2.size();// cache lengths
  //return -1,0 or 1 according to strings' lengths
  if (size1==size2) 
    return 0;
  return (size1<size2) ? -1 : 1;
}

}	//namespace dbaccess

