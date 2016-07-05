#ifndef DBACCESS_H
#define DBACCESS_H
/*@file dbAccess.h
 *@brief This class provides interface to dbaccess functionality. The BC shall only interact with this class.
 * Created on Dec 5, 2004
 *
 *
 */

#include <string>

namespace dbaccess {

class ODBCConnection;

/**@class DBAccess
 * @brief DBAccess is a class that provides database connection and connection transaction.
 * @author   c.b.balajadia 
 * @version    11/2004 initial draft c.b.balajadia
 * @version    12/2004 added facility for OracleOCIDBAccess connection and set OracleOCIDBAccess as default - c.b.balajadia
 * @version    02/2005 prepared dbaccess for listener - c.b.balajadia
 * @since   1.1
 */
class DBAccess {

private: 
     static ODBCConnection* conn_;
     static std::string dsnName_, userName_, passwd_;
	         
	
	/**
	 * Initializes databse connection
	 * @param connType -  database connection type
	 * @throws DBAccessException - thrown when failed to connect to database
	 */
	static bool initializeConnection ();

public:
           
    DBAccess();
           
	/**
	 * get a database connection
	 * @param none
	 * @throws DBAccessException
	 */
	static ODBCConnection* getConnection() ;
	
	/**
	 * closes database connection
	 * @param conn - Connection
	 * @throws DBAccessException
	 */
	static void releaseConnection();
	 
 	static const std::string getError();

	static void setDSNName(std::string dsnName);
	static void setUserName(std::string userName);
	static void setPassword(std::string passwd); 

};

}	//namespace dbaccess 
#endif
