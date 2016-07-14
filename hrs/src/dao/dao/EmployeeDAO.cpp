#include<dbaccess/ODBCConnection.h>
#include<dbaccess/ODBCResultSet.h>
#include<dbaccess/ODBCStatement.h>

#include<common/GeneralException.h>
#include <common/HRSObject.h>

#include<common/EmployeeInfo.h>
#include<common/AccentureDetails.h>

#include<dbaccess/dbAccess.h>
#include<dbaccess/DBException.h>
#include<dbaccess/ODBCError.h>

#include<dao/DAOConstants.h>
#include<dao/EmployeeDAO.h>

#include<dao/Transforms.h>
#include<dao/assemblers/EmployeeAssembler.h>


#ifdef ALOGGER
#include<logger/Logger.h>
#endif

#include<vector>
#include<string>

/**@file EmployeeDAO.cpp
 * @brief Defines Data Access Object for Employee.
 *
 **
* <BR>NAME: EmployeeDAO
* 
* <BR>BASE CLASSES: No Parent
* 
* <BR>PURPOSE: This class is responsible for direct interaction with the
*  database for Employee related issues.
*
* <BR>AUTHOR: Arun Veeramany
* <BR>$Revision: 9th Dec'05
* 
* <BR>$Log: 9th Dec'05
* 
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/





namespace dao {



  /**@fn EmployeeDAO
    * @brief Default Constructor.
    * This constructor will not take any argument.
    * @param none
    * @return none
    */
	
  EmployeeDAO::EmployeeDAO()
  {
        
  }

  /**@fn create(HRSObject &employeeInfo)
   * @brief Insert data into Employee table
   * This method gets an instance of the connection from
   * DBAccess and inserts data from the employeeInfo object
   * into the Employee table.
   * @param A reference to EmployeeInfo object containing employee data
   * @return none
   */               
  void EmployeeDAO::create(HRSObject &employeeInfo)
  {
    try{

      dbaccess::ODBCConnection* conn = dbaccess::DBAccess::getConnection();
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}
	 
      dbaccess::ODBCStatement* stmt = conn->createStatement();
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      std::string sqlstmt = DAOConstants::EMPSQL_CREATE;

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlstmt.c_str() );
#endif

      sqlstmt = EmployeeAssembler::assemble( static_cast<EmployeeInfo&>(employeeInfo), sqlstmt);

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlstmt.c_str() );
#endif

      bool res = stmt->execute(sqlstmt);

      if( res == false)
	{
#ifdef ALOGGER
	  logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "Create Employee Failed");
