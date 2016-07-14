

/**@file ProjectIdGen.cpp
 * @brief  Declares the ProjectIdGen
 *
 * <BR>NAME:
 * 
 * <BR>BASE CLASSES:
 * 
 * <BR>PURPOSE:
 *
 * <BR>AUTHOR:
 * <BR>
 * <BR>$Revision: $
 * 
 * <BR>$Log:
 * 
 * <BR>COPYRIGHT NOTICE:
 * <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
 */

#include <fstream>
#include <iostream>
#include<string>

#include<common/GeneralException.h> // must be declared before DBException.

#include<dao/DAOConstants.h>

#include<business/idgen/ProjectIdGen.h>
#include<dbaccess/ODBCConnection.h>
#include<dbaccess/ODBCResultSet.h>
#include<dbaccess/ODBCStatement.h>
#include<dbaccess/dbAccess.h>

#include<dbaccess/DBException.h>
#include<dbaccess/ODBCError.h>

namespace idgen {
	
  ProjectIdGen* ProjectIdGen::m_thisInstance = NULL;

  /**@class ProjectIdGen
   * @brief Declaration of ProjectIdGen
   * <PRE>The participants will be give following Activity.
   * 1. Write a class ProjectIdGen, which will enforce encapsulation.
   * 2. class ProjectIdGen should have class member variable to reference to ProjectIdGen.
   * 3. class ProjectIdGen should have another member variable from which SQL statement will retrieve the next category id.
   * 4. Declare an empty private constructor. 
   * 5. Declare a function that will implement a Singleton ProjectIdGen.
   * 6. Declare a function that checks whether the object is null,if null,ProjectIdGen object is instantiated and the object is returned.
   * 7. Declare a function that gets database connection.
   </PRE>
  */

  ProjectIdGen::ProjectIdGen()
  {
  }


  /**@fn getInstance
   * @brief implements singleton ProjectIdGen class.
   * @param none
   * @return Pointer to ProjectIdGen.
   */
  ProjectIdGen* ProjectIdGen::getInstance()
  {
    if(m_thisInstance == NULL)
      m_thisInstance = new ProjectIdGen;
    return m_thisInstance;
  }
 
  
  /**@fn getNextId
   * @brief gets the next system-generated id.
   * @param none.
   * @return string.
   */
  std::string ProjectIdGen::getNextId()
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

      dbaccess::ODBCResultSet* res = stmt->executeQuery( DAOConstants::PROJSQL_GETID);
      if(conn->getError().isError()) //Checks for error.
	{
	  throw new GeneralException(conn->getError().getErrorMessage());
	}

      if(!res->next())
	{
	  res->close();
	  stmt->close();
	  dbaccess::DBAccess::releaseConnection();
	  throw new GeneralException("Error obtaining next Id");
	}

      std::string id = res->getString(1);
      
      res->close();
      stmt->close();
      
      dbaccess::DBAccess::releaseConnection();

      return id;
	  
    }catch(dbaccess::DBException* dbe)
      {
	throw new GeneralException(dbe->getMessage());
      }
  }

} //namespace idgen
