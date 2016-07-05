/**@file ODBCStatement.cpp
*@brief Wrapper Class around the ODBC Specific SQL Statement Handle
*
* NAME:						ODBCStatement	
* 
* BASE CLASSES:				Statement
* 
* PURPOSE:					Wrapper Class around the ODBC Specific SQL Statement Handle
* 
* AUTHOR:					Arun Veeramany
* 
* $Revision: 1.8 $
* 
* $Log: ODBCStatement.cpp,v $
* Revision 1.8  2005/08/30 05:23:25  Jignesh.Kanchanlal
* Bugs after Testing fixed
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/


///////////////////////////////////////////////////////////////
//Includes
#include <dbaccess/ODBCStatement.h>		///< Corresponding header file
#include <dbaccess/ODBCError.h>			///< For ODBC errors
#include <dbaccess/ODBCResultSet.h>		///< For ResultSet
#include <common/GeneralException.h>	///< For ADBC exceptions
#include <dbaccess/ODBCTypes.h>

#ifdef ALOOGER
	#include <logger/Logger.h>
#endif



namespace dbaccess {

// std::string toUpper(std::string str)
// {

//   int size = str.length();
//   char temp[100];
//   int i = 0;
//   for(i = 0; i < size ; ++i)
//   {
//     temp[i] = ::toupper(str[i]);
//   }
//   temp[i] = '\0';

//   return temp;
// }

	
/**
* <BR>NAME:Overloaded Constructor
* <BR>DESCRIPTION:Suppress the Default constructor
* <BR>SIDE EFFECTS:Nil
* <BR>PARAMETERS: @param Nil
* <BR>RETURN: @return Nil
*/
ODBCStatement::ODBCStatement():
			rsType_(Types::ODBC::FORWARD_ONLY),
			hdlEnv_(0),
			hdlDbc_(0), 
			hdlStmt_(0), 
			cursorName_(""),		
			ptrError_(NULL)
{
}


/**
 * <BR>NAME:Destructor.
 * <BR>DESCRIPTION:frees up the statement handle after completion.
 * <BR>SIDE EFFECTS: Nil
 * <BR>PARAMETERS:
 * <BR>			@param Nil
 * <BR>@return RETURN:Nil
 */
ODBCStatement::~ODBCStatement()
{
	close();				///<closes the cursor and frees up the statement handle.
}

ODBCStatement::ODBCStatement(const ODBCStatement& other)
{
	/// This is protected...Need not implement.
}

ODBCStatement& ODBCStatement::operator =(const ODBCStatement & other)
{
	/// This is protected...Need not implement.
	return *this;
}

/**
 * <BR>NAME:Overloaded Constructor
 * <BR>DESCRIPTION:Other ADBC Classes use this constructor and return a pointer.
 * <BR>SIDE EFFECTS:Nil
 * <BR> PARAMETERS:
 * <BR>			@param handleHENV - Handle to the ODBC Environment
 * <BR>			@param handleHDBC - Handle to the ODBC Database
 * <BR>			@param error	  -	An error object to fill up in case of failure
 * <BR>RETURN: @return Nil
 */
ODBCStatement::ODBCStatement(	SQLHANDLE handleHENV, 
				SQLHANDLE handleHDBC, 
				ODBCError* error):
					rsType_(Types::ODBC::FORWARD_ONLY),
					hdlEnv_(handleHENV), 
					hdlDbc_(handleHDBC), 
					hdlStmt_(0),
					cursorName_(""),		
					ptrError_(error)
{
	
#ifdef ALOGGER
	logger::Logger::getInstance().debug("ODBCStatement::Constructor:Entering ODBCStatement Overloaded Constructor");
#endif

    /** allocate another statement handle */
/*
  SQLRETURN rc = SQLAllocHandle(SQL_HANDLE_STMT, hdlDbc_, &hdlStmt_);
  static_cast<ODBCError*>(ptrError_)->setError(hdlStmt_, Types::ODBC::STMT_HDL);
  
  if(rc != SQL_SUCCESS)			// -1 rows updated; let user figure out why it failed thru Error*
  {
#ifdef ALOGGER
	  logger::Logger::getInstance().error( "ODBCStatement:executeUpdate:Error allocating memory for the handle.Aborting...");
#endif
	 // return -1;
  }
  */
}