#endif
	  stmt->close();
	  dbaccess::DBAccess::releaseConnection();
	  throw new GeneralException("Create Employee Failed");
	  return;
	}
  
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }

   /**@fn find(std::string searchCriteria)
     * @brief Search the records with the given criteria
     * @param The condition to be specified while searching for records
     * @return A vector of EmployeeInfo matching the criteria
     */             
  std::vector<HRSObject*> EmployeeDAO::find(std::string searchCriteria)
  {

    try{
      std::vector<HRSObject*> empInfo; 

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, searchCriteria.c_str());
#endif

      dbaccess::ODBCConnection* conn = dbaccess::DBAccess::getConnection();
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}
      dbaccess::ODBCStatement* stmt = conn->createStatement();
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      std::string sqlStmt = DAOConstants::EMPSQL_FIND_MAIN;

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlStmt.c_str());
#endif

      sqlStmt.replace( sqlStmt.find("%s"), 2, searchCriteria );

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlStmt.c_str());
#endif

      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}
      if( !rs->next() )
	throw new GeneralException("Record Not Found.");

      AccentureDetails adInfo;
    
      EmployeeInfo eInfo;

      do {
	eInfo = EmployeeAssembler::disAssemble(rs); 
	empInfo.push_back( new EmployeeInfo(eInfo)  ); 
      }while( rs->next() );

      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

      return empInfo;
    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      } 
  }


   /**@fn findByAll()
     * @brief Retrieve all records from the Employee table
     * @param none
     * @return A vector of all EmployeeInfo found in the table 
     */            
  std::vector<HRSObject*> EmployeeDAO::findByAll()
  {
    try{
      std::vector<HRSObject*> empInfo; 

      dbaccess::ODBCConnection* conn = dbaccess::DBAccess::getConnection();
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      dbaccess::ODBCStatement* stmt = conn->createStatement();
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      std::string sqlStmt = DAOConstants::EMPSQL_FIND_ALL;

      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      if( !rs->next() )
	throw new GeneralException("Record Not Found.");

      do {
	empInfo.push_back( new EmployeeInfo(EmployeeAssembler::disAssemble(rs))  ); 
      }while( rs->next() );

      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

      return empInfo;
    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }



    /**@fn  findByPK(std::string pkValue)
      * @brief Fetch Employees whose primary key value matches the passed one
      * @param pkValue - Value of the primary key (Employee No.)
      * @return EmployeeInfo - Record Matching the pkValue 
      */   
  HRSObject* EmployeeDAO::findByPK(std::string pkValue)
  {

    try{
      dbaccess::ODBCConnection* conn = dbaccess::DBAccess::getConnection();
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, dbaccess::DBAccess::getError().c_str()  );
#endif

      dbaccess::ODBCStatement* stmt = conn->createStatement();
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      std::string sqlStmt = DAOConstants::EMPSQL_FIND_BYPK;

      HRSObject* employeeReturn = NULL;

      sqlStmt.replace( sqlStmt.find("%s"), 2, pkValue);

      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      //Fill the empInfo object.
      if(rs->next())
	employeeReturn = new EmployeeInfo(EmployeeAssembler::disAssemble(rs));
      else
	throw new GeneralException("Search by PK Failed");

      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

      return employeeReturn;

    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
            
  }     


    /**@fn remove(std::string pkValue)
      * @brief Remove the project from the Employee table given the EmployeeId
      * @param pkValue - Delete the record corresponding to pkValue
      * @return bool - Status of deletion
      */   
  
  bool EmployeeDAO::remove( std::string pkValue)     
  {

    try{
      dbaccess::ODBCConnection* conn = dbaccess::DBAccess::getConnection();
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      dbaccess::ODBCStatement* stmt = conn->createStatement();
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      std::string sqlstmt = DAOConstants::EMPSQL_DELETE;

      sqlstmt.replace(sqlstmt.find("%s"), 2, pkValue);

      bool res = stmt->execute(sqlstmt);
	
      if(res == false)
	{
	  stmt->close();
	  dbaccess::DBAccess::releaseConnection();
	  throw new GeneralException("Error deleting record");
	}

      stmt->close();
      dbaccess::DBAccess::releaseConnection();
              
#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

      return res;

    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }

  }


   /**@fn update(EmployeeInfo& piSet)
     * @brief Update those records that match piWhere with piSet
     * @param piSet - the SET part of the UPDATE statement
     * @return bool - status of updatiom
     */   

  
  bool EmployeeDAO::update(HRSObject& piSet)
  {
    try{
      dbaccess::ODBCConnection* conn = dbaccess::DBAccess::getConnection();
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      dbaccess::ODBCStatement* stmt = conn->createStatement();
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      std::string sqlStmt = DAOConstants::EMPSQL_UPDATE;

      EmployeeInfo info = static_cast<EmployeeInfo&>(piSet);

      Transform t;
      std::string set = t.transform(info);
    
      char query[1024];
      sprintf( query, sqlStmt.c_str(), set.c_str() , info.getEmpNo().c_str() );

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, query);
#endif


      bool res = stmt->executeUpdate( query );
	
      if( res == false)
	{
#ifdef ALOGGER
	  logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "Error updating record");
#endif
	  stmt->close();
	  dbaccess::DBAccess::releaseConnection();
	  throw new GeneralException("Error updating record");
	}

      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

      return res;
    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }


  }

}	//namespace dao

