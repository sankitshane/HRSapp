#ifndef EMPIDGEN_H
#define EMPIDGEN_H

#include<string>

/**@file EmpIdGen.h
* @brief Declares the EmpIdGen
*
* <BR>NAME:EmpIdGen
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:To generate employee id.
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

/**@namespace idgen
 *@brief All the classes related to IDGenerator is defined in this namespace.
 */

namespace idgen {
	
/**@class EmpIdGen
* @brief  Declaration of EmpIdGen
* <PRE>This class shall do the following
* This class is the singleton.
* It will provide a method to get an instance of it.
* It will also provide a method to create a next id.
</PRE>
*/

class EmpIdGen
{
	static EmpIdGen *m_thisInstance; ///<Variable to reference to EmpIdGen. 

 private:

 /**@fn EmpIdGen.
  * @brief empty private Constructor.
  * This constructor will not take any argument.
  * Instance can be obtained through getInstance()
  * @param none
  * @return none
  */
  EmpIdGen();

  public:

 /**@fn getInstance
  * @brief implements singleton EmplIdGen class.
  * @param none
  * @return Pointer to EmpIdGen.
  */
  static EmpIdGen* getInstance();
 
  
 /**@fn getNextId
  * @brief gets the next system-generated id.
  * @param none.
  * @return string.
  */
  std::string getNextId();
};

}	//namespace idgen 
#endif //EMPIDGEN_H
