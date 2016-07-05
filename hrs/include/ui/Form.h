#ifndef FORM_H
#define FORM_H

/**@file Form.h
 *@brief Declares the framework for the User Interface
 *
 * <BR>NAME: Form
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


#include<string>

/**@namespace ui
   @brief Declares core UI classes and those that depend on them
 */

namespace ui{

	class FormElement;

typedef bool (*pFunc)(std::string value);///<Make a type out of the validator function pointer

/**@class Form
  * @brief Declares a typical data entry form
  * <BR> 
  * <PRE> Given a list of form elements, this class 
  * takes the responsibility of displaying, taking input
  * and storing them.
  * </PRE> 
  */
class Form
{
    int m_maxWidth;              ///< Max of widths of the labels, inorder to align the display
    
    int m_count;                 ///< No. of Form Elements
    
    std::string m_cargo;         ///< All typed characters are buffered here before storing it
    
	Form() { }					///< Suppress the default one

	FormElement* m_elementList;	///< The list of form elements
	
	int m_currentElementIndex;  ///< Index of the Element which is being input
	
	std::string m_formTitle;     ///< Title to be displayed

    /**@fn displayElement(FormElement* element)
     * @brief Displays & Decorate a single form element
     * @param element - The element to be displayed
     * @return none
     */            
	void displayElement(FormElement* element);	

    /**@fn display()
     * @brief Display the entire form. Calls displayElement for each form element.
     * @param none
     * @return none
     */            
	void display();	
	
    /**@fn displayError(bool bErase = false)
     * @brief Display error description of current form element or erase the status bar.
     * @param bErase - optional - Whether to display the error or erase the status bar.
     * @return none
     */            
	void displayError(bool bErase = false);

    /**@fn getElement(std::string label)
     * @brief returns a pointer to a FormElement object corresponding to the label.
     * @param label - The text onto the left of the area where user enters data.
     * @return FormElement* - The Corresponding pointer to the FormElement object 
     */            
	FormElement* getElement(std::string label);

public:
       
    /**@fn getElement(std::string label)
     * @brief returns a pointer to a FormElement object corresponding to the label.
     * @param label - The text onto the left of the area where user enters data.
     * @return FormElement* - The Corresponding pointer to the FormElement object 
     */            
	Form(FormElement* elementList, std::string formTitle);

    ~Form();

    /**@fn setReadOnly(std::string label, bool newVal)
     * @brief sets whether data can be typed in the form element or not
     * @param label - The text onto the left of the area where user enters data.
	 * @param newVal - true / false
     * @return none
     */            
	void setReadOnly(std::string label, bool newVal);

    /**@fn setText(std::string label, std::string newVal)
     * @brief sets newVal in the FormElement object corresponding to label
     * @param label - The text onto the left of the area where user enters data.
	 * @param newVal - Text to be set for that FormElement object.
     * @return none
     */            
	void setText(std::string label, std::string newVal);
	
    /**@fn setText(int index, std::string newVal)
     * @brief sets newVal in the FormElement object corresponding to the array index
     * @param index - The index in the array of FormElement objects
	 * @param newVal - Text to be set for that FormElement object.
     * @return none
     */            
	void setText(int index, std::string newVal);

    /**@fn setFocus(std::string label)
     * @brief Sets the cursor position to that label 
	 * @param label - The label corresponding to which cursor has to be moved
     * @return none
     */            
	void setFocus(std::string label);

    /**@fn setFocus(int index)
     * @brief Sets the cursor position to the form element at the index
	 * @param index - The index in the array of FormElement objects
     * @return none
     */            
	void setFocus(int index);

    /**@fn getText(std::string label)
     * @brief returns the text in the m_value corresponding to label
	 * @param label - the label that identifies the form element
     * @return std::string - the corresponding value of label
     */            
	std::string getText(std::string label);

    /**@fn handleForm()
     * @brief manage the display, input and storage in a loop
	 * @param none
     * @return bool - whether the form was submitted or canceled
     */            
	bool handleForm();	// Do all the work here

    /**@fn clearFields
     * @brief clear off the m_value of all the form elements 
	 * @param none
     * @return none
     */            
    void clearFields();
};

} //namespace ui
#endif
