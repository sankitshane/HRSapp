// SkillCategoryDAO.h : The DAO layer responsible for direct interaction with the
// database for Major Skill Category related issues.

#ifndef SKILLCATEGORYDAO_H
#define SKILLCATEGORYDAO_H

#include<vector>
#include<string>

#include<common/SkillCategory.h>
#include <dao/DAO.h>
#include <common/HRSObject.h>

/**@file SkillCategoryDAO.h
 * @brief Delares Data Access Object for Skill Category.
 *
 * <BR>NAME: SkillCategoryDAO
 * 
 * <BR>BASE CLASSES: No Parent
 * 
 * <BR>PURPOSE: This class is responsible for direct interaction with the
 *  database for Major Skill Category related issues.
 *
 * <BR>AUTHOR: Arun Veeramany
 * <BR>$Revision: 9th Dec'05
 * 
 * <BR>$Log: 9th Dec'05
 * 
 * <BR>COPYRIGHT NOTICE:
 * <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
 */

namespace dao {

  /**@class SkillCategoryDAO SkillCategoryDAO.h ./SkillCategoryDAO.h
   * @brief SkillCategoryDAO is the layer closest to the database.
   * The Skill Business Component forwards calls from the HR Manager to this class.
   * This class gets the Database Connection from DBAccess
   * The following tasks are taken up by this class
   *               1. Insert a SkillCategory in to SkillCategory Table
   *               2. Delete a SkillCategoryDAO from the SkillCategory Table
   *               3. Update a SkillCategoryDAO's details
   *               4. Find SkillCategory with specific search criteria
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

    /**@fn create( SkillCategory& skillCategory)
     * @brief Insert a SkillCategory into SkillCategory table
     * This method gets an instance of the connection from
     * DBAccess and inserts data from the skillCategory object
     * into the skillCategory table.
     * sample usage:
     *        SkillCategoryDAO scDAO;
     *        SkillCategory sc;
     *        //Fill Skill Category data into sc
     *        scDAO.create(sc);
     *
     * @param A reference to SkillCategory object containing Skill Category data
     * @return none
     */            
    void create(HRSObject& skillCategory);
       
    /**@fn find(std::string searchCriteria)
     * @brief Search the records with the given criteria
     * @param The condition to be specified while searching for records
     * @return A vector of SkillCategory matching the criteria
     */            
    std::vector<HRSObject*> find(std::string searchCriteria);

    /**@fn findByAll
     * @brief Retrieve all records from the SkillCategory table
     * @param none
     * @return A vector of all SkillCategory found in the table 
     */            
    std::vector<HRSObject*> findByAll();

    /**@fn  findByPK
     * @brief Fetch SkillCategories whose primary key value matches the passed one
     * @param pkValue - Value of the primary key (SkillCategory Id)
     * @return SkillCategory - Record Matching the pkValue 
     */            
    HRSObject* findByPK(std::string pkValue);     

    /**@fn remove(std::string pkValue)
     * @brief Remove the SkillCategory from the SkillCategory table given the SkillCategory Id
     * @param pkValue - Delete the record corresponding to pkValue
     * @return bool - Status of deletion
     */            
    bool remove(std::string pkValue);       
      
    /**@fn update(SkillCategory& piSet)
     * @brief Update those records that match piWhere with piSet
     * @param piSet - the SET part of the UPDATE statement
     * @return bool - status of updatiom
     */            
    bool update( HRSObject& piSet);      
  };

}	//namespace dao
#endif     //SKILLCATEGORYDAO_H
