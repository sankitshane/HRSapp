#include<dbaccess/ODBCConnection.h>
#include<dbaccess/ODBCResultSet.h>
#include<dbaccess/ODBCStatement.h>

#include<common/SkillsInformation.h>
#include<common/GeneralException.h>

#include<dao/SkillDAO.h>
#include<dbaccess/dbAccess.h>
#include<dbaccess/DBException.h>
#include<dbaccess/ODBCError.h>

#include<dao/DAOConstants.h>

#include<dao/Transforms.h>
#include<dao/assemblers/SkillAssembler.h>

#include<vector>
#include<string>
#include<logger/Logger.h>

/**@file SkillDAO.cpp
 * @brief Defines Data Access Object for Skill.
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



    /**@fn create(SkillInformation& skillInformation)
     * @brief Insert a Skill into Skill table
     * This method gets an instance of the connection from
     * DBAccess and inserts data from the SkillInformation object
     * into the Skill table.
     * sample usage:
     *        SkillDAO skill;
     *        SkillInformation skillInformation;
     *        //Fill Skill data into skillInformation object
     *        skill.create(skillInformation);
     *
     * @param A reference to SkillInformation object containing skill data
     * @return none
     */ 
  void SkillDAO::create(HRSObject& skillsInformation)
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
    
      sqlstmt = SkillAssembler::assemble(static_cast<SkillsInformation&>(skillsInformation), sqlstmt);

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
     * @return A vector of SkillInformation matching the criteria
     */  
  
  std::vector<HRSObject*> SkillDAO::find(std::string searchCriteria)
  {
    try{
      std::vector<HRSObject*> skillInfo; 

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

      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      if( ! rs->next() )
        throw new GeneralException("Record Not Found.");

      do {
	skillInfo.push_back(new SkillsInformation(SkillAssembler::disAssemble(rs) ) ); 
      }while( rs->next() );
    
      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

      return skillInfo;
    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }


   /**@fn findByAll()
     * @brief Retrieve all records from the Skill table
     * @param none
     * @return A vector of all Skills found in the table 
     */              
  std::vector<HRSObject*> SkillDAO::findByAll()
  {
    try{
      std::vector<HRSObject*> skillInfo; 

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

      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      if( ! rs->next() )
        throw new GeneralException("Record Not Found.");

      do {
	skillInfo.push_back(new SkillsInformation(SkillAssembler::disAssemble(rs))  ); 
      }while( rs->next() );

      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

      return skillInfo;
    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }


   /**@fn  findByPK(std::string pkValue)
     * @brief Fetch Skills whose primary key value matches the passed one
     * @param pkValue - Value of the primary key (Skill  Id)
     * @return SkillInformation - Record Matching the pkValue 
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
	
      SkillsInformation* skillReturn = NULL ;

      sqlStmt.replace( sqlStmt.find("%s"), 2, pkValue);

      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      //Fill the empInfo object.
      if(rs->next())
	skillReturn = new SkillsInformation(SkillAssembler::disAssemble(rs));
      else
	throw new GeneralException("Search by PK Failed");

      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

      return skillReturn;
    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
              
  }     


   /**@fn remove( std::string pkValue)
     * @brief Remove the Skill from the Skill table given the Skill Id
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

  
   /**@fn update( SkillInformation& piSet)
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

      SkillsInformation info = static_cast<SkillsInformation&>(piSet);

      Transform t;
      std::string set = t.transform(info);
    
      char query[1024];
      sprintf( query, sqlStmt.c_str(), set.c_str() , info.getSkillId().c_str() );

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, query);
#endif

      bool res = stmt->execute( query );

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
     
      return true;
    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }

}	//namespace dao
