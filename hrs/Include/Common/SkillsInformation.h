#ifndef SKILLSINFORMATION_H
#define SKILLSINFORMATION_H

/**
* @file SkillsInformation.h
* @brief Value Object used to pass information between UI and DB.
* 
* NAME: SkillsInformation
* $Header: SkillsInformation.h
* BASE CLASSES: HRSObject
* 
* PURPOSE: Value Object used to pass information between UI and DB.
* 
* AUTHOR: Arun Veeramany
* 
* $Revision: 1.10 $
* 
* $Log: SkillsInformation.h,v $
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

#include <string>
#include <common/HRSObject.h>

/**@class SkillsInformation
 * @brief Value Object used to pass information between UI and DB.
 **/
class SkillsInformation : public HRSObject
 {
	
   	std::string m_skillId;
	
	std::string m_categoryId;
    
    std::string m_skillName;

	std::string m_skillDescription;

	std::string m_status;

public:
	SkillsInformation()
	{
	  m_className = "SkillsInformation";
	}

///Getters

	const std::string getClassName()const {return m_className;}

	std::string getSkillId() {	return m_skillId;	}

	std::string getCategoryId() { return m_categoryId; }

	std::string getSkillName() {  return m_skillName; }

    std::string getSkillDescription() { return m_skillDescription; }

    std::string getStatus() { return m_status; }

///Setters

 	void setSkillId(std::string skillId) { m_skillId = skillId; } 

	void setCategoryId(std::string categoryId) { m_categoryId = categoryId; }
		    
	void setSkillName(std::string skillName) { m_skillName = skillName; } 

	void setSkillDescription(std::string skillDescription) { m_skillDescription = skillDescription; }

	void setStatus(std::string status) { m_status = status; } 

};

#endif //SKILLSINFORMATION_H
