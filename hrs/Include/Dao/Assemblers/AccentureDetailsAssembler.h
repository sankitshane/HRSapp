#ifndef ACCENTUREDETAILSASSEMBLER_H
#define ACCENTUREDETAILSASSEMBLER_H

/**@file EmpAccentureAssembler.h
* @brief: EmpAccentureAssembler
*
* <BR>NAME:EmpAccentureAssembler
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


/**@class EmpAccentureAssembler
* @brief: Declaration of EmpAccentureAssembler
* <PRE>The participants will be given the following Activity.
* 1. Write a class EmpAccentureAssembler, which will enforce encapsulation.
* 2. Declare a function that will get value from the class EmployeeInfo.
* 3. Declare a function that will get value from the database and set the value.
</PRE>
*/

#include<string>

#include<dbaccess/ODBCResultSet.h>

class AccentureDetail;///<Forward declaration...

class AccentureDetailsAssembler
{

  public:

 /**@fn assemble.
  * @brief Gets value from the class EmployeeInfo.
  * @param Reference to the object of the class EmployeeInfo and std::string.
  * @return std::string.
  */

	 static std::string assemble(AccentureDetail& employee,std::string query);


 /**@fn disAssemble.
  * @brief Gets values from the database and sets the values.
  * @param Pointer to the object of the class ODBCResultSet.
  * @return none.
  */
	  static AccentureDetail disAssemble(dbaccess::ODBCResultSet* rs);



};

#endif //EmpAccentureAssembler_H
