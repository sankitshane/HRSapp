#include <fstream>
#include <iostream>
#include<string>

#include<common/GeneralException.h> // must be declared before DBException.

#include<dao/DAOConstants.h>

#include<business/idgen/CategoryIdGen.h>
#include<dbaccess/ODBCConnection.h>
#include<dbaccess/ODBCResultSet.h>
#include<dbaccess/ODBCStatement.h>
#include<dbaccess/dbAccess.h>

#include<dbaccess/DBException.h>
#include<dbaccess/ODBCError.h>

namespace idgen {

  CategoryIdGen* CategoryIdGen::m_thisInstance = NULL;

  /**@class SkillCategoryIdGen
   * @brief Declaration of SkillCategoryIdGen
   * <PRE>The participants will be give following Activity.
   * 1. Write a class SkillCategoryIdGen, which will enforce encapsulation.
   * 2. class SkillCategoryIdGen should have class member variable to reference to SkillCategoryIdGen.
   * 3. class SkillCategoryIdGen should have another member variable from which SQL statement will retrieve the next category id.
   * 4. Declare an empty private constructor.
   * 5. Declare a function that will implement a Singleton SkillCategoryIdGen.
   * 6. Declare a function that checks whether the object is null,if null,SkillCategoryIdGen object is instantiated and the object is returned.
   * 7. Declare a function that gets database connection.
   </PRE>
  */

  CategoryIdGen::CategoryIdGen()
  {
  }


  /**@fn getInstance
   * @brief implements singleton SkillCategoryIdGen class.
   * @param none
   * @return Pointer to SkillCategoryIdGen.
   */
  static CategoryIdGen* CategoryIdGen::getInstance()
  {
    if(m_thisInstance == NULL)
      m_thisInstance = new CategoryIdGen;
    return m_thisInstance;
  }


  /**@fn getNextId
   * @brief gets the next system-generated id.
   * @param none.
   * @return string.
   */
  std::string CategoryIdGen::getNextId()
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

      dbaccess::ODBCResultSet* res = stmt->executeQuery( DAOConstants::CATSQL_GETID);
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
