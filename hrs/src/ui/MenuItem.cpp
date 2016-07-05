#include<curses.h>
#include<iostream>
#include <ui/MenuItem.h>

namespace ui{

MenuItem::MenuItem( std::string label, pActionFunc pFunc, MenuItem* child) :
    m_label(label),
    m_actionFunc(pFunc),
    m_child(child)            
{
}

}
