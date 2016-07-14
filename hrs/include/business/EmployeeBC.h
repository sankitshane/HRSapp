#ifndef EmployeeBC_H
#define EmployeeBC_H

#include <common/EmployeeInfo.h>
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
 * 2. class EmployeeBC should have three private member variable. 
 * 3. Declare one constructors.
 * 4. Declare Destructor.
 * 5. Declare a function to print the content of the Complex class.
 */

class EmployeeBC
{
 private: 
	 dao::EmployeeDAO m_empDao; ///<Reference to the employee Data Access object
	 dao::EmpAccentureDetailsDAO m_empAccDao; ///<Reference to the employee accenture deatils DAO

      //	 EmployeeDao m_dbAccess; ///<Reference to the  employee DAO
	 
    public:

    /**@fn EmployeeBC
     * @brief Default Constructor.
     * This constructor will not take any argument.
     * It will initialize both the variable to ZERO.
     * @param none
     * @return none
     */
  EmployeeBC(){};// Check why it was not defined!!!!

  
    /**@fn EmployeeBC
     * @brief Destructor.
     * @param none
     * @return none
     */ 
  ~EmployeeBC(){};//


     /**@fn createEmployee
     *@brief This creates employee
     * It create the employee data
     * returns nothing.
     * @param reference to the Object of employeeInfo
     * @return void.
     */
    void createEmployee(EmployeeInfo& info);
  
 
    /**@fn searchEmployee
     *@brief This function searchs for employee
     * returns the Information of the employee.
     * @param std::string
     * @return an object of the class employeeinfo.
     */
    EmployeeInfo searchEmployee(std::string empno);
  
   /**@fn searchEmployees
     *@brief This function searchs for employees
     * returns the collection of Information of the employee.
     * @param std::string
     * @return the collection of objects of the class EmployeeInfo.
     */
    std::vector<EmployeeInfo> searchEmployees(std::string info);

  
  
    /**@fn update
     *@brief This function updates for employees
     * this function updates the information of the employees.
     * Returns nothing
     * @param reference to the object of theclass EmployeeInfo
     * @return none
     */
    void update(EmployeeInfo& piSet);
};

}	//namespace bc
#endif //EmployeeBC.h

