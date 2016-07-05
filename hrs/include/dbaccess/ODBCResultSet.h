#ifndef ODBCRESULTSET_H
#define ODBCRESULTSET_H

/**@file ODBCResultSet.h
* @brief ODBC specific implementation of ResultSet abstraction.
*
* $Header: ODBCResultSet.h
* 
* NAME: ODBCResultSet
* 
* BASE CLASSES: ResultSet
* 
* PURPOSE: ODBC specific implementation of ResultSet abstraction.
* 
* AUTHOR: Nitesh Sahu, Gurudutt Mallapur
* 
* DATE: 05-Aug-2005
*
* $Revision: 1.14 $
* 
* $Log: ODBCResultSet.h,v $
* Revision 1.14  2005/09/02 11:40:12  Jignesh.Kanchanlal
* Ready for Final Release
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

///////////////////////////////////////////////////////////////

///Typedefs

///Constants and defines

///Includes
/// windows.h : required by ODBC API headers
/// sql.h, sqlext.h : required for ODBC API Functions
/// ResultSet.h : required as base class/interface for ODBCResultSet

///Externals

///Variables

///Enumerations and Classes
///ODBCResultSet : implements ResultSet interface for ODBC


///Namespaces
/// ADBC : used to wrap all ADBC Framework classes etc.

//Forward Declaration for Data Types classes for used by getXXX() functions
#include <dbaccess/Common.h>
#include <string>

#ifdef WIN32
//required by sql.h etc.
#include <windows.h>
#endif

//for ODBC related includes
#include <sql.h>
#include <sqlext.h>

#ifdef ALOGGER
#include <logger/Logger.h>
#endif

//for ResultSet 
//#include "../include/ResultSet.h"		

//for enum HANDLE_TYPES etc.
#include <dbaccess/ODBCTypes.h>

#ifdef CPPUNIT_TESTING
//forward declaration for ODBCResultSetTest
namespace ADBC_TEST {
	class ODBCResultSetTest;
}
#endif
	
	//Forward Declaration for Error
	class ODBCError;
	

namespace dbaccess {
	
/** @class ODBCResultSet 
 * @brief ODBC-Specific implementation of ResultSet abstraction.
 */
class ODBCResultSet
{
public:

#ifdef CPPUNIT_TESTING
	friend class ADBC_TEST::ODBCResultSetTest;
#endif

	enum DataTypes { DT_BYTE=SQL_C_TINYINT, DT_SHORT=SQL_C_SHORT, DT_INTEGER=SQL_C_LONG, DT_LONG=SQL_C_SLONG, DT_FLOAT=SQL_C_FLOAT, DT_DOUBLE=SQL_C_DOUBLE, DT_STRING=SQL_C_CHAR, DT_BOOL=SQL_C_BIT, DT_BLOB=SQL_C_BINARY, DT_BYTES=SQL_C_BINARY, DT_DATE=SQL_C_TYPE_DATE, DT_TIME=SQL_C_TYPE_TIME, DT_DECIMAL=SQL_C_NUMERIC };


//Constructor and destructor
public : 
			/**Overloaded Constructor.
			* <BR>NAME:  ODBCResultSet
			* <BR>DESCRIPTION: Overloaded Constructor
			* <BR>PARAMETERS: @param  SQLHENV - Environment handle 
			* @param SQLHDBC -  Connection handle
			* @param SQLHSTMT - Statement handle
			* @param Error * - Pointer to Error object
			* <BR>SIDE EFFECTS: 
			*/
	ODBCResultSet(HENV env,HDBC conn,HSTMT stmt, ODBCError * eptr);

			/** Virtual Destructor.
			* <BR>NAME:  ~ODBCResultSet
			* <BR>DESCRIPTION:  Virtual Destructor of ODBCResultSet
			* <BR>PARAMETERS: @param Nil
			* <BR>SIDE EFFECTS: virtual destructor for polymorphic call to derived class destructor 
			*/
		virtual ~ODBCResultSet();

//Member Functions
public:		
//Modifier Functions
	
