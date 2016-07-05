// ODBCConnection.cpp : Defines the entry point for the console application.
//
/**@file ODBCConnection.cpp
* @brief Implements Connection for ODBC Connectivity.
*
* <BR>NAME: ODBCConnection
* 
* <BR>BASE CLASSES: Connection 
* 
* <BR>PURPOSE: interface to connect with database through ODBC
*
* <BR>AUTHOR: Jignesh K. Sherdiwala
* <BR>Implementation of ODBCConnection.
* <BR>$Revision: 1.9 $
* 
* <BR>$Log: ODBCConnection.cpp,v $
* <BR>Revision 1.9  2005/09/01 05:40:48  Jignesh.Kanchanlal
* <BR>Documentation modified for the Release
* <BR>
* <BR>Revision 1.8  2005/08/30 05:23:25  Jignesh.Kanchanlal
* <BR>Bugs after Testing fixed
* <BR>
* <BR>Revision 1.6  2005/08/23 08:54:50  Jignesh.Kanchanlal
* <BR>in connect freeing of Handles commented
* <BR>
* <BR>Revision 1.2  2005/08/17 09:55:06  Jignesh.Kanchanlal
* <BR>Changed to make it work with test application
* <BR>
* <BR>Revision 1.1  2005/08/12 12:29:56  Jignesh.Kanchanlal
* <BR>Added for the first time
* <BR>
* 
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

#include <dbaccess/ODBCConnection.h>
#include <dbaccess/ODBCStatement.h>
#include <dbaccess/ODBCError.h>
#include <dbaccess/ODBCTypes.h>

#ifdef ALOOGER
	#include <logger/Logger.h>
#endif

#define SIZE_OF_OUTPUT_CON_STR 2048

namespace dbaccess {

	/**@fn ODBCConnection
	Constructor which takes Connection String.
	*/
	ODBCConnection :: ODBCConnection(const char* connectionString){
#ifdef ALOGGER
		logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
		errorObj_ = new ODBCError();

		connectionString_ = connectionString;
		isConnectionString_ = true;

		dsnName_ = "";
		userID_ = "";
		passwd_ = "";
	}

	/**@fn ODBCConnection
	Constructor which takes Connection String.
	*/
	ODBCConnection :: ODBCConnection(const std::string connectionString){
#ifdef ALOGGER
		logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
		errorObj_ = new ODBCError();

		connectionString_ = connectionString;
		isConnectionString_ = true;

		dsnName_ = "";
		userID_ = "";
		passwd_ = "";
	}
	/**@fn ODBCConnection
	Constructor which takes, dsnName, userID and passwd.

	*/
	ODBCConnection :: ODBCConnection(const char* dsnName, const char* userID, const char* pwd){
#ifdef ALOGGER
		logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
		errorObj_ = new ODBCError();///<Creates new Error Object for the connection
		dsnName_ = dsnName;///<stores DSN name
		userID_ = userID;////<Stores user ID
		passwd_ = pwd;///<Stores passwd
		
		isConnectionString_ = false;
		connectionString_ = "";
	}

	/**@fn ODBCConnection
	Constructor which takes, dsnName, userID and passwd.

	*/
	ODBCConnection :: ODBCConnection(const std::string dsnName, const std::string userID, const std::string pwd){
#ifdef ALOGGER
		logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
		errorObj_ = new ODBCError();///<Creates new Error Object for the connection
		dsnName_ = dsnName;///<stores DSN name
		userID_ = userID;////<Stores user ID
		passwd_ = pwd;///<Stores passwd
		
		isConnectionString_ = false;
		connectionString_ = "";
	}

	ODBCConnection :: ~ODBCConnection(){
#ifdef ALOGGER
		logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
		disconnect();///<Call to the method to free the handles.
		delete errorObj_;///<deletes the dynamically created error object
	}

	bool ODBCConnection :: connect(){
#ifdef ALOGGER
		logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
		RETCODE retCode = SQL_SUCCESS ; ///< set RETCODE to default success

		retCode = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hdlEnv_); // set the environment handle. following is ODBC 3.x syntax
		//retCode = SQLAllocEnv(&hdlEnv_);///<Allocates the

		static_cast<ODBCError*>(errorObj_)->setError(hdlEnv_,Types::ODBC::ENV_HDL);
		if( !(retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO) )
		{
			return false;
		}

		retCode = SQLSetEnvAttr(hdlEnv_, SQL_ATTR_ODBC_VERSION,
			(void *)SQL_OV_ODBC3, 0);
		static_cast<ODBCError*>(errorObj_)->setError(hdlEnv_,Types::ODBC::ENV_HDL);
		if( !(retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO) )
		{
			return false;
		}

		retCode = SQLAllocHandle(SQL_HANDLE_DBC, hdlEnv_, &hdlConn_); // set the connection handle.

		//retCode = SQLAllocConnect(hdlEnv_, &hdlConn_);
		static_cast<ODBCError*>(errorObj_)->setError(hdlConn_,Types::ODBC::ENV_HDL);
		if( !(retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO) )
		{
			SQLFreeHandle(SQL_HANDLE_ENV, hdlEnv_);
			return false;
		}

		if(isConnectionString_)
		{
			SQLSMALLINT     connStrOut;
			char connectionString[SIZE_OF_OUTPUT_CON_STR];

			retCode = SQLDriverConnect(hdlConn_, NULL, 
				(SQLCHAR*)connectionString_.c_str(), SQL_NTS,
				(SQLCHAR*)connectionString, SIZE_OF_OUTPUT_CON_STR,
				&connStrOut, SQL_DRIVER_NOPROMPT);

		}
		else
		{
			retCode = SQLConnect(hdlConn_, (SQLCHAR*)dsnName_.c_str(), SQL_NTS, (SQLCHAR*)userID_.c_str(), SQL_NTS, (SQLCHAR*)passwd_.c_str(), SQL_NTS);//connects to the database with provided dsnName and authentication details.
		}
		static_cast<ODBCError*>(errorObj_)->setError(hdlConn_,Types::ODBC::CONN_HDL);

