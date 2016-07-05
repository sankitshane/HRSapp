#include <ui/SkillMenu.h>
#include <ui/FormElement.h>
#include <ui/Form.h>
#include <ui/UITransform.h>
#include <common/Validator.h>
#include <ui/HelperForm.h>
#include <ui/Formatter.h>

#include <common/SkillsInformation.h>

#include <common/GeneralException.h>

#include <business/HRManager.h>

#include <curses.h>

#ifdef ALOGGER
#include<logger/Logger.h>
#endif


namespace ui
{
  FormElement skillForm[] =
    {
      FormElement("Category Id",						4, 3,20,		Validator::notNull),
      FormElement("Skill Description",				6, 3,40,		Validator::E, "Letters,Numbers,_ - () . , / \\ + # ( ) only are allowed."),
      FormElement("Skill Name",						8, 3,30,		Validator::E, "Letters,Numbers,_ - () . , / \\ + # ( ) only are allowed."),
      FormElement("Skill Status",						10,3,12,		Validator::status, "ACTIVE OR INACTIVE"),


      FormElement("",	-1, -1, 0,		NULL)
    };

  bool SkillMenu::create(void)
  {
    ui::Form form(skillForm, "Create New Skill");
    form.clearFields();

    if(!(form.handleForm()))
      return false;

    SkillsInformation info;

    ui::UITransform t;
    t.transformForm2Object(form, info);

    try {
      bc::HRManager::getInstance()->createSkill(info);
    }
    catch(GeneralException* ge)
      { 
		clear();
		mvprintw(15, 1, ge->getMessage().c_str());
		mvprintw(20, 3, "Press any key to continue..." );
		getch();
		delete ge;
      }


    return false;                //do not quit from the menu
  }

  bool SkillMenu::update(void)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

    ui::HelperForm hfForm;
    std::string skillCode = hfForm.getSimpleInput("Skill Id");

    if( skillCode.empty())
      return false;

    SkillsInformation info;

    try {
      info = bc::HRManager::getInstance()->searchSkill(skillCode);

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, info.getSkillId().c_str());
#endif

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


    ui::Form form(skillForm, "Update Existing Skill");
    form.clearFields();

    ui::UITransform t;
    t.transformObject2Form(info, form);

    if(!form.handleForm())	// As simple as this!
      return false;

    t.transformForm2Object(form, info);

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, skillCode.c_str());
#endif

    info.setSkillId(skillCode);

    try {
      bc::HRManager::getInstance()->updateSkill(info);
    }
    catch(GeneralException* ge)
      {
		clear();
		mvprintw(15, 1, ge->getMessage().c_str());
		mvprintw(20, 3, "Press any key to continue..." );
		getch();
		delete ge;
      }

    return false;                //do not quit from the menu
  }

  bool SkillMenu::search(void)
  {
    ui::HelperForm hfForm;
    std::string skillCode = hfForm.getSimpleInput("Skill Id");

    if( skillCode.empty())
      return false;

    SkillsInformation  info;

    try {
      info = bc::HRManager::getInstance()->searchSkill(skillCode);
    }
    catch(GeneralException* ge)
      {
	mvprintw(15, 1, ge->getMessage().c_str());
	mvprintw(20, 3, "Press any key to continue..." );
	getch();
	delete ge;
	return false;
      }

    Formatter fm;
    fm.getFormattedOutput(info);

    return false;                //do not quit from the menu
  }


  bool SkillMenu::searchByName(void)
  {
    ui::HelperForm hfForm;
    std::string skillName = hfForm.getSimpleInput("Skill Name");

    if( skillName.empty())
      return false;


    std::vector<SkillsInformation> infoList;

    try {
      infoList = bc::HRManager::getInstance()->searchSkills(skillName);
    }catch(GeneralException* ge)
      {
	mvprintw(15, 1, ge->getMessage().c_str());
	mvprintw(20, 3, "Press any key to continue..." );
	getch();
	return false;
      }


    std::vector<SkillsInformation>::iterator it;


    Formatter fm;
    SkillsInformation info;
    std::string out;

    for( it=infoList.begin(); it != infoList.end(); it++)
      {
	info = *it;
	out = fm.getFormattedOutput(info);
      }

    return false;                //do not quit from the menu
  }

}
