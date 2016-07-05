#ifndef ODBCSTATEMENT_H
#define ODBCSTATEMENT_H

/**@file ODBCStatement.h
* @brief Wrapper Class around the ODBC Specific SQL Statement Handle
*
* NAME:						ODBCStatement	
* 
* $Header:					ODBCStatement.h
*
* BASE CLASSES:				Statement
* 
* PURPOSE:					Wrapper Class around the ODBC Specific SQL Statement Handle
* 
* AUTHOR:					Arun Veeramany
* 
* $Revision: 1.7 $
* 
* $Log: ODBCStatement.h,v $
* Revision 1.7  2005/08/30 05:21:26  Jignesh.Kanchanlal
* Bugs after Testing fixed
*
* Revision 1.4  2005/08/12 12:31:37  Jignesh.Kanchanlal
* Added for the first time after integration
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/


///////////////////////////////////////////////////////////////

///Includes
//#include "../include/Statement.h" ///< Header file for statement
//#include "ODBCTypes.h" ///< Header file for ADBC component defined types

///< Required by ODBC functions
#ifdef WIN32
	#include <windows.h>   
#endif

#include <sql.h>
#include <sqlext.h>
#include <string>

/**ADBC_TEST::ODBCStatementTest is the Unit test class using CppUnit for ODBCStatement.
*Forward declaration for ADBC_TEST and ODBCStatementTest to be recognised in ADBC::ODBCStatement
*/
#ifdef CPPUNIT_TESTING //Macro for adding CPPUnit related code
	namespace ADBC_TEST
	{
		class ODBCStatementTest;
	}
#endif



//namespace 
namespace dbaccess {


// ADBC : used to wrap all ADBC Framework classes.
	//Forward declaration of classes in .h and including #include in .cpp 
	//to reduce compile time
    class ODBCResultSet;
	class ODBCError;
	
	/**@class ODBCStatement
	*@brief ODBCStatement representing an SQL Statement specific to ODBC 
	*  Used to execute SQL Statements.
	*/
	class ODBCStatement 
	{
		/** So as to let ADBC_TEST::ODBCStatementTest access the private and protected members of
		* ADBC::ODBCStatement
		*/
//		friend class ADBC_TEST::ODBCStatementTest;

	//Constructor and destructor
	public:		
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
		ODBCStatement(SQLHANDLE handleHENV, 
					  SQLHANDLE handleHDBC, 
					  ODBCError* error);

		/**
		 * <BR>NAME:Destructor.
		 * <BR>DESCRIPTION:free up the statement handle after completion.
		 * <BR>SIDE EFFECTS: Nil
		 * <BR>PARAMETERS:
		 * <BR>			@param Nil
		 * <BR>@return RETURN:Nil
		 */
		virtual ~ODBCStatement();

//Member Functions
public:		

	/**	
	 *	<BR>NAME:executeQuery
	 *	<BR>DESCRIPTION:
	 *	<BR>Executes a given SELECT statement and returns a ResultSet 
	 *	<BR>which can be used to access the contents returned by the query.
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
	 *	<BR>@return RETURN:ODBCResultSet* - A pointer to the returned resultset.
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
	virtual ODBCResultSet* executeQuery(const std::string query) ;

	/**
	 * <BR>NAME:executeUpdate
	 * <BR>DESCRIPTION:Executes the given UPDATE/INSERT/DELETE statement
	 * <BR>SIDE EFFECTS: Nil
	 * <BR>PARAMETERS:
	 * <BR>			@param query - SQL Update Statement to be executed.
	 * <BR>@return RETURN:int - returns the number of rows affected.
	 * <BR>SIDE EFFECTS: Throws an exception if not an INSERT/UPDATE/DELETE statement
	 * <BR>\test Follow the same test cases as in executeQuery()
	 */
	virtual int executeUpdate(const std::string query) ;

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
	virtual bool execute(const std::string query) ;

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
	 virtual int getRowCount(void) const;

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
	virtual void setType(const int rsType) ;

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
	virtual const int getType(void) const;

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
	virtual void setCursorName(const std::string cursorName) ;

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
	virtual const std::string getCursorName(void) const;

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
	virtual void closeCursor(void) ;

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
	virtual void close(void) ;


//Helper methods
protected:	

	/**
	 *	Holds one of the enumerated values specifying the type of 
	 *	ResultSet to be returned by ExecuteQuery method.	
	 */
	//Types::ODBC::SCROLL_TYPE rsType_;
	int rsType_;


//Hidden to prevent accidental copying or assignment
private:	

	ODBCStatement(const ODBCStatement & other);///< Suppressed Copy constructor

	ODBCStatement & operator =(const ODBCStatement & other); ///< Suppressed Overloaded Assignment operator

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
	void setType_(SQLINTEGER attribute, SQLPOINTER value) const;

protected:
	
	/**
	* <BR>NAME:Overloaded Constructor
	* <BR>DESCRIPTION:Suppress the Default constructor
	* <BR>SIDE EFFECTS:Nil
	* <BR>PARAMETERS: @param Nil
	* <BR>RETURN: @return Nil
	*/
	ODBCStatement();


	//Instance data.
	private:	
		SQLHANDLE	hdlEnv_;		///< A Handle to the ODBC Environment.
		SQLHANDLE	hdlDbc_;		///< A Handle to the ODBC Database.
		SQLHSTMT	hdlStmt_;		///< A Handle to the ODBC Statement.

		std::string cursorName_;			///< A string containing the name for the cursor
		
		ODBCError* ptrError_;
	}; //class Statement

}	//namespace dbaccess 
#endif	//ODBCSTATEMENT_H