#ifdef ALOGGER
		logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, static_cast<ODBCError*>(errorObj_)->getErrorMessage().c_str() );
#endif
		
		if( !(retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO) ) //Checks the failure
		{
			
			//SQLFreeHandle(SQL_HANDLE_DBC, hdlConn_); // frees the connection handle
			//SQLFreeHandle(SQL_HANDLE_ENV, hdlEnv_);  // frees the environment handle
			return false;
		}

		return true; // if success.
	}

	bool ODBCConnection ::setAutoCommit(bool autoCommit){
#ifdef ALOGGER
		logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
		RETCODE retCode = SQL_SUCCESS;
		
		if(autoCommit){
			retCode = SQLSetConnectAttr(hdlConn_,
				SQL_ATTR_AUTOCOMMIT,
				(SQLPOINTER)SQL_AUTOCOMMIT_ON,
				SQL_NTS);
		}
		else{
			retCode = SQLSetConnectAttr(hdlConn_,
				SQL_ATTR_AUTOCOMMIT,
				(SQLPOINTER)SQL_AUTOCOMMIT_OFF,
				SQL_NTS);
		}
		static_cast<ODBCError*>(errorObj_)->setError(hdlConn_,Types::ODBC::CONN_HDL);
		if( !(retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO) ){
			//Error stuff... Its better to return bool from it.
			return false;
		}
		return true;
	}
	bool ODBCConnection :: commit(){
#ifdef ALOGGER
		logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
		RETCODE retCode = SQL_SUCCESS; // set RETCODE to default success

		retCode = SQLEndTran(SQL_HANDLE_ENV, hdlEnv_, SQL_COMMIT); // End transaction, with SQL_COMMIT
		errorObj_->setError(hdlConn_,Types::ODBC::CONN_HDL);
		if( !(retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO) ){
			//Error stuff... Its better to return bool from it.
			return false;
		}
		else
			return true;
	}

	bool ODBCConnection :: rollback(){
#ifdef ALOGGER
		logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
		RETCODE retCode = SQL_SUCCESS; // set RETCODE to default success

		retCode = SQLEndTran(SQL_HANDLE_ENV, hdlEnv_, SQL_ROLLBACK); // End transaction, with SQL_COMMIT
		errorObj_->setError(hdlConn_,Types::ODBC::CONN_HDL);
		if( !(retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO) ){
			//Error stuff... Its better to return bool from it.
			return false;
		}
		return true;
	}

	bool ODBCConnection :: disconnect(){
#ifdef ALOGGER
		logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
		RETCODE retCode = SQL_SUCCESS;

		retCode = SQLFreeHandle(SQL_HANDLE_DBC, hdlConn_); // frees the connection handle
		errorObj_->setError(hdlEnv_,Types::ODBC::ENV_HDL);
		if( !(retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO) )
		{
			return false;
		}

		retCode = SQLFreeHandle(SQL_HANDLE_ENV, hdlEnv_);  // frees the environment handle
		errorObj_->setError(hdlEnv_,Types::ODBC::ENV_HDL);
		if( !(retCode == SQL_SUCCESS || retCode == SQL_SUCCESS_WITH_INFO) )
		{
			return false;
		}
		
		return true;
	}

	ODBCStatement* ODBCConnection :: createStatement(){
#ifdef ALOGGER
		logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
		return new ODBCStatement(hdlEnv_, hdlConn_, errorObj_);
	}

	ODBCError& ODBCConnection :: getError() const{
#ifdef ALOGGER
		logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
		return (*errorObj_);
	}

}	//namespace dbaccess
