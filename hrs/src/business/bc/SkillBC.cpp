#include<business/idgen/SkillIdGen.h>
#include<common/SkillsInformation.h>
#include<dao/SkillDAO.h>
#include<business/SkillBC.h>

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
   * SkillBC constructior
   * @author Vinoj.V.S
   * @author last modified by: $Author: 
   * @version 1.0
   */
  SkillBC::SkillBC()
  {
			 
  }
		


  /**It create the Skill data
   * returns nothing.
   * @param an objectof SkillsInformationn
   * @return nothing.
   */
  void SkillBC::createSkill(SkillsInformation& info)
  {

    //#ifdef ALOGGER
    //	logger::Logger::getLogger().info("SkillBC::createSkill::About to create a Skill");
    //#endif
	
    std::string id;

    id=(idgen::SkillIdGen::getInstance())->getNextId();

    info.setSkillId(id);//info is an instance of the class SkillInformation and id is a string

    m_skillDAO.create(info); 

#ifdef ALOGGER
    //logger::Logger::getInstance().info("EmployeeBC::createEmployee::Created an Employee");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif	
	
	
  }
	


  /**returns the Information of the project.
   * @param std::string
   * @return an object of the class Skillinfo.
   */
  SkillsInformation SkillBC::searchSkill(std::string id)
  {
#ifdef ALOGGER
    //logger::Logger::getInstance().info("EmployeeBC::searchEmployee::searching an Employee");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str() );
#endif
    SkillsInformation skillInfo;
    SkillsInformation* skillInfoPtr = NULL;

    skillInfoPtr = static_cast<SkillsInformation*>(m_skillDAO.findByPK(id));
    skillInfo = *skillInfoPtr;
    delete skillInfoPtr;

    return skillInfo;
  }


  /**returns the collection of skillInformation
   * @param SkillInformatioin
   * @return collection of SkillInformation.
   */
  std::vector<SkillsInformation> SkillBC::searchSkills(std::string criteria)
  {

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, criteria.c_str() );
#endif

	
    std::vector<SkillsInformation> skillList;
    std::vector<HRSObject*> skillListPtr;

    if( criteria.empty() )
      skillListPtr = m_skillDAO.findByAll();
    else
      skillListPtr = m_skillDAO.find(criteria);


    int size = skillListPtr.size();
    for(int i = 0; i < size; ++i)
      {
	skillList.push_back( *(static_cast<SkillsInformation*>(skillListPtr[i])) );
      }
    for(int i = 0; i < size; ++i)
      delete skillListPtr[i];

    skillListPtr.clear();

    return skillList;

  }
   
  /**This function updates the information of the skill records in the database.
   * Returns nothing
   * @param an object of Skillinformatiom
   * @return none
   */
  void SkillBC::updateSkill(SkillsInformation& info)
  {
    m_skillDAO.update(info);

	
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
    //logger::Logger::getInstance().info("EmployeeBC::updateEmployee::About to updatet the Employee");
#endif
  }
  
}//namespace bc
