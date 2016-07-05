// EmployeeDAO.h : The DAO layer responsible for direct interaction with the
// database for Employee related issues.

#ifndef EMPLOYEEDAO_H
#define EMPLOYEEDAO_H

/**@file EmployeeDAO.h
 * @brief Delares Data Access Object for Employee.
* <BR>NAME: EmployeeDAO
* 
* <BR>BASE CLASSES: No Parent
* 
* <BR>PURPOSE: This class is responsible for direct interaction with the
*  database for Employee related issues.
*
* <BR>AUTHOR: Arun Veeramany
* <BR>$Revision: 9th Dec'05
* 
* <BR>$Log: 9th Dec'05
* 
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/


#include<string>
#include<vector>

#include <dao/DAO.h>
#include <common/HRSObject.h>
#include <common/EmployeeInfo.h>


namespace dao {


  /**@class EmployeeDAO EmployeeDAO.h ./EmployeeDAO.h
   * @brief EmployeeDAO is the layer closest to the database.
   * The Employee Business Component forwards calls from the HR Manager to this class.
   * This class gets the Database Connection from DBAccess
   * The following tasks are taken up by this class
   *               1. Insert an employee in to Employee Table
   *               2. Delete an employee from the Employee Table
   *		   3. Update an employee's details
   *		   4. Find Employees with specific search criteria
   * </PRE> 
   */
  class EmployeeDAO : public DAO
  {
         
  public:

    /**@fn EmployeeDAO
     * @brief Default Constructor.
     * This constructor will not take any argument.
     * @param none
     * @return none
     */     
    EmployeeDAO();

    virtual ~EmployeeDAO(){}

    
    /**@fn create(EmployeeInfo& employeeInfo)
      * @brief Insert an Employee into Employee table
      * This method gets an instance of the connection from
      * DBAccess and inserts data from the employeeInfo object
      * into the Employee table.
      * @param A reference to EmployeeInfo object containing employee data
      * @return none
      */         
    void create(HRSObject& employeeInfo);
       
               
    /**@fn find(std::string searchCriteria)
     * @brief Search the records with the given criteria
     * @param The condition to be specified while searching for records
     * @return A vector of EmployeeInfo matching the criteria
     */              
    std::vector<HRSObject*> find(std::string searchCriteria);

    /**@fn findByAll
     * @brief Retrieve all records from the Employee table
     * @param none
     * @return A vector of all EmployeeInfo found in the table 
     */           
    std::vector<HRSObject*> findByAll();

    /**@fn  findByPK(std::string pkValue)
      * @brief Fetch Employees whose primary key value matches the passed one
      * @param pkValue - Value of the primary key (Employee No.)
      * @return EmployeeInfo - Record Matching the pkValue 
      */          
    HRSObject* findByPK(std::string pkValue);     

    /**@fn remove(std::string pkValue)
      * @brief Remove the project from the Employee table given the EmployeeId
      * @param pkValue - Delete the record corresponding to pkValue
      * @return bool - Status of deletion
      */            
    bool remove(std::string pkValue);       
      
    /**@fn update(EmployeeInfo& piSet)
     * @brief Update those records that match piWhere with piSet
     * @param piSet - the SET part of the UPDATE statement
     * @return bool - status of updatiom
     */              
    bool update(HRSObject& piSet);      
  };

}	// namespace dao
#endif     //EMPLOYEEDAO_H
