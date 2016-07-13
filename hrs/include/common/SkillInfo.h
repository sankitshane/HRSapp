#ifndef SkillINFO_H
#define SkillINFO_H

/**
* @file SkillInfo.h
* @brief Value Object used to pass information between UI and DB.
*
* NAME: SkillInfo
* $Header: SkillInfo.h
* BASE CLASSES:HRSObject
*
* PURPOSE: Value Object used to pass information between UI and DB.
*
* AUTHOR: Arun Veeramany
*
* $Revision: 1.10 $
*
* $Log: SkillInfo.h,v $
*
*
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

#include <string>
#include <common/HRSObject.h>

/**@class SkillInfo
 * @brief Value Object used to pass information between UI and DB.
 **/
class SkillInfo : public HRSObject
{
	std::string m_SkillDescription;

	std::string m_SkillId;

	std::string m_SkillName;

	std::string m_status;
	 
	std::string m_catId;

public:
	SkillInfo()
	{
	  m_className = "SkillInfo";
	}

//Getters
	const std::string getClassName()const {return m_className;}

	std::string getSkillCatId(){return m_catId;}

	std::string  getSkillDescription( ) { return m_SkillDescription; }

	std::string  getSkillId() { return m_SkillId; }

	std::string  getSkillName() { return m_SkillName; }

	std::string getStatus() { return m_status; }

//Setters

	void setSkillCatId(std::string SkillCatId){m_catId - SkillCatId;}

 void setSkillDescription(std::string  SkillDescription) { m_SkillDescription = SkillDescription; }

 void setSkillId(std::string  SkillId) { m_SkillId = SkillId; }

 void setSkillName(std::string  SkillName) { m_SkillName = SkillName; }

 void setStatus(std::string  status) { m_status = status; }


};

#endif  //SkillINFO_H
