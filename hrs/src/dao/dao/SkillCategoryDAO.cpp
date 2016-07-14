#include<dbaccess/ODBCConnection.h>
#include<dbaccess/ODBCResultSet.h>
#include<dbaccess/ODBCStatement.h>

#include<common/SkillCategory.h>
#include<common/GeneralException.h>


#include<dao/SkillCategoryDAO.h>

#include<dao/Transforms.h>

#include<dbaccess/dbAccess.h>
#include<dbaccess/DBException.h>
#include<dbaccess/ODBCError.h>

#include<dao/assemblers/SkillCategoryAssembler.h>

#include<dao/DAOConstants.h>

#include<vector>
#include<string>

#ifdef ALOGGER
#include<logger/Logger.h>
#endif


/**@file SkillCategoryDAO.cpp
 * @brief defines Data Access Object for Skill Category.
 *
 * <BR>NAME: SkillCategoryDAO
 * 
 * <BR>BASE CLASSES: No Parent
 * 
 * <BR>PURPOSE: This class is responsible for direct interaction with the
 *  database for Major Skill Category related issues.
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


   /**@fn SkillCategoryDAO
     * @brief Default Constructor.
     * This constructor will not take any argument.
     * @param none
     * @return none
     */	
  SkillCategoryDAO::SkillCategoryDAO()
  {
        
  }

   /**@fn create( SkillCategory& skillCategory)
     * @brief Insert a SkillCategory into SkillCategory table
     * This method gets an instance of the connection from
     * DBAccess and inserts data from the skillCategory object
     * into the skillCategory table.
     * @param A reference to SkillCategory object containing Skill Category data
     * @return none
     */     
  
  void SkillCategoryDAO::create(HRSObject& skillCategory)
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

      std::string sqlstmt = DAOConstants::SKILLCAT_CREATE;

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlstmt.c_str() );
#endif
    
      sqlstmt = SkillCategoryAssembler::assemble(static_cast<SkillCategory&>(skillCategory), sqlstmt);

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlstmt.c_str() );
#endif


      bool res = stmt->execute(sqlstmt);
      if( res == false)
	{
#ifdef ALOGGER
	  logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "Create SkillCategory Failed");
#endif
	  stmt->close();
	  dbaccess::DBAccess::releaseConnection();
	  throw new GeneralException("Create SkillCategory Failed");
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
     * @return A vector of SkillCategory matching the criteria
     */

  std::vector<HRSObject*> SkillCategoryDAO::find(std::string searchCriteria)
  {
    try{
      std::vector<HRSObject*> skillInfo; 

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

      std::string sqlStmt = DAOConstants::SKILLCAT_FIND_MAIN;

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlStmt.c_str());
#endif

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
	skillInfo.push_back(new SkillCategory(SkillCategoryAssembler::disAssemble(rs))  ); 
      }while( rs->next() );


      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "About to return the vector...");
#endif

      return skillInfo;

    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }


   /**@fn findByAll()
     * @brief Retrieve all records from the SkillCategory table
     * @param none
     * @return A vector of all SkillCategory found in the table 
     */             
  std::vector<HRSObject*> SkillCategoryDAO::findByAll()
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

      std::string sqlStmt = DAOConstants::SKILLCAT_FIND_ALL;

      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      if( ! rs->next() )
        throw new GeneralException("Record Not Found.");

      do {
	skillInfo.push_back(new SkillCategory(SkillCategoryAssembler::disAssemble(rs))  ); 
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


   /**@fn  findByPK
     * @brief Fetch SkillCategories whose primary key value matches the passed one
     * @param pkValue - Value of the primary key (SkillCategory Id)
     * @return SkillCategory - Record Matching the pkValue 
     */ 
  
  HRSObject* SkillCategoryDAO::findByPK(std::string pkValue)
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

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, pkValue.c_str());
#endif

      std::string sqlStmt = DAOConstants::SKILLCAT_FIND_BYPK;
	
#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlStmt.c_str());
#endif

      SkillCategory* skillReturn = NULL;

      sqlStmt.replace( sqlStmt.find("%s"), 2, pkValue);

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlStmt.c_str());
#endif

      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      //Fill the empInfo object.
      if(rs->next())
	skillReturn = new SkillCategory(SkillCategoryAssembler::disAssemble(rs));
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


   /**@fn remove(std::string pkValue)
     * @brief Remove the SkillCategory from the SkillCategory table given the SkillCategory Id
     * @param pkValue - Delete the record corresponding to pkValue
     * @return bool - Status of deletion
     */ 
  
  bool SkillCategoryDAO::remove( std::string pkValue)     
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

      std::string sqlstmt = DAOConstants::SKILLCAT_DELETE;

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


   /**@fn update(SkillCategory& piSet)
     * @brief Update those records that match piWhere with piSet
     * @param piSet - the SET part of the UPDATE statement
     * @return bool - status of updatiom
     */
  
  bool SkillCategoryDAO::update(HRSObject& piSet)
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

      std::string sqlStmt = DAOConstants::SKILLCAT_UPDATE_MAIN;

      SkillCategory info = static_cast<SkillCategory&>(piSet);

      Transform t;
      std::string set = t.transform(info);
    
      char query[1024];
      sprintf( query, sqlStmt.c_str(), set.c_str() , info.getCategoryId().c_str() );

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

      return res;

    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }

  }

}	// namespace dao 
