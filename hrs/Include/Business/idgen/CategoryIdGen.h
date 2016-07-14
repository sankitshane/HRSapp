#ifndef CATEGORYIDGEN
#define CATEGORYIDGEN


/**@file CategoryIdGen.h
* @brief Declares the CategoryIdGen
*
* <BR>NAME:CategoryIdGen
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:To generate category id.
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
#include <string>

namespace idgen {

/**@class CategoryIdGen
* @brief  Declaration of CategoryIdGen.
* <PRE>The participants will be give following Activity.
* <PRE>This class shall do the following
* This class is the singleton.
* It will provide a method to get an instance of it.
* It will also provide a method to create a next id.
</PRE>
*/

class CategoryIdGen
{
	
	static CategoryIdGen* m_thisInstance; ///<Variable to reference to CategoryIdGenerator. 

 private:

 /**@fn CategoryIdGen.
  * @brief empty private Constructor.
  * This constructor will not take any argument.
  * Instance can be obtained through getInstance()
  * @param none
  * @return none
  */
  CategoryIdGen();

  public:

 /**@fn getInstance
  * @brief implements singleton CategoryIdGen class.
  * @param none
  * @return Pointer to CategoryIdGen.
  */
  static CategoryIdGen* getInstance();
 
  
 /**@fn getNextId
  * @brief gets the next system-generated id.
  * @param none.
  * @return string.
  */
  std::string getNextId();
};

} //namespace idgen
#endif //CATEGORYIDGEN