			/** Moves the cursor to a specific row in this ResultSet.
			* <BR>NAME:  absolute
			* <BR>DESCRIPTION: Moves the cursor to a specific row in this ResultSet
			* <BR>@todo To Be Implemented in next version, so currently returns false.
			* <BR>PARAMETERS: @param int - absolute row no. to move to 
			* <BR>RETURN: @return bool - true means success and false means fail
			* <BR>SIDE EFFECTS: 
			*/
	virtual	bool absolute(int row)  ;
	
			/** Moves the cursor inside the ResultSet relative to the current row.
			* <BR>NAME:  relative
			* <BR>DESCRIPTION:  Moves the cursor inside the ResultSet relative to the current row
			* <BR>@todo To Be Implemented in next version, so currently returns false.
			* <BR>PARAMETERS: @param int - row number to move to (relative to current position)
			* <BR>RETURN:@return bool - true means success and false means fail
			* <BR>SIDE EFFECTS:
			*/
	virtual	bool relative(int rows)  ;

			/** Places the cursor after the last row in the ResultSet.
			* <BR>NAME:  afterLast
			* <BR>DESCRIPTION:  places the cursor after the last row in the ResultSet 
			* <BR>@todo To Be Implemented in next version, so currently returns false.
			* <BR>PARAMETERS: @param Nil
			* <BR>RETURN: @return bool
			* <BR>SIDE EFFECTS:
			*/	
	virtual	bool afterLast()  ;

			/** Checks if the cursor is before the first row in the ResultSet.
			* <BR>NAME:  beforeFirst
			* <BR>DESCRIPTION: checks if the cursor is before the first row in the ResultSet.
			* <BR>@todo To Be Implemented in next version, so currently returns false.
			* <BR>PARAMETERS: @param Nil
			* <BR>RETURN: @return bool
			* <BR>SIDE EFFECTS:
			*/	
	virtual	bool beforeFirst()  ;

			/** Moves to the next row in the ResultSet.
			* <BR>NAME: next 
			* <BR>DESCRIPTION:  moves to the next row in the ResultSet.
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>PARAMETERS: @param Nil
			* <PRE> @param Error * - pointer to Error object 
			*  used to store errors after Any Connectivity Function call.
			* </PRE>
			* <BR>RETURN: @return bool - true if next() operation on success and false on failure
			* <BR>SIDE EFFECTS:
			*/	
	virtual	bool next()  ;

			/** Moves to the previous row in the ResultSet.
			* <BR>NAME: previous 
			* <BR>DESCRIPTION:  moves to the previous row in the ResultSet.
			* <BR>@todo To Be Implemented in next version, so currently returns false.
			* <BR>PARAMETERS: @param  Nil
			* <BR>RETURN: @return bool - true if success and false is fail.
			* <BR>SIDE EFFECTS:
			*/	
	virtual	bool previous()  ;

			/** Moves to the first row in the ResultSet.
			* <BR>NAME: first 
			* <BR>DESCRIPTION:  moves to the first row in the ResultSet.
			* <BR>@todo To Be Implemented in next version, so currently returns false.
			* <BR>PARAMETERS: @param Nil
			* <BR>RETURN: @return bool - true if success and false is fail.
			* <BR>SIDE EFFECTS:
			*/	
	virtual	bool first()  ;

			/** Moves to the last row in the ResultSet.
			* <BR>NAME: last 
			* <BR>DESCRIPTION:  moves to the last row in the ResultSet
			* <BR>@todo To Be Implemented in next version, so currently returns false.
			* <BR>PARAMETERS: @param Nil
			* <BR>RETURN: @return bool - true if success and false is fail.
			* <BR>SIDE EFFECTS:
			*/	
	virtual	bool last()  ;

			/** Closes the ResultSet.
			* <BR>NAME: close
			* <BR>DESCRIPTION:  closes the ResultSet
			* <BR>@todo To Be Implemented in next version, so currently returns false.
			* <BR>PARAMETERS: @param Nil
			* <BR>RETURN: @return bool
			* <BR>SIDE EFFECTS:
			*/	
	virtual	bool close()  ;

			/** Sets the direction of fetching of rows.
			* <BR>NAME:  setFetchDirection
			* <BR>DESCRIPTION:  sets the direction of fetching of rows
			* <BR>@todo To Be Implemented in next version, so currently returns false.
			* <BR>PARAMETERS: @param int - direction of fetching of rows
			* <BR>RETURN: @return bool
			* <BR>SIDE EFFECTS:
			*/	
	virtual	bool setFetchDirection(int direction)  ;