/**	
 *	<BR>NAME:executeQuery
 *	<BR>DESCRIPTION:
 *	<BR>Executes a given SELECT statement and returns a ResultSet 
 *	<BR>which can be used to access the contents returned by the query.
 *	<BR>
 *  <BR>It may be noted that a statement as of this version can only be bound to one
 *  <BR>ResultSet. Initiating a new query would result in a new resultset
 *  <BR>invalidating the old one.
 *  <BR> Eg:
 *	<BR>		ResultSet* rsOld = stmt->executeQuery("SQL1");
 *	<BR>		ResultSet* rsNew = stmt->executeQuery("SQL2");
 *	<BR>		Now, rsOld->getXXXX() does not fetch the expected results at its
 *	<BR>		Statement Handle is overwritten by that of rsNew.
 *	<BR>
 *	<BR>ODBC API FOR executeQuery, executeUpdate, execute
 *	<BR>
 *	<BR>SQLRETURN   SQLExecDirect (
 *  <BR>    SQLHSTMT          StatementHandle,         // hstmt 
 *	<BR>    SQLCHAR           *StatementText,          // szSqlStr 
 *  <BR>    SQLINTEGER        TextLength);             // cbSqlStr  
 *	<BR>
 *	<BR>SIDE EFFECTS: Nil
 *	<BR>PARAMETERS:
 *	<BR>			@param string - String representing the SQL SELECT Query
 *	<BR>@return RETURN:ODBCResultSet* - A pointer to the returned resultset, NULL on failure
 *	<BR> 
 *  <BR> SIDE EFFECTS : Throws exception when the statement passes is not 
 *  <BR> a SELECT statement.
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>\test No active database / statement not initialized
 *	<BR>
 *	<BR>\test executeQuery("");
 *	<BR>\test executeQuery("dskjfjsdhgkjhdk");
 *	<BR>\test executeQuery("select * from TABLE_DOES_NOT_EXIST");
 *	<BR>\test executeQuery("select COL_DOES_NOT_EXIST from TABLE");
 *	<BR>\test executeQuery("THIS IS NOT FOR UPDATE STATEMENT");
 *	<BR>\test executeQuery("THIS IS NOT FOR DELETE STATEMENT");
 *	<BR>\test executeQuery("THIS IS NOT FOR INSERT STATEMENT");
 *	<BR>\test executeQuery("TYPE MISMATCH");
 *	<BR>\test executeQuery("MISTAKE IN WHERE CLAUSE");
 *	<BR>
 */
ODBCResultSet* ODBCStatement::executeQuery(std::string szQuery) 
{
  SQLCHAR *stmt = (SQLCHAR*)(szQuery.c_str()) ;		///<Get an SQLCHAR* version of std::string

  /* Test for the presence of SELECT Statement */

  //char* testStmt = new char[ szQuery.length() + 1 ];	///<Replicate the query; to preserve the original case

    //strcpy(testStmt, (char*)stmt);		//don't convert *stmt to uppercase, 
  //  strupr((char*)testStmt);				//it might contain sensitive string comparisons.
  //  strcpy(testStmt, (char*)(toUpper( (std::string (testStmt))).c_str()));

#ifdef ALOGGER
  logger::Logger::getInstance().info("ODBCStatement::executeQuery:Checking presence of SELECT Statement...");
#endif
/*
  char* posPtr = strstr(testStmt, "SELECT");		//Search for the select keyword.

  if(posPtr == NULL)					// hey! this method is for SELECT Query!
  {
	  delete testStmt;		//freeup and exit with an exception
	  throw new GeneralException("Invalid SELECT Statement.");
  }

  delete testStmt;			//exception was not thrown, freeup and continue;
*/
  /* End Test for the presence of SELECT Statement */

  SQLRETURN rc = SQL_SUCCESS;			///<Assume Success

   rc = SQLFreeHandle(SQL_HANDLE_STMT, &hdlStmt_);

    /** allocate another statement handle */

   rc = SQLAllocHandle(SQL_HANDLE_STMT, hdlDbc_, &hdlStmt_);
  static_cast<ODBCError*>(ptrError_)->setError(hdlStmt_, Types::ODBC::STMT_HDL);


#ifdef ALOGGER
  logger::Logger::getInstance().info("ODBCStatement:executeQuery:About to execute the Query...");
#endif

  /** execute a statement */
  rc = SQLExecDirect(hdlStmt_, stmt, SQL_NTS);/* let the turbine do its work!*/	
  (static_cast<ODBCError*>(ptrError_))->setError(hdlStmt_,Types::ODBC::STMT_HDL);

  if(rc != SQL_SUCCESS)
  {
#ifdef ALOGGER
	  logger::Logger::getInstance().error( "ODBCStatement:executeQuery:SQLExecDirect:Aborting...", (char*)stmt );
#endif
		return NULL;
  }

#ifdef ALOGGER
  logger::Logger::getInstance().info("ODBCStatement::executeQuery:Returning the Resultset...");
#endif


  return  new ODBCResultSet(hdlEnv_, hdlDbc_, hdlStmt_, ptrError_);
}

