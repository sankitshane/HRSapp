#include<dbaccess/ODBCConnection.h>

#include<dbaccess/dbAccess.h>
#include<dbaccess/ODBCError.h>

#include<dbaccess/DBException.h>

#include<string>
//#include<curses.h>

#ifdef ALOGGER
       #include<logger/Logger.h>
#endif


namespace dbaccess {

ODBCConnection* DBAccess::conn_ = (NULL);

std::string DBAccess::dsnName_ = ("");
std::string DBAccess::userName_ = ("");
std::string DBAccess::passwd_ = ("");

DBAccess::DBAccess()
{
}

bool DBAccess::initializeConnection () 
{
#ifdef ALOGGER
	logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "" );
#endif

    	conn_ = 
              new ODBCConnection(dsnName_, userName_, passwd_); //create ODBCConnection object.
        bool isConnected = conn_->connect(); //connect to the dsn

     	if(!isConnected)//Checks whether connected or not.
     	{
	  //            clear();
	    delete conn_;
	    conn_ = NULL;

	    std::string str1 = "There was an error connecting to the database.\n";
	    std::string str2 = "Verify if the database is up and running.\n";
	    std::string str3 = "Verfiy if the dsn is properly created.\n";
	    std::string str4 = "DSN Name: oracleHRS, Username: scott, password: hrs\n";
	    
	    std::string message = str1 + str2 + str3 + str4;

	    throw new DBException(message);

//             printw("There was an error connecting to the database.\n");
//             printw("Verify if the database is up and running.\n");
//             printw("Verfiy if the dsn is properly created.\n");
//             printw("DSN Name: oracleHRS, Username: scott, password: hrs\n");
            
//             printw("\n\nPress any key tp continue...");
            
//             getch();
            
//             endwin();
            
//             exit(0);
     	}
		
	return isConnected;
}

ODBCConnection* DBAccess::getConnection() 
{
#ifdef ALOGGER
	logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "" );
#endif

    if( conn_ == NULL)
        initializeConnection();
        	
	return conn_;
}

void DBAccess::releaseConnection() 
{
#ifdef ALOGGER
	logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "" );
#endif

		if (conn_ != NULL) {
			conn_->disconnect();
			conn_ = NULL;
		}
}

const std::string DBAccess::getError()
{
#ifdef ALOGGER
	logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "" );
#endif

	return conn_->getError().getErrorMessage();
}

  void DBAccess :: setDSNName(std::string dsnName) {dsnName_ = dsnName; }
  void DBAccess :: setUserName(std::string userName){ userName_ = userName; }
  void DBAccess :: setPassword(std::string passwd) { passwd_ = passwd; }

} //namespace dbaccess