	//Metadeta functions
			
			/** Get Column-Type for a column in the ResultSet as defined by ODBC/Database.
			* <BR>NAME: getColumnType 
			* <BR>
			* <PRE>
			*  DESCRIPTION:  Use this function when you want to find out the 
			*  data-type no. as specified by ODBC/Database for a column/aliased column 
			*  in the ResultSet. 
			*  Note : It's better to use getColumnTypeName(), *Unless* you need the exact
			*  type in  a numeric form AND you're aware of ODBC/Database mapping of
			*  datatype to numeric form.
			*  NOTE : column indexes for ResultSet are 1 indexed.
			* </PRE>
			* <BR>PARAMETERS: @param int -  column no. in ResultSet (1 indexed)
			* <BR>
			* <BR>SIDE EFFECTS:
			*/
	virtual	int getColumnType(int colNum) const  ;

			/** Gets the data type as a std::string of given column index of the ResultSet.
			* <BR>NAME:  getColumnTypeName
			* <BR><PRE>
			* DESCRIPTION: It gets the data type in of given column index of the ResultSet.
			* NOTE : column indexes for ResultSet are 1 indexed.
			* </PRE>
			* <BR>PARAMETERS: @param int - column no. in ResultSet 
			* <BR>
			* <PRE>RETURN:  @return std::string - column typename as a string 
			*  i.e. "BYTE", "SMALLINT", "INTEGER", "REAL", "DOUBLE", "DECIMAL", "BIT", 
			*       "VARCHAR", "DATETIME", "CURRENCY", "LONGBINARY" etc.
			* </PRE>
			* <BR>SIDE EFFECTS:
			*/
	virtual	std::string getColumnTypeName(int colNum)const  ;

			/** Gets the direction of fetching of rows.
			* <BR>NAME:  getFetchDirection
			* <BR>DESCRIPTION:  gets the direction of fetching of rows
			* <BR>PARAMETERS: @param Nil
			* <BR>
			* <PRE>RETURN: @return int - Direction of fetching the data as in dbaccess::Types::ODBC::SCROLL_TYPE
			*  Currently dbaccess::Types::ODBC::FORWARD_ONLY is supported, 
			*  future implementations to implement this fully.			
			* </PRE>
			* <BR>SIDE EFFECTS:
			*/ 
	virtual  int getFetchDirection()const  ;

			/** Gets the number of rows retrieved into the ResultSet by Select statement.
			* <BR>NAME: getRowCount 
			* <BR>
			* <PRE>DESCRIPTION: Gets the number of rows retrived into the ResultSet by Select statement. 
			* Gets the no. of rows  affected by modifying commands .
			* NOTE :-  Not reliablly implemented on all Databases. 
			*          Use "Select COUNT(*) query" for better result.
			* </PRE>
			* <BR>PARAMETERS: @param Nil 
			* <BR>RETURN: @return int - currently returns -1.
			* <BR>SIDE EFFECTS:
			*/	
	virtual  int getRowCount()const   ;

			/** Gets the number of columns in the ResultSet, returns zero otherwise.
			* <BR>NAME: getColCount 
			* <BR>DESCRIPTION:  gets the number of columns in the ResultSet, returns zero otherwise.
			* <BR>PARAMETERS: @param Nil 
			* <BR>RETURN: @return int - no. of columns in the ResultSet
			* <BR>SIDE EFFECTS:
			*/
	virtual  int getColCount()const   ;

			/** Gets the type of this ResultSet.
			* <BR>NAME: getResultSetType 
			* <BR>DESCRIPTION: gets the type of this ResultSet 
			* <BR>PARAMETERS: @param Nil 
			* <PRE>RETURN: @return int - Type of ResultSet as in dbaccess::Types::ODBC::SCROLL_TYPE
			*  Currently dbaccess::Types::ODBC::FORWARD_ONLY is supported, 
			*  future versions to implement this fully.			
			* </PRE>			
			* <BR>SIDE EFFECTS:
			*/
	virtual  int getResultSetType() const  ;

