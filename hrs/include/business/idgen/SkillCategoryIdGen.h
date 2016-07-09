#ifndef SkillCategoryIDGEN_H
#define SkillCategoryIDGEN_H

#include<string>

/**@file SkillCategoryIdGen.h
* @brief Declares the SkillCategoryIdGen
*
* <BR>NAME:SkillCategoryIdGen
*
* <BR>BASE CLASSES:None
*
* <BR>PURPOSE:To generate SkillCategory id.
*
* <BR>AUTHOR:Smitha Manjunath
* <BR>
* <BR>$Revision: $12/14/2005
*
* <BR>$Log:12/14/2005
*
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

namespace idgen {

/**@class SkillCategoryIdGen
* @brief  Declaration of SkillCategoryIdGen
* <PRE>This class shall do the following
* This class is the singleton.
* It will provide a method to get an instance of it.
* It will also provide a method to create a next id.
</PRE>
*/

class SkillCategoryIdGen
{
	static SkillCategoryIdGen *m_thisInstance; ///<Variable to reference to CategoryIdGenerator.

 private:

 /**@fn SkillCategoryIdGen.
  * @brief empty private Constructor.
  * This constructor will not take any argument.
  * Instance can be obtained through getInstance()
  * @param none
  * @return none
  */
  SkillCategoryIdGen();

  public:

 /**@fn getInstance
  * @brief implements singleton SkillCategoryIdGen class.
  * @param none
  * @return Pointer to SkillCategoryIdGen.
  */
  static SkillCategoryIdGen* getInstance();


 /**@fn getNextId
  * @brief gets the next system-generated id.
  * @param none.
  * @return string.
  */
  std::string getNextId();
};

} //namespace idgen

#endif //SkillCategoryIDGEN
