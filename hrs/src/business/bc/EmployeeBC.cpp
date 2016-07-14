#include<business/EmployeeBC.h> 

#include<common/EmployeeInfo.h>
#include<common/AccentureDetails.h>
#include<common/GeneralException.h>

#include<dao/EmployeeDAO.h>
#include<dao/EmpAccentureDetailsDAO.h>

#include<business/idgen/EmpIdGen.h>

#include<string>
#include<vector>

#ifdef ALOGGER
#include<logger/Logger.h>
#endif


/**@file EmployeeBC.cpp
 * @brief HRS Application : Defines the EmployeeBC Class.
 *
 * <BR>NAME:EmployeeBC
 * 
 * <BR>BASE CLASSES:None
 * 
 * <BR>PURPOSE:It is the interface bitween HRManager class and EmployeeDAO class
 *
 * <BR>AUTHOR:Vinoj.V.S
 * <BR>
 * <BR>$Revision: $5/12/2005
 * 
 * <BR>$Log:5/12/2005
 * 
 * <BR>COPYRIGHT NOTICE:
 * <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
 */

namespace bc {

  /**@fn createEmployee
    *@brief This creates employee
    * It create the employee data
    * returns nothing.
    * @param reference to the class employeeInfo
    * @return void.
    */
  void EmployeeBC::createEmployee(EmployeeInfo& info)
  {

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "About to get the next ID");
#endif	

    std::string id;
    id=(idgen::EmpIdGen::getInstance())->getNextId();

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str());
#endif	

    info.setEmpNo(id);//info is an instance of the class EmployeeInfo and id is a string
    m_empDao.create(info); 

    AccentureDetails accdetails=info.getAccentureDetails();
    accDetails.setEmployeeNo(id);
    m_empAccDao.create(accDetails);

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif	

  }
	

   /**@fn searchEmployee
     *@brief This function searchs for employee
     * returns the Information of the employee.
     * @param std::string
     * @return an object of the class employeeinfo.
     */
  EmployeeInfo EmployeeBC::searchEmployee(std::string id)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str() );
#endif	

    /*EmployeeDAO::findByPK will return the pointer to the HRSObject which we shall be converting 
      into a specific EmployeeInfo object and will delete the returned pointer for memory management.
     */
    EmployeeInfo eInfo;
    EmployeeInfo* eInfoPtr = NULL; //converted to the pointers.
    
    eInfoPtr = static_cast<EmployeeInfo*>(m_empDao.findByPK(id));
    eInfo = *eInfoPtr;
    delete eInfoPtr;

    AccentureDetails accInfo;
    AccentureDetails* accInfoPtr = NULL; //converted to the pointers.
    
    accInfoPtr = static_cast<AccentureDetails*>(m_empAccDao.findByPK(id));
    accInfo = *accInfoPtr;
    delete accInfoPtr;
    
    eInfo.setAccentureDetails(accInfo);

    return eInfo;
  }



   /**@fn searchEmployees
     *@brief This function searchs for employees
     * returns the collection of Information of the employee.
     * @param std:string info
     * @return the collection of objects of the class EmployeeInfo.
     */
  std::vector<EmployeeInfo> EmployeeBC::searchEmployees(std::string info)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, info.c_str() );
#endif	
	
    std::vector<EmployeeInfo> empList;

    std::vector<HRSObject*> empListPtr;

    empListPtr = m_empDao.find(info);             // Find all the employees
    
    EmployeeInfo eInfo;
    AccentureDetails* accInfoPtr = NULL; //converted to the pointers.
    
    int size = empListPtr.size();
    for(int i = 0; i < size; ++i)
    {
        eInfo = *(static_cast<EmployeeInfo*>(empListPtr[i]));
        accInfoPtr = static_cast<AccentureDetails*>(m_empAccDao.findByPK( eInfo.getEmpNo() ));
        eInfo.setAccentureDetails( *accInfoPtr);
        delete accInfoPtr;
    	empList.push_back( eInfo );
    }
      
    for(int i = 0; i < size; ++i)
      delete empListPtr[i];

    empListPtr.clear();

    return empList;

  }

   
   /**@fn update
     *@brief This function updates for employees
     * this function updates the information of the employees.
     * Returns nothing
     * @param reference totheobject of the class EmployeeInfo
     * @return none
     */
  void EmployeeBC::update(EmployeeInfo& info)  
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif	
    m_empDao.update(info);
    AccentureDetails acc = info.getAccentureDetails();
    m_empAccDao.update(acc);
  }
} //namespace bc
