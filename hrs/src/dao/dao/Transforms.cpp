#include<common/AccentureDetails.h>
#include<common/ProjectInfo.h>
#include<common/EmployeeInfo.h>
#include<common/SkillsInformation.h>
#include<common/SkillCategory.h>

#include<dao/Transforms.h>

#include<string>

std::string Transform::transform(AccentureDetails& info)
{
	bool CommaNeeded=false;
	std::string sql;

		sql = sql + "DateHired ='" + info.getDateHired () + "'";
		CommaNeeded=true;
	
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "EMAILADD='" + info.getEnterpriseAddress () + "'";
		CommaNeeded=true;
		
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "EnterpriseId='" + info.getEnterpriseId () + "'";
		CommaNeeded=true;


		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "GMU='" + info.getGMU () + "'";
		CommaNeeded=true;
	

		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "LMU='" + info.getLMU() + "'";
		CommaNeeded=true;

     
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "ServiceLine='" + info.getServiceLine () + "'";
		CommaNeeded=true;
	

		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Specialty='" + info.getSpecialty() + "'";
		CommaNeeded=true;
		
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Status='" + info.getStatus() + "'";
		CommaNeeded=true;

		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "WorkGroup='" + info.getWorkGroup() + "'";

	return sql;

}
//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//EMPLOYEE TRANSFORM

std::string Transform::transform(EmployeeInfo& info)
{
	bool CommaNeeded=false;
	std::string sql;


		char buf[30];
		sprintf(buf, " Age=%d", info.getAge() );
		
		sql = sql + std::string(buf);
		CommaNeeded=true;
		
	           
		sql+=(CommaNeeded==true?",\n":" ");
	    sql = sql + "Citizenship ='" + info.getCitizenship() + "'";
		CommaNeeded=true;

            
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "City ='" + info.getCity() + "'";
		CommaNeeded=true;
		
            
		sql+=(CommaNeeded==true?",\n":" ");	
		sql = sql + "CivilStatus='" + info.getCivilStatus() + "'";
		CommaNeeded=true;

        
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Country='" + info.getCountry() + "'";
		CommaNeeded=true;
			
            
		sql+=(CommaNeeded==true?",\n":" ");	
		sql = sql + " DateOfBirth='" + info.getDOB() + "'";
		CommaNeeded=true;

		            
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Educattainment ='" + info.getEducationalAttainment() + "'";
		CommaNeeded=true;
		            
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "FirstName ='" + info.getFirstName() + "'";
		CommaNeeded=true;
		
	            
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Gender ='" + info.getGender() + "'";
		CommaNeeded=true;

	
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "HomeNo ='" + info.getHomePhoneNo() + "'";
		CommaNeeded=true;
	
            
		sql+=(CommaNeeded==true?",\n":" ");	
		sql = sql + "LastName='" + info.getLastName() + "'";
		CommaNeeded=true;
            
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "MiddleName ='" + info.getMiddleName() + "'";
		CommaNeeded=true;
	
            
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "MobileNo='" + info.getMobilePhoneNo() + "'";
		CommaNeeded=true;
            
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Recognition='" + info.getRecognitions() + "'";
		CommaNeeded=true;
               
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "SSSNo='" + info.getSSSNo() + "'";
		CommaNeeded=true;
	
            
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Province ='" + info.getState() + "'";
		CommaNeeded=true;
            
		sql+=(CommaNeeded==true?",\n":" ");	
		sql = sql + "StAdd1='" + info.getStreet1() + "'";
		CommaNeeded=true;

            
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "StAdd2 ='" + info.getStreet2() + "'";
		CommaNeeded=true;
            
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "TinNo ='" + info.getTinNo() + "'";
		
	return sql;
}
//*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//SKILLS TRANSFORM

std::string Transform::transform(SkillsInformation& info)
{

	bool CommaNeeded=false;
	std::string sql;

		sql = sql + "CatId='" + info.getCategoryId () + "'";
		CommaNeeded=true;

		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Description='" + info.getSkillDescription() + "'";
		CommaNeeded=true;
		
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Id='" + info.getSkillId() + "'";
		CommaNeeded=true;

		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Name='" + info.getSkillName() + "'";
		CommaNeeded=true;

		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Status='" + info.getStatus() + "'";
		
	return sql;
}

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//SKILL CATEGORY TRANSFORM	

std::string Transform::transform(SkillCategory& info)
{

	bool CommaNeeded=false;
	std::string sql;

		sql = sql + "Description='" + info.getCategoryDescription () + "'";
		CommaNeeded=true;

		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Id='" + info.getCategoryId () + "'";
		CommaNeeded=true;
	
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Name='" + info.getCategoryName() + "'";
	
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Status='" + info.getStatus() + "'";
		
		return sql;
}

//*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

// PROJECT TRANSFORM

std::string Transform::transform(ProjectInfo& info)
{

	bool CommaNeeded=false;
	std::string sql;

		sql = sql + "ClientName ='" + info.getClient() + "'";
		CommaNeeded=true;
		
	
		sql+=(CommaNeeded==true?",\n":" ");	
		sql = sql + "EndDate ='" + info.getEndDate () + "'";
		CommaNeeded=true;
            
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Description ='" + info.getProjectDescription () + "'";
		CommaNeeded=true;
			
		sql+=(CommaNeeded==true?",\n":" ");
		sql = sql + "Name ='" + info.getProjectName () + "'";
		CommaNeeded=true;
			
		sql+=(CommaNeeded==true ? ",\n" : " ");
		sql = sql + "StartDate ='" + info.getStartDate() + "'";
		CommaNeeded=true;
	
		sql+=(CommaNeeded==true ? ",\n" : " ");
		sql = sql + "Status='" + info.getStatus() + "'";
	
	return sql;
}