/**
 * <BR>NAME:executeUpdate
 * <BR>DESCRIPTION:Executes the given UPDATE/INSERT/DELETE statement
 * <BR>SIDE EFFECTS: Nil
 * <BR>PARAMETERS:
 * <BR>			@param query - SQL Update Statement to be executed.
 * <BR>@return RETURN:int - returns the number of rows affected; -1 on failure
 * <BR>SIDE EFFECTS: Throws an exception if not an INSERT/UPDATE/DELETE statement
 * <BR>\test Follow the same test cases as in executeQuery()
 */
int ODBCStatement::executeUpdate(std::string szQuery)
{
  SQLCHAR *stmt = (SQLCHAR*)(szQuery.c_str()) ; ///< Convert the std-string to SQLCHAR

  /* Test for the presence of UPDATE/INSERT/DELETE Statement */

/*
  char* testStmt = new char[ szQuery.length() + 1 ]; ///<Replicate the query; to preserve the original case

  strcpy(testStmt,(char*) stmt);		//don't convert *stmt to uppercase, 

  char temp[1024];
  std::string tempString(testStmt);
  strcpy(temp,toUpper(tempString).c_str());

  strcpy(testStmt, temp);

  // strcpy(testStmt, (char*)(toUpper( (std::string (testStmt))).c_str()));
 //  strupr((char*)testStmt); 										//it might contain sensitive string comparisons.

#ifdef ALOGGER
  logger::Logger::getInstance().info("ODBCStatement::executeUpdate:Checking for the presence of INSERT/DELETE/UPDATE...");
#endif


  //Search for the UPDATE/INSERT/DELETE keyword.
  bool keywordPresent = strstr(testStmt, "UPDATE") || strstr(testStmt, "INSERT") || strstr(testStmt, "DELETE");		

  if(keywordPresent == false)					// hey! this method is for UPDATE/INSERT/DELETE Query!
  {
#ifdef ALOGGER
	  logger::Logger::getInstance().error( "ODBCStatement:executeUpdate:Aborting...INSERT/DELETE/UPDATE Missing", (char*)stmt );
#endif

	 //freeup and exit with an exception
	  delete testStmt;
	  throw new GeneralException("Invalid Insert/Update/Delete Statement.");
	  		
  }

  delete testStmt;			//exception was not thrown, freeup and continue;
*/
  /* End Test for the presence of SELECT Statement */


  SQLRETURN rc = SQL_SUCCESS;			///< Assume a successful execution

#ifdef ALOGGER
	  logger::Logger::getInstance().info( "ODBCStatement:executeUpdate:About to allocate handle..." );
#endif

  rc = SQLFreeHandle(SQL_HANDLE_STMT, &hdlStmt_);

    /** allocate another statement handle */

   rc = SQLAllocHandle(SQL_HANDLE_STMT, hdlDbc_, &hdlStmt_);
  static_cast<ODBCError*>(ptrError_)->setError(hdlStmt_, Types::ODBC::STMT_HDL);

#ifdef ALOGGER
  logger::Logger::getInstance().info("ODBCStatement::executeUpdate:About to execute ExecDirect");
#endif

  /** execute a statement */
  rc = SQLExecDirect(hdlStmt_, stmt, SQL_NTS);
  static_cast<ODBCError*>(ptrError_)->setError(hdlStmt_, Types::ODBC::STMT_HDL);

#ifdef ALOGGER
  logger::Logger::getInstance().info("ODBCStatement::executeUpdate:Executed ExecDirect");
#endif


 if(rc != SQL_SUCCESS)
 {
#ifdef ALOGGER
	  logger::Logger::getInstance().error( "ODBCStatement:executeUpdate:SQLExecDirect:Aborting...", (char*)stmt );
#endif
	  return -1;
 }

 return getRowCount();			///< Successful Execution; return the number of rows affected.
}

