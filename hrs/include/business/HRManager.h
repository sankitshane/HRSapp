#ifndef HRMANAGER_H
#define HRMANAGER_H

#ifndef Null
#define Null 0


#include<string>
#include<vector>

#include <common/EmployeeInfo.h>
#include <common/SkillCategory.h>
#include <common/SkillsInformation.h>
#include <common/ProjectInfo.h>

#include <business/EmployeeBC.h>
#include <business/SkillCategoryBC.h>
#include <business/SkillBC.h>
#include <business/ProjectBC.h>



/**@file HRManagerBC_h
* @brief HRS Application : Declares the HRManager class.
* <BR>NAME:HRManager
*
* <BR>BASE CLASSES:None
*
* <BR>PURPOSE:To do effective communication bitween the Business Component and the User Interface
*
* <BR>AUTHOR:Vinoj.V.S
* <BR>
* <BR>$Revision: $09/12/2005
*
* <BR>$Log:09/12/2005
*
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

/**@namespace bc
 * @brief This will contain all the Business Component Classes.
 */

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
   HRManager();
 public:
   /**@fn HRManager
   * @brief Destructor.
   * @param none
   * @return not applicable
   */
  ~HRManager();


   /**@fn getInstance
    * @brief It takes values of the HRManager class data returns an object to HRManager.
    * @param none
    * @return an object to HRManager.
    */
<<<<<<< HEAD
  static HRManager* getInstance(void);
||||||| merged common ancestors
  static HRManager* getInstance(void)
    {
      if (m_instance == Null)
      {
        HRManager * new_instance = new HRManager;
        return new_instance;
      }
      return m_instance;
    }
=======
  static HRManager* getInstance(void)
    {
      if (m_instance == Null)
      {
       new_instance = new HRManager;
      }
      return m_instance;
    }
>>>>>>> fb32a921932aa23e0fd80e6be50911ebeb06b16d

   /**@fn createEmployee
    *@brief  This method uses createEmployee method of EmployeeBC.
   * @param Object of the class EmployeeInfo
   * @return nothing.
   */
  void createEmployee(EmployeeInfo& info);



  /**@fn searchEmployee
   *@brief This method uses searchEmployee method of EmployeeBC.
   * @param std::string
   * @return an object of the class employeeInfo.
   */
<<<<<<< HEAD
   EmployeeInfo searchEmployee(std::string empno);
||||||| merged common ancestors
   EmployeeInfo searchEmployee(std::string empno)
   {
     m_empBC.searchEmployee(empno);
   }
=======
   EmployeeInfo searchEmployee(std::string empno)
   {
     return m_empBC.searchEmployee(empno);
   }
>>>>>>> fb32a921932aa23e0fd80e6be50911ebeb06b16d



  /**@fn searchEmployees
   * @brief This method uses searchEmployees method of EmployeeBC
   * @param Object of the class EmployeeInfo
   * @return the collection of employeeInfo .
   */
<<<<<<< HEAD
    std::vector<EmployeeInfo> searchEmployees(std::string info);
||||||| merged common ancestors
    std::vector<EmployeeInfo> searchEmployees(std::string info)
    {
      m_empBC.searchEmployees(info);
    }
=======
    std::vector<EmployeeInfo> searchEmployees(std::string info)
    {
      return m_empBC.searchEmployees(info);
    }
>>>>>>> fb32a921932aa23e0fd80e6be50911ebeb06b16d


  /**@fn updateEmployee
   *@briefthis function updates the information of the employees.
   * Returns nothing
   * @param Object of the class EmployeeInfo
   * @return none
   */
<<<<<<< HEAD
  void updateEmployee(EmployeeInfo& info);
||||||| merged common ancestors
  void updateEmployee(EmployeeInfo& info)
  {
    m_empBC.updateEmployee(info);
  }
=======
  void updateEmployee(EmployeeInfo& info)
  {
  m_empBC.updateEmployee(info);
  }
>>>>>>> fb32a921932aa23e0fd80e6be50911ebeb06b16d


  /**@fn createCategory
   * @brief This method uses createCategory of SkillCategoryBC.
   * @param Object of the class SkillCategory
   * @return nothing.
   */
  void createCategory(SkillCategory& info);


   /**@fn searchCategory
    *@brief This method uses searchCategory method of SkillCategoryBC.
   * @param std::string
   * @return an object of the class SkillCategory.
   */
<<<<<<< HEAD
   SkillCategory searchCategory(std::string id);
