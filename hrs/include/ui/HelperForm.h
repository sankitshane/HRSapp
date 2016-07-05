#ifndef HELPERFORM_H
#define HELPERFORM_H


/**@file HelperForm.h
 *@brief Handles a form with single form field
 *
 * <BR>NAME: HelperForm
 * 
 * <BR>BASE CLASSES: No Parent
 * 
 * <BR>PURPOSE: Used to get input for Update & Search 
 * 
 *
 * <BR>AUTHOR: Arun Veeramany
 * <BR>$Revision: 9th Dec'05
 * 
 * <BR>$Log: 9th Dec'05
 * 
 * <BR>COPYRIGHT NOTICE:
 * <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
 */

#include <string>


/**@namespace ui
   @brief Declares core UI classes and those that depend on them
 */
namespace ui
{
/**@class HelperForm
  * @brief Handles a form with single form field
  * <BR> 
  * <PRE> 
  * Used to get input for Update & Search. This form is so
  * extensively used that it has to be put in a separate class of its own!
  * </PRE> 
  */
  class HelperForm
  {
  public:
    /**@fn getSimpleInput(std::string label)
     * @brief declares a form with single field;
     * @param label - a descriptive label against the form element
     * @return string - user entered text or empty if form was canceled
     */   
    std::string getSimpleInput(std::string label);
  };
}
#endif //HELPERFORM_H