/**
 * <BR>NAME:execute
 * <BR>DESCRIPTION:Executes DDL SQL statements i.e. CREATE TABLE / DROP / ALTER TABLE
 * <BR>SIDE EFFECTS: Nil
 * <BR>PARAMETERS:
 * <BR>			@param query - SQL Update Statement to be executed.
 * <BR>@return RETURN:bool - returns whether the operation was successful.
 * <BR>\test Follow the same test cases as in executeQuery()
 * <BR> SIDE EFFECTS: Throws an exception if it is not a CREATE/DROP/ALTER query.
 */
bool ODBCStatement::execute(std::string szQuery) 
{
  SQLCHAR *stmt = (SQLCHAR*)(szQuery.c_str()) ;	///<Convert SQLCHAR* from std::string;

  
  /* Test for the absence of SELECT & UPDATE Statement */
/*
  char* testStmt = new char[ szQuery.length() + 1 ];	///<Replicate the query; to preserve the original case

  strcpy(testStmt,(char*)stmt);		//don't convert *stmt to uppercase, 

  char temp[1024];
  std::string tempString(testStmt);
  strcpy(temp,toUpper(tempString).c_str());

  strcpy(testStmt, temp);
  //  strcpy(testStmt, (char*)(toUpper( (std::string (testStmt))).c_str()));
//  strupr((char*)testStmt);										//it might contain sensitive string comparisons.

  bool dmlPtr =  strstr(testStmt, "CREATE") || 
				 strstr(testStmt, "DROP")   ||
				 strstr(testStmt, "ALTER") ;

 #ifdef ALOGGER
	  logger::Logger::getInstance().info( "ODBCStatement:execute:Checking for CREATE/DROP/ALTER...");
#endif
dmlPtr=true;

  if(dmlPtr == false)					// hey! this method does not support the above ones
  {
	 delete testStmt;		//freeup and exit with an exception

#ifdef ALOGGER
	  logger::Logger::getInstance().error( "ODBCStatement:execute:CREATE/DROP/ALTER Not found.Aborting...", (char*)stmt );
#endif

	 throw new GeneralException("execute supports CREATE / DROP / ALTER Only");
  }

  delete testStmt;			//exception was not thrown, freeup and continue;
*/
  /* End Test for the presence of SELECT Statement */


  SQLRETURN rc = SQL_SUCCESS;

#ifdef ALOGGER
	  logger::Logger::getInstance().info( "ODBCStatement:execute:Allocating memory for handle...");
#endif

  rc = SQLFreeHandle(SQL_HANDLE_STMT, &hdlStmt_);

    /** allocate another statement handle */
  rc = SQLAllocHandle(SQL_HANDLE_STMT, hdlDbc_, &hdlStmt_);
  static_cast<ODBCError*>(ptrError_)->setError(hdlStmt_, Types::ODBC::STMT_HDL);

  if(rc != SQL_SUCCESS)
  {
#ifdef ALOGGER
	  logger::Logger::getInstance().info( "ODBCStatement:execute:Error allocating memory for handle.Aborting...");
#endif
	  return false;
  }

#ifdef ALOGGER
	  logger::Logger::getInstance().info( "ODBCStatement:execute:About to call SQLExecDirect");
#endif

  /** execute a statement */
  rc = SQLExecDirect(hdlStmt_, stmt, SQL_NTS);/* bind column 1 to variable */	
  static_cast<ODBCError*>(ptrError_)->setError(hdlStmt_, Types::ODBC::STMT_HDL);


 if(rc != SQL_SUCCESS)
 {
#ifdef ALOGGER
	  logger::Logger::getInstance().info( "ODBCStatement:execute:SQLExecDirect:Aborting..." );
#endif
	 return false;
 }

 return true;		///< if control has come here, deemed to be successful
}

