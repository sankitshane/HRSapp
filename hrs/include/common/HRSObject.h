#ifndef HRSOBJECT_H
#define HRSOBJECT_H

/**
* @file HRSObject.h
* @brief Base class for all the Value Object used to pass information between UI and DB.
* 
* NAME: HRSObject
* $Header: HRSObject.h
* BASE CLASSES: None
* 
* PURPOSE: Base class for all the Value Object used to pass information between UI and DB.
* 
* AUTHOR: Arun Veeramany
* 
* $Revision: 1.10 $
* 
* $Log: HRSObject.h,v $
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

#include <string>

/**@class HRSObject
 * @brief  Base class for all the Value Object used to pass information between UI and DB.
 **/

class HRSObject
{
 protected:
  std::string m_className;

 public:
  HRSObject(){ m_className = "HRSObject";}
  virtual ~HRSObject(){}

  virtual const std::string getClassName() const = 0;
};
#endif //HRSOBJECT_H
