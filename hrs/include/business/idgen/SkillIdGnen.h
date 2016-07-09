#ifndef SkillIDGEN_H
#define SkillIDGEN_H

#include<string>

/**@file SkillIdGen.h
* @brief Declares the SkillIdGen
*
* <BR>NAME:SkillIdGen
*
* <BR>BASE CLASSES:None
*
* <BR>PURPOSE:To generate Skill id.
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

/**@class SkillIdGen
* @brief  Declaration of SkillIdGen
* <PRE>This class shall do the following
* This class is the singleton.
* It will provide a method to get an instance of it.
* It will also provide a method to create a next id.
</PRE>
*/

class SkillIdGen
{
	static SkillIdGen *m_thisInstance; ///<Variable to reference to CategoryIdGenerator.

 private:

 /**@fn SkillIdGen.
  * @brief empty private Constructor.
  * This constructor will not take any argument.
  * Instance can be obtained through getInstance()
  * @param none
  * @return none
  */
  SkillIdGen();

  public:

 /**@fn getInstance
  * @brief implements singleton SkillIdGen class.
  * @param none
  * @return Pointer to SkillIdGen.
  */
  static SkillIdGen* getInstance();


 /**@fn getNextId
  * @brief gets the next system-generated id.
  * @param none.
  * @return string.
  */
  std::string getNextId();
};

} //namespace idgen

#endif //SkillIDGEN
