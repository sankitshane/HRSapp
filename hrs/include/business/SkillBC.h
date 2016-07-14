#ifndef SKILLBC_H
#define SKILLBC_H
#include <string>
#include <vector>



class SkillsInformation;
#include<dao/SkillDAO.h>


/**@file SkillBC.h
* @brief HRS Application : Declares the SkillBC Class.
*
* <BR>NAME:SkillBC
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:To do the effective communication bitween the HRManager class and the SkillDAO class
*
* <BR>AUTHOR:Vinoj.V.S
* <BR>
* <BR>$Revision: $7/12/2005
* 
* <BR>$Log:7/12/20005
* 
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

namespace bc {

/**@class SkillBC
* @brief HRS Application  Declaration of SkillBC Class.
* <PRE>The participants will be give following Activity.
* 1. Write a class SkillBC, which will enforce encapsulation.
* 2. class SkillBC should have three private member variable. 
* 3. Declare one constructors.
* 4. Declare Destructor.
*/

class SkillBC
{
	dao::SkillDAO m_skillDAO;
	
 public:

  /**@fn SkillBC
   * @brief Default Constructor.
   * This constructor will not take any argument.
   * It will initialize both the variable to ZERO.
   * @param none
   * @return none
   */
  SkillBC();

  
  /**@fn SkillBC
   * @brief Destructor.
   * @param none
   * @return none
   */ 
  ~SkillBC(){};

   /**It create the Skill data
   * returns nothing.
   * @param Object of the class SkillInformation
   * @return nothing.
   */
  void createSkill(SkillsInformation& info);
  
 
  /**returns the Information of the Skill.
   * @param std::string
   * @return an object of the class Skillinfo.
   */
   SkillsInformation searchSkill(std::string id);
  
  /**returns the collection of Information of the Skill.
   * @param Object of the class SkillInformation
   * @return a set of objects to the class Skillinfo.
   */
   std::vector<SkillsInformation> searchSkills(std::string dataFind);


  
  /**This function updates the information of the Skill records in the database.
   * Returns nothing
   * @param Object of the class SkillInformation
   * @return none
   */
  void updateSkill(SkillsInformation& info);
};

}	//namespace bc
#endif //SkillBC.h