	//const member functions

			/** Checks if the cursor is after the last row in the ResultSet.
			* <BR>NAME: isAfterLast 
			* <BR>DESCRIPTION: checks if the cursor is after the last row in the ResultSet 
			* <BR>@todo To Be Implemented in next version, so currently returns false.
			* <BR>PARAMETERS: @param Nil 
			* <BR>RETURN: @return bool - true if success and false is fail.
			* <BR>SIDE EFFECTS:
			*/
	virtual  bool isAfterLast() const   ;

			/** Checks if the cursor is before the first row in the ResultSet.
			* <BR>NAME: isBeforeFirst 
			* <BR>DESCRIPTION: checks if the cursor is before the first row in the ResultSet 
			* <BR>@todo To Be Implemented in next version, so currently returns false.
			* <BR>PARAMETERS: @param Nil 
			* <BR>RETURN: @return bool - true if success and false is fail.
			* <BR>SIDE EFFECTS:
			*/
	virtual  bool isBeforeFirst() const   ;

			/** Checks if the cursor is on the first row in the ResultSet.
			* <BR>NAME: isFirst 
			* <BR>DESCRIPTION:  checks if the cursor is on the first row in the ResultSet.
			* <BR>@todo To Be Implemented in next version, so currently returns false.
			* <BR>PARAMETERS: @param Nil 
			* <BR>RETURN: @return bool - true if success and false is fail.
			* <BR>SIDE EFFECTS:
			*/
	virtual  bool isFirst()const   ;

			/** Checks if the cursor is on the last row in the ResultSet.
			* <BR>NAME: isLast 
			* <BR>DESCRIPTION: checks if the cursor is on the last row in the ResultSet.  
			* <BR>@todo To Be Implemented in next version, so currently returns false.
			* <BR>PARAMETERS: @param  Nil 
			* <BR>RETURN: @return bool - true if success and false is fail.
			* <BR>SIDE EFFECTS:
			*/
	virtual  bool isLast()const   ;

			/** Returns the current row number.
			* <BR>NAME: getRowNum
			* <BR>DESCRIPTION:  returns the current row number.
			* <BR>@todo To Be Implemented in next version, so currently returns -1.
			* <BR>PARAMETERS: @param  Nil 
			* <BR>RETURN: @return int - current row number
			* <BR>SIDE EFFECTS:
			*/
	virtual int  getRowNum()const   ;

	//getxxx() functions

			/** Gets a column's value as a double.
			* <BR>NAME: getDouble 
			* <BR>DESCRIPTION:  gets a column's value as a double.
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>NOTE: Column indexes for ResultSet are 1 indexed.
			* <BR>PARAMETERS: @param int - column no. of ResultSet 
			* <BR>RETURN: @return double - field value as a double
			* <BR>SIDE EFFECTS:
			*/
	virtual  double getDouble(int col)const   ; 

			/** Gets a column's value as a double.
			* <BR>NAME: getDouble 
			* <BR>DESCRIPTION:  gets a column's value as a double.
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>PARAMETERS: @param int - column no. of ResultSet 
			* <BR>RETURN: @return double - field value as a double
			* <BR>SIDE EFFECTS:
			*/
	virtual double getDouble(std::string colName)const   ;

			/** Gets the date in DD-MON-YYYY Format
			* <BR>NAME: getDate 
			* <BR>DESCRIPTION:  Gets the date in DD-MON-YYYY Format
			* <BR>NOTE: 
			* <BR>PARAMETERS: @param colNum - Index of the column in the Select Stmt.
			* <BR>RETURN: @return std::string - Date in the above format
			* <BR>SIDE EFFECTS:
			*/
    virtual std::string getDate(int colNum)const ;
    
			/** Gets a column's value as a bool.
			* <BR>NAME: getBool 
			* <BR>DESCRIPTION:  gets a column's value as a bool. 
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>NOTE: Column indexes for ResultSet are 1 indexed.
			* <BR>PARAMETERS: @param int - column no. of ResultSet 
			* <BR>RETURN: @return bool - field value as a bool
			* <BR>SIDE EFFECTS:
			*/
	virtual  bool getBool(int col)const   ; 

