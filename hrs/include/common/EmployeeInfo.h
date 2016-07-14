#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

/**
* @file EmployeeInfo.h
* @brief Value Object used to pass information between UI and DB.
* 
* NAME: EmployeeInfo
* $Header: EmployeeInfo.h
* BASE CLASSES: HRSObject
* 
* PURPOSE: Value Object used to pass information between UI and DB.
* 
* AUTHOR: Arun Veeramany
* 
* $Revision: 1.10 $
* 
* $Log: EmployeeInfo.h,v $
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

#include <string>
#include<common/AccentureDetails.h>
#include <common/HRSObject.h>

/**@class EmployeeInfo
 * @brief Value Object used to pass information between UI and DB.
 * */
class EmployeeInfo : public HRSObject
{

	int m_age;
            
	std::string m_attainment;
            
	std::string m_citizenship; 
            
	std::string m_city;
            
	std::string m_country;
                        
	std::string m_dob;
                        
	std::string m_empNo; 
            
	std::string m_firstName;            
            
	std::string m_lastName;
            
	std::string m_middleName;
	
	std::string m_homePhoneNo;

	std::string m_gender;
            
	std::string m_SSSNo;
            
	std::string m_phoneNo;
           
	std::string m_recognitions;
                        
	std::string m_state;
                        
	std::string m_street1; 
            
	std::string m_street2;
            
	std::string m_tinNo;
            
	std::string m_civilStatus;

	
	AccentureDetails m_AccentureDetails;

public:

	EmployeeInfo()
	{

	  m_className = "EmployeeInfo";
	} 

	const std::string getClassName()const {return m_className;}

///Getters of the variables            

	int getAge() { return m_age;  }

	std::string getEducationalAttainment() { return m_attainment; }  
                    
	std::string getCitizenship() { return m_citizenship;  }
            
	std::string getCity() { return m_city;  }
            
	std::string getCountry() { return m_country; }
            
	std::string getDOB() { return m_dob;  }
            
	std::string getEmpNo() { return m_empNo; }  
            
	std::string getFirstName() { return m_firstName; }              
            
	std::string getLastName() { return m_lastName; }  
            
	std::string getMiddleName() { return m_middleName; }  

	std::string getHomePhoneNo() { return m_homePhoneNo; }  
	
	std::string getGender() { return m_gender; }  
                                            
	std::string getSSSNo() { return m_SSSNo; }

	std::string getMobilePhoneNo() { return m_phoneNo; }  

	std::string getRecognitions() { return m_recognitions; }  
            
	std::string getState() { return m_state; }  
            
	std::string getStreet1() { return m_street1; }  
            
	std::string getStreet2() { return m_street2; }  
            
	std::string getTinNo() { return m_tinNo; }  
            
	std::string getCivilStatus() { return m_civilStatus;  }

	AccentureDetails getAccentureDetails() { return m_AccentureDetails; }
            
///setters of the variables            
	

 void setAge(int age) { m_age= age; } 

 void setEducationalAttainment(std::string attainment) { m_attainment= attainment ; } 

 void setCitizenship(std::string citizenship) { m_citizenship= citizenship; } 
            
 void setCity(std::string city) { m_city= city ; } 
            
 void setCountry(std::string country) { m_country= country ; } 
            
 void setDOB(std::string dob) { m_dob  = dob; }                                    
           
 void setEmpNo(std::string empNo) { m_empNo= empNo ; } 
            
 void setFirstName(std::string firstName) { m_firstName= firstName ; } 
                        
 void setLastName(std::string lastName) { m_lastName= lastName ; } 
            
 void setMiddleName(std::string middleName) { m_middleName= middleName;  } 
            
 void setHomePhoneNo(std::string homePhoneNo) { m_homePhoneNo= homePhoneNo ; } 

 void setGender(std::string gender) { m_gender= gender ; } 

 void setSSSNo(std::string no) { m_SSSNo= no; } 

 void setMobilePhoneNo(std::string phoneNo) { m_phoneNo= phoneNo ; } 
                        
 void setRecognitions(std::string recognitions) { m_recognitions= recognitions ; } 
                                    
 void setState(std::string state) { m_state= state ; } 
            
 void setStreet1(std::string street1) { m_street1= street1 ; } 
            
 void setStreet2(std::string street2) { m_street2= street2 ; } 
            
 void setTinNo(std::string tinNo) { m_tinNo= tinNo ; } 
                        
 void setCivilStatus(std::string status) { m_civilStatus= status; } 

 void setAccentureDetails(AccentureDetails accDetails) { m_AccentureDetails = accDetails; }

};

#endif  //EMPLOYEEINFO_H
