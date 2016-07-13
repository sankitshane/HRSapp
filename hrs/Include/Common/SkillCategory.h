#ifndef SkillCategory_H
#define SkillCategory_H

/**
* @file SkillCategoryInfo.h
* @brief Value Object used to pass information between UI and DB.
*
* NAME: SkillCategoryInfo
* $Header: SkillCategoryInfo.h
* BASE CLASSES:HRSObject
*
* PURPOSE: Value Object used to pass information between UI and DB.
*
* AUTHOR: Arun Veeramany
*
* $Revision: 1.10 $
*
* $Log: SkillCategoryInfo.h,v $
*
*
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

#include <string>
#include <common/HRSObject.h>

/**@class SkillCategoryInfo
 * @brief Value Object used to pass information between UI and DB.
 **/
class SkillCategory : public HRSObject
{
	
    std::string m_SkillCategoryDescription;

	std::string m_SkillCategoryId;

	std::string m_SkillCategoryName;

	std::string m_status;

public:
	SkillCategory()
	{
	  m_className = "SkillCategory";
	}

//Getters
	const std::string getClassName()const {return m_className;}

	std::string  getSkillCategoryDescription( ) { return m_SkillCategoryDescription; }

	std::string  getSkillCategoryId() { return m_SkillCategoryId; }

	std::string  getSkillCategoryName() { return m_SkillCategoryName; }

	std::string getStatus() { return m_status; }

//Setters

 void setSkillCategoryDescription(std::string  SkillCategoryDescription) { m_SkillCategoryDescription = SkillCategoryDescription; }

 void setSkillCategoryId(std::string  SkillCategoryId) { m_SkillCategoryId = SkillCategoryId; }

 void setSkillCategoryName(std::string  SkillCategoryName) { m_SkillCategoryName = SkillCategoryName; }

 void setStatus(std::string  status) { m_status = status; }


};

#endif  //SkillCategory_H