/**
 *	<BR>NAME:getRowCount
 *	<BR>DESCRIPTION:Returns the number of rows in a table that were affected by an UPDATE, INSERT, DELETE, or MERGE statement executed against the table, or a view based on the table. 
 *	<BR>SIDE EFFECTS:Nil
 *	<BR>ODBC API:
 *	<BR>
 *	<BR>SQLRETURN   SQLRowCount (
 *  <BR>        SQLHSTMT     StatementHandle,   // hstmt 
 *  <BR>        SQLINTEGER   *RowCountPtr);     // pcrow
 *	<BR>
 *	<BR>TEST CASES:
 *	<BR>\test No statement was executed.
 *	<BR>\test Statement was executed unsuccessfully.
 *	<BR> PARAMETERS: 
 *		@param	Nil
 *	
 *	<BR>RETURN:
 *		@return int - Returns the number of rows affected by the recent query
 */
int ODBCStatement::getRowCount(void) const
{
	SQLRETURN rc = SQL_SUCCESS;	// Assume success
	SQLINTEGER numAffected = 0;		// The return value

#ifdef ALOGGER
	  logger::Logger::getInstance().info( "ODBCStatement:getRowCount:Fetching the rowcount..." );
#endif

	
	rc = SQLRowCount(hdlStmt_, &numAffected);	// The main ODBC Function to drive this.
	static_cast<ODBCError*>(ptrError_)->setError(hdlStmt_, Types::ODBC::STMT_HDL);

	if(rc != SQL_SUCCESS)
	{
#ifdef ALOGGER
	  logger::Logger::getInstance().error( "ODBCStatement:getRowCount:Error retrieving Row Count.Aborting...");
#endif
			return -1;					//let the user figure out through Error*
	}

	return numAffected;
}

/**
 * <BR>NAME:setType
 * <BR>DESCRIPTION:
 * <BR>Sets the type of ResultSet to be returned by the ExecuteQuery method. 
 * <BR>SIDE EFFECTS: Nil
 * <BR>PARAMETERS:
 * <BR>			@param rsType:For a list of valid ResultSet types refer to the 
 * <BR>ResultSetType Enumeration.
 * <BR>@return RETURN:Nil
 * <BR>TEST CASES
 * <BR>	
 * <BR>\test setType(NOT_IN_ENUM_LIST);
 * <BR>\test setType(DATABASE_DOES_NOT_SUPPORT_THIS_TYPE);
 * <BR> SIDE EFFECTS: Throws an exception if the type passed is not 
 * <BR>one of the specified types in enum.
 */
void ODBCStatement::setType(int rsType)
{
		switch(rsType)
		{
		case Types::ODBC::FORWARD_ONLY:
				setType_(SQL_ATTR_CURSOR_TYPE, (SQLPOINTER)SQL_CURSOR_FORWARD_ONLY);
				break;
		case Types::ODBC::SCROLL_SENSITIVE:
				setType_(SQL_ATTR_CURSOR_SCROLLABLE , (SQLPOINTER)SQL_SCROLLABLE);
				
			//	setType_(SQL_ATTR_CURSOR_SENSITIVITY, (SQLPOINTER)SQL_SENSITIVE );
				break;
		case Types::ODBC::SCROLL_INSENSITIVE:
				setType_(SQL_ATTR_CURSOR_SCROLLABLE, (SQLPOINTER)SQL_SCROLLABLE );
				setType_(SQL_ATTR_CURSOR_TYPE , (SQLPOINTER)SQL_CURSOR_DYNAMIC   );

				//setType_(SQL_ATTR_CURSOR_SENSITIVITY, (SQLPOINTER)SQL_INSENSITIVE );
				break;
		default:
#ifdef ALOGGER
			    logger::Logger::getInstance().error( "ODBCStatement:setType:Unspecified Type.Aborting..." );
#endif

				throw new GeneralException("Could not set the specified type.");
		
		/* Not for the current release*/

// 		case ResultSet::ResultSetType::CONCURRENT_READ_ONLY:
// 				setType_(SQL_ATTR_CONCURRENCY, (SQLPOINTER)SQL_CONCUR_READ_ONLY );
// 				break;
// 		case ResultSet::ResultSetType::CONCURRENT_UPDATE:
// 				setType_(SQL_ATTR_CONCURRENCY, (SQLPOINTER)SQL_CONCUR_LOCK);
// 				break;
		}

#ifdef ALOGGER
	  logger::Logger::getInstance().info( "ODBCStatement:setType:Setting the resultset type...");
#endif

	rsType_ = rsType;
}

