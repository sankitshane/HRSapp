#include<iostream>
#include<string>
#include<vector>


#include<business/HRManager.h>

#include<common/EmployeeInfo.h>
#include<common/SkillCategory.h>
#include<common/SkillsInformation.h>
#include<common/ProjectInfo.h>
#include<business/EmployeeBC.h>
#include<business/SkillCategoryBC.h>
#include<business/SkillBC.h>
#include<business/ProjectBC.h>

#ifdef ALOGGER
#include<logger/Logger.h>
#endif

/**@file HRManagerBC_cpp
 * @brief HRS Application : Defines the HRManager class.
 * <BR>NAME:
 * 
 * <BR>BASE CLASSES:NONE
 * 
 * <BR>PURPOSE:To obtain an interface bitween UI and Business Co mponent.
 *
 * <BR>AUTHOR:Vinoj.V.S
 * <BR>
 * <BR>$Revision: $
 * 
 * <BR>$Log:14/12/2005
 * 
 * <BR>COPYRIGHT NOTICE:
 * <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
 */

/**@class HRManager.
 * @brief HRS Application  Defenition of HRManager class.
 * <PRE>The participants will be give following Activity.
 * 1. Write a class HRManager , which will enforce encapsulation.
 * 2. class HRManager should have five private member variable. 
 * 3. Declare one constructors.
 * 4. Declare Destructor.
 * 5. Declare a function to print the content of the HRManager class.
 * 6. Write getters and setters for two varialbes.
 */

namespace bc {

  HRManager* HRManager::m_instance = NULL;


  /**@fn HRManager
   * @brief Default Constructor.
   * This constructor will not take any argument.
   * It will initialize both the variable to ZERO.
   * @param none
   * @return none
   */
  HRManager::HRManager()
  {
    //	  m_instance=NULL;///<Reference to the HRManager class 

  }
  


  /**It takes values of the HRManager cklass data
   * returns an object to HRManager.
   * @param none
   * @return an object to HRManager.
   */
  HRManager* HRManager::getInstance(void)
  {
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::getInstance::If the instance is NULL ;then dynamically inintialises the insatance");
    logger::Logger::getInstance().debug(__FILE__, __LINE__,__FUNCTION__, "");
#endif
    //Initialising the instance of HRManager
    if(m_instance == NULL)
      m_instance = new HRManager;

    return m_instance;
  }

  
  /**This method uses createEmployee method of EmployeeBC
   * @param none
   * @return nothing.
   */
  void HRManager::createEmployee(EmployeeInfo& info)
  {
		
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::createEmployee::Calls EmployeeBC to create Employee");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "" );
#endif		
    m_empBC.createEmployee(info);
  }
	
		
  
  /**This method uses searchEmployee method of EmployeeBC
   * @param none
   * @return an object of the class employeeInfo.
   */
  EmployeeInfo HRManager::searchEmployee(std::string empno)
  {
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::searchEmployee::Calls EmployeeBC to search Employee");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, empno.c_str() );
#endif			
    return m_empBC.searchEmployee(empno);
  }


     
  /**This method uses searchEmployees method of EmployeeBC
   * @param none
   * @return the collection of employyeeInfo .
   */
  std::vector<EmployeeInfo> HRManager::searchEmployees(std::string info)
  {
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::searcheEmployees::Calls EmployeeBC to Search Employees");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, info.c_str() );
#endif	
    return m_empBC.searchEmployees("FirstName LIKE '%" + info + "%'");
  }



  /**this function updates the information of the employees.
   * Returns nothing
   * @param void
   * @return none
   */
  void HRManager::updateEmployee(EmployeeInfo& info)
  {
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::updateEmployee::Calls EmployeeBC to Update Employee");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "" );
#endif			
    m_empBC.update(info);
  }



