#include <fstream>
#include <iostream>
#include <string>

#include<dao/assemblers/EmployeeAssembler.h>
#include<common/EmployeeInfo.h>
#include<dbaccess/ODBCResultSet.h>

std::string EmployeeAssembler::assemble(EmployeeInfo& Employees,std::string query)

{
	char buf[1024];

	sprintf(buf,query.c_str(),
				      Employees.getAge().c_str(),
					  Employees.getEducationalAttainment().c_str(),
					  Employees.getCitizenship().c_str(),
					  Employees.getCity().c_str(),
					  Employees.getCountry().c_str(),
					  Employees.getDOB().c_str(),
					  Employees.getEmpNo().c_str(),
            Employees.getFirstName().c_str()
            Employees.getLastName().c_str(),
            Employees.getMiddleName().c_str(),
            Employees.getHomePhoneNo().c_str(),
            Employees.getGender().c_str(),
            Employees.getSSSNo().c_str(),
            Employees.getMobilePhoneNo(),c_str(),
            Employees.getRecognitions(),c_str(),
            Employees.getState().c_str(),
            Employees.getStreet1().c_str(),
            Employees.getStreet2(),c_str(),
            Employees.getTinNo().c_str(),
            Employees.getCivilStatus().c_str(),
            Employees.getAccentureDetails().c_str());

	return std::string(buf);
}


  EmployeeInfo EmployeeAssembler::disAssemble(dbaccess::ODBCResultSet* rs)
  {

	  EmployeeInfo emp;


	   emp.setAge( rs->getString( rs->getColNum("AGE")) );
	   emp.setEducationalAttainment( rs->getString( rs->getColNum("EDUCATIONALATTAINMENT")) );
	   emp.setCitizenship( rs->getString( rs->getColNum("CITIZENSHIP")) );
	   emp.setCity( rs->getDate( rs->getColNum("CITY") ));
	   emp.setCountry( rs->getDate( rs->getColNum("COUNTRY")) );
	   emp.setDOB( rs->getString( rs->getColNum("DATEOFBIRTH")) );
	   emp.setEmpNo( rs->getString( rs->getColNum("EMPNO") ));
     emp.setFirstName(rs->getString( rs->getColNum("FIRSTNAME")));
     emp.setLastName( rs->getString( rs->getColNum("LASTNAME")));
     emp.setMiddleName( rs->getString( rs->getColNum("MIDDLENAME")));
     emp.setHomePhoneNo( rs->getString( rs->getColNum("HOMENO")));
     emp.setGender( rs->getString( rs->getColNum("GENDER")));
     emp.setSSSNo( rs->getString( rs->getColNum("SSSNO")));
     emp.setMobilePhoneNo( rs->getString( rs->getColNum("MOBILENO")));
     emp.setRecognitions( rs->getString( rs->getColNum("RECOGNITION")));
     emp.setState( rs->getString( rs->getColNum("STATE")));
     emp.setStreet1( rs->getString( rs->getColNum("STREET1")));
     emp.setStreet2( rs->getString( rs->getColNum("STREET2")));
     emp.setTinNo( rs->getString( rs->getColNum("TINNO")));
     emp.setCivilStatus( rs->getString( rs->getColNum("CIVILSTATUS")));
     emp.setAccentureDetails( rs->getString( rs->getColNum("ACCENTUREDETAILS")));

	   return emp;
  }