			/** Gets a column's value as a bool.
			* <BR>NAME: getBool 
			* <BR>DESCRIPTION:  gets a column's value as a bool. 
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>PARAMETERS: @param std::string  - column name/alias of ResultSet 
			* <BR>RETURN: @return bool - field value as a bool
			* <BR>SIDE EFFECTS:
			*/
	virtual  bool getBool(std::string colName)const   ;


			/** Gets a column's value as a float. 
			* <BR>NAME: getFloat 
			* <BR>DESCRIPTION:  gets a column's value as a float
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>PARAMETERS: @param std::string  - column name/alias of ResultSet 
			* <BR>RETURN: @return float - field value as a float
			* <BR>SIDE EFFECTS:
			*/
	virtual  float getFloat(int col)const   ; 

			/** Gets a column's value as a float. 
			* <BR>NAME: getFloat 
			* <BR>DESCRIPTION:  gets a column's value as a float
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>PARAMETERS: @param std::string  - column no. of ResultSet 
			* <BR>RETURN: @return float
			* <BR>SIDE EFFECTS:
			*/
	virtual  float getFloat (std::string colName)const   ;

			/** Gets a column's value as an int.
			* <BR>NAME: getInt 
			* <BR>DESCRIPTION:  gets a column's value as an integer 
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>NOTE: Column indexes for ResultSet are 1 indexed.
			* <BR>PARAMETERS: @param int - column no. of ResultSet 
			* <BR>RETURN: @return int - field value as an int
			* <BR>SIDE EFFECTS:
			*/
	virtual  int getInt(int col)const   ; 

			/** Gets a column's value as an int.
			* <BR>NAME: getInt 
			* <BR>DESCRIPTION:  gets a column's value as an integer 
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>PARAMETERS: @param std::string  - column name/alias of ResultSet 
			* <BR>RETURN: @return int - field value as an int
			* <BR>SIDE EFFECTS:
			*/
	virtual  int getInt(std::string colName)const   ;

			/**  Gets a column's value as a long.
			* <BR>NAME: getLong 
			* <BR>DESCRIPTION:  gets a column's value as a long
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>NOTE: Column indexes for ResultSet are 1 indexed.
			* <BR>PARAMETERS: @param int - column no. of ResultSet 
			* <BR>RETURN: @return long - field value as a long
			* <BR>SIDE EFFECTS:
			*/
	virtual  long getLong(int col)const   ;  

			/**  Gets a column's value as a long.
			* <BR>NAME: getLong 
			* <BR>DESCRIPTION:  gets a column's value as a long
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>PARAMETERS: @param std::string  - column name/alias of ResultSet 
			* <BR>RETURN: @return long - field value as a long
			* <BR>SIDE EFFECTS:
			*/
	virtual  long getLong(std::string colName)const   ;

			/** Gets a column's value as a short.
			* <BR>NAME: getShort 
			* <BR>DESCRIPTION:  gets a column's value as a short
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>NOTE: Column indexes for ResultSet are 1 indexed.
			* <BR>PARAMETERS: @param int - column no. of ResultSet 
			* <BR>RETURN: @return short - field value as a short
			* <BR>SIDE EFFECTS:
			*/
	virtual  short getShort(int col)const   ;  

			/**  Gets a column's value as a short.
			* <BR>NAME: getShort 
			* <BR>DESCRIPTION:  gets a column's value as a short
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>PARAMETERS: @param std::string  - column name/alias of ResultSet 
			* <BR>RETURN: @return short - field value as a short
			* <BR>SIDE EFFECTS:
			*/
	virtual  short getShort(std::string colName)const   ;

			/** Gets a column's value as a std::string. 
			* <BR>NAME: getString 
			* <BR>DESCRIPTION:  gets a column's value as a string
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>NOTE: Column indexes for ResultSet are 1 indexed.
			* <BR>PARAMETERS: @param int - column no. of ResultSet 
			* <BR>RETURN: @return std::string - field value as a std::string
			* <BR>SIDE EFFECTS:
			*/
	virtual  std::string getString(int col)const   ;  

