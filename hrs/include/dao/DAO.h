#ifndef DAO_H
#define DAO_H

/**@file DAO.h
 *@brief Declares the Base class DAO for all Data Access Objects.
 *
 * <BR>NAME: DAO
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
#include <common/HRSObject.h>
#include <common/EmployeeInfo.h>

/**@namespace dao
   @brief Declares classes which will act as Data Access Objects.
 */

namespace dao {

  class ODBCConnection;
  class ODBCResultSet;
  //  class EmployeeInfo;

  /**@class DAO
   * @brief The base class for All Data Access Objects.
   * <BR> 
   * <PRE> DAO is the layer closest to the database.
   * This class is the Base Class for all the DAO classes.
   * Each DAO class must inherit from this and provide the implementation for each function.
   * </PRE> 
   */
  class DAO
  {
  public:
    /**@fn DAO
     * @brief Default Constructor.
     * This constructor will not take any argument.
     * @param none
     * @return none
     */
    DAO(){};

    virtual ~DAO(){};

    /**@fn create(AccentureDetails& accentureDetails)
     * @brief Insert data into EmpAccentureDetail table
     * This method gets an instance of the connection from
     * DBAccess and inserts data from the accentureDetails object
     * into the EmpAccentureDetail table.
     * sample usage:
     *        EmployeeDAO emp;
     *        AccentureDetail ad = empInfo.getAccentureDetail();
     *        emp.create(ad);
     *
     * @param A reference to AccentureDetails object containing employee data
     * @return none
     */            
    virtual void create(HRSObject& object) = 0;
       
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
#endif    //DAO_H
