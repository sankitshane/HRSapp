#ifndef Null
#define Null 0

#include<business/EmployeeBC.h>
#include <common/EmployeeInfo.h>
#include<common/AccentureDetails.h>
#include <dao/EmployeeDAO.h>
#include <dao/EmpAccentureDetailsDAO.h>

#include <string>
#include <vector>


/**@file EmployeeBC.h
 * @brief HRS Application : Declares the EmployeeBC Class.
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

/**@class EmployeeBC
 * @brief HRS Application  Declaration of EmployeeBC Class.
 * <PRE>The participants will be give following Activity.
 * 1. Write a class EmployeeBC, which will enforce encapsulation.
 * 2. class EmployeeBC should have two private member variable.
 * 3. Declare one constructors.
 * 4. Declare Destructor.
 * 5. Declare a function to print the content of the Complex class.
 */



  EmployeeBC::EmployeeBC()
  {
    m_empDao = Null;
    m_empAccDao = Null;
  }
  // Check why it was not defined!!!!


    /**@fn EmployeeBC
     * @brief Destructor.
     * @param none
     * @return none
     */
  EmpolyeeBC::~EmployeeBC()
  {
    m_empDao = Null;
    m_empAccDao = Null;
  }//


     /**@fn createEmployee
     *@brief This creates employee
     * It create the employee data
     * returns nothing.
     * @param reference to the Object of employeeInfo
     * @return void.
     */
    void EmployeeBC::createEmployee(EmployeeInfo& info)
    {
        #ifdef ALOGGER
            logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "About to get unique id");
        #endif

        std::string id=(idgen::ProjectIdGen::getInstance())->getNextId();

        #ifdef ALOGGER
            logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str());
        #endif

        info.setEmpNo(id);
        m_empDao.create(info);


        AccentureDetails AccDetails;
        AccDetails.setEnterpriseId(id);
        m_empAccDao.create(info);

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
    EmployeeInfo EmployeeBC::searchEmployee(std::string empno)
    {
      EmployeeInfo eInfo;
      EmployeeInfo* pInfoPtr = NULL;

      #ifdef ALOGGER
          logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str() );
      #endif

      eInfoPtr = static_cast<EmployeeInfo*>(m_empDAO.findByPK(id));

      eInfo = *eInfoPtr;
      delete eInfoPtr;

      AccentureDetails accDetails;
      AccentureDetails* accDetailsptr = NULL;

      #ifdef ALOGGER
          logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str() );
      #endif

      accDetailsptr = static_cast<AccentureDetails*>(m_empDAO.findByPK(id));

      accDetails = *accDetailsptr;
      delete accDetailsptr;

      return eInfo;



    }

   /**@fn searchEmployees
     *@brief This function searchs for employees
     * returns the collection of Information of the employee.
     * @param std::string
     * @return the collection of objects of the class EmployeeInfo.
     */
    std::vector<EmployeeInfo> EmployeeBC::searchEmployees(std::string info)
    {
      #ifdef ALOGGER
          logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, name.c_str() );
      #endif

        std::vector<EmployeeInfo> empList;
        std::vector<AccentureDetails> accList;
        std::vector<HRSObject*> empListptr;
        std::vector<HRSObject*> accListptr;

        empListptr = m_empDAO.find(info);
        accListptr = m_empAccDao.find(info);

        int size = empListPtr.size();
        for(int i = 0; i < size; ++i)
        {
    	     empList.push_back( *(static_cast<EmployeeInfo*>(empListPtr[i])) );
        }

        int size = accListptr.size();
        for(int i =0;i< size; ++i)
        {
          accList.push_back( *(static_cast<AccentureDetails*>(accListptr[i])));
        }

        for(int i = 0; i < size; ++i)
          delete empListPtr[i];
          delete accListptr[i];
        empListPtr.clear();
        accListptr.clear();

        return emplist;

    }



    /**@fn update
     *@brief This function updates for employees
     * this function updates the information of the employees.
     * Returns nothing
     * @param reference to the object of theclass EmployeeInfo
     * @return none
     */
    void EmployeeBC::update(EmployeeInfo& piSet)
    {
      #ifdef ALOGGER
          logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
      #endif

      m_empDAO.update(info);
      m_empAccDao.update(info);
    }
};

}	//namespace bc
#endif //EmployeeBC.cpp
