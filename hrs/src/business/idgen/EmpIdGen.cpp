#include<string>

/**@file EmpIdGen.cpp
 * @brief  Declares the EmpIdGen
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

#include<common/GeneralException.h>// must be declared before DBException.
#include<dao/DAOConstants.h>

#include<business/idgen/EmpIdGen.h>

#include<dbaccess/ODBCConnection.h>
#include<dbaccess/ODBCResultSet.h>
#include<dbaccess/ODBCStatement.h>
#include<dbaccess/dbAccess.h>


#include<dbaccess/DBException.h>
#include<dbaccess/ODBCError.h>



namespace idgen {
	
  EmpIdGen* EmpIdGen::m_thisInstance = NULL;

  /**@class EmpIdGen
   * @brief  Declaration of EmpIdGen
  */

  EmpIdGen::EmpIdGen()
  {
  }


  EmpIdGen* EmpIdGen::getInstance()
  {
    if(m_thisInstance == NULL)
      m_thisInstance = new EmpIdGen;
    return m_thisInstance;
  }
 
  std::string EmpIdGen::getNextId()
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

      dbaccess::ODBCResultSet* res = stmt->executeQuery( DAOConstants::EMPSQL_GETID);
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

}	//namespace idgen
