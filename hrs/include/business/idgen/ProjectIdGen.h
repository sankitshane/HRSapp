#ifndef PROJECTIDGEN_H
#define PROJECTIDGEN_H

#include<string>

/**@file ProjectIdGen.h
* @brief Declares the ProjectIdGen
*
* <BR>NAME:ProjectIdGen
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:To generate project id.
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
	
/**@class ProjectIdGen
* @brief  Declaration of ProjectIdGen
* <PRE>This class shall do the following
* This class is the singleton.
* It will provide a method to get an instance of it.
* It will also provide a method to create a next id.
</PRE>
*/

class ProjectIdGen
{
	static ProjectIdGen *m_thisInstance; ///<Variable to reference to CategoryIdGenerator. 

 private:

 /**@fn ProjectIdGen.
  * @brief empty private Constructor.
  * This constructor will not take any argument.
  * Instance can be obtained through getInstance()
  * @param none
  * @return none
  */
  ProjectIdGen();

  public:

 /**@fn getInstance
  * @brief implements singleton ProjectIdGen class.
  * @param none
  * @return Pointer to ProjectIdGen.
  */
  static ProjectIdGen* getInstance();
 
  
 /**@fn getNextId
  * @brief gets the next system-generated id.
  * @param none.
  * @return string.
  */
  std::string getNextId();
};

} //namespace idgen 

#endif //PROJECTIDGEN
