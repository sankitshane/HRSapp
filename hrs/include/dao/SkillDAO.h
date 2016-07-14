// SkillDAO.h : The DAO layer responsible for direct interaction with the
// database for Skills under each of the categories in SkillCategory.

#ifndef SKILLDAO_H
#define SKILLDAO_H

/**@file SkillDAO.h
 * @brief Delares Data Access Object for Skill.
 *
 * <BR>NAME: SkillDAO
 * 
 * <BR>BASE CLASSES: No Parent
 * 
 * <BR>PURPOSE: This class is responsible for direct interaction with the
 *  database for Skill related issues.
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
#include<common/SkillsInformation.h>
#include <dao/DAO.h>
#include <common/HRSObject.h>

namespace dao {
	
  /**@class SkillDAO SkillDAO.h ./SkillDAO.h
   * @brief SkillDAO is the layer closest to the database.
   * The Skill Business Component forwards calls from the HR Manager to this class.
   * This class gets the Database Connection from DBAccess
   * The following tasks are taken up by this class
   *               1. Insert a Skill in to Skill Table
   *               2. Delete a Skill from the Skill Table
   *               3. Update a Skill's details
   *               4. Find Skills with specific search criteria
   * </PRE> 
   */
  class SkillDAO : public DAO
  {
       
  public:
    /**@fn SkillDAO
     * @brief Default Constructor.
     * This constructor will not take any argument.
     * @param none
     * @return none
     */
    SkillDAO();
    virtual ~SkillDAO() {}

    /**@fn create(SkillInformation& skillInformation)
     * @brief Insert a Skill into Skill table
     * This method gets an instance of the connection from
     * DBAccess and inserts data from the SkillInformation object
     * into the Skill table.
     * sample usage:
     *        SkillDAO skill;
     *        SkillInformation skillInformation;
     *        //Fill Skill data into skillInformation object
     *        skill.create(skillInformation);
     *
     * @param A reference to SkillInformation object containing skill data
     * @return none
     */ 
    void create(HRSObject& SkillInformation);
       
    /**@fn find(std::string searchCriteria)
     * @brief Search the records with the given criteria
     * @param The condition to be specified while searching for records
     * @return A vector of SkillInformation matching the criteria
     */            
    std::vector<HRSObject*> find(std::string searchCriteria);

    /**@fn findByAll
     * @brief Retrieve all records from the Skill table
     * @param none
     * @return A vector of all Skills found in the table 
     */            
    std::vector<HRSObject*> findByAll();

    /**@fn  findByPK(std::string pkValue)
     * @brief Fetch Skills whose primary key value matches the passed one
     * @param pkValue - Value of the primary key (Skill  Id)
     * @return SkillInformation - Record Matching the pkValue 
     */            
    HRSObject* findByPK(std::string pkValue);     

    /**@fn remove( std::string pkValue)
     * @brief Remove the Skill from the Skill table given the Skill Id
     * @param pkValue - Delete the record corresponding to pkValue
     * @return bool - Status of deletion
     */            
    bool remove( std::string pkValue);       
      
    /**@fn update( SkillInformation& piSet)
     * @brief Update those records that match piWhere with piSet
     * @param piSet - the SET part of the UPDATE statement
     * @return bool - status of updatiom
     */            
    bool update(HRSObject& piSet);      
  };

}	//namespace dao
#endif     //SKILLDAO_H
