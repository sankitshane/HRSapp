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

class HRManager
{
 private:
	 static HRManager* m_instance; ///<Reference to the HRManager class
   EmployeeBC m_empBC; ///<Object of the EmployeeBC Class.
	 SkillCategoryBC m_skillCatBC; ///<Object of the skill categoryBC class
	 SkillBC m_skillBC; ///<Object of  the skillBC class
	 ProjectBC m_projectBC; ///<Object of the projectBC class

   /**@fn HRManager
   * @brief Default Constructor.
   * This constructor will not take any argument.
   * It will initialize all the variable to ZERO.
   * @param none
   * @return none
   */
   HRManager()
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
  ~HRManager()
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
  static HRManager* getInstance(void)
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
  void createEmployee(EmployeeInfo& info)
    {
      m_empBC.createEmployee(info);
    }



  /**@fn searchEmployee
   *@brief This method uses searchEmployee method of EmployeeBC.
   * @param std::string
   * @return an object of the class employeeInfo.
   */
   EmployeeInfo searchEmployee(std::string empno)
   {
     m_empBC.searchEmployee(empno);
   }



  /**@fn searchEmployees
   * @brief This method uses searchEmployees method of EmployeeBC
   * @param Object of the class EmployeeInfo
   * @return the collection of employeeInfo .
   */
    std::vector<EmployeeInfo> searchEmployees(std::string info)
    {
      m_empBC.searchEmployees(info);
    }


  /**@fn updateEmployee
   *@briefthis function updates the information of the employees.
   * Returns nothing
   * @param Object of the class EmployeeInfo
   * @return none
   */
  void updateEmployee(EmployeeInfo& info)
  {
    m_empBC.updateEmployee(info);
  }


  /**@fn createCategory
   * @brief This method uses createCategory of SkillCategoryBC.
   * @param Object of the class SkillCategory
   * @return nothing.
   */
  void createCategory(SkillCategory& info)
  {
    m_skillCatBC.createCategory(info);
  }


   /**@fn searchCategory
    *@brief This method uses searchCategory method of SkillCategoryBC.
   * @param std::string
   * @return an object of the class SkillCategory.
   */
   SkillCategory searchCategory(std::string id)
   {
     m_skillCatBC.searchCategory(id);
   }


   /**@fn searchCategories
    *@brief This method uses searchApprovedCategory method of SkillCategoryBC.
   * @param Object of the class SkillCategory
   * @return an collection of SkillCategory.
   */
   std::vector<SkillCategory>  searchCategories(std::string dataFind)
   {
     m_skillCatBC.searchCategories(dataFind);
   }


   /**@fn updateCategory
    *@brief this function updates the information of the Category.
   * Returns nothing
   * @param bject of the class SkillCategory
   * @return nothing.
   */
  void updateCategory(SkillCategory& info)
  {
    m_skillCatBC.updateCategory(info);
  }


   /**This method uses createSkill method of EmployeeBC
   * @param Object of the class SkillInfornmation
   * @return nothing.
   */
  void createSkill(SkillsInformation& info)
  {
    m_skillBC.createSkill(info);
  }


  /**This method uses searchSkill method of SkillBC.
   * @param std::string
   * @return an object of the class SkillInformation.
   */
   SkillsInformation searchSkill(std::string id)
   {
     m_skillBC.searchSkill(id);
   }


 /**This method uses searchSkills method of SkillCategoryBC.
   * @param Object of the class SkillInformation
   * @return an object of SkillInformation.
   */
   std::vector<SkillsInformation>  searchSkills(std::string name)
   {
     m_skillBC.searchSkills(name);
   }


   /**this function uses the updateSkill method of SkillBC.
   * Returns nothing
   * @param Object of the class SkillInformation
   * @return none
   */
  void updateSkill(SkillsInformation& info)
  {
    m_skillBC.updateSkill(info);
  }


   /**This method uses createProject method of ProjectBC
   * @param Object of the class ProjectInfo
   * @return nothing.
   */
  void createProject(ProjectInfo& info)
  {
    m_projectBC.createProject(info);
  }


  /**This method uses searchProject method of ProjectBC.
   * @param std::string
   * @return an object of the class ProjectInfo.
   */
   ProjectInfo searchProject(std::string id)
   {
     m_projectBC.searchProject(id);
   }


   /**This method uses searchApprovedPoject method of ProjectBC.
   * @param Object of the class Project Info
   * @return a collection of ProjectInformation.
   */
   std::vector<ProjectInfo>  searchProjects(std::string dataFind)
   {
     m_projectBC.searchProjects(dataFind);
   }



  /**this function updateProject method of ProjectBC.
   * Returns nothing
   * @param Object of the class ProjectInfo
   * @return none
   */
  void updateProject(ProjectInfo& info)
  {
    m_projectBC.updateProject(info);
  }
};

} //namespace bc
#endif
