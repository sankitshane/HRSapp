#ifndef FORMELEMENT_H
#define FORMELEMENT_H

/**@file FromElement.h
 *@brief Describes a single FormElement of the entire form
 *
 * <BR>NAME: FormElement
 * 
 * <BR>BASE CLASSES: No Parent
 * 
 * <BR>PURPOSE: This class puts up the necessary foundation for
 * a uniform UI with standard features
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
  class Form;

  typedef bool (*pFunc)(std::string value);		///< Function Pointer as a data-type
  
  
  /**@class FormElement
  * @brief Describes a single form field. Eg. Name:
  * <BR> 
  * <PRE> A single form field constitutes
  * a label, its value & a description along with
  * the co-ordinates where this field needs to be displayed
  * </PRE> 
  */
class FormElement
  {
    std::string m_label;		///< The label that appears to the left
    std::string m_value;		///< The default value / value to be entered by the user
    std::string m_desc;         ///< Error String / Description about the form element
	
    int m_x, m_y;				///< Co-Ordinates of this element
	
    int m_maxLength;			///< max of lengths of all labels; for alignment

    bool m_readonly;			///< whether user can type anything in this field
    
    bool m_canBeNull;			///< whether the field can be left empty

    pFunc m_validationFunc;	///< Function that is called for validation after input is provided

    friend class Form;

    FormElement();			//< Suppress the default one

  public:

   /**@fn FormElement Constructor
     * @brief Constructs the FormElement out of the arguments sent
     * @param label - string to be displayed to the left
	 * @param y -	  y co-ord 	
	 * @param x -	  x co-ord	
	 * @param length - Maximum chars that can be allowed to type
	 * @param func -	pointer to the validation function
	 * @param desc -	Error/Brief description about the form element
	 * @param canBeNull - whether the field can be left empty
     * @return none
     */      
	  FormElement(std::string label, int y, int x, int length, pFunc func, std::string desc = "", bool canBeNull=false);

  };

}
#endif //FORMELEMENT_H
