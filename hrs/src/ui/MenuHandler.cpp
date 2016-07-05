#include<curses.h>
#include<iostream>
#include <ui/MenuHandler.h>
#include <ui/MenuItem.h>

namespace ui{

MenuHandler::MenuHandler(MenuItem* rootMenu, std::string title):
                                   m_rootMenu(rootMenu),
                                   m_title(title)
{
}

int MenuHandler::display(MenuItem* menu)
{
     char buf[80];
     
     clear();

     int y,x;
     
     getmaxyx(stdscr, y, x);

     attron(A_BOLD);
     mvprintw( 0, (x - m_title.length())/2   ,  m_title.c_str());
     attroff(A_BOLD);

     int iCtr = 0;
     while( ! menu[iCtr].m_label.empty())
     {
        sprintf(buf, "%d. %s", iCtr+1 , menu[iCtr].m_label.c_str());
        mvprintw( (iCtr+1) * 2, 10,  buf);
        iCtr++;
     }

     attron(A_BOLD);
     mvprintw( (iCtr+1) * 2, 10,  "Choose an option: ");
     attroff(A_BOLD);
     
     refresh();
 
     return iCtr;  
}

bool MenuHandler::run()
{
     return run(m_rootMenu);
}

bool MenuHandler::run(MenuItem* menu)
{
     MenuItem* current = &menu[0];
     int iOption, iCount;
     bool bTimeToQuit = false;
     
     while(! bTimeToQuit)
     {
         iCount = display(current);
         iOption = getch() - 48;
         
         if( iOption + 48 == 27)     //Escape ?
             return false;
         
         if( iOption < 1 || iOption > iCount)        // Invalid choice
             continue;
         
         if( menu[iOption-1].m_actionFunc != NULL) 
             bTimeToQuit = (*menu[iOption-1].m_actionFunc)();   // End of tree, time for action
         else
             bTimeToQuit = run(menu[iOption-1].m_child);        // Not the leaf, recurse further
     }   
     
     return false;
}

} //namespace ui
