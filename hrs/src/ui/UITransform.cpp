// UITransform.cpp: implementation of the UITransform class.
//
//////////////////////////////////////////////////////////////////////

#include <ui/UITransform.h>

#include<ui/Form.h>


#include<common/AccentureDetails.h>
#include<common/ProjectInfo.h>
#include<common/SkillsInformation.h>
#include<common/SkillCategory.h>
#include<common/EmployeeInfo.h>





namespace ui{

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

UITransform::UITransform()
{

}


//-----------------------------------------------------------------

void UITransform::transformForm2Object(Form& form, EmployeeInfo& info)
{
	info.setFirstName( form.getText("First Name") );
	info.setLastName(  form.getText("Last Name") );
	info.setMiddleName( form.getText("Middle Name") );
	info.setGender( form.getText("Gender(M/F)") );
//	info.setAge( atoi(form.getText("Age").c_str()) );
	info.setDOB( form.getText("Date of Birth (DD-MON-YYYY)") );
	info.setCitizenship( form.getText("Citizenship") );
	info.setCity( form.getText("City") );
	info.setHomePhoneNo( form.getText("Home Phone") );
	info.setMobilePhoneNo( form.getText("Mobile Number") );
	info.setEducationalAttainment( form.getText("Educational Attainment") );
	info.setStreet1( form.getText("Street Address 1") );
	info.setStreet2( form.getText("Street Address 2") );
	info.setState( form.getText("State") );
	info.setCountry( form.getText("Country") );
	info.setRecognitions( form.getText("Recognition") );
	info.setSSSNo( form.getText("SSS No") );
	info.setTinNo( form.getText("TIN No") );
	info.setCivilStatus( form.getText("Civil Status") );
}

void UITransform::transformObject2Form(EmployeeInfo& info, Form& form)
{
	form.setText("First Name", info.getFirstName() );
	form.setText("Last Name",info.getLastName() );
	form.setText("Middle Name",info.getMiddleName() );
	form.setText("Gender(M/F)",info.getGender() );
	
	char buf[20];
	sprintf(buf, "%d", info.getAge() );
	
  //  form.setText("Age", buf);
	form.setText("Date of Birth (DD-MON-YYYY)",info.getDOB() );
	form.setText("Citizenship",info.getCitizenship() );
	form.setText("City",info.getCity() );
	form.setText("Home Phone",info.getHomePhoneNo() );
	form.setText("Mobile Number",info.getMobilePhoneNo() );
	form.setText("Educational Attainment",info.getEducationalAttainment() );
	form.setText("Street Address 1",info.getStreet1() );
	form.setText("Street Address 2",info.getStreet2() );
	form.setText("State",info.getState() );
	form.setText("Country",info.getCountry() );
	form.setText("Recognition",info.getRecognitions() );
	form.setText("SSS No",info.getSSSNo() );
	form.setText("TIN No",info.getTinNo() );
	form.setText("Civil Status",info.getCivilStatus() );

}


//-----------------------------------------------------------------

void UITransform::transformForm2Object(Form& form, ProjectInfo& info)
{
	info.setClient( form.getText("Client") );
	info.setStartDate( form.getText("Start Date"));
	info.setEndDate( form.getText("End Date"));
	info.setProjectDescription( form.getText("Project Description"));
	info.setProjectName( form.getText("Project Name"));
	info.setStatus( form.getText("Project Status"));
}

void UITransform::transformObject2Form(ProjectInfo& info, Form& form)
{
	form.setText("Client",info.getClient());
	form.setText("Start Date",info.getStartDate());
	form.setText("End Date",info.getEndDate());
	form.setText("Project Description",info.getProjectDescription());
	form.setText("Project Name",info.getProjectName());
	form.setText("Project Status",info.getStatus());
}

//-----------------------------------------------------------------

void UITransform::transformForm2Object(Form& form, SkillsInformation& info)
{
	info.setCategoryId( form.getText("Category Id"));
	info.setSkillDescription( form.getText("Skill Description"));
	info.setSkillId( form.getText("Skill Id"));
	info.setSkillName(form.getText("Skill Name"));
	info.setStatus( form.getText("Skill Status"));
}

void UITransform::transformObject2Form(SkillsInformation& info, Form& form)
{
	form.setText("Category Id",info.getCategoryId());
	form.setText("Skill Description",info.getSkillDescription());
	form.setText("Skill Id",info.getSkillId());
	form.setText("Skill Name",info.getSkillName());
	form.setText("Skill Status",info.getStatus());

}

//-----------------------------------------------------------------

void UITransform::transformForm2Object(Form& form, SkillCategory& info)
{
	info.setCategoryDescription(form.getText("Category Description"));
	info.setCategoryName(form.getText("Category Name"));
	info.setStatus(form.getText("Category Status"));
	
    
    //info.setSkillList(form.getText("SkillList"));
}

void UITransform::transformObject2Form(SkillCategory& info, Form& form)
{
	form.setText("Category Description",info.getCategoryDescription());
	form.setText("Category Name",info.getCategoryName());
	form.setText("Category Status",info.getStatus());
}

//-----------------------------------------------------------------

void UITransform::transformForm2Object(Form& form, AccentureDetails& info)
{
	info.setEnterpriseAddress(form.getText("Enterprise Address"));
	info.setEnterpriseId(form.getText("Enterprise Id"));
	info.setGMU(form.getText("GMU"));
	info.setDateHired(form.getText("Hire Date (DD-MON-YYYY)"));
	info.setLevel(form.getText("Level"));
	info.setLMU(form.getText("LMU"));
	info.setServiceLine(form.getText("Service Line"));
	info.setSpecialty(form.getText("Speciality"));
	info.setStatus(form.getText("Status"));
	info.setWorkGroup(form.getText("WorkGroup"));
}

void UITransform::transformObject2Form(AccentureDetails& info, Form& form)
{
	form.setText("Enterprise Address",info.getEnterpriseAddress());
	form.setText("Enterprise Id",info.getEnterpriseId());
	form.setText("GMU",info.getGMU());
	form.setText("Hire Date (DD-MON-YYYY)",info.getDateHired());
	form.setText("Level",info.getLevel());
	form.setText("LMU",info.getLMU());
	form.setText("Speciality",info.getSpecialty());
	form.setText("Status",info.getStatus());
	form.setText("WorkGroup",info.getWorkGroup());
	form.setText("Service Line",info.getServiceLine() );

}



} //namespace ui
