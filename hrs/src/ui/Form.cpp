#include <ui/Form.h>
#include <ui/FormElement.h>

#include<iostream>
#include<string>
#include<ncurses.h>
#include<ctype.h>
#include<sstream>

#ifdef ALOGGER
       #include<logger/Logger.h>
#endif

/**@file Form.cpp
* @brief HRS Application :Defines Form class.
*
* <BR>NAME:Form
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:It is the part of the UI and taks the parameters from the user
*
* <BR>AUTHOR:Arun Veeramany
* <BR>
* <BR>$Revision: $17/12/2005
* 
* <BR>$Log:17/12/2005
* 
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

/**@class Form
* @brief HRS Application  Definition of Form Class.
* <PRE>The participants will be give following Activity.
* 1. Write a class Form, which will enforce encapsulation.
* 2. Declare one constructors which is private.
*/


namespace ui {
/**
 * Form constructor
 * @author Arun Veeramany
 * @author last modified by: $Author: 
 * @version 1.0
 */



Form::Form(FormElement* elementList, std::string formTitle)
{ 
    m_elementList = elementList;  
    m_formTitle = formTitle;
    
   //Determine the field of max length
    int ctr = 0;
	FormElement* element = &m_elementList[ctr]; ///< The first field
    m_maxWidth = element->m_label.length();
	for(; !element->m_label.empty()  ; element = &m_elementList[ctr++] )
          if( element->m_label.length() > m_maxWidth )
              m_maxWidth = element->m_label.length();
              
    m_count = ctr;
}


Form::~Form()
{
}
	

   /**returns the Nothing
   * @param pointer to the object of  FormElement
   * @return Nothing
   */
void Form::displayElement(FormElement* element)
{
	attron(A_BOLD);
    mvprintw(element->m_y, element->m_x, element->m_label.c_str());    // Label
	attroff(A_BOLD);
	
	attron(A_REVERSE);

	char spaces[ element->m_maxLength + 1];                            // Value place holder
	sprintf( spaces, "%*s", element->m_maxLength, " ");
    
	mvprintw(element->m_y, element->m_x + m_maxWidth + 1, spaces );
	
	if( !element->m_value.empty() )                                    // For updation ?
	    mvprintw(element->m_y, element->m_x + m_maxWidth + 1,  element->m_value.c_str());

	attroff(A_REVERSE);
	
    if(!element->m_canBeNull )
    	mvprintw(element->m_y, element->m_x + m_maxWidth + element->m_maxLength + 1, "*" );
    
	refresh();
}


/**returns Nothing.
   * @param Nothing
   * @return Nothing
   */

void Form::display(void)
{
	int ctr = 0;
	FormElement* element = &m_elementList[ctr]; ///< The first field
	
    clear();
	
    //center the form title 
    int y, x;
    getmaxyx(stdscr, y, x);
    attron(A_BOLD);
	mvprintw(1, ( x - m_formTitle.length() ) /2 , m_formTitle.c_str() );
    attroff(A_BOLD);	
	
    
    ctr = 0;
    element = &m_elementList[ctr]; ///< The first field
	///< Iterate through each form field, validate, store and then exit
	for(; !element->m_label.empty()  ; element = &m_elementList[ctr++] )
			displayElement(element);
			

    element = &m_elementList[ctr-2]; ///< The first field
    
    attron(A_BOLD);
	mvprintw(element->m_y + 3, 10, "Ctrl+A : Submit");
	mvprintw(element->m_y + 4, 10, "Esc    : Cancel");
    attroff(A_BOLD);	
}

void Form::displayError(bool bErase)
{
    FormElement* feElt = &m_elementList[m_count-2];
 
    int y, x;
    
    getyx(stdscr, y, x);
    
    char buf[81];
    sprintf(buf, "%*s", 65, " ");

    attron(A_REVERSE);
    mvprintw(feElt->m_y + 6, 2,  buf);        

    if(!bErase)
    {
    	mvprintw(feElt->m_y + 6, 2, m_elementList[m_currentElementIndex].m_desc.c_str() );
    }
    
    attroff(A_REVERSE);
    
    mvprintw(y, x, "");
}

bool Form::handleForm()
{
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "Entry");
#endif	

 display();
 
 setFocus( 0  );
 m_currentElementIndex = 0;

 bool caseHandled = false, vStatus = true;
 int y,x, ctr=0;
 bool bValidationResult = true;

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "About to start the loop...");
#endif	

  displayError(true);

 int ch;
 while( (ch=getch()) != 27 )     //Not until Esc is pressed
 {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "While loop");
