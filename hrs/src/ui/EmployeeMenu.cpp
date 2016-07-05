#include <ui/EmployeeMenu.h>
#include <ui/FormElement.h>
#include <ui/Form.h>
#include <ui/UITransform.h>
#include <common/Validator.h>
#include <ui/HelperForm.h>
#include <ui/Formatter.h>

#include <common/EmployeeInfo.h>
#include <common/AccentureDetails.h>

#include <common/GeneralException.h>

#include <business/HRManager.h>

#include <curses.h>

namespace ui
{
  FormElement empForm[] =
    {
      FormElement("First Name",	                   4, 3,20,		   Validator::D, "Letters, Numbers, Spaces, _ -  . only are allowed."),
      FormElement("Last Name",			           5, 3,20,        Validator::D, "Letters, Numbers, Spaces, _ - . only are allowed."),
      FormElement("Middle Name",			           6, 3,20,    Validator::D, "Letters, Numbers, Spaces, _ - . only are allowed."),
      FormElement("Gender(M/F)",				       7, 3, 1,    Validator::gender,"M or F"),
      FormElement("Date of Birth (DD-MON-YYYY)",	   9, 3,11,    Validator::date, "Date must be in DD-MON-YYYY format. eg. 11-SEP-2001"),
      FormElement("Civil Status",			           10,3,12,    Validator::civilStatus, "SINGLE, MARRIED, DIVORCED, WIDOW", true),
      FormElement("Citizenship",			           11, 3,10,   Validator::D, "Letters, Numbers, Spaces, _ - . only are allowed.", true),
      FormElement("City",		        	           12,3,20,    Validator::D, "Letters, Numbers, Spaces, _ - . only are allowed.", true),
      FormElement("Country",				           13,3,20,    Validator::D, "Letters, Numbers, Spaces, _ -  . only are allowed.", true),
      FormElement("Home Phone",			           14,3,15,        Validator::B, "Numbers, Spaces, Dashes only are allowed.", true),
      FormElement("Mobile Number",			       15,3,15,        Validator::B, "Numbers, Spaces, Dashes only are allowed.", true),
      FormElement("Educational Attainment",		   16,3,20,        Validator::E, "Letters,Numbers, Spaces, _ - . , / \\ + # ( ) only are allowed."),
      FormElement("Street Address 1",				   17,3,40,    Validator::E,"Letters,Numbers, Spaces, _ - . , / \\ + # ( ) only are allowed."),
      FormElement("Street Address 2",				   18,3,40,    Validator::E,"Letters,Numbers, Spaces, _ - . , / \\ + # ( ) only are allowed.", true),
      FormElement("State",						   19,3,20,        Validator::D, "Letters, Numbers, Spaces, _ - . only are allowed.", true),
      FormElement("Recognition",				   20,3,20,        Validator::C, "Letters and Numbers only are allowed.", true),
      FormElement("Enterprise Address",			   21,3,40,        Validator::F, "Letters, Numbers, Spaces, @ _ - . only are allowed."),
      FormElement("Enterprise Id",		    	   22,3,30,        Validator::D, "Letters, Numbers, Spaces, _ - . only are allowed."),
      FormElement("GMU",			               23,3, 5,        Validator::C, "Letters and Numbers only are allowed."),
      FormElement("Hire Date (DD-MON-YYYY)",	   24,3,11,        Validator::date, "Date must be in DD-MON-YYYY format. eg. 11-SEP-2001"),
      FormElement("Level",				           25,3,20,        Validator::D, "Letters, Numbers, Spaces, _ - . only are allowed.", true),
      FormElement("LMU",			            	   26,3, 5,    Validator::C, "Letters and Numbers only are allowed."),
      FormElement("Service Line",				       27,3,20,    Validator::E, "Letters,Numbers, Spaces, _ - . , / \\ + # ( ) only are allowed.", true),
      FormElement("Speciality",				       28,3,20,        Validator::D, "Letters, Numbers, Spaces, _ - . only are allowed.", true),
      FormElement("WorkGroup",				       29,3,20,        Validator::E, "Letters,Numbers, Spaces, _ - . , / \\ + # ( ) only are allowed.", true),
      FormElement("SSS No",                          30,3,12,      Validator::B, "Numbers, Spaces, Dashes only are allowed."),
      FormElement("TIN No",				           31,3,12,        Validator::B, "Numbers, Spaces, Dashes only are allowed."),
      FormElement("Status",				           32,3,10,        Validator::status,"ACTIVE or INACTIVE", true),

      FormElement("",	-1, -1, 0,		NULL)
    };


