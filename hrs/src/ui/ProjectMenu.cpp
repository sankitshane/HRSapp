#include <ui/ProjectMenu.h>
#include <ui/FormElement.h>
#include <ui/Form.h>
#include <ui/UITransform.h>
#include <common/Validator.h>
#include <ui/HelperForm.h>
#include <ui/Formatter.h>

#include <common/ProjectInfo.h>

#include <common/GeneralException.h>

#include <business/HRManager.h>

#include <curses.h>

namespace ui
{
  FormElement projForm[] =
    {
      FormElement("Client",							4, 3,20,		Validator::E, "Letters,Numbers, Spaces, _ -  . , / \\ + # ( ) only are allowed."),
      FormElement("Start Date",						6, 3,11,		Validator::date, "Date must be in DD-MON-YYYY format. eg. 11-SEP-2001"),
      FormElement("End Date",							8, 3,11,		Validator::date, "Date must be in DD-MON-YYYY format. eg. 11-SEP-2001", true),
      FormElement("Project Description",				10,3,40,		Validator::E, "Letters,Numbers, Spaces, _ - . , / \\ + # ( ) only are allowed."),
      FormElement("Project Name",						12,3,30,		Validator::E, "Letters,Numbers, Spaces, _ - () . , / \\ + # ( ) only are allowed."),
      FormElement("Project Status",					14,3,12,		Validator::status,"ACTIVE or INACTIVE"),


      FormElement("",	-1, -1, 0,		NULL)
    };

  bool ProjectMenu::create (void)
  {
    ui::Form form(projForm, "Create New Project");
    form.clearFields();

    if(!form.handleForm())
      return false;

    ProjectInfo info;

    ui::UITransform t;
    t.transformForm2Object(form, info);

    try {
      bc::HRManager::getInstance()->createProject(info);
    }
    catch(GeneralException* ge)
      {
		clear();
		mvprintw(15, 1, ge->getMessage().c_str());
		mvprintw(20, 3, "Press any key to continue..." );
		getch();
		delete ge;
      }

    return false;

  };

  bool ProjectMenu::update(void)
  {
    ui::HelperForm hfForm;
    std::string projCode = hfForm.getSimpleInput("Project Id");

    if( projCode.empty())
      return false;

    ProjectInfo info;

    try {
      info = bc::HRManager::getInstance()->searchProject(projCode);
    }
    catch(GeneralException* ge)
      {
		clear();
		mvprintw(15, 1, ge->getMessage().c_str());
		mvprintw(20, 3, "Press any key to continue..." );
		getch();
		delete ge;
		return false;
      }


    ui::Form form(projForm, "Update Existing Project");
    form.clearFields();

    ui::UITransform t;
    t.transformObject2Form(info, form);

    if(!form.handleForm())	// As simple as this!
      return false;

    t.transformForm2Object(form, info);

    try {
      bc::HRManager::getInstance()->updateProject(info);
    }
    catch(GeneralException* ge)
      {
		clear();
		mvprintw(15, 1, ge->getMessage().c_str());
		mvprintw(20, 3, "Press any key to continue..." );
		getch();
		delete ge;
      }

    return false;           //do not quit from the menu
  }

  bool ProjectMenu::search(void)
  {
    ui::HelperForm hfForm;
    std::string projectCode = hfForm.getSimpleInput("Project Id");

    if( projectCode.empty())
      return false;

    ProjectInfo info;

    try {
      info = bc::HRManager::getInstance()->searchProject(projectCode);
    }
    catch(GeneralException* ge)
      {
	mvprintw(15, 1, ge->getMessage().c_str());
	mvprintw(20, 3, "Press any key to continue..." );
	getch();
	delete ge;
	return false;
      }


    Formatter formatter;
    std::string out = formatter.getFormattedOutput(info);

    return false;                //do not quit from the menu
  }


  bool ProjectMenu::searchByName(void)
  {
    ui::HelperForm hfForm;
    std::string projectName = hfForm.getSimpleInput("Project Name");

    if( projectName.empty())
      return false;


    std::vector<ProjectInfo> infoList;

    try {
      infoList = bc::HRManager::getInstance()->searchProjects(projectName);
    }catch(GeneralException* ge)
      {
	mvprintw(15, 1, ge->getMessage().c_str());
	mvprintw(20, 3, "Press any key to continue..." );
	delete ge;
	getch();
	return false;
      }


    std::vector<ProjectInfo>::iterator it;


    Formatter fm;
    ProjectInfo info;
    std::string out;

    for( it=infoList.begin(); it != infoList.end(); it++)
      {
	info = *it;
	out = fm.getFormattedOutput(info);
      }


    return false;                //do not quit from the menu
  }

}
