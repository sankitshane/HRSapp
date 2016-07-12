#ifndef SKILLBC_H
#define SKILLBC_H
#include <string>
#include <vector>

#include<dao/SKILLDAO.h>

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
* <BR>$Revision: $6/12/2005
*
* <BR>$Log:6/12/2005
*
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

namespace bc {
/**@class SkillBC
* @brief HRS Application  Declaration of SkillBC Class.
* <PRE>The participants will be give following Activity.
* 1. Write a class SkillBC, which will enforce encapsulation.
* 2. class SkillBC should have two private member variable.
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


  /**@fn ~SkillBC
   * @brief Destructor.
   * @param none
   * @return none
   */
  ~SkillBC(){};

   /**@fn createSkill
    * @brief it creats the skill
   * It create the project data
   * returns nothing.
   * @param a reference to the object of SkillInfo
   * @return nothing.
   */
  void createSkill(SkillInfo& info);


  /**@fn searchSkill
   * @brief it seerchs for a skill
   * @param std::string
   * @return an object of the class Skillinfo.
   */
   ProjectInfo searchSkill(std::string id);

  /**@fn searchSkills
   * @brief it seerchs for a collection of skills
   * @param std::string
   * @return a set of objects to the class Skillinfo.
   */
   std::vector<ProjectInfo> searchSkills(std::string dataFind);


  /**@fn updateSkill
   * @brief it updtes the skill
   * This function updates the information of the skill records in the database.
   * Returns nothing
   * @parama reference to the object of SkillInfo
   * @return none
   */
  void updateSkill(SkillInfo& info);
};

} //namespace bc
#endif //SkillBC.h
