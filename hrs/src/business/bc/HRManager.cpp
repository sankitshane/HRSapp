#include<business/HRManager.h>
#include <common/EmployeeInfo.h>
#include <common/SkillCategory.h>
#include <common/SkillsInformation.h>
#include <common/ProjectInfo.h>

#include <business/EmployeeBC.h>
#include <business/SkillCategoryBC.h>
#include <business/SkillBC.h>
#include <business/ProjectBC.h>

#ifndef Null
#define Null 0


#include<string>
#include<vector>

namespace bc {
/**@class HRManager.
** @brief HRS Application  Declaration of HRManager class.
* <PRE>The participants will be give folowing Activity.
* 1. Write a class HRManager , which will enforce encapsulation.
* 2. class HRManager should have five private member variable.
* 3. Declare one constructors.
* 4. Declare Destructor.
*/



   /**@fn HRManager
   * @brief Default Constructor.
   * This constructor will not take any argument.
   * It will initialize all the variable to ZERO.
   * @param none
   * @return none
   */
   HRManager::HRManager()
   {
     m_empBC = Null;
     m_skillBC = Null;
     m_skillCatBC= Null;
     m_projectBC= Null;
   }
 public:
   /**@fn HRManager
   * @brief Destructor.
   * @param none
   * @return not applicable
   */
  HRManager::~HRManager()
  {
    m_empBC = Null;
    m_skillBC = Null;
    m_skillCatBC= Null;
    m_projectBC= Null;
  }


   /**@fn getInstance
    * @brief It takes values of the HRManager class data returns an object to HRManager.
    * @param none
    * @return an object to HRManager.
    */
  static HRManager* HRManager::getInstance(void)
    {
      if (m_instance == Null)
      {
        HRManager * new_instance = new HRManager;
        return new_instance;
      }
      return m_instance;
    }

   /**@fn createEmployee
    *@brief  This method uses createEmployee method of EmployeeBC.
   * @param Object of the class EmployeeInfo
   * @return nothing.
   */
  void HRManager::createEmployee(EmployeeInfo& info)
    {
      m_empBC.createEmployee(info);
    }



  /**@fn searchEmployee
   *@brief This method uses searchEmployee method of EmployeeBC.
   * @param std::string
   * @return an object of the class employeeInfo.
   */
   EmployeeInfo HRManager::searchEmployee(std::string empno)
   {
     return m_empBC.searchEmployee(empno);
   }



  /**@fn searchEmployees
   * @brief This method uses searchEmployees method of EmployeeBC
   * @param Object of the class EmployeeInfo
   * @return the collection of employeeInfo .
   */
    std::vector<EmployeeInfo> HRManager::searchEmployees(std::string info)
    {
      return m_empBC.searchEmployees(info);
    }


  /**@fn updateEmployee
   *@briefthis function updates the information of the employees.
   * Returns nothing
   * @param Object of the class EmployeeInfo
   * @return none
   */
  void HRManager::updateEmployee(EmployeeInfo& info)
  {
    m_empBC.updateEmployee(info);
  }


  /**@fn createCategory
   * @brief This method uses createCategory of SkillCategoryBC.
   * @param Object of the class SkillCategory
   * @return nothing.
   */
  void HRManager::createCategory(SkillCategory& info)
  {
    m_skillCatBC.createCategory(info);
  }


   /**@fn searchCategory
    *@brief This method uses searchCategory method of SkillCategoryBC.
   * @param std::string
   * @return an object of the class SkillCategory.
   */
   SkillCategory HRManager::searchCategory(std::string id)
   {
     return m_skillCatBC.searchCategory(id);
   }


   /**@fn searchCategories
    *@brief This method uses searchApprovedCategory method of SkillCategoryBC.
   * @param Object of the class SkillCategory
   * @return an collection of SkillCategory.
   */
   std::vector<SkillCategory>  HRManager::searchCategories(std::string dataFind)
   {
     return m_skillCatBC.searchCategories(dataFind);
   }


   /**@fn updateCategory
    *@brief this function updates the information of the Category.
   * Returns nothing
   * @param bject of the class SkillCategory
   * @return nothing.
   */
  void HRManager::updateCategory(SkillCategory& info)
  {
    m_skillCatBC.updateCategory(info);
  }


   /**This method uses createSkill method of EmployeeBC
   * @param Object of the class SkillInfornmation
   * @return nothing.
   */
  void HRManager::createSkill(SkillsInformation& info)
  {
    m_skillBC.createSkill(info);
  }


  /**This method uses searchSkill method of SkillBC.
   * @param std::string
   * @return an object of the class SkillInformation.
   */
   SkillsInformation HRManager::searchSkill(std::string id)
   {
     return m_skillBC.searchSkill(id);
   }


 /**This method uses searchSkills method of SkillCategoryBC.
   * @param Object of the class SkillInformation
   * @return an object of SkillInformation.
   */
   std::vector<SkillsInformation>  HRManager::searchSkills(std::string name)
   {
     return m_skillBC.searchSkills(name);
   }


   /**this function uses the updateSkill method of SkillBC.
   * Returns nothing
   * @param Object of the class SkillInformation
   * @return none
   */
  void HRManager::updateSkill(SkillsInformation& info)
  {
    m_skillBC.updateSkill(info);
  }


   /**This method uses createProject method of ProjectBC
   * @param Object of the class ProjectInfo
   * @return nothing.
   */
  void HRManager::createProject(ProjectInfo& info)
  {
    m_projectBC.createProject(info);
  }


  /**This method uses searchProject method of ProjectBC.
   * @param std::string
   * @return an object of the class ProjectInfo.
   */
   ProjectInfo HRManager::searchProject(std::string id)
   {
    return  m_projectBC.searchProject(id);
   }


   /**This method uses searchApprovedPoject method of ProjectBC.
   * @param Object of the class Project Info
   * @return a collection of ProjectInformation.
   */
   std::vector<ProjectInfo>  HRManager::searchProjects(std::string dataFind)
   {
     return m_projectBC.searchProjects(dataFind);
   }



  /**this function updateProject method of ProjectBC.
   * Returns nothing
   * @param Object of the class ProjectInfo
   * @return none
   */
  void HRManager::updateProject(ProjectInfo& info)
  {
    m_projectBC.updateProject(info);
  }


} //namespace bc
#endif