			/** Gets a column's value as a std::string. 
			* <BR>NAME: getString 
			* <BR>DESCRIPTION:  gets a column's value as a string
			* <BR>NOTE: Call next() to fetch the row. Followed by calls to getXXX() for the fields of that row.			
			* <BR> Use the Error class methods to check for errors and get the error status.
			* <BR>PARAMETERS: @param std::string  - column name/alias of ResultSet 
			* <BR>RETURN: @return std::string - field value as a std::string
			* <BR>SIDE EFFECTS:
			*/
	virtual  std::string getString(std::string colName)const   ;


			/** Finds a column no. by the column's name/alias (of ResultSet).
			* <BR>NAME: getColNum 
			* <BR>DESCRIPTION:  finds a column no. by the column's name/alias (of ResultSet).
			* <BR>NOTE: Column indexes for ResultSet are 1 indexed.
			* <BR>PARAMETERS: @param std::string - column name/alias (of ResultSet) as a string
			* <BR>RETURN: @return int - column no. in ResultSet
			* <BR>SIDE EFFECTS:
			*/
	virtual int getColNum(std::string colName) const   ;

//Helper methods
protected:	
#ifdef ALOGGER
			/** Prints diagnostics error messages to logfile using aLib::Logger.
			* <BR>NAME: logError
			* <BR>DESCRIPTION:  Prints diagnostics error messages to logfile using aLib::Logger
			* <BR>PARAMETERS: @param char * - File name in which error occured 
			* <BR> @param char * - Function name in which error occured
			* <BR> @param size_t - Line number at which error occured
			* <BR>RETURN: @return RETCODE - Error status
			* <BR>SIDE EFFECTS: 
			*/
	RETCODE ODBCResultSet::logError(const char *file,const char * fname,const size_t lnum) const ;

#endif
	 			
			/** Gets a column's values in the specified format.
			* <BR>NAME: getData
			* <BR>DESCRIPTION:  Gets a column's values in the specified format
			* <BR>NOTE: It is a wrapper around the SQLGetData() ODBC function,
			* <BR>and is a data-type conversion function.
			* <BR>It will convert properly for compatible data-types. 
			* <BR> It gives junk when used to convert between incompatible datatypes.
			* <BR> i.e. converting between Long and Int is okay.
			* <BR> even converting between String and Int is possible ("10" --> 10 )
			* <BR> however not ("ABCD" -> junk )
			* <BR> but converting between Double and Decimal will create junk.
			* <BR>PARAMETERS: @param int - column no. of ResultSet 
			* <BR>@param ODBCResultSet::DataTypes - Target Datatype to convert to 
			* <BR>@param unsigned int - length of buffer to store value in 
			* <BR>@param void * - address of buffer to store value in 
			* <BR>RETURN: @return RETCODE - Error status
			* <BR>SIDE EFFECTS:
			*/
	 RETCODE getData(unsigned int colNum,ODBCResultSet::DataTypes type,
		unsigned int bufLength,void * retVal) const;


//Hidden to prevent accidental copying or assignment
private :	

			/** Copy constructor for ODBCResultSet.
			* <BR>NAME: ODBCResultSet
			* <BR>DESCRIPTION:  Copy constructor for ODBCResultSet
			* <BR>PARAMETERS: @param ODBCResultSet & 
			* <BR>SIDE EFFECTS:
			*/
		ODBCResultSet(const ODBCResultSet &other);

			/** Assignment Operator for ODBCResultSet.
			* <BR>NAME: operator = 
			* <BR>DESCRIPTION:  Assignment Operator for ODBCResultSet
			* <BR>PARAMETERS: @param ODBCResultSet &
			* <BR>RETURN: @return ODBCResultSet &
			* <BR>SIDE EFFECTS:
			*/
		ODBCResultSet & operator =(const ODBCResultSet & other);

		

protected: 
			/** Fills up ResultSet column metaData in ColMap member.
			* <BR>NAME: getColMetaData
			* <BR>DESCRIPTION: Fills up ResultSet column metaData in ColMap member
			* <BR> maps the column index of ResultSet to column name/alias of ResultSet
			* <BR>NOTE: This method is required for using the getXXX(std::string colName) methods
			* <BR>      to map the column name/alias of ResultSet to column No. of ResultSet
			* <BR>PARAMETERS: @param Nil
			* <BR>RETURN: @return bool - True on success and false on failure.
			* <BR>SIDE EFFECTS:
			*/
		virtual bool getColMetaData(); 