/**
 * <BR>NAME:setType_
 * <BR>DESCRIPTION:
 * <BR>Helper function for setType().
 * <BR>SIDE EFFECTS: Nil
 * <BR>SQLRETURN   SQLSetStmtAttr (
 * <BR>							SQLHSTMT          StatementHandle,  // hstmt
 * <BR>							SQLINTEGER        Attribute,        // fOption 
 * <BR>							SQLPOINTER        ValuePtr,         // pvParam 
 * <BR>							SQLINTEGER        StringLength);    // fStrLen 
 * <BR>
 * <BR>PARAMETERS:
 * <BR>			@param attribute:the name of the statement property to be set
 * <BR>	http://publib.boulder.ibm.com/infocenter/db2help/index.jsp?topic=/com.ibm.db2.udb.doc/ad/r0000632.htm
 * <BR>			@param value:the value for the above property
 * <BR>@return RETURN:Nil
 * <BR>TEST CASES
 * <BR>	
 * <BR>\test setType_(NOT_IN_ENUM_LIST);
 * <BR>\test setType_(DATABASE_DOES_NOT_SUPPORT_THIS_TYPE);
 */
void ODBCStatement::setType_(SQLINTEGER attribute, SQLPOINTER value) const
{
#ifdef ALOGGER
	  logger::Logger::getInstance().info( "ODBCStatement:setType_:Calling SQLSetStmtAttr..." );
#endif

		 SQLSetStmtAttr (
								hdlStmt_,		// hstmt
								attribute,      // fOption 
								value	,       // pvParam 
								SQL_NTS			// NTS for string, rest ignored	
							);	
		static_cast<ODBCError*>(ptrError_)->setError(hdlStmt_,Types::ODBC::STMT_HDL );

		string e = ptrError_->getErrorMessage();
}


/**	
 * <BR>NAME:getType
 * <BR>DESCRIPTION:
 * <BR>Returns a value indicating the type of ResultSet type that will be 
 * <BR>returned by the ExecuteQuery method. 
 * <BR>The default type is FORWARD_ONLY.
 * <BR>SIDE EFFECTS: Nil
 * <BR>PARAMETERS:
 * <BR>			@param Nil
 * <BR>@return RETURN:ResultSet::ResultSetType - For a list of valid 
 * <BR>ResultSet types refer to the ResultSetType Enumeration. 
 */
const int ODBCStatement::getType(void) const
{
#ifdef ALOGGER
	  logger::Logger::getInstance().info( "ODBCStatement:getType:Returning rsType_..." );
#endif

	  return rsType_;			//return whatever is present, if not set, it shall default to FORWARD_ONLY
}


/**
 * <BR>NAME:setCursorName
 * <BR>DESCRIPTION:Sets the name of the cursor used to fetch the data through a SELECT Query.
 * <BR>SIDE EFFECTS: Nil
 * <BR>SQLRETURN   SQLSetCursorName (
 * <BR>						SQLHSTMT          StatementHandle,  // hstmt 
 * <BR>						SQLCHAR           *CursorName,      // szCursor
 * <BR>						SQLSMALLINT       NameLength);      // cbCursor
 * <BR>
 * <BR>PARAMETERS:
 * <BR>			@param cursorName - A valid string representing a cursor name
 * <BR>@return RETURN:Nil
 * <BR>
 * <BR>TEST CASES
 * <BR>
 * <BR>\test setCursorName("$%^$%&%^*^%*&^(");
 * <BR>\test setCursorName(DATABASE_DOES_NOT_SUPPORT_CURSORS);
 * <BR>\test No SQL Query was executed.
 * <BR>\test No active Statement.
 */
