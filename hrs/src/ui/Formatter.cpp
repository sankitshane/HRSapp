#include <ui/Formatter.h>

#include <common/EmployeeInfo.h>
#include<common/ProjectInfo.h>
#include<common/SkillsInformation.h>
#include<common/SkillCategory.h>
#include<common/AccentureDetails.h>

#include<string>
#include<sstream>
#include<cstdio>

#include <curses.h>

namespace ui
{
std::string Formatter::getFormattedOutput(EmployeeInfo& info)
{

	std::ostringstream out;


	//Employee		-	info
	out <<"\tEmployee Number\t\t"		<<info.getEmpNo()					<<"\n";
	out <<"\tFirst Name\t\t"			<<info.getFirstName()				<<"\n";
	out <<"\tLast Name\t\t"				<<info.getLastName()				<<"\n";
	out <<"\tMiddle Name\t\t"			<<info.getMiddleName()				<<"\n";
	out <<"\tGender\t\t\t"				<<info.getGender()					<<"\n";
	out <<"\tDate of Birth\t\t"			<<info.getDOB()						<<"\n";
	out <<"\tAge\t\t\t"					<<info.getAge()						<<"\n";
	out <<"\tCitizenship\t\t"			<<info.getCitizenship()				<<"\n";
	out <<"\tCity\t\t\t"				<<info.getCity()					<<"\n";
	out <<"\tCivil Status\t\t"			<<info.getCivilStatus()				<<"\n";
	out <<"\tCountry\t\t\t"				<<info.getCountry()					<<"\n";
	out <<"\tEducational Attainment\t"	<<info.getEducationalAttainment()	<<"\n";
	out <<"\tHome phone number\t"		<<info.getHomePhoneNo()				<<"\n";
	out <<"\tMoblie phone number\t"		<<info.getMobilePhoneNo()			<<"\n";
	out <<"\tRecognitions\t\t"			<<info.getRecognitions()			<<"\n";
	out <<"\tSSS number\t\t"			<<info.getSSSNo()					<<"\n";
	out <<"\tState\t\t\t"				<<info.getState()					<<"\n";
	out <<"\tStreet1\t\t\t"				<<info.getStreet1()					<<"\n";
	out <<"\tStreet2\t\t\t"				<<info.getStreet2()					<<"\n";
	out <<"\tTin number\t\t"			<<info.getTinNo()					<<"\n";


	//AccentureDetail	-	accDetail
	AccentureDetails accDetail = info.getAccentureDetails();

	out <<"\tDate Hired\t\t"			<<accDetail.getDateHired()			<<"\n";
	out <<"\tEnterprise Address\t"		<<accDetail.getEnterpriseAddress()	<<"\n";
	out <<"\tEnterprise Id\t\t"			<<accDetail.getEnterpriseId()		<<"\n";
	out <<"\tGMU\t\t\t"					<<accDetail.getGMU()				<<"\n";
	out <<"\tLevel\t\t\t"				<<accDetail.getLevel()				<<"\n";
	out <<"\tLMU\t\t\t"					<<accDetail.getLMU()				<<"\n";
	out <<"\tService Line\t\t"			<<accDetail.getServiceLine()		<<"\n";
	out <<"\tSpecialty\t\t"				<<accDetail.getSpecialty()			<<"\n";
	out <<"\tStatus\t\t\t"				<<accDetail.getStatus()				<<"\n";
	out <<"\tWork Group\t\t"			<<accDetail.getWorkGroup()			<<"\n";

    clear();

	attron(A_BOLD);
	printw("\t\tEmployee Details\n\n");
	attroff(A_BOLD);

	printw(out.str().c_str());
	printw("\n\nPress any key to continue...");
	getch();

	return out.str();


}

std::string Formatter::getFormattedOutput(ProjectInfo& info)
{
	std::ostringstream out;

	out << "\tId\t\t"			<< info.getProjectId()				<< "\n\n";
	out << "\tName\t\t"		<< info.getProjectName()			    << "\n\n";
	out << "\tDescription\t"	<< info.getProjectDescription()		<< "\n\n";
	out << "\tStart Date\t"	<< info.getStartDate()	                << "\n\n";
	out << "\tEnd Date\t"		<< info.getEndDate()	            << "\n\n";
	out << "\tClient Name\t"	<< info.getClient()					<< "\n\n";
	out << "\tStatus\t\t"		<< info.getStatus()					<< "\n\n";

    clear();

	attron(A_BOLD);
	printw("\t\tProject Details\n\n");
	attroff(A_BOLD);

	printw(out.str().c_str());
	printw("\nPress any key to continue...");
	getch();

	return out.str();
}

std::string Formatter::getFormattedOutput(SkillsInformation& info)
{
	std::ostringstream out;

	out << "\tCategory Id\t\t"		<<info.getCategoryId()			<<"\n\n";
	out << "\tSkill Description\t"	<<info.getSkillDescription()	<<"\n\n";
	out << "\tSkill Id\t\t"			<<info.getSkillId()				<<"\n\n";
	out << "\tSkill Name\t\t"			<<info.getSkillName()			<<"\n\n";
	out << "\tSkill Status\t\t"			<<info.getStatus()			<<"\n\n";

    clear();

	attron(A_BOLD);
	printw("\t\tSkill Details\n\n");
	attroff(A_BOLD);


	printw(out.str().c_str());
	printw("\nPress any key to continue...");
	getch();

	return out.str();
}

std::string Formatter::getFormattedOutput(SkillCategory& info)
{
	std::ostringstream out;

	out << "\tCategory Description\t"		<<info.getCategoryDescription()	<<"\n\n";
	out << "\tCategory Id\t\t"			<<info.getCategoryId()			<<"\n\n";
	out << "\tCategory Name\t\t"			<<info.getCategoryName()		<<"\n\n";
	out << "\tCategory Status\t\t"			<<info.getStatus()		<<"\n\n";

    clear();

	attron(A_BOLD);
	printw("\t\tSkill Category Details\n\n");
	attroff(A_BOLD);

	printw(out.str().c_str());
	printw("\nPress any key to continue...");
	getch();

	return out.str();
}
}
