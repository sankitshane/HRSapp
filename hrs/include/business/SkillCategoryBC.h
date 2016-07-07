#ifndef SkillCategoryBC_H
#define SkillCategoryBC_H
#include <string>
#include <vector>

class SkillCategoryInfo;

#include<dao/SkillCategoryDAO.h>

/**@file SkillCategoryBC.h
* @brief HRS Application : Declares the SkillCategoryBC Class.
*
* <BR>NAME:SkillCategoryBC
*
* <BR>BASE CLASSES:None
*
* <BR>PURPOSE:To do the effective communication bitween the HRManager class and the SkillCategoryDAO class
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
	dao::SkillCategoryDAO m_SkillCategoryDAO;

 public:

  /**@fn SkillCategoryBC
   * @brief Default Constructor.
   * This constructor will not take any argument.
   * It will initialize both the variable to ZERO.
   * @param none
   * @return none
   */
  SkillCategoryBC();


  /**@fn ~SkillCategoryBC
   * @brief Destructor.
   * @param none
   * @return none
   */
  ~SkillCategoryBC(){};

   /**@fn createSkillCategory
    * @brief it creats the SkillCategory
   * It create the SkillCategory data
   * returns nothing.
   * @param a reference to the object of SkillCategoryInfo
   * @return nothing.
   */
  void createCategory(SkillCategoryInfo& info);


  /**@fn searchSkillCategory
   * @brief it seerchs for a SkillCategory
   * @param std::string
   * @return an object of the class SkillCategoryinfo.
   */
   SkillCategoryInfo searchCategory(std::string id);

  /**@fn searchSkillCategorys
   * @brief it seerchs for a collection of SkillCategorys
   * @param std::string
   * @return a set of objects to the class SkillCategoryinfo.
   */
   std::vector<SkillCategoryInfo> searchCategorys(std::string dataFind);


  /**@fn updateSkillCategory
   * @brief it updtes the SkillCategory
   * This function updates the information of the SkillCategory records in the database.
   * Returns nothing
   * @parama reference to the object of SkillCategoryInfo
   * @return none
   */
  void updateCategory(SkillCategoryInfo& info);
};

} //namespace bc
#endif //SkillCategoryBC.h