||||||| merged common ancestors
   SkillCategory searchCategory(std::string id)
   {
     m_skillCatBC.searchCategory(id);
   }
=======
   SkillCategory searchCategory(std::string id)
   {
     return m_skillCatBC.searchCategory(id);
   }
>>>>>>> fb32a921932aa23e0fd80e6be50911ebeb06b16d


   /**@fn searchCategories
    *@brief This method uses searchApprovedCategory method of SkillCategoryBC.
   * @param Object of the class SkillCategory
   * @return an collection of SkillCategory.
   */
<<<<<<< HEAD
   std::vector<SkillCategory>  searchCategories(std::string dataFind);
||||||| merged common ancestors
   std::vector<SkillCategory>  searchCategories(std::string dataFind)
   {
     m_skillCatBC.searchCategories(dataFind);
   }
=======
   std::vector<SkillCategory>  searchCategories(std::string dataFind)
   {
     return m_skillCatBC.searchCategories(dataFind);
   }
>>>>>>> fb32a921932aa23e0fd80e6be50911ebeb06b16d


   /**@fn updateCategory
    *@brief this function updates the information of the Category.
   * Returns nothing
   * @param bject of the class SkillCategory
   * @return nothing.
   */
  void updateCategory(SkillCategory& info);


   /**This method uses createSkill method of EmployeeBC
   * @param Object of the class SkillInfornmation
   * @return nothing.
   */
  void createSkill(SkillsInformation& info);


  /**This method uses searchSkill method of SkillBC.
   * @param std::string
   * @return an object of the class SkillInformation.
   */
<<<<<<< HEAD
   SkillsInformation searchSkill(std::string id);
||||||| merged common ancestors
   SkillsInformation searchSkill(std::string id)
   {
     m_skillBC.searchSkill(id);
   }
=======
   SkillsInformation searchSkill(std::string id)
   {
     return m_skillBC.searchSkill(id);
   }
>>>>>>> fb32a921932aa23e0fd80e6be50911ebeb06b16d


 /**This method uses searchSkills method of SkillCategoryBC.
   * @param Object of the class SkillInformation
   * @return an object of SkillInformation.
   */
<<<<<<< HEAD
   std::vector<SkillsInformation>  searchSkills(std::string name);
||||||| merged common ancestors
   std::vector<SkillsInformation>  searchSkills(std::string name)
   {
     m_skillBC.searchSkills(name);
   }
=======
   std::vector<SkillsInformation>  searchSkills(std::string name)
   {
     return m_skillBC.searchSkills(name);
   }
>>>>>>> fb32a921932aa23e0fd80e6be50911ebeb06b16d


   /**this function uses the updateSkill method of SkillBC.
   * Returns nothing
   * @param Object of the class SkillInformation
   * @return none
   */
  void updateSkill(SkillsInformation& info);


   /**This method uses createProject method of ProjectBC
   * @param Object of the class ProjectInfo
   * @return nothing.
   */
  void createProject(ProjectInfo& info);


  /**This method uses searchProject method of ProjectBC.
   * @param std::string
   * @return an object of the class ProjectInfo.
   */
<<<<<<< HEAD
   ProjectInfo searchProject(std::string id);
||||||| merged common ancestors
   ProjectInfo searchProject(std::string id)
   {
     m_projectBC.searchProject(id);
   }
=======
   ProjectInfo searchProject(std::string id)
   {
     return m_projectBC.searchProject(id);
   }
>>>>>>> fb32a921932aa23e0fd80e6be50911ebeb06b16d


   /**This method uses searchApprovedPoject method of ProjectBC.
   * @param Object of the class Project Info
   * @return a collection of ProjectInformation.
   */
<<<<<<< HEAD
   std::vector<ProjectInfo>  searchProjects(std::string dataFind);
||||||| merged common ancestors
   std::vector<ProjectInfo>  searchProjects(std::string dataFind)
   {
     m_projectBC.searchProjects(dataFind);
   }
=======
   std::vector<ProjectInfo>  searchProjects(std::string dataFind)
   {
     return m_projectBC.searchProjects(dataFind);
   }
>>>>>>> fb32a921932aa23e0fd80e6be50911ebeb06b16d



  /**this function updateProject method of ProjectBC.
   * Returns nothing
   * @param Object of the class ProjectInfo
   * @return none
   */
  void updateProject(ProjectInfo& info);
};

} //namespace bc

#endif //EmployeeBC.h