  bool EmployeeMenu::create (void)
  {
    ui::Form form(empForm, "Add New Employee");
    form.clearFields();

    if(!form.handleForm())			// As simple as this!
      return false;

    ui::UITransform t;

    EmployeeInfo info;
    AccentureDetails empAcc;

    t.transformForm2Object(form, info);
    t.transformForm2Object(form, empAcc);

    info.setAccentureDetails(empAcc);

    try {
      bc::HRManager::getInstance()->createEmployee(info);
    }catch(GeneralException* ge)
      {
        clear();
    	mvprintw(15, 1, ge->getMessage().c_str());
    	mvprintw(20, 3, "Press any key to continue..." );
    	getch();
    	delete ge;
      }



    return false;                //do not quit from the menu
  }

  bool EmployeeMenu::update(void)
  {
    ui::HelperForm hfForm;
    std::string empCode = hfForm.getSimpleInput("Employee Id");

    if( empCode.empty())
      return false;

    ui::Form form(empForm, "Update Existing Employee");
    form.clearFields();

    ui::UITransform t;
    EmployeeInfo info;
    AccentureDetails adInfo;

    try {
      info = bc::HRManager::getInstance()->searchEmployee(empCode);
    }catch(GeneralException *ge)
      {
	clear();
	mvprintw(15, 1, ge->getMessage().c_str());
	mvprintw(20, 3, "Press any key to continue..." );
	getch();
	delete ge;
	return false;
      }



    adInfo = info.getAccentureDetails();

    t.transformObject2Form(info, form);
    t.transformObject2Form(adInfo , form);


    if(!form.handleForm())	// As simple as this!
      return false;

    t.transformForm2Object(form, info);
    t.transformForm2Object(form, adInfo);

    info.setEmpNo(empCode);
    adInfo.setEmployeeNo(empCode);

    info.setAccentureDetails(adInfo);

    try {
      bc::HRManager::getInstance()->updateEmployee(info);
    }catch(GeneralException* ge)
      {
		clear();
		mvprintw(15, 1, ge->getMessage().c_str());
		mvprintw(20, 3, "Press any key to continue..." );
		getch();
		delete ge;
      }

    return false;           //do not quit from the menu
  };

  bool EmployeeMenu::search(void)
  {
    ui::HelperForm hfForm;
    std::string employeeCode = hfForm.getSimpleInput("Employee Id");

    if( employeeCode.empty())
      return false;

    EmployeeInfo info;

    try {
      info = bc::HRManager::getInstance()->searchEmployee(employeeCode);
    }catch(GeneralException* ge)
      {
	mvprintw(15, 1, ge->getMessage().c_str());
	mvprintw(20, 3, "Press any key to continue..." );
	getch();
	return false;
      }

    Formatter fm;
    fm.getFormattedOutput(info);


    return false;                //do not quit from the menu
  }


  bool EmployeeMenu::searchByName(void)
  {
    ui::HelperForm hfForm;
    std::string employeeName = hfForm.getSimpleInput("Employee Name");

    if( employeeName.empty())
      return false;


    std::vector<EmployeeInfo> infoList;

    try {
      infoList = bc::HRManager::getInstance()->searchEmployees(employeeName);
    }catch(GeneralException* ge)
      {
	mvprintw(15, 1, ge->getMessage().c_str());
	mvprintw(20, 3, "Press any key to continue..." );
	getch();
	return false;
      }

    std::vector<EmployeeInfo>::iterator it;

    Formatter fm;
    EmployeeInfo info;
    std::string out;

    for( it=infoList.begin(); it != infoList.end(); it++)
      {
	info = *it;
	out = fm.getFormattedOutput(info);
      }


    return false;                //do not quit from the menu
  }

}
