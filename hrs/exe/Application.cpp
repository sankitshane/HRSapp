#include "Application.h"

#include <ui/MenuHandler.h>
#include <ui/HRSMenu.h>
#include <ui/EmployeeMenu.h>
#include <ui/ProjectMenu.h>
#include <ui/SkillCategoryMenu.h>
#include <ui/SkillMenu.h>
#include <ui/MenuItem.h>

#include <curses.h>


ui::MenuItem employee[] = {

  ui::MenuItem( "Add Employee",			ui::EmployeeMenu::create,	NULL),
  ui::MenuItem( "Update Employee",		ui::EmployeeMenu::update,	NULL ) ,
  ui::MenuItem( "Search Employee",		ui::EmployeeMenu::search,	NULL ) ,
  ui::MenuItem( "Search Employee by Name",ui::EmployeeMenu::searchByName,	NULL ) ,
  ui::MenuItem( "Back",					ui::HRSMenu::back,				NULL),
  ui::MenuItem( "", NULL, NULL )

} ;


ui::MenuItem project[] = {

  ui::MenuItem( "Add Project",				ui::ProjectMenu::create,	NULL),
  ui::MenuItem( "Update Project",				ui::ProjectMenu::update,	NULL ) ,
  ui::MenuItem( "Search Project",				ui::ProjectMenu::search,	NULL ) ,
  ui::MenuItem( "Search Project by Name",		ui::ProjectMenu::searchByName,	NULL ) ,
  ui::MenuItem( "Back",						ui::HRSMenu::back,				NULL),
  ui::MenuItem( "", NULL, NULL )

} ;


ui::MenuItem skillCategory[] = {

  ui::MenuItem( "Add Skill Category",					ui::SkillCategoryMenu::create,	NULL),
  ui::MenuItem( "Update Skill Category",				ui::SkillCategoryMenu::update,	NULL ) ,
  ui::MenuItem( "Search Skill Category",				ui::SkillCategoryMenu::search,	NULL ) ,
  ui::MenuItem( "Search Skill Category by Name",		ui::SkillCategoryMenu::searchByName,	NULL ) ,
  ui::MenuItem( "Back",								ui::HRSMenu::back,					NULL),
  ui::MenuItem( "", NULL, NULL )

} ;

ui::MenuItem skill[] = {

  ui::MenuItem( "Add Skill",				ui::SkillMenu::create,	NULL),
  ui::MenuItem( "Update Skill",			ui::SkillMenu::update,	NULL ) ,
  ui::MenuItem( "Search Skill",			ui::SkillMenu::search,	NULL ) ,
  ui::MenuItem( "Search Skill by Name",	ui::SkillMenu::searchByName,	NULL ) ,
  ui::MenuItem( "Back",					ui::HRSMenu::back,				NULL),
  ui::MenuItem( "", NULL, NULL )

} ;

ui::MenuItem rootMenu[] = {

  ui::MenuItem( "Employee",			NULL, employee),
  ui::MenuItem( "Project",			NULL, project ) ,
  ui::MenuItem( "Skill Category",	NULL, skillCategory ) ,
  ui::MenuItem( "Skill",			NULL, skill ) ,
  ui::MenuItem( "Exit",				ui::HRSMenu::back, NULL),
  ui::MenuItem( "", NULL, NULL )

} ;

void Application::initCurses()
{
  WINDOW *scrn; // will point to curses window object
  scrn = initscr();
  raw();
  noecho(); // don’t echo keystrokes
  cbreak(); // keyboard input valid immediately, not after hit Enter
  keypad(stdscr, TRUE);	/* accept func keys */
}

void Application::endCurses()
{
  endwin();
}

int Application::run()
{
  initCurses();
  ui::MenuHandler handler( rootMenu, "=- Human Resource System -=" );
  bool res = handler.run();
  endCurses();
  return res;
}
