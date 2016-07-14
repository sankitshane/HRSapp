// EmpAccentureDetailsDAO.h : The DAO layer responsible for direct interaction with the
// database for detailed employee data used within accenture.

#ifndef EMPACCENTUREDETAILSDAO_H
#define EMPACCENTUREDETAILSDAO_H

/**@file EmpAccentureDetailsDAO.h
 * @brief Delares Data Access Object for Employee Accenture Details.
 *
 * <BR>NAME: EmpAccentureDetailsDAO
 * 
 * <BR>BASE CLASSES: No Parent
 * 
 * <BR>PURPOSE: This class is responsible for direct interaction with the
 *  database for Employee data specific to Accenture.
 *
 * <BR>AUTHOR: Arun Veeramany
 * <BR>$Revision: 9th Dec'05
 * 
 * <BR>$Log: 9th Dec'05
 * 
 * <BR>COPYRIGHT NOTICE:
 * <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
 */

#include <string>
#include <vector>
#include <common/AccentureDetails.h>
#include <dao/DAO.h>
#include <common/HRSObject.h>

namespace dao {

  class ODBCConnection;
  class ODBCResultSet;
  class EmployeeInfo;

  /**@class EmpAccentureDetailsDAO EmpAccentureDetailsDAO.h ./EmpAccentureDetailsDAO.h
   * @brief  EmpAccentureDetailsDAO is the one of the layers closest to the database.
   * <PRE> EmpAccentureDetailsDAO is the layer closest to the database.
   * The EmpAccentureDetails Business Component forwards calls from the HR Manager to this class.
   * This class gets the Database Connection from DBAccess
   * The following tasks are taken up by this class
   *               1. Insert Employee+Accenture related data in to EmpAccentureDetail Table
   *               2. Delete a Employee+Accenture data from the EmpAccentureDetail Table
   *               3. Update a Employee+Accenture's details
   *               4. Find Employee+Accenture with specific search criteria
   * </PRE> 
   */
  class EmpAccentureDetailsDAO : public DAO
  {
  public:
    /**@fn EmpAccentureDetailsDAO
     * @brief Default Constructor.
     * This constructor will not take any argument.
     * @param none
     * @return none
     */
    EmpAccentureDetailsDAO();

    virtual ~EmpAccentureDetailsDAO(){};

    /**@fn create(AccentureDetails& accentureDetails)
     * @brief Insert data into EmpAccentureDetail table
    * This method gets an instance of the connection from
     * DBAccess and inserts data from the accentureDetails object
     * into the EmpAccentureDetail table.
     * sample usage:
     * EmployeeDAO emp;
     * AccentureDetail ad = empInfo.getAccentureDetail()
     * emp.create(ad);
     * @param A reference to AccentureDetails object containing employee data
     * @return none
     */               
    void create(HRSObject& employeeInfo);
       
    /**@fn find(std::string searchCriteria)
     * @brief Search the records with the given criteria
     * @param The condition to be specified while searching for records
     * @return A vector of AccentureDetails matching the criteria
     */           
    std::vector<HRSObject*> find(std::string searchCriteria);

    /**@fn findByAll
     * @brief Retrieve all records from the EmpAccentureDetail table
     * @param none
     * @return A vector of all EmpAccentureDetail found in the table 
     */             
    std::vector<HRSObject*> findByAll();

    /**@fn  findByPK(std::string pkValue)
     * @brief Fetch Employees whose primary key value matches the passed one
     * @param pkValue - Value of the primary key (Employee No.)
     * @return AccentureDetail - Record Matching the pkValue 
     */           
    HRSObject* findByPK(std::string pkValue);     

    /**@fn remove(std::string pkValue)
      * @brief Remove the AccentureDetails from the EmpAccentureDetails table given the EmployeeId
      * @param pkValue - Delete the record corresponding to pkValue
      * @return bool - Status of deletion
      */           
    bool remove( std::string pkValue);       
      
    /**@fn update(AccentureDetails& piSet)
     * @brief Update those records that match piWhere with piSet
     * @param piSet - the SET part of the UPDATE statement
     * @return bool - status of updatiom
     */           
    bool update(HRSObject& piSet);     
  };

}	//namespace dao
#endif     //EMPACCENTUREDETAILSDAO_H
