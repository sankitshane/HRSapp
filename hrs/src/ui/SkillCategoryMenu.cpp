#include <ui/SkillCategoryMenu.h>
#include <ui/FormElement.h>
#include <ui/Form.h>
#include <ui/UITransform.h>
#include <common/Validator.h>
#include <ui/HelperForm.h>
#include <ui/Formatter.h>

#include <common/SkillCategory.h>

#include <common/GeneralException.h>

#include <business/HRManager.h>

#include <curses.h>

#ifdef ALOGGER
#include<logger/Logger.h>
#endif

namespace ui
{
  FormElement categoryForm[] =
    {
      FormElement("Category Description",				4,3,40,			 Validator::D, "Letters, Numbers, _ - () . only are allowed."),
      FormElement("Category Name",					6,3,30,			 Validator::D, "Letters, Numbers, _ - () . only are allowed."),
      FormElement("Category Status",					8,3,12,			 Validator::status, "ACTIVE or INACTIVE"),

      FormElement("",	-1, -1, 0,		NULL)
    };

  bool SkillCategoryMenu::create (void)
  {
    ui::Form form(categoryForm, "Create New Skill Category");		//
    form.clearFields();

    if(!(form.handleForm()))
      return false;

    SkillCategory info;
    ui::UITransform t;
    t.transformForm2Object(form, info);

    try {
      bc::HRManager::getInstance()->createCategory(info);
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

  bool SkillCategoryMenu::update(void)
  {
    ui::HelperForm hfForm;
    std::string catCode = hfForm.getSimpleInput("Category Id");

    if( catCode.empty())
      return false;

    SkillCategory info;

    try {
      info = bc::HRManager::getInstance()->searchCategory(catCode);
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


    ui::Form form(categoryForm, "Update Existing Skill Category");
    form.clearFields();

    ui::UITransform t;
    t.transformObject2Form(info, form);

    if(!form.handleForm())	// As simple as this!
      return false;

    t.transformForm2Object(form, info);

    try {
      bc::HRManager::getInstance()->updateCategory(info);
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

  bool SkillCategoryMenu::search(void)
  {
    ui::HelperForm hfForm;
    std::string catCode = hfForm.getSimpleInput("Category Id");

    if(catCode.empty())
      return false;

    SkillCategory info;

    try {
      info = bc::HRManager::getInstance()->searchCategory(catCode);
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


  bool SkillCategoryMenu::searchByName(void)
  {
    ui::HelperForm hfForm;
    std::string categoryName = hfForm.getSimpleInput("Category Name");

    if( categoryName.empty())
      return false;

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "About to start Business...");
#endif

    std::vector<SkillCategory> infoList;

    try {
      infoList = bc::HRManager::getInstance()->searchCategories(categoryName);
#ifdef ALOGGER
      logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "...Back from Business");
#endif
    }catch(GeneralException* ge)
      {
	mvprintw(15, 1, ge->getMessage().c_str());
	mvprintw(20, 3, "Press any key to continue..." );
	getch();
	delete ge;
	return false;
      }

    std::vector<SkillCategory>::iterator it;

    Formatter fm;
    SkillCategory info;
    std::string out;

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif

    for( it=infoList.begin(); it != infoList.end(); it++)
      {
	info = *it;
	out = fm.getFormattedOutput(info);
      }

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif


    return false;                //do not quit from the menu
  }

}
