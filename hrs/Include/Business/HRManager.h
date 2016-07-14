#ifndef HRMANAGER_H
#define HRMANAGER_H

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
   * It will initialize both the variable to ZERO.
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
  static HRManager* getInstance(void);

  
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
   EmployeeInfo searchEmployee(std::string empno);


     
  /**@fn searchEmployees
   * @brief This method uses searchEmployees method of EmployeeBC
   * @param Object of the class EmployeeInfo
   * @return the collection of employeeInfo .
   */
    std::vector<EmployeeInfo> searchEmployees(std::string info);


  /**@fn updateEmployee
   *@briefthis function updates the information of the employees.
   * Returns nothing
   * @param Object of the class EmployeeInfo
   * @return none
   */
  void updateEmployee(EmployeeInfo& info);


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
   SkillCategory searchCategory(std::string id);


   /**@fn searchCategories
    *@brief This method uses searchApprovedCategory method of SkillCategoryBC.
   * @param Object of the class SkillCategory
   * @return an collection of SkillCategory.
   */
   std::vector<SkillCategory>  searchCategories(std::string dataFind);


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
   SkillsInformation searchSkill(std::string id);


 /**This method uses searchSkills method of SkillCategoryBC.
   * @param Object of the class SkillInformation
   * @return an object of SkillInformation.
   */
   std::vector<SkillsInformation>  searchSkills(std::string name);
 

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
   ProjectInfo searchProject(std::string id);


   /**This method uses searchApprovedPoject method of ProjectBC.
   * @param Object of the class Project Info
   * @return a collection of ProjectInformation.
   */
   std::vector<ProjectInfo>  searchProjects(std::string dataFind);


   
  /**this function updateProject method of ProjectBC.
   * Returns nothing
   * @param Object of the class ProjectInfo
   * @return none
   */
  void updateProject(ProjectInfo& info);
};

} //namespace bc

#endif //EmployeeBC.h



