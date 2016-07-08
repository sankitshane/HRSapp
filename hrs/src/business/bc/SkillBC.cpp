#include<business/SkillBC.h>
#include<common/SkillInfo.h>
#include<dao/SkillDAO.h>
#include<business/idgen/SkillIdGen.h>

/**@file SkillBC.cpp
* @brief HRS Application : Defines the SkillBC Class.
*
* <BR>NAME:SkillBC
*
* <BR>BASE CLASSES:None
*
* <BR>PURPOSE:To do the effective communication bitween the HRManager class and the SkillDAO class
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

 /**@fn SkillBC
   * @brief Default Constructor.
   * This constructor will not take any argument.
   * It will initialize both the variable to ZERO.
   * @param none
   * @return none
   */

  SkillBC::SkillBC()
  {
  }




 /**@fn createSkill
   * @brief it creats the Skill
   * It create the Skill data
   * returns nothing.
   * @param reference to the objectof SkillInfo
   * @return nothing.
   */
  void SkillBC::createSkill(SkillInfo& info)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "About to get unique id");
#endif

    std::string id=(idgen::SkillIdGen::getInstance())->getNextId();

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str());
#endif

    info.setSkillId(id);//proj is an instance of the class SkillInfo and id is a string
    m_SkillDAO.create(info);

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif


  }



  /**@fn searchSkill
   * @brief it seerchs for a Skill
   * @param std::string id
   * @return an object of the class Skillinfo.
   */
  SkillInfo SkillBC::searchSkill(std::string id)
  {
    SkillInfo skInfo;
    SkillInfo* skInfoPtr = NULL;


#ifdef ALOGGER
    //logger::Logger::getInstance().info("EmployeeBC::searchEmployee::searching an Employee");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str() );
#endif
    skInfoPtr = static_cast<SkillInfo*>(m_SkillDAO.findByPK(id));//we may overload == operator in SkillInfo

    skInfo = *skInfoPtr;
    delete skInfoPtr;

    return skInfo;
  }

 /**@fn searchSkills
   * @brief it seerchs for a collection of Skills
   * @param an reference to the object of SkillInfo.
   * @return a set of objects to the class Skillinfo.
   */
  std::vector<SkillInfo> SkillBC::searchSkills(std::string name)
  {

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, name.c_str() );
#endif

    std::vector<SkillInfo> sklList;

    std::vector<HRSObject*> sklListPtr;
    sklListPtr = m_SkillDAO.find(name);

    int size = sklListPtr.size();
    for(int i = 0; i < size; ++i)
      {
	sklList.push_back( *(static_cast<SkillInfo*>(sklListPtr[i])) );
      }
    for(int i = 0; i < size; ++i)
      delete sklListPtr[i];
    sklListPtr.clear();

    return sklList;
  }



  /**@fn updateSkill
   * @brief it updtes the Skill
   * This function updates the information of the Skill records in the database.
   * Returns nothing
   * @param an reference to the object of Skillinfo
   * @return none
   */
  void SkillBC::updateSkill(SkillInfo& info)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
    //logger::Logger::getInstance().info("EmployeeBC::updateEmployee::About to updatet the Employee");
#endif
    m_SkillDAO.update(info);
  }

}//namespace bc
