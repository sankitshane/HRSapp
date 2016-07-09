#ifndef SkillCategoryINFO_H
#define SkillCategoryINFO_H

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
class SkillCategoryInfo : public HRSObject
{
	std::string m_client;

	std::string m_startDate;

	std::string m_endDate;

	std::string m_SkillCategoryDescription;

	std::string m_SkillCategoryId;

	std::string m_SkillCategoryName;

	std::string m_status;

public:
	SkillCategoryInfo()
	{
	  m_className = "SkillCategoryInfo";
	}

//Getters
	const std::string getClassName()const {return m_className;}

	std::string  getClient() { return m_client;}

	std::string  getStartDate() { return m_startDate; }

	std::string  getEndDate() { return m_endDate; }

	std::string  getSkillCategoryDescription( ) { return m_SkillCategoryDescription; }

	std::string  getSkillCategoryId() { return m_SkillCategoryId; }

	std::string  getSkillCategoryName() { return m_SkillCategoryName; }

	std::string getStatus() { return m_status; }

//Setters

 void setClient(std::string  client) { m_client = client; }

 void setStartDate(std::string  startDate) { m_startDate = startDate; }

 void setEndDate(std::string  endDate) { m_endDate = endDate; }

 void setSkillCategoryDescription(std::string  SkillCategoryDescription) { m_SkillCategoryDescription = SkillCategoryDescription; }

 void setSkillCategoryId(std::string  SkillCategoryId) { m_SkillCategoryId = SkillCategoryId; }

 void setSkillCategoryName(std::string  SkillCategoryName) { m_SkillCategoryName = SkillCategoryName; }

 void setStatus(std::string  status) { m_status = status; }


};

#endif  //SkillCategoryINFO_H
