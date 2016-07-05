// ODBCConnection.cpp : Defines the entry point for the console application.
//

// Connection.cpp : Defines the entry point for the console application.
//

#ifndef ODBCCONNECTION_H
#define ODBCCONNECTION_H

/**@file ODBCConnection.h
* @brief Implements Connection for ODBC Connectivity.
*
* <BR>NAME: ODBCConnection
* 
* <BR>BASE CLASSES: Connection 
* 
* <BR>PURPOSE: interface to connect with database through ODBC
*
* <BR>AUTHOR: V.Leela Madhavi
* <BR>Implementation of ODBCConnection.
* <BR>$Revision: 2nd Aug'05
* 
* <BR>$Log: 2nd Aug'05
* 
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

//#include "stdafx.h"
//#include <Connection.h>

#ifdef WIN32
#include <windows.h>
#endif

#include <sql.h>
#include <sqlext.h>
#include <string>

#ifdef CPPUNIT_TESTING
namespace ADBC_TEST
{
	class ODBCConnection;
}
#endif


namespace dbaccess {

	class ODBCStatement;
	class ODBCError;
	/**@class ODBCConnection
	* @brief Low level interface to interact with database through ODBC
	*/


	class ODBCConnection 
	{
#ifdef CPPUNIT_TESTING
		friend class ADBC_TEST::ODBCConnection;
#endif

		SQLHENV hdlEnv_; ///< Environmental Handler >
		SQLHDBC hdlConn_; ///< Connection Handler >

    	ODBCError *errorObj_; ///< To handle Errors OR Exceptions occured during runtime >
    	std::string dsnName_;
    	std::string userID_;
    	std::string passwd_;
    	std::string connectionString_;
    	bool isConnectionString_;

	public:

		/**Constructor to take Connection String as parameter.
		* <BR>NAME: ODBCConnection Consturctor
		* <BR>DESCRIPTION: Constructor to take Connection String as parameter. Used to instantiate the ODBCConnection through Connection String. Please refer to http://www.connectionstrings.com for knowing what connection string to be used for a particular database.
		* <BR>PARAMETERS: string
		* <BR>SIDE EFFECTS:
		* <BR>@param connectionString specifies the connection string
		*/
		ODBCConnection(const char* connectionString); 

		/**Constructor to take Connection String as parameter.
		* <BR>NAME: ODBCConnection Consturctor
		* <BR>DESCRIPTION: Constructor to take Connection String as parameter. Used to instantiate the ODBCConnection through Connection String. Please refer to http://www.connectionstrings.com for knowing what connection string to be used for a particular database.
		* <BR>PARAMETERS: string
		* <BR>SIDE EFFECTS:
		* <BR>@param connectionString specifies the connection string
		*/
		ODBCConnection(const std::string connectionString); 

		/**Constructor to take DSN Name, User Name and Password as parameters.
		* <BR>NAME: ODBCConnection Constructor
		* <BR>DESCRIPTION: Constructor to take DSN Name, User Name and Password as parameters.
		* <BR>It shall create the Error object for this connection and sets the dsnName, userID and password for the connection.
		* <BR>PARAMETERS: dsnName, UserID, pwd
		* <BR>SIDE EFFECTS:
		* <BR>TEST CASES : 
		*
		* @param dsnName Specify the DSN Name
		* @param userID Specify the User Name or Code
		* @param pwd specify the Pass Word
		*/
		ODBCConnection(const char* dsnName, const char* userID, const char* pwd); 

		/** Constructor to take DSN Name, User Name and Password as parameters.
		* <BR>NAME: ODBCConnection Constructor
		* <BR>DESCRIPTION: Constructor to take DSN Name, User Name and Password as parameters.
		* <BR>It shall create the Error object for this connection and sets the dsnName, userID and password for the connection.
		* <BR>PARAMETERS: dsnName, UserID, pwd
		* <BR>SIDE EFFECTS:
		* <BR>TEST CASES : 
		*
		* @param dsnName Specify the DSN Name
		* @param userID Specify the User Name or Code
		* @param pwd specify the Pass Word
		*/
		ODBCConnection(const std::string dsnName, const std::string userID, const std::string pwd);

		/** To deallocate all the instances of Connection at the time of closing connection.
		* <BR>NAME: Destructor
		* <BR>DESCRIPTION: Destructor. Calls disconnect by default though it may be called. It also deallocates memory assign for Error object
		* <BR>PARAMETERS: Nil
		* <BR>SIDE EFFECTS:
		*/
		virtual ~ODBCConnection();  

		/**Opening the connection with database.
		* <BR>NAME: Member function 
		* <BR>DESCRIPTION: Opening the connection with database. 
		* <BR> Steps :
		* <BR> 1. With SQLAllocEnv get the environment handle.
		* <BR> 2. Test the SQLAllocEnv call was successful or not. If not set error and return back.
		* <BR> 3. With SQLAllocDBC get the Connection Handle.
		* <BR> 4. Test the SQLAllocDBC call was successful or not. If not set error, Free Environment handle and return back.
		* <BR> 5. With SQLConnect connect to the database.
		* <BR> 6. Test the SQLConnect call, was successful or not. If not set error, free allocated handles and return back.
		* <BR>PARAMETERS: Nil
		* <BR>SIDE EFFECTS:
		*/
		virtual bool connect();
		/**@fn setAutoCommit
		*Turn ON/OFF the auto commit option.
		* <BR>NAME: setAutoCommit
		* <BR>DESCRIPTION: Turn ON/OFF the auto commit option.
		* <BR>It turns ON/OFF the auto-commit option of ODBC. By Default is is ON.
		* If it is not turn OFF the ADBC::Connection::commit and ADBC::Connection::rollback will not have any effect.
		* To specifically use commit/rollback set the autoCommitOption to OFF.
		* It returns the status whether the command was successful or not.
		* 
		* <BR>PARAMETERS
		* <BR> bool : to turn ON/OFF autocommit
		* <BR>RETURN:
		* <BR> bool : success/failure of function
		* @param off bool autocommit to be turned ON/OFF.
		* @return bool function was successful or not.
		*/
		virtual bool setAutoCommit(bool off);

		/**Implementation of commit to save the data permanently.
		* <BR>NAME: Member function 
		* <BR>DESCRIPTION: Implementation of commit to save the data permanently.
		* <BR> It uses SQLEndTran for commiting. If the statement fails sets error and returns.
		* <BR>PARAMETERS: Nil
		* <BR>SIDE EFFECTS:
		*/
		virtual bool commit(); 

		/**Implementation of Rollback Inorder to reset the data, if transaction are not succeeded.
		* <BR>NAME: Member Function 
		* <BR>DESCRIPTION: Implementation of Rollback Inorder to reset the data.
		* <BR> It uses SQLEndTran for rolling back. If the statement fails sets error and returns.
		* <BR>PARAMETERS: Nil
		* <BR>SIDE EFFECTS:
		*/

		virtual bool rollback();  
		/**Closing the connection with database.
		* <BR>NAME: Member function 
		* <BR>DESCRIPTION: Closing the connection with database.
		* <BR> Frees all the assigned handles in connection. 
		* <BR>PARAMETERS: Nil
		* <BR>SIDE EFFECTS:
		*/
		virtual bool disconnect();  
		/**Creation of the statement for query processing.
		* <BR>NAME: CreateStatement
		* <BR>DESCRIPTION: Creation of the statement for query processing.
		* <BR> It in turn calls the ODBCStatement constructor. It do not check anything.
		* <BR>PARAMETERS: Nil
		* <BR>RETURN: Statement Object
		* <BR>SIDE EFFECTS:
		* @return Statement* returns pointer to the newly created Statement Object
		*/
		virtual ODBCStatement* createStatement();  
		/**Retrieval of Error occured during implementation of the system.
		* <BR>NAME: GetError
		* <BR>DESCRIPTION: Retrieval of Error occured during implementation of the system
		* <BR> The only place through which the Component user can access error object.
		* <BR>PARAMETERS: Nil
		* <BR>RETURN: Error reference
		* <BR>SIDE EFFECTS:
		* @return Error& return reference to the error object
		* 
		*/
		virtual ODBCError& getError() const; // 
	};

}	//namespace dbaccess 
#endif //ODBCCONNECTION_H

