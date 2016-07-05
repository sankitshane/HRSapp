#ifndef ACCENTUREDETAILS_H
#define ACCENTUREDETAILS_H
/**
* @file AccentureDetails.h
* @brief Value Object used to pass information between UI and DB.
* 
* NAME: AccentureDetails
* $Header: AccentureDetails.h
* BASE CLASSES: HRSObject
* 
* PURPOSE: Value Object used to pass information between UI and DB.
* 
* AUTHOR: Arun Veeramany
* 
* $Revision: 1.10 $
* 
* $Log: AccentureDetails.h,v $
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

#include<string>
#include <common/HRSObject.h>

/**@class AccentureDetails
 * @brief Value Object used to pass information between UI and DB.
 * */
class AccentureDetails : public HRSObject
{
    std::string m_employeeNo; 

    std::string m_enterpriseId;

	std::string m_dateHired; 
            
	std::string m_enterpriseAddress;
            
	std::string m_GMU;
                                              
	std::string m_level;
            
	std::string m_LMU;
                        
	std::string m_serviceLine;
            
	std::string m_specialty;
            
	std::string m_status;
            
	std::string m_workGroup;
            
            
public:
	AccentureDetails()
	{
	  m_className = "AccentureDetails";
	}


//Getters

	const std::string getClassName()const {return m_className;}
		
	std::string getEmployeeNo() { return m_employeeNo; }
	
	std::string getEnterpriseId() { return m_enterpriseId; }

	std::string getDateHired() { return m_dateHired; }            
            
	std::string getEnterpriseAddress() { return m_enterpriseAddress; }
            
	std::string getGMU() { return m_GMU; }
                    
	std::string getLevel() { return m_level; }
            
	std::string getLMU() { return m_LMU; }
            
	std::string getServiceLine() { return m_serviceLine; }
            
	std::string getSpecialty() { return m_specialty; }
            
	std::string getStatus() { return m_status; }
            
	std::string getWorkGroup() { return m_workGroup; }


            
//Setters            
	void setEmployeeNo(std::string employeeNo) { m_employeeNo= employeeNo; }
                        
	void setEnterpriseId(std::string enterpriseId) { m_enterpriseId= enterpriseId; }

	void setDateHired(std::string dateHired) { m_dateHired= dateHired; }

	void setEnterpriseAddress(std::string enterpriseAddress) { m_enterpriseAddress= enterpriseAddress; }
            
	void setGMU(std::string GMU) { m_GMU= GMU; }
                        
	void setLevel(std::string level) { m_level= level; }
            
	void setLMU(std::string LMU) { m_LMU= LMU; }
                        
	void setServiceLine(std::string serviceLine) { m_serviceLine= serviceLine; }
            
	void setSpecialty(std::string specialty) { m_specialty= specialty; }
            
	void setStatus(std::string status) { m_status= status; }
	            
	void setWorkGroup(std::string workGroup) { m_workGroup= workGroup; }
            
};

#endif //ACCENTUREDETAILS_H
