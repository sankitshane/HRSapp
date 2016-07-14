#include<business/SkillCategoryBC.h>
#include<common/SkillCategory.h>
#include<dao/SkillCategoryDAO.h>
#include<business/idgen/CategoryIdGen.h>


/*
 * Created on Dec 15, 2005
 * 
 * C++ Development School
 * Copyright 2005 Accenture
 */

#ifdef ALOGGER
#include<logger/Logger.h>
#endif

namespace bc{
  /**
   * SkillBC constructor
   * @author Vinoj.V.S
   * @author last modified by: $Author: 
   * @version 1.0
   */
  SkillCategoryBC::SkillCategoryBC()
  {
  }
			      

		


  /**It create the SkillCategory data
   * returns nothing.
   * @param an objectof SkillCategory
   * @return nothing.
   */
  void SkillCategoryBC::createCategory(SkillCategory& info)
  {
    //#ifdef ALOGGER
    //	logger::Logger::getLogger().info("SkillCategoryBC::createCategory::About to create a Category");
    //#endif
    std::string id;
    id=(idgen::CategoryIdGen::getInstance())->getNextId();
    info.setCategoryId(id);//info is an instance of the class SkillCatefory and id is a string

    m_catDAO.create(info); 
#ifdef ALOGGER
    //logger::Logger::getInstance().info("EmployeeBC::createEmployee::Created an Employee");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

  }
	


  /**returns the Information of the SkillCategory
   * @param std::string
   * @return an object of the class SkillCategory.
   */
  SkillCategory SkillCategoryBC::searchSkillCategory(std::string id)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str() );
#endif
    SkillCategory catInfo;
    SkillCategory* catInfoPtr = NULL;
		
    catInfoPtr = static_cast<SkillCategory*>(m_catDAO.findByPK(id));
    catInfo = *catInfoPtr;
    delete catInfoPtr;

    return catInfo;
  }


  /**returns the collection of skillCategory
   * @param Skillcategory
   * @return collection of SkillCategory
   */
  std::vector<SkillCategory> SkillCategoryBC::searchSkillCategories(std::string criteria)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, criteria.c_str() );
#endif

    std::vector<SkillCategory> skillList;
    std::vector<HRSObject*> skillListPtr;

    if( criteria.empty() )
      skillListPtr = m_catDAO.findByAll();
    else
      skillListPtr = m_catDAO.find(criteria);

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "...After fetching the vector");
#endif

    int size = skillListPtr.size();
    for(int i = 0; i < size; ++i)
      {
	skillList.push_back( *(static_cast<SkillCategory*>(skillListPtr[i])) );
      }
    for(int i = 0; i < size; ++i)
      delete skillListPtr[i];

    skillListPtr.clear();

    return skillList;

  }
   
  /**This function updates the information of the skillCategory records in the database.
   * Returns nothing
   * @param an object of SkillCategory
   * @return none
   */
  void SkillCategoryBC::updateCategory(SkillCategory& info)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
    //logger::Logger::getInstance().info("EmployeeBC::updateEmployee::About to updatet the Employee");
#endif
    m_catDAO.update(info);

	
  }
  
}//namespace bc
