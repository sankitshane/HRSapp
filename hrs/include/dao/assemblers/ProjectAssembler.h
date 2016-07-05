#ifndef PROJECTASSEMBLER_H
#define PROJECTASSEMBLER_H

/**@file ProjectAssembler.h
* @brief: ProjectAssembler
*
* <BR>NAME:ProjectAssembler
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


/**@class ProjectAssembler
* @brief: Declaration of ProjectAssembler
* <PRE>The participants will be given the following Activity.
* 1. Write a class ProjectAssembler, which will enforce encapsulation.
* 2. Declare a function that will get value from the class ProjectInfo.
* 3. Declare a function that will get value from the database and set the value.
</PRE>
*/

#include<string>
#include<dbaccess/ODBCResultSet.h>

class ProjectInfo;


class ProjectAssembler
{
	
  public:

 /**@fn assemble.
  * @brief Gets value from the class ProjectInfo.
  * @param Reference to the object of the class ProjectInfo and std::string.
  * @return std::string.
  */
	  static std::string assemble(ProjectInfo& projects,std::string query);

 /**@fn disAssemble.
  * @brief Gets values from the database and sets the values.
  * @param Pointer to the object of the class ODBCResultSet.
  * @return none.
  */
				   
	  static ProjectInfo disAssemble(dbaccess::ODBCResultSet* rs);

	 
};

#endif //PROJECTASSEMBLER_H