void ODBCStatement::setCursorName(const std::string cursorName)
{
#ifdef ALOGGER
	  logger::Logger::getInstance().info( "ODBCStatement:setCursorName:Setting the name..." );
#endif

	SQLRETURN rc = SQLSetCursorName(hdlStmt_, (SQLCHAR*)cursorName.c_str(), cursorName.length() );
	static_cast<ODBCError*>(ptrError_)->setError(hdlStmt_, Types::ODBC::STMT_HDL);

	if(rc == SQL_SUCCESS)
		cursorName_ = cursorName;
	else
	{
#ifdef ALOGGER
	  logger::Logger::getInstance().error( "ODBCStatement:setCursorName:Error setting the cursor name...", cursorName.c_str() );
#endif

	}
}

/**
 * <BR>NAME:getCursorName
 * <BR>DESCRIPTION:Gets the name of the cursor used to fetch the data through a SELECT Query.
 * <BR>SIDE EFFECTS: Nil
 * <BR>PARAMETERS:
 * <BR>			@param Nil
 * <BR>@return RETURN:string - name of the active cursor 
 * <BR>
 * <BR>TEST CASES
 * <BR>
 * <BR>\test No active cursor / Statement / Database
 */
std::string const ODBCStatement::getCursorName(void) const
{
#ifdef ALOGGER
	  logger::Logger::getInstance().info( "ODBCStatement:getCursorName:Returning the name..." );
#endif

	return cursorName_;
}

/**
 * <BR>NAME:closeCursor
 * <BR>DESCRIPTION:closes the active cursor
 * <BR>SIDE EFFECTS: Nil
 * <BR>ODBC CLI
 * <BR>
 * <BR>SQLRETURN   SQLCloseCursor (SQLHSTMT     StatementHandle);  // hStmt
 * <BR>PARAMETERS:
 * <BR>			@param Nil
 * <BR>@return RETURN:Nil
 * <BR>
 * <BR>TEST CASES
 * <BR>\test There is no cursor open
 * <BR>\test Database does not support cursors
 */
void ODBCStatement::closeCursor(void)
{
	/**	
	 *	SQLCloseCursor() returns SQLSTATE 24000 (Invalid cursor state) if no cursor is open. 
	 *	Calling SQLCloseCursor() is equivalent to calling SQLFreeStmt() with the SQL_CLOSE 
	 *	option, with the exception that SQLFreeStmt() with SQL_CLOSE has no effect on the 
	 *	application if no cursor is open on the statement, while SQLCloseCursor() 
	 *	returns SQLSTATE 24000 (Invalid cursor state).
	 */

#ifdef ALOGGER
	logger::Logger::getInstance().info( "ODBCStatement::closeCursor:Calling SQLCloseCursor..." );
#endif

	SQLCloseCursor(hdlStmt_);
	static_cast<ODBCError*>(ptrError_)->setError(hdlStmt_, Types::ODBC::STMT_HDL);

	return;			// return coolly, even if it was an error, let the user figure it out thru Error*!
}

/**
 * <BR>NAME:close
 * <BR>DESCRIPTION:Closes the active statement.
 * <BR>SIDE EFFECTS: Nil
 * <BR>PARAMETERS:
 * <BR>			@param Nil
 * <BR>RETURN: @return Nil
 * <BR>
 * <BR>TEST CASES
 * <BR>
 * <BR>\test There is no active statement.
 */
void ODBCStatement::close(void)
{
  SQLRETURN cliRC = SQL_SUCCESS;		///<Assume Success

#ifdef ALOGGER
	logger::Logger::getInstance().info( "ODBCStatement::close:Calling SQLFreeHandle..." );
#endif

  SQLFreeStmt(hdlStmt_, SQL_CLOSE);
  
  /* free the statement handle */
  if(hdlStmt_ != 0)
  {
	cliRC = SQLFreeHandle(SQL_HANDLE_STMT, hdlStmt_);
	static_cast<ODBCError*>(ptrError_)->setError(hdlStmt_, Types::ODBC::STMT_HDL);
  }
 
 hdlStmt_ = 0;			// if closing was successful.

}


}	//namespace dbaccess
