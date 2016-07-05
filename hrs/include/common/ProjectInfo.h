#ifndef PROJECTINFO_H
#define PROJECTINFO_H

/**
* @file ProjectInfo.h
* @brief Value Object used to pass information between UI and DB.
* 
* NAME: ProjectInfo
* $Header: ProjectInfo.h
* BASE CLASSES:HRSObject
* 
* PURPOSE: Value Object used to pass information between UI and DB.
* 
* AUTHOR: Arun Veeramany
* 
* $Revision: 1.10 $
* 
* $Log: ProjectInfo.h,v $
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

#include <string>
#include <common/HRSObject.h>

/**@class ProjectInfo
 * @brief Value Object used to pass information between UI and DB.
 **/
class ProjectInfo : public HRSObject
{
	std::string m_client; 
	  
	std::string m_startDate;
            
	std::string m_endDate; 

	std::string m_projectDescription;

	std::string m_projectId;

	std::string m_projectName; 

	std::string m_status;

public:
	ProjectInfo() 
	{
	  m_className = "ProjectInfo"; 
	}

//Getters
	const std::string getClassName()const {return m_className;}

	std::string  getClient() { return m_client;}

	std::string  getStartDate() { return m_startDate; } 
            
	std::string  getEndDate() { return m_endDate; }
            
	std::string  getProjectDescription( ) { return m_projectDescription; }
            
	std::string  getProjectId() { return m_projectId; } 
            
	std::string  getProjectName() { return m_projectName; } 

	std::string getStatus() { return m_status; }

//Setters
            
 void setClient(std::string  client) { m_client = client; }
 
 void setStartDate(std::string  startDate) { m_startDate = startDate; }
 
 void setEndDate(std::string  endDate) { m_endDate = endDate; }
            
 void setProjectDescription(std::string  projectDescription) { m_projectDescription = projectDescription; } 
            
 void setProjectId(std::string  projectId) { m_projectId = projectId; } 
            
 void setProjectName(std::string  projectName) { m_projectName = projectName; } 

 void setStatus(std::string  status) { m_status = status; }           


};

#endif  //PROJECTINFO_H
