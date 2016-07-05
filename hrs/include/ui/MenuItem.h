#ifndef MENUITEM_H
#define MENUITEM_H

/**@file MenuItem.h
 *@brief Declares a framework for Menu
 *
 * <BR>NAME: MenuItem
 * 
 * <BR>BASE CLASSES: No Parent
 * 
 * <BR>PURPOSE: This class puts up the necessary foundation for
 * a menu with standard features
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

	
typedef bool (*pActionFunc)(void);

class MenuItem
{
      MenuItem();				///< Suppress the default constructor
      
      std::string m_label;		///< A short label to be displayed for the item
      pActionFunc m_actionFunc;	///< Function POinter to be invoked when this item is selected
      MenuItem* m_child;		///< Sub-Menu
      
public:
   /**@fn MenuItem Constructor
     * @brief Constructs the MenuItem out of the arguments sent
     * @param label - string to be displayed to the left
	 * @param pFunc - Function POinter to be invoked when this item is selected
	 * @param child - sub-menu if any
     * @return none
     */      
	MenuItem( std::string label, pActionFunc pFunc, MenuItem* child);

	friend class MenuHandler;	///< MenuHandler needs to access private members of MenuItem
       
};
}
#endif //MENUITEM_H
