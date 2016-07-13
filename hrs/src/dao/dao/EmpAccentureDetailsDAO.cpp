#include<dbaccess/ODBCConnection.h>
#include<dbaccess/ODBCResultSet.h>
#include<dbaccess/ODBCStatement.h>

#include<common/AccentureDetail.h>
#include<common/GeneralException.h>

#include<dao/EmpAccentureDetailsDAO.h>

#include<dbaccess/dbAccess.h>
#include<dbaccess/DBException.h>
#include<dbaccess/ODBCError.h>

#include<dao/DAOConstants.h>

#include<dao/assemblers/AccentureDetailsAssembler.h>
#include<dao/Transforms.h>

#include<vector>
#include<string>

#ifdef ALOGGER
#include<logger/Logger.h>
#endif

/**@file EmployeeAccentureDAO.cpp
 *@brief Defines Data Access Object for EmployeeAccenture.
 *
 * <BR>NAME: EmployeeAccentureDAO
 *
 * <BR>BASE CLASSES: No Parent
 *
 * <BR>PURPOSE: This class is responsible for direct interaction with the
 *  database for EmployeeAccenture related issues.
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



     /**@fn EmployeeAccentureDAO
      * @brief Default Constructor.
      * This constructor will not take any argument.
      * @param none
      * @return none
      */

   EmployeeAccentureDetailsDAO::EmployeeAccentureDetailsDAO()
   {

   }


    /**@fn create(AccentureDetails& AccentureDetails)
      * @brief Insert a EmployeeAccenture into EmployeeAccenture table
      * This method gets an instance of the connection from
      * DBAccess and inserts data from the AccentureDetails object
      * into the EmployeeAccenture table.
      * @param A reference to AccentureDetails object containing EmployeeAccenture data
      * @return none
      */

      void EmpAccentureDetailsDAO::create(HRSObject& AccentureDetails)
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

          std::string sqlstmt = DAOConstants::EMPACC_CREATE;

    #ifdef ALOGGER
          logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlstmt.c_str() );
    #endif

          sqlstmt = AccentureDetailsAssembler::assemble(static_cast<AccentureDetail&>(AccentureDetail), sqlstmt);

    #ifdef ALOGGER
          logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlstmt.c_str() );
    #endif


          bool res = stmt->execute(sqlstmt);

          if( res == false)
    	{
    #ifdef ALOGGER
    	  logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "Create EmployeeAccenture Failed");
    #endif
    	  stmt->close();
    	  dbaccess::DBAccess::releaseConnection();
    	  throw new GeneralException("Create EmployeeAccenture Failed");
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
        * @return A vector of AccentureDetails matching the criteria
        */
      std::vector<HRSObject*> EmpAccentureDetailsDAO::find(std::string searchCriteria)
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

          std::string sqlStmt = DAOConstants::PROJ_FIND_MAIN;

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
      prjInfo.push_back(new AccentureDetails(EmployeeAccentureAssembler::disAssemble(rs))  );
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
         * @brief Retrieve all records from the EmployeeAccenture table
         * @param none
         * @return A vector of all AccentureDetails found in the table
         */
      std::vector<HRSObject*> EmployeeAccentureDAO::findByAll()
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

          std::string sqlStmt = DAOConstants::PROJ_FIND_ALL;

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
      prjInfo.push_back( new AccentureDetails(EmployeeAccentureAssembler::disAssemble(rs)) );
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
         * @brief Fetch EmployeeAccentures whose primary key value matches the passed one
         * @param pkValue - Value of the primary key (EmployeeAccenture Id)
         * @return AccentureDetails - Record Matching the pkValue
         */

      HRSObject* EmployeeAccentureDAO::findByPK(std::string pkValue)
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

          std::string sqlStmt = DAOConstants::PROJ_FIND_BYPK;

          AccentureDetails* EmployeeAccentureReturn = NULL ;

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
      EmployeeAccentureReturn = new AccentureDetails(EmployeeAccentureAssembler::disAssemble(rs));
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

          return EmployeeAccentureReturn;

        }catch(dbaccess::DBException* dbe)
          {
      throw new GeneralException(dbe->getMessage());
          }
      }


       /**@fn remove(std::string pkValue)
         * @brief Remove the AccentureDetails from the EmployeeAccenture table given the EmployeeAccentureId
         * @param pkValue - Delete the record corresponding to pkValue
         * @return bool - Status of deletion
         */

      bool EmployeeAccentureDAO::remove( std::string pkValue)
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

          std::string sqlstmt = DAOConstants::PROJ_DELETE;

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



       /**@fn update(AccentureDetails& piSet)
         * @brief Update those records that match piWhere with piSet
         * @param piSet - the SET part of the UPDATE statement
         * @return bool - status of updatiom
         */
      bool EmployeeAccentureDAO::update(HRSObject& piSet)
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

          std::string sqlStmt = DAOConstants::PROJ_UPDATE_MAIN;

          AccentureDetails info = static_cast<AccentureDetails&>(piSet);

          Transform t;
          std::string set = t.transform(info);

          char query[1024];
          sprintf( query, sqlStmt.c_str(), set.c_str() , info.getEmployeeAccentureId().c_str() );

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
