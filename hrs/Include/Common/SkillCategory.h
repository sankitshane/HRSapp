#ifndef SKILLCATEGORY_H
#define SKILLCATEGORY_H
/**
* @file SkillCategory.h
* @brief Value Object used to pass information between UI and DB.
* 
* NAME: SkillCategory
* $Header: SkillCategory.h
* BASE CLASSES: HRSObject
* 
* PURPOSE: Value Object used to pass information between UI and DB.
* 
* AUTHOR: Arun Veeramany
* 
* $Revision: 1.10 $
* 
* $Log: SkillCategory.h,v $
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/
#include<common/SkillsInformation.h>

#include<string>
#include <common/HRSObject.h>

/**@class SkillCategory
 * @brief Value Object used to pass information between UI and DB.
 **/
class SkillCategory : public HRSObject
{ 

	std::string m_categoryId;

	std::string m_categoryName;

	std::string m_categoryDescription;

	std::string m_status;
            
public:
	SkillCategory()
	{
	  m_className = "SkillCategory";
	}

//Getters
	const std::string getClassName()const {return m_className;}
            
	 std::string getCategoryId() { return m_categoryId; }
            
	 std::string getCategoryName() { return m_categoryName; }

	 std::string getCategoryDescription()  { return m_categoryDescription; }

	 std::string getStatus()  { return m_status; }
            
            

	 
//Setters
            
	 void setCategoryId(std::string categoryId) { m_categoryId = categoryId; }
            
	 void setCategoryName(std::string categoryName) { m_categoryName = categoryName; } 

	 void setCategoryDescription(std::string categoryDesc) { m_categoryDescription = categoryDesc; }

	 void setStatus(std::string status) { m_status = status; }
};

#endif //SKILLCATEGORY_H