			/** Gets the Name of the table as in the database.
			* <BR>NAME: getBaseTableName
			* <BR>DESCRIPTION: Gets the Name of the table as in the database
			* <BR>PARAMETERS: @param Nil
			* <BR>RETURN: @return std::string - Name of the table
			* <BR>SIDE EFFECTS:
			*/
		virtual std::string getBaseTableName() const;
		
			/** Gets the alias Name of the table as in the query.
			* <BR>NAME: getAliasTableName
			* <BR>DESCRIPTION: Gets the alias Name of the table as in the query
			* <BR>PARAMETERS: @param Nil
			* <BR>RETURN: @return std::string - Alias name of the table
			* <BR>SIDE EFFECTS:
			*/
		virtual std::string getAliasTableName() const;

			/** Gets the column number for column name as in table.
			* <BR>NAME: getBaseColNum
			* <BR>DESCRIPTION: Gets the column number for column name as in table 
			* <BR>PARAMETERS: @param std::string - Name of the column
			* <BR>RETURN: @return int - column number 
			* <BR>SIDE EFFECTS:
			*/
		virtual int ODBCResultSet::getBaseColNum(std::string colName)const;

			/** Gets the column number for column alias as in query.
			* <BR>NAME: getAliasColNum
			* <BR>DESCRIPTION: Gets the column number for column alias as in query 
			* <BR>PARAMETERS: @param std::string - Alias/Name of the column
			* <BR>RETURN: @return int - column number 
			* <BR>SIDE EFFECTS:
			*/
		virtual int ODBCResultSet::getAliasColNum(std::string colName)const;

			/** Sets the Error status in the Error Object.
			* <BR>NAME: setError
			* <BR>DESCRIPTION: Sets the Error status in the Error Object.
			* <BR>NOTE: This method MUST be called after calling any ODBC Function.
			* <BR>PARAMETERS: @param HSTMT-Handle to statement
			*  @param dbaccess::Types::ODBC::HANDLE_TYPE - Handle type
			* <BR>RETURN: Nil
			* <BR>SIDE EFFECTS:
			*/
		virtual void ODBCResultSet::setError(const char fileName[BUFSIZ],
			const char funcName[BUFSIZ],const long lineNum, SQLHANDLE hdl,
			dbaccess::Types::ODBC::HANDLE_TYPE hType) const;

		
			/** Gets the column name of a given index.
			* <BR>NAME: getColName
			* <BR>DESCRIPTION: Gets the column name of a given index 
			* <BR>PARAMETERS: @param int - column number 
			* <BR>RETURN: @return std::string - Name of the column
			* <BR>SIDE EFFECTS:
			*/	
		virtual std::string ODBCResultSet::getColName(int col) const ;


//Protected Variables
protected:	
	HENV hEnv_;	///<  ODBC handle for environment.
	HDBC hConn_; ///< ODBC handle for connection.
	HSTMT hStmt_; ///< ODBC handle for statement.

	/** @struct ColMap 
	* @brief Used to store the mapping between Column index ,name and Alias for a resultset as stored in cursor.
	*/
	struct ColMap {
	int colNum_;			///< column index in ResultSet produced by select query
	char baseColName_[BUFSIZ];	///< base column name as in database table
	char aliasColName_[BUFSIZ];	///< alias column name as in query
	};
	ColMap * colMap_ ;		///< pointer to ColMap object

#ifdef ALOGGER
	mutable char logBuff_[BUFSIZ];		///< used to store temp log messages
#endif

//Instance data.
private:
	///mutable memeber variable to allow const methods to change it.
	mutable RETCODE rc_; ///< Temporary variable to store Error status returned by ODBC functions 

	SQLCHAR msg_[BUFSIZ]; ///< Temporary Error message buffer used by error()
	SQLCHAR status_[BUFSIZ]; ///< Temporary Error status buffer used by error()

	ODBCError *err_; ///< Pointer to Error object used to store error/warning status.

}; //class ODBCResultSet

}	//namespace dbaccess 
#endif  //ODBCRESULTSET_H

