#ifndef SKILLCATEGORYBC_H
#define SKILLCATEGORYBC_H

#include <string>
#include <vector>


class SkillCategory;
#include<dao/SkillCategoryDAO.h>


/**@file SkillCategoryBC.h
* @brief HRS Application : Declares the SkillCategoryBC Class.
*
* <BR>NAME:SkillCategoryBC
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:To do the effective communication bitween the HRManager class and the SkillCategoryDAO
*
* <BR>AUTHOR:Vinoj.V.S
* <BR>
* <BR>$Revision: $8/12/2005
* 
* <BR>$Log:8/12/2005
* 
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/
namespace bc {
/**@class SkillCategoryBC
* @brief HRS Application  Declaration of SkillCategoryBC Class.
* <PRE>The participants will be give following Activity.
* 1. Write a class SkillCategoryBC, which will enforce encapsulation.
* 2. class SkillCategoryBC should have two private member variable. 
* 3. Declare one constructors.
* 4. Declare Destructor.
*/

class SkillCategoryBC
{
 private: 
	 dao::SkillCategoryDAO m_catDAO; ///<Reference to the SkillCategoryCategoryDAO
	 
 public:

  /**@fn SkillCategoryBC
   * @brief Default Constructor.
   * This constructor will not take any argument.
   * It will initialize both the variable to ZERO.
   * @param none
   * @return none
   */
  SkillCategoryBC();

  
  /**@fn SkillCategoryBC
   * @brief Destructor.
   * @param none
   * @return none
   */ 
  ~SkillCategoryBC(){};



   /**It create the SkillCategory data
   * returns nothing.
   * @param object of the class SkillCategory
   * @return nothing.
   */
  void createCategory(SkillCategory& info);
  
 
  /**returns the Information of the SkillCategory.
   * @param std::string
   * @return an object of the class SkillCategory.
   */
   SkillCategory searchSkillCategory(std::string id);
  
  /**returns the collection of Information of the SkillCategory.
   * @param object of the class SkillCategory.
   * @return a set of objects to the class SkillCategory.
   */
   std::vector<SkillCategory> searchSkillCategories(std::string dataFind);


  /**This function updates the information of the SkillCategory records in the database.
   * Returns nothing
   * @param object of the class SkillCategory.
   * @return none
   */
  void updateCategory(SkillCategory& info);
};

} //namespace bc
#endif //SkillCategoryBC.h


