#ifndef EmpAccentureDetails_H
#define EmpAccentureDetails_H

/**@file EmployeeAccenture.h
 *@brief Delares Data Access Object for EmployeeAccenture.
 * <BR>NAME: EmployeeAccenture
 *
 * <BR>BASE CLASSES: No Parent
 *
 * <BR>PURPOSE: This class is responsible for direct interaction with the
 *  database for EmployeeAccenture related issues.
 *
 * <BR>AUTHOR: Arun Veeramany
 * <BR>$Revision: 9th Dec'05
 *
 * <BR>$Log: 9th Dec'05
 *
 * <BR>COPYRIGHT NOTICE:
 * <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
 */

 #include<vector>
 #include<string>

 #include<common/AccentureDetail.h>
 #include <dao/DAO.h>
 #include <common/HRSObject.h>

namespace dao
{
  /**@class EmployeeAccenture EmployeeAccenture.h ./EmployeeAccenture.h
   * @brief EmployeeAccenture is the layer closest to the database.
  * The EmployeeAccenture Business Component forwards calls from the HR Manager to this class.
   * This class gets the Database Connection from DBAccess
   * The following tasks are taken up by this class
   *               1. Insert a EmployeeAccenture in to EmployeeAccenture Table
   *               2. Delete a EmployeeAccenture from the EmployeeAccenture Table
   *               3. Update a EmployeeAccenture's details
   *               4. Find EmployeeAccentures with specific search criteria
   * </PRE>
   */

   class EmpAccentureDetailsDAO : public DAO
   {
   public:
     /**@fn EmployeeAccenture
      * @brief Default Constructor.
      * This constructor will not take any argument.
      * @param none
      * @return none
      */
     EmpAccentureDetailsDAO();

     virtual ~EmpAccentureDetailsDAO() {}

     /**@fn create(EmployeeAccentureInfo& EmployeeAccentureInfo)
      * @brief Insert a EmployeeAccenture into EmployeeAccenture table
      * This method gets an instance of the connection from
      * DBAccess and inserts data from the EmployeeAccentureInfo object
      * into the EmployeeAccenture table.
      * sample usage:
      *        EmployeeAccenture prj;
      *        EmployeeAccentureInfo prjInfo;
      *        //Fill EmployeeAccenture data into prjInfo
      *        prj.create(prjInfo);
      *
      * @param A reference to EmployeeAccentureInfo object containing EmployeeAccenture data
      * @return none
      */
      void create(HRSObject AccentureDetail);

      /**@fn find(std::string searchCriteria)
       * @brief Search the records with the given criteria
       * @param The condition to be specified while searching for records
       * @return A vector of EmployeeAccentureInfo matching the criteria
       */
      std::vector<HRSObject*> find(std::string searchCriteria);

      /**@fn findByAll
       * @brief Retrieve all records from the EmployeeAccenture table
       * @param none
       * @return A vector of all EmployeeAccentureInfo found in the table
       */
      std::vector<HRSObject*> findByAll();

      /**@fn  findByPK
       * @brief Fetch EmployeeAccentures whose primary key value matches the passed one
       * @param pkValue - Value of the primary key (EmployeeAccenture Id)
       * @return EmployeeAccentureInfo - Record Matching the pkValue
       */
      HRSObject* findByPK(std::string pkValue);

      /**@fn remove(std::string pkValue)
       * @brief Remove the EmployeeAccentureInfo from the EmployeeAccenture table given the EmployeeAccentureId
       * @param pkValue - Delete the record corresponding to pkValue
       * @return bool - Status of deletion
       */
      bool remove(std::string pkValue);

      /**@fn update(EmployeeAccentureInfo& piSet)
       * @brief Update those records that match piWhere with piSet
       * @param piSet - the SET part of the UPDATE statement
       * @return bool - status of updatiom
       */
      bool update(HRSObject& piSet);

   };

}
 #endif
