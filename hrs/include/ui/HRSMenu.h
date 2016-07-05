#ifndef HRSMENU_H
#define HRSMENU_H

/**@file HRSMenu.h
 *@brief Some common menu callbacks specific to HRS
 *
 * <BR>NAME: HRSMenu
 * 
 * <BR>BASE CLASSES: No Parent
 * 
 * <BR>PURPOSE: Some common menu callbacks specific to HRS
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


/**@namespace ui
   @brief Declares classes which will be used by the UI.
 */
namespace ui{

  /**@class HRSMenu
  * @brief Some common menu callbacks specific to HRS
  * <BR> 
  * <PRE> 
  * back() is the only identified common callback.
  * </PRE> 
  */
  class HRSMenu
  {
  public:

    /**@fn back(void)
     * @brief signals that previous menu be displayed
     * @param none
     * @return bool - always returns true
     */   
    static bool back(void);
  };

} //namespace ui
#endif //HRSMENU_H
