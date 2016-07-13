// SkillCategoryDAO.h : The DAO layer responsible for direct interaction with the
// database for SkillCategory related issues.

#ifndef SKILLCATEGORYDAO_H
#define SKILLCATEGORYDAO_H

/**@file SkillCategoryDAO.h
 *@brief Delares Data Access Object for SkillCategory.
 * <BR>NAME: SkillCategoryDAO
 *
 * <BR>BASE CLASSES: No Parent
 *
 * <BR>PURPOSE: This class is responsible for direct interaction with the
 *  database for SkillCategory related issues.
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

#include<common/SkillCategory.h>
#include <dao/DAO.h>
#include <common/HRSObject.h>

namespace dao {

  /**@class SkillCategoryDAO SkillCategoryDAO.h ./SkillCategoryDAO.h
   * @brief SkillCategoryDAO is the layer closest to the database.
  * The SkillCategory Business Component forwards calls from the HR Manager to this class.
   * This class gets the Database Connection from DBAccess
   * The following tasks are taken up by this class
   *               1. Insert a SkillCategory in to SkillCategory Table
   *               2. Delete a SkillCategory from the SkillCategory Table
   *               3. Update a SkillCategory's details
   *               4. Find SkillCategorys with specific search criteria
   * </PRE>
   */
  class SkillCategoryDAO : public DAO
  {

  public:

    /**@fn SkillCategoryDAO
     * @brief Default Constructor.
     * This constructor will not take any argument.
     * @param none
     * @return none
     */
    SkillCategoryDAO();

    virtual ~SkillCategoryDAO() {}

    /**@fn create(SkillCategoryInfo& SkillCategoryInfo)
     * @brief Insert a SkillCategory into SkillCategory table
     * This method gets an instance of the connection from
     * DBAccess and inserts data from the SkillCategoryInfo object
     * into the SkillCategory table.
     * sample usage:
     *        SkillCategoryDAO prj;
     *        SkillCategoryInfo prjInfo;
     *        //Fill SkillCategory data into prjInfo
     *        prj.create(prjInfo);
     *
     * @param A reference to SkillCategoryInfo object containing SkillCategory data
     * @return none
     */
    void create(HRSObject& SkillCategory);

    /**@fn find(std::string searchCriteria)
     * @brief Search the records with the given criteria
     * @param The condition to be specified while searching for records
     * @return A vector of SkillCategoryInfo matching the criteria
     */
    std::vector<HRSObject*> find(std::string searchCriteria);

    /**@fn findByAll
     * @brief Retrieve all records from the SkillCategory table
     * @param none
     * @return A vector of all SkillCategoryInfo found in the table
     */
    std::vector<HRSObject*> findByAll();

    /**@fn  findByPK
     * @brief Fetch SkillCategorys whose primary key value matches the passed one
     * @param pkValue - Value of the primary key (SkillCategory Id)
     * @return SkillCategoryInfo - Record Matching the pkValue
     */
    HRSObject* findByPK(std::string pkValue);

    /**@fn remove(std::string pkValue)
     * @brief Remove the SkillCategoryInfo from the SkillCategory table given the SkillCategoryId
     * @param pkValue - Delete the record corresponding to pkValue
     * @return bool - Status of deletion
     */
    bool remove(std::string pkValue);

    /**@fn update(SkillCategoryInfo& piSet)
     * @brief Update those records that match piWhere with piSet
     * @param piSet - the SET part of the UPDATE statement
     * @return bool - status of updatiom
     */
    bool update(HRSObject& piSet);
  };

} // namespace dao
#endif     //SkillCategoryDAO_H
