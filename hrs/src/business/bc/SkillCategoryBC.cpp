#include<business/SkillCategoryBC.h>
#include<common/SkillCategoryInfo.h>
#include<dao/SkillCategoryDAO.h>
#include<business/idgen/SkillCategoryIdGen.h>

/**@file SkillCategoryBC.cpp
* @brief HRS Application : Defines the SkillCategoryBC Class.
*
* <BR>NAME:SkillCategoryBC
*
* <BR>BASE CLASSES:None
*
* <BR>PURPOSE:To do the effective communication bitween the HRManager class and the SkillCategoryDAO class
*
* <BR>AUTHOR:Vinoj.V.S
* <BR>
* <BR>$Revision: $6/12/2005
*
* <BR>$Log:6/12/2005
*
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/
#ifdef ALOGGER
#include<logger/Logger.h>
#endif


namespace bc{

 /**@fn SkillCategoryBC
   * @brief Default Constructor.
   * This constructor will not take any argument.
   * It will initialize both the variable to ZERO.
   * @param none
   * @return none
   */

  SkillCategoryBC::SkillCategoryBC()
  {
  }




 /**@fn createSkillCategory
   * @brief it creats the SkillCategory
   * It create the SkillCategory data
   * returns nothing.
   * @param reference to the objectof SkillCategoryInfo
   * @return nothing.
   */
  void SkillCategoryBC::createSkillCategory(SkillCategoryInfo& info)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "About to get unique id");
#endif

    std::string id=(idgen::SkillCategoryIdGen::getInstance())->getNextId();

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str());
#endif

    info.setSkillCategoryId(id);//proj is an instance of the class SkillCategoryInfo and id is a string
    m_SkillCategoryDAO.create(info);

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif


  }



  /**@fn searchSkillCategory
   * @brief it seerchs for a SkillCategory
   * @param std::string id
   * @return an object of the class SkillCategoryinfo.
   */
  SkillCategoryInfo SkillCategoryBC::searchCategory(std::string id)
  {
    SkillCategoryInfo catInfo;
    SkillCategoryInfo* catInfoPtr = NULL;


#ifdef ALOGGER
    //logger::Logger::getInstance().info("EmployeeBC::searchEmployee::searching an Employee");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str() );
#endif
    catInfoPtr = static_cast<SkillCategoryInfo*>(m_SkillCategoryDAO.findByPK(id));//we may overload == operator in SkillCategoryInfo

    catInfo = *catInfoPtr;
    delete catInfoPtr;

    return catInfo;
  }

 /**@fn searchSkillCategorys
   * @brief it seerchs for a collection of SkillCategorys
   * @param an reference to the object of SkillCategoryInfo.
   * @return a set of objects to the class SkillCategoryinfo.
   */
  std::vector<SkillCategoryInfo> SkillCategoryBC::searchCategorys(std::string name)
  {

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, name.c_str() );
#endif

    std::vector<SkillCategoryInfo> catList;

    std::vector<HRSObject*> catListPtr;
    catListPtr = m_SkillCategoryDAO.find(name);

    int size = catListPtr.size();
    for(int i = 0; i < size; ++i)
      {
	catList.push_back( *(static_cast<SkillCategoryInfo*>(catListPtr[i])) );
      }
    for(int i = 0; i < size; ++i)
      delete catListPtr[i];
    catListPtr.clear();

    return catList;
  }



  /**@fn updateSkillCategory
   * @brief it updtes the SkillCategory
   * This function updates the information of the SkillCategory records in the database.
   * Returns nothing
   * @param an reference to the object of SkillCategoryinfo
   * @return none
   */
  void SkillCategoryBC::updateCategory(SkillCategoryInfo& info)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
    //logger::Logger::getInstance().info("EmployeeBC::updateEmployee::About to updatet the Employee");
#endif
    m_SkillCategoryDAO.update(info);
  }

}//namespace bc