  /**This method uses createCategory of SkillCategoryBC.
   * @param none
   * @return nothing.
   */
  void HRManager::createCategory(SkillCategory& info)
  {
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::createCategory::Calls SkillCategoryBC to create SkillCategory");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "" );
#endif			
    m_skillCatBC.createCategory(info);
  }


  /**This method uses searchCategory method of SkillCategoryBC.
   * @param none
   * @return an object of the class SkillCategory.
   */
  SkillCategory HRManager::searchCategory(std::string id)
  {
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::searchCategory::Calls SkillCategoryBC to search SkillCategory");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str() );
#endif	
    return m_skillCatBC.searchSkillCategory(id);
  }



  /**This method uses searchApprovedCategory method of SkillCategoryBC.
   * @param none
   * @return an collection of SkillCategory.
   */
  std::vector<SkillCategory>HRManager::searchCategories(std::string info)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, info.c_str() );
#endif			
    return  m_skillCatBC.searchSkillCategories("Name LIKE '%" + info + "%'" );
  }



  /**this function updates the information of the Category.
   * Returns nothing
   * @param void
   * @return nothing.
   */
  void HRManager::updateCategory(SkillCategory& info)
  {
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::updateCategory::Calls SkillCategoryBC to update SkillCategory");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif			
    m_skillCatBC.updateCategory(info);
  }



  /**This method uses createSkill method of EmployeeBC
   * @param none
   * @return nothing.
   */
  void HRManager::createSkill(SkillsInformation& info)
  {
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::createSkill::Calls SkillBC to create SkillCategory");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "" );
#endif			
    m_skillBC.createSkill(info);
  }



  /**This method uses searchSkill method of SkillBC.
   * @param SkillInformation
   * @return an object of the class SkillInformation.
   */
  SkillsInformation HRManager::searchSkill(std::string id)
  {
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::searchSkill::Searching for skill" + id);
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str() );
#endif
    return m_skillBC.searchSkill(id);
  }


  /**This method uses searchSkill method of SkillInformation.
   * @param Reference to an object of SkillInformation
   * @return an object of SkillInformation.
   */
  std::vector<SkillsInformation> HRManager::searchSkills(std::string dataFind)
  {
#ifdef ALOGGER
    //	logger::Logger::getLogger().info("HRManager::searchSkills::Searching for skills");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, dataFind.c_str() );
#endif		
		
    return m_skillBC.searchSkills("Name LIKE '%" + dataFind + "%'");
  }
 

  /**this function uses the updateSkill method of SkillBC.
   * Returns nothing
   * @param void
   * @return none
   */
  void HRManager::updateSkill(SkillsInformation& info)
  {
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::updateSkill::Updating skill");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "" );
#endif		
    m_skillBC.updateSkill(info);
  }
 


  /**This method uses createProject method of ProjectBC
   * @param none
   * @return nothing.
   */
  void HRManager::createProject(ProjectInfo& info)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "" );
#endif		
    m_projectBC.createProject(info);
  }




  /**This method uses searchProject method of ProjectBC.
   * @param none
   * @return an object of the class ProjectInfo.
   */
  ProjectInfo HRManager::searchProject(std::string id)
  {
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::searchPrioject::Searching for Project");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str() );
#endif		
    return m_projectBC.searchProject(id);
  }


  /**This method uses searchApprovedPoject method of ProjectBC.
   * @param none
   * @return a collection of ProjectInformation.
   */
  std::vector<ProjectInfo>  HRManager::searchProjects(std::string dataFind)
  {
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::searchProjects::Searching for Projects");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, dataFind.c_str() );
#endif		
    return m_projectBC.searchProjects("Name like '%" + dataFind + "%'");
  }



   
  /**this function updateProject method of ProjectBC.
   * Returns nothing
   * @param void
   * @return none
   */
  void HRManager::updateProject(ProjectInfo& info)
  {
#ifdef ALOGGER
    //logger::Logger::getLogger().info("HRManager::updateProjects::Updating for Project");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif	
    m_projectBC.updateProject(info);
  }
} //namespace bc
