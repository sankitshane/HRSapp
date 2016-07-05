#ifndef EMPLOYEEASSEMBLER_H
#define EMPLOYEEASSEMBLER_H

/**@file EmployeeAssembler.h
* @brief: EmployeeAssembler
*
* <BR>NAME:EmployeeAssembler
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:To pass information between the UI and the DAO.
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


/**@class EmployeeAssembler
* @brief: Declaration of EmployeeAssembler
* <PRE>The participants will be given the following Activity.
* 1. Write a class EmployeeAssembler, which will enforce encapsulation.
* 2. Declare a function that will get value from the class EmployeeInfo.
* 3. Declare a function that will get value from the database and set the value.
</PRE>
*/

#include<string>

#include<dbaccess/ODBCResultSet.h>

class EmployeeInfo;///<Forward declaration...

class EmployeeAssembler
{
	
  public:

 /**@fn assemble.
  * @brief Gets value from the class EmployeeInfo.
  * @param Reference to the object of the class EmployeeInfo and std::string.
  * @return std::string.
  */

	 static std::string assemble(EmployeeInfo& employee,std::string query);

				   
 /**@fn disAssemble.
  * @brief Gets values from the database and sets the values.
  * @param Pointer to the object of the class ODBCResultSet.
  * @return none.
  */
	  static EmployeeInfo disAssemble(dbaccess::ODBCResultSet* rs);


	 
};

#endif //EMPLOYEEASSEMBLER_H

