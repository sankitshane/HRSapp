#include<dbaccess/ODBCConnection.h>
#include<dbaccess/ODBCResultSet.h>
#include<dbaccess/ODBCStatement.h>

#include<common/EmployeeInfo.h>
#include<common/GeneralException.h>

#include<dao/EmployeeDAO.h>

#include<dbaccess/dbAccess.h>
#include<dbaccess/DBException.h>
#include<dbaccess/ODBCError.h>

#include<dao/DAOConstants.h>

#include<dao/assemblers/EmployeeAssembler.h>
#include<dao/Transforms.h>

#include<vector>
#include<string>

#ifdef ALOGGER
#include<logger/Logger.h>
#endif

/**@file EmployeeDAO.cpp
 *@brief Defines Data Access Object for Employee.
 *
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


   /**@fn create(EmployeeInfo& EmployeeInfo)
     * @brief Insert a Employee into Employee table
     * This method gets an instance of the connection from
     * DBAccess and inserts data from the EmployeeInfo object
     * into the Employee table.
     * @param A reference to EmployeeInfo object containing Employee data
     * @return none
     */

  void EmployeeDAO::create(HRSObject& EmployeeInfo)
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

      std::string sqlstmt = DAOConstants::EMPSQL_GETID;

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlstmt.c_str() );
#endif

      sqlstmt = EmployeeAssembler::assemble(static_cast<EmployeeInfo&>(EmployeeInfo), sqlstmt);

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
      std::vector<HRSObject*> prjInfo;

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

      std::string sqlStmt = DAOConstants::EMP_FIND_MAIN;

      sqlStmt.replace( sqlStmt.find("%s"), 2, searchCriteria  );

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlStmt.c_str());
#endif


      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      if( ! rs->next() )
        throw new GeneralException("Record Not Found.");

      do {
	prjInfo.push_back(new EmployeeInfo(EmployeeAssembler::disAssemble(rs))  );
      } while( rs->next() );

      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

      return prjInfo;
    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }


   /**@fn findByAll
     * @brief Retrieve all records from the Employee table
     * @param none
     * @return A vector of all EmployeeInfo found in the table
     */
  std::vector<HRSObject*> EmployeeDAO::findByAll()
  {
    try{
      std::vector<HRSObject*> prjInfo;

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

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlStmt.c_str());
#endif

      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      if( ! rs->next() )
        throw new GeneralException("Record Not Found.");

      do {
	prjInfo.push_back( new EmployeeInfo(EmployeeAssembler::disAssemble(rs)) );
      } while( rs->next() );

      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

      return prjInfo;

    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }



    /**@fn  findByPK
     * @brief Fetch Employees whose primary key value matches the passed one
     * @param pkValue - Value of the primary key (Employee Id)
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

      dbaccess::ODBCStatement* stmt = conn->createStatement();
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      std::string sqlStmt = DAOConstants::EMP_FIND_BYPK;

      EmployeeInfo* EmployeeReturn = NULL ;

      sqlStmt.replace( sqlStmt.find("%s"), 2, pkValue);

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlStmt.c_str());
#endif

      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "Query Executed");
#endif

      //Fill the empInfo object.
      if(rs->next())
	EmployeeReturn = new EmployeeInfo(EmployeeAssembler::disAssemble(rs));
      else
        throw new GeneralException("Search by PK Failed");

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

      return EmployeeReturn;

    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }


   /**@fn remove(std::string pkValue)
     * @brief Remove the EmployeeInfo from the Employee table given the EmployeeId
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

      std::string sqlstmt = DAOConstants::EMP_DELETE;

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

      std::string sqlStmt = DAOConstants::EMP_UPDATE;

      EmployeeInfo info = static_cast<EmployeeInfo&>(piSet);

      Transform t;
      std::string set = t.transform(info);

      char query[1024];
      sprintf( query, sqlStmt.c_str(), set.c_str() , info.getEmployeeId().c_str() );

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, query);
#endif

      bool res = stmt->execute( query );

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "Query Executed");
#endif

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
