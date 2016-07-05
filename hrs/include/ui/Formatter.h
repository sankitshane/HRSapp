#ifndef FORMATTER_H
#define FORMATTER_H

/**@file Formatter.h
* @brief Declares the Formatter class used by Search option
*
* <BR>NAME:Formatter
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:To create a single formatted string which acts as a report
*
* <BR>AUTHOR:Arun Veeramany
* <BR>
* <BR>$Revision: $12/14/2005
* 
* <BR>$Log:12/14/2005
* 
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

#include <string>

class EmployeeInfo;
class SkillsInformation;
class ProjectInfo;
class SkillCategory;

/**@namespace ui
   @brief Declares core UI classes and those that depend on them
 */
namespace ui
{
/**@class Formatter
  * @brief  Declares a set of methods to format the search results
  * <PRE> A single method getFormattedOutput is overloaded with
  * different value objects as arguments
  * </PRE>
  */
  class Formatter
  {
  public:
    /**@fn getFormattedOutput
     * @brief returns a formatted string ready to be displayed as a report
     * @param info - an EmployeeInfo object
     * @return string - the formatted output to be displayed
     */            
    std::string getFormattedOutput(EmployeeInfo& info);

    /**@fn getFormattedOutput
     * @brief returns a formatted string ready to be displayed as a report
     * @param info - a ProjectInfo object
     * @return string - the formatted output to be displayed
     */            
	std::string getFormattedOutput(ProjectInfo& info);

    /**@fn getFormattedOutput
     * @brief returns a formatted string ready to be displayed as a report
     * @param info - a SkillsInformation object
     * @return string - the formatted output to be displayed
     */            
	std::string getFormattedOutput(SkillsInformation& info);

    /**@fn getFormattedOutput
     * @brief returns a formatted string ready to be displayed as a report
     * @param info - a SkillCategory object
     * @return string - the formatted output to be displayed
     */            
	std::string getFormattedOutput(SkillCategory& info);
  };
}
#endif //FORMATTER_H
