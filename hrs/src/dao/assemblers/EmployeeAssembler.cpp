#include <fstream>
#include <iostream>
#include <string>

#include <dao/assemblers/EmployeeAssembler.h>
#include <common/EmployeeInfo.h>
#include <dbaccess/ODBCResultSet.h>

 std::string EmployeeAssembler::assemble(EmployeeInfo& employee,std::string query)
				   
	 {

	  char buf[1024];
		
      sprintf(buf, query.c_str(),
			           employee.getEmpNo().c_str(),
					   employee.getFirstName().c_str(),
					   employee.getLastName().c_str(),
					   employee.getMiddleName().c_str(),
					   employee.getDOB().c_str(),			
					   employee.getGender().c_str(),
					   employee.getCivilStatus().c_str(),
					   employee.getCitizenship().c_str(),
					   employee.getSSSNo().c_str(),
					   employee.getTinNo().c_str(),
					   employee.getMobilePhoneNo().c_str(),
					   employee.getHomePhoneNo().c_str(),
					   employee.getStreet1().c_str(),
					   employee.getStreet2().c_str(),
					   employee.getCity().c_str(),
					   employee.getState().c_str(),
					   employee.getCountry().c_str(),
					   employee.getEducationalAttainment().c_str(),
 					   employee.getRecognitions().c_str());

		 return std::string(buf);

}


 EmployeeInfo EmployeeAssembler::disAssemble(dbaccess::ODBCResultSet* rs)
{

	EmployeeInfo emp;

	emp.setEmpNo( rs->getString( rs->getColNum("EMPNO")));          
	emp.setFirstName( rs->getString( rs->getColNum("FIRSTNAME")));                
	emp.setLastName( rs->getString( rs->getColNum("LASTNAME")));                 
	emp.setMiddleName( rs->getString( rs->getColNum("MIDDLENAME")));               
	emp.setDOB( rs->getDate( rs->getColNum("DATEOFBIRTH")));              
	emp.setAge (rs->getInt( rs->getColNum("AGE")));                      
	emp.setGender (rs->getString( rs->getColNum("GENDER")));                   
	emp.setCivilStatus( rs->getString( rs->getColNum("CIVILSTATUS")));              
	emp.setCitizenship( rs->getString( rs->getColNum("CITIZENSHIP")));              
	emp.setSSSNo( rs->getString( rs->getColNum("SSSNO")));                    
	emp.setTinNo (rs->getString( rs->getColNum("TINNO")));                    
	emp.setMobilePhoneNo( rs->getString( rs->getColNum("MOBILENO")));               
	emp.setHomePhoneNo( rs->getString( rs->getColNum("HOMENO")));                                
	emp.setStreet1( rs->getString( rs->getColNum("STADD1")));                                     
	emp.setStreet2 (rs->getString( rs->getColNum("STADD2")));                   
	emp.setCity( rs->getString( rs->getColNum("CITY")));                     
	emp.setState( rs->getString( rs->getColNum("PROVINCE")));                 
	emp.setCountry (rs->getString( rs->getColNum("COUNTRY")));                  
	emp.setEducationalAttainment (rs->getString( rs->getColNum("EDUCATTAINMENT")));          
	emp.setRecognitions (rs->getString( rs->getColNum("RECOGNITION")));              

	return emp;

}
