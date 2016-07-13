#include<dbaccess/ODBCConnection.h>
#include<dbaccess/ODBCResultSet.h>
#include<dbaccess/ODBCStatement.h>

#include<common/SkillInformation.h>
#include<common/GeneralException.h>

#include<dao/SkillDAO.h>

#include<dbaccess/dbAccess.h>
#include<dbaccess/DBException.h>
#include<dbaccess/ODBCError.h>

#include<dao/DAOConstants.h>

#include<dao/assemblers/SkillAssembler.h>
#include<dao/Transforms.h>

#include<vector>
#include<string>

#ifdef ALOGGER
#include<logger/Logger.h>
#endif

/**@file SkillDAO.cpp
 *@brief Defines Data Access Object for Skill.
 *
 * <BR>NAME: SkillDAO
 *
 * <BR>BASE CLASSES: No Parent
 *
 * <BR>PURPOSE: This class is responsible for direct interaction with the
 *  database for Skill related issues.
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



    /**@fn SkillDAO
     * @brief Default Constructor.
     * This constructor will not take any argument.
     * @param none
     * @return none
     */

  SkillDAO::SkillDAO()
  {

  }


   /**@fn create(SkillInfo& SkillInfo)
     * @brief Insert a Skill into Skill table
     * This method gets an instance of the connection from
     * DBAccess and inserts data from the SkillInfo object
     * into the Skill table.
     * @param A reference to SkillInfo object containing Skill data
     * @return none
     */

  void SkillDAO::create(HRSObject& SkillInformation)
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

      std::string sqlstmt = DAOConstants::SKILL_CREATE;

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlstmt.c_str() );
#endif

      sqlstmt = SkillAssembler::assemble(static_cast<SkillInfrmationo&>(SkillInformation), sqlstmt);

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlstmt.c_str() );
#endif


      bool res = stmt->execute(sqlstmt);

      if( res == false)
	{
#ifdef ALOGGER
	  logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "Create Skill Failed");
#endif
	  stmt->close();
	  dbaccess::DBAccess::releaseConnection();
	  throw new GeneralException("Create Skill Failed");
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
    * @return A vector of SkillInfo matching the criteria
    */
  std::vector<HRSObject*> SkillDAO::find(std::string searchCriteria)
  {
    try{
      std::vector<HRSObject*> sklInfo;

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

      std::string sqlStmt = DAOConstants::SKILL_FIND_MAIN;

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
	sklInfo.push_back(new SkillInformation(SkillAssembler::disAssemble(rs))  );
      } while( rs->next() );

      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

      return sklInfo;
    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }


   /**@fn findByAll
     * @brief Retrieve all records from the Skill table
     * @param none
     * @return A vector of all SkillInfo found in the table
     */
  std::vector<HRSObject*> SkillDAO::findByAll()
  {
    try{
      std::vector<HRSObject*> sklInfo;

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

      std::string sqlStmt = DAOConstants::SKILL_FIND_ALL;

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
	sklInfo.push_back( new SkillInformation(SkillAssembler::disAssemble(rs)) );
      } while( rs->next() );

      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

      return sklInfo;

    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }



    /**@fn  findByPK
     * @brief Fetch Skills whose primary key value matches the passed one
     * @param pkValue - Value of the primary key (Skill Id)
     * @return SkillInfo - Record Matching the pkValue
     */

  HRSObject* SkillDAO::findByPK(std::string pkValue)
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

      std::string sqlStmt = DAOConstants::SKILL_FIND_BYPK;

      SkillInformation* SkillReturn = NULL ;

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
	SkillReturn = new SkillInformation(SkillAssembler::disAssemble(rs));
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

      return SkillReturn;

    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }


   /**@fn remove(std::string pkValue)
     * @brief Remove the SkillInfo from the Skill table given the SkillId
     * @param pkValue - Delete the record corresponding to pkValue
     * @return bool - Status of deletion
     */

  bool SkillDAO::remove( std::string pkValue)
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

      std::string sqlstmt = DAOConstants::SKILL_DELETE;

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



   /**@fn update(SkillInfo& piSet)
     * @brief Update those records that match piWhere with piSet
     * @param piSet - the SET part of the UPDATE statement
     * @return bool - status of updatiom
     */
  bool SkillDAO::update(HRSObject& piSet)
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

      std::string sqlStmt = DAOConstants::SKILL_UPDATE_MAIN;

      SkillInformation info = static_cast<SkillInformation&>(piSet);

      Transform t;
      std::string set = t.transform(info);

      char query[1024];
      sprintf( query, sqlStmt.c_str(), set.c_str() , info.getSkillId().c_str() );

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
