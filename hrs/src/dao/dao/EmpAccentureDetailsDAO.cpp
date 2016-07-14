#include<fstream>
#include<vector>
#include<string>

#include<dbaccess/ODBCConnection.h>
#include<dbaccess/ODBCResultSet.h>
#include<dbaccess/ODBCStatement.h>

#include<common/AccentureDetails.h>
#include<common/GeneralException.h>

#include<dao/EmpAccentureDetailsDAO.h>
#include<dbaccess/dbAccess.h>
#include<dbaccess/DBException.h>
#include<dbaccess/ODBCError.h>

#include<dao/DAOConstants.h>
#include<dao/assemblers/AccentureDetailsAssembler.h>

#include<dao/Transforms.h>

#ifdef ALOGGER
#include<logger/Logger.h>
#endif

/**@file EmpAccentureDetailsDAO.cpp
 * @brief Defines Data Access Object for Employee Accenture Details.
 *
 * <BR>NAME: EmpAccentureDetailsDAO
 * 
 * <BR>BASE CLASSES: No Parent
 * 
 * <BR>PURPOSE: This class is responsible for direct interaction with the
 *  database for Employee data specific to Accenture.
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


   /**@fn EmpAccentureDetailsDAO
     * @brief Default Constructor.
     * This constructor will not take any argument.
     * @param none
     * @return none
     */

  EmpAccentureDetailsDAO::EmpAccentureDetailsDAO()
  {
    
  }


 /**@fn create(HRSObject& accentureDetails)
     * @brief Insert data into EmpAccentureDetail table
     * This method gets an instance of the connection from
     * DBAccess and inserts data from the accentureDetails object
     * into the EmpAccentureDetail table.
     * sample usage:
     *        EmployeeDAO emp;
     *        AccentureDetail ad = empInfo.getAccentureDetail();
     *        emp.create(ad);
     *
     * @param A reference to AccentureDetails object containing employee data
     * @return none
     */   
  
  void EmpAccentureDetailsDAO::create(HRSObject& accentureDetails)
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

      sqlstmt = AccentureDetailsAssembler::assemble(static_cast<AccentureDetails&>(accentureDetails), sqlstmt);

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, sqlstmt.c_str() );
#endif

      bool res = stmt->execute(sqlstmt);
	
      if( res == false)
	{
#ifdef ALOGGER
	  logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__,  "Create Employee Failed");
#endif
	  stmt->close();
	  dbaccess::DBAccess::releaseConnection();
	  throw new GeneralException("Create Employee Failed");
	  return;
	}

      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__,  "");
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
      std::vector<HRSObject*> accInfo; 

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

      std::string sqlStmt = DAOConstants::EMPACC_FIND_MAIN;

      sqlStmt.replace( sqlStmt.find("%s"), 2, searchCriteria  );

      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      while( rs->next() )
	accInfo.push_back(new AccentureDetails(AccentureDetailsAssembler::disAssemble(rs))  ); 

      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();




#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__,  "");
#endif
      return accInfo;
    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }

  }


   /**@fn findByAll()
     * @brief Retrieve all records from the EmpAccentureDetail table
     * @param none
     * @return A vector of all EmpAccentureDetail found in the table 
     */             
  std::vector<HRSObject*> EmpAccentureDetailsDAO::findByAll()
  {
    try{

      std::vector<HRSObject*> accInfo; 

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

      std::string sqlStmt = DAOConstants::EMPACC_FIND_ALL;

      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      while( rs->next() )
	accInfo.push_back( new AccentureDetails(AccentureDetailsAssembler::disAssemble(rs))  ); 

      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__,  "");
#endif

      return accInfo;

    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }


   /**@fn  findByPK(std::string pkValue)
     * @brief Fetch Employees whose primary key value matches the passed one
     * @param pkValue - Value of the primary key (Employee No.)
     * @return AccentureDetail - Record Matching the pkValue 
     */ 

  HRSObject* EmpAccentureDetailsDAO::findByPK(std::string pkValue)
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

      std::string sqlStmt = DAOConstants::EMPACC_FIND_BYPK;

      AccentureDetails* empAccReturn = NULL;

      sqlStmt.replace( sqlStmt.find("%s"), 2, pkValue);

      dbaccess::ODBCResultSet* rs = stmt->executeQuery(sqlStmt);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      //Fill the empInfo object.
      if(rs->next())
	empAccReturn = new AccentureDetails(AccentureDetailsAssembler::disAssemble(rs));
      else
	throw new GeneralException("Search by PK Failed");

      rs->close();
      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__,  "");
#endif

      return empAccReturn;

    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
              
  }     


   /**@fn remove(std::string pkValue)
     * @brief Remove the AccentureDetails from the EmpAccentureDetails table given the EmployeeId
     * @param pkValue - Delete the record corresponding to pkValue
     * @return bool - Status of deletion
     */ 
  
  bool EmpAccentureDetailsDAO::remove( std::string pkValue)     
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

      std::string sqlstmt = DAOConstants::EMPACC_DELETE;

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
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__,  "");
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
  
  bool EmpAccentureDetailsDAO::update(HRSObject& piSet)
  {
    try{

      dbaccess::DBAccess::releaseConnection();

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

      std::string sqlStmt = DAOConstants::EMPACC_UPDATE;

      AccentureDetails info = static_cast<AccentureDetails&>(piSet);

      Transform t;
      std::string set = t.transform(info);
    
      char query[1024];
      sprintf( query, sqlStmt.c_str(), set.c_str() , info.getEmployeeNo().c_str() );


#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, query);
#endif

      bool res = stmt->executeUpdate( query );

      if( res == false)
	{
#ifdef ALOGGER
	  logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__,  "Error updating record");
#endif
	  stmt->close();
	  dbaccess::DBAccess::releaseConnection();
	  throw new GeneralException("Error updating record");
	}
	

      stmt->close();
      dbaccess::DBAccess::releaseConnection();

#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__,  "");
#endif

      return true;

    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }

  }

}	//namespace dao
