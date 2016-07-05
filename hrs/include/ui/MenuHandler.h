#ifndef MENUHANDLER_H
#define MENUHANDLER_H

/**@file MenuHandler.h
 *@brief Handles the menu display, input and action to be performed
 *
 * <BR>NAME: MenuHandler
 * 
 * <BR>BASE CLASSES: No Parent
 * 
 * <BR>PURPOSE: Takes the menu as an array and handles it
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
namespace ui{

class MenuItem;		
	
typedef bool (*pActionFunc)(void);	

class MenuHandler
{
      MenuItem *m_rootMenu;			///< The root menu 

	/**@class display(MenuItem* menu)
	* @brief internally called by MenuHandler to display
	* <BR> 
	* <PRE> 
	* @param menu - the array containing the menu items to be displayed
	* @return int - the number of elements in the array
	* </PRE> 
	*/
	  int display(MenuItem* menu);	

	/**@class run(MenuItem* menu)
	* @brief display menu, wait for input and act !
	* <BR> 
	* <PRE> 
	* @param menu - the array containing the menu items 
	* @return bool - whether to quit the menu or go to the previous menu.
	* </PRE> 
	*/
	  bool run(MenuItem* menu);		

	  std::string m_title;			///< title for the menu

public:

 /**@class Constructor MenuHandler
  * @brief Constructs the menu out of that array
  * <BR> 
  * <PRE> 
  * @param rootMenu - the top most in the hierarchy
  * @param title - title for the menu
  * @return none
  * </PRE> 
  */
  MenuHandler(MenuItem* rootMenu, std::string title);

 /**@class run()
  * @brief Constructs the menu out of that array
  * <BR> 
  * <PRE> 
  * @param none
  * @return bool - whether go to the previous menu or exit the menu
  * </PRE> 
  */
  bool run();					///< call the other run with root menu
};
} //namespace ui

#endif //MENUHANDLER_H
