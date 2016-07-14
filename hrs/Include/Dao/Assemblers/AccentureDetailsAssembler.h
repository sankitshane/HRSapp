#ifndef ACCENTUREDETAILSASSEMBLER_H
#define ACCENTUREDETAILSASSEMBLER_H

/**@file AccentureDetailsAssembler.h
* @brief This is used to by DAOs to construct and break down SQL Queries.
*
* <BR>NAME:AccentureDetailsAssembler
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:
* 		1) Assemble: Take an incomplete SQL query, stuff it with data and return the valid Query.
* 		2) DisAssemble: To extract data from resultset and fill it in the object.
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

/**@class AccentureDetailsAssembler
* @brief: Declaration of AccentureDetailsAssembler
* <PRE>The participants will be given the following Activity.
* 1. Write a class AccentureDetailsAssembler, which will enforce encapsulation.
* 2. Declare a function that will get value from the class AccentureDetails.
* 3. Declare a function that will get value from the database and set the value.
</PRE>
*/
#include<string>

class AccentureDetails;///<Forward declaration...


#include<dbaccess/ODBCResultSet.h>


class AccentureDetailsAssembler
{
	
  public:

 /**@fn assemble.
  * @brief Gets value from the class Accenture Details.
  * @param Reference to the object of the class AccentureDetails from which data will be taken & Query will be constructed. 
  * @param std::string - the incomplete SQL Statement which needs to be completed and returned.
  * @return std::string - The completed SQL Statement after stuffing in the %s with the data from AccentureDetails.
  */
	  
	  static std::string assemble(AccentureDetails& accenture,std::string query);  


/**@fn disAssemble.
  * @brief Gets values from the database and sets them in a temporary object of AccentureDetails and returns it.
  * @param Pointer to an ODBCResultSet which contains the data to be disassembled.
  * @return An object of AccentureDetails after the disassembly is done.
  */
	  static AccentureDetails disAssemble(dbaccess::ODBCResultSet* rs);
 
};

#endif //ACCENTUREDETAILSASSEMBLER_H

