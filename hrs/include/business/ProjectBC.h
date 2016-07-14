#ifndef PROJECTBC_H
#define PROJECTBC_H
#include <string>
#include <vector>

class ProjectInfo;

#include<dao/ProjectDAO.h>

/**@file ProjectBC.h
* @brief HRS Application : Declares the ProjectBC Class.
*
* <BR>NAME:ProjectBC
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:To do the effective communication bitween the HRManager class and the ProjectDAO class
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

namespace bc {
/**@class ProjectBC
* @brief HRS Application  Declaration of ProjectBC Class.
* <PRE>The participants will be give following Activity.
* 1. Write a class ProjectBC, which will enforce encapsulation.
* 2. class ProjectBC should have two private member variable. 
* 3. Declare one constructors.
* 4. Declare Destructor.
*/

class ProjectBC
{
	dao::ProjectDAO m_projectDAO;

 public:

  /**@fn ProjectBC
   * @brief Default Constructor.
   * This constructor will not take any argument.
   * It will initialize both the variable to ZERO.
   * @param none
   * @return none
   */
  ProjectBC();

  
  /**@fn ~ProjectBC
   * @brief Destructor.
   * @param none
   * @return none
   */ 
  ~ProjectBC(){};

   /**@fn createProject
    * @brief it creats the project 
   * It create the project data
   * returns nothing.
   * @param a reference to the object of ProjectInfo
   * @return nothing.
   */
  void createProject(ProjectInfo& info);
  
 
  /**@fn searchProject
   * @brief it seerchs for a project 
   * @param std::string
   * @return an object of the class Projectinfo.
   */
   ProjectInfo searchProject(std::string id);
  
  /**@fn searchProjects
   * @brief it seerchs for a collection of projects 
   * @param std::string
   * @return a set of objects to the class Projectinfo.
   */
   std::vector<ProjectInfo> searchProjects(std::string dataFind);


  /**@fn updateProject
   * @brief it updtes the project
   * This function updates the information of the project records in the database.
   * Returns nothing
   * @parama reference to the object of ProjectInfo
   * @return none
   */
  void updateProject(ProjectInfo& info);
};

} //namespace bc
#endif //ProjectBC.h