#endif	

 FormElement* m_currentElement = &m_elementList[m_currentElementIndex];
 caseHandled = false;
 
 displayError(true);
 
 switch(ch)
 {
  case '\t':         //Tab Key
  case KEY_DOWN:
  case KEY_UP:
  case 10:    //Enter Key

        caseHandled = true;     
        
        if( ! (m_currentElement->m_canBeNull && m_cargo.empty()) )
        {
                                                  // and update cargo if necessary   
            vStatus = (*m_currentElement->m_validationFunc)(m_cargo);  //Validate the data
            
            if(vStatus == false)           // Validation failed
            {
             displayError();
             break;
            }
        }

        setText(m_currentElementIndex, m_cargo);   //Validation Successful, transfer cargo to the field value
        
        if( ch == KEY_UP )
        {
            if( m_currentElementIndex != 0)
                --m_currentElementIndex;                                        //     then goto the next one
        }
        else
        {
            if( ! m_elementList[m_currentElementIndex + 1].m_label.empty() )    // Not the last field?
                ++m_currentElementIndex;                                        //     then goto the next one
            else                                                                // else
                m_currentElementIndex = 0;                                      //     goto the first field   
        }
        
        
        m_cargo = "";                                                       // Nullify cargo       
        setFocus(m_currentElementIndex);                                    // set focus to the next field
        break;                                                                            

   case 1:       /* user pressed Ctrl+A ...  validate overall & save the form*/
        caseHandled = true;                                            
   
        if( ! (m_currentElement->m_canBeNull && m_cargo.empty()) )
        {
            vStatus = (*m_currentElement->m_validationFunc)(m_cargo);  //Validate the data
            if(vStatus == false)
            {
                       displayError();
                       break;
            }
        }
        
        setText(m_currentElementIndex, m_cargo);   //Validation Successful, transfer cargo to the field value
   
        ctr = 0;
        FormElement* element = &m_elementList[ctr]; ///< The first field
        bValidationResult = true;
    	///< Iterate through each form field, validate
    	for(; !element->m_label.empty()  ; element = &m_elementList[ctr] )
    	{
            if( ! (element->m_canBeNull && element->m_value.empty()) )
            {
                  bValidationResult = (*element->m_validationFunc)(element->m_value);
                  if(bValidationResult == false)
                  {
                        setFocus(ctr);          //There;s atleast one field unvalidated. 
                        displayError();               
                        break;                  //Set focus to that field.
                  }
            }
            ctr++;
        }
                                           
         if(bValidationResult == true) 
           return true;
         break;
  
  case KEY_BACKSPACE:                     //backspace
  
      if( m_cargo.length() == 0)         // Nothing to delete ? 
          break;
      
      getyx(stdscr, y, x);               // delete the prev char
      attron(A_REVERSE);
      mvprintw(y, x-1, " ");
      mvprintw(y, x-1, "");
      attroff(A_REVERSE);
      
      m_cargo = m_cargo.substr(0, m_cargo.length()-1 );     //reflect that in memory
      caseHandled = true;
      break;
  }
        
  if( !caseHandled && isprint(ch) )                         //not a special char, lets print it
  {
      if( m_cargo.length() < m_currentElement->m_maxLength)           
      {
        addch(ch | A_REVERSE);
        m_cargo += ch;
      }
  }
 }               //End of the while loop

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "Quitting ...");
#endif	
 return false;
}

   /**returns pointer to the object of FormElement
   * @param std::string
   * @return pointer to the object of FormElement
   */

FormElement* Form::getElement(std::string label)
{
	int ctr = 0;

	FormElement* element = &m_elementList[0]; // The first field
	
	///< Iterate through each form field until we reach label
	for(; !element->m_label.empty()  ; element = &m_elementList[ctr++] )
		if( element->m_label == label)
			return element;

	return NULL;
}



  /**returns Nothing
   * @param one std::string and a bool type data
   * @return Nothing
   */
void Form::setReadOnly(std::string label, bool newVal)
{

	FormElement* element = getElement(label);
	
	if( element != NULL)
			element->m_readonly = true;

}


 /**Set Focus to a form field
   * @param the form field to be focussed
   * @returns Nothing
   */

void Form::setFocus(std::string label)
{
	FormElement* element = getElement(label);
	m_cargo = element->m_value;
	
	if( element != NULL)
        mvprintw( element->m_y, element->m_x + m_maxWidth + m_cargo.length() + 1 , "" );
}

void Form::setFocus(int index)
{
	FormElement* element = &m_elementList[index];
	m_cargo = element->m_value;
    mvprintw( element->m_y, element->m_x + m_maxWidth + m_cargo.length() + 1, "" );
    m_currentElementIndex = index;
}


 /**returns Nothing
   * @param two variable of the type std::string
   * @returns Nothing
   */

void Form::setText(std::string label, std::string newVal)
{
	FormElement* element = getElement(label);
	
	if( element != NULL)
			element->m_value = newVal;
}

void Form::setText(int index, std::string newVal)
{
	FormElement* element = &m_elementList[index];
	element->m_value = newVal;
}


   /**returns std::string
   * @param std::string
   * @return std::string
   */

std::string Form::getText(std::string label)
{
	FormElement* element = getElement(label);
	
	if( element != NULL)
			return element->m_value;

	return "";
}


void Form::clearFields()
{
	int ctr = 0;
	FormElement* element = &m_elementList[0]; // The first field
	
	///< Iterate through each form field & clear it
	for(; !element->m_label.empty()  ; element = &m_elementList[ctr++] )
	      element->m_value = "";
}

} // namespace ui
