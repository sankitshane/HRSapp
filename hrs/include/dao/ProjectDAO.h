// ProjectDAO.h : The DAO layer responsible for direct interaction with the
// database for Project related issues.

#ifndef PROJECTDAO_H
#define PROJECTDAO_H

/**@file ProjectDAO.h
 *@brief Delares Data Access Object for Project.
 * <BR>NAME: ProjectDAO
 * 
 * <BR>BASE CLASSES: No Parent
 * 
 * <BR>PURPOSE: This class is responsible for direct interaction with the
 *  database for Project related issues.
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

#include<common/ProjectInfo.h>
#include <dao/DAO.h>
#include <common/HRSObject.h>

namespace dao {

  /**@class ProjectDAO ProjectDAO.h ./ProjectDAO.h
   * @brief ProjectDAO is the layer closest to the database.
  * The Project Business Component forwards calls from the HR Manager to this class.
   * This class gets the Database Connection from DBAccess
   * The following tasks are taken up by this class
   *               1. Insert a Project in to Project Table
   *               2. Delete a Project from the Project Table
   *               3. Update a Project's details
   *               4. Find Projects with specific search criteria
   * </PRE> 
   */
  class ProjectDAO : public DAO
  {
       
  public:
       
    /**@fn ProjectDAO
     * @brief Default Constructor.
     * This constructor will not take any argument.
     * @param none
     * @return none
     */
    ProjectDAO();

    virtual ~ProjectDAO() {}

    /**@fn create(ProjectInfo& projectInfo)
     * @brief Insert a Project into Project table
     * This method gets an instance of the connection from
     * DBAccess and inserts data from the projectInfo object
     * into the Project table.
     * sample usage:
     *        ProjectDAO prj;
     *        ProjectInfo prjInfo;
     *        //Fill Project data into prjInfo
     *        prj.create(prjInfo);
     *
     * @param A reference to ProjectInfo object containing Project data
     * @return none
     */            
    void create(HRSObject& projectInfo);
       
    /**@fn find(std::string searchCriteria)
     * @brief Search the records with the given criteria
     * @param The condition to be specified while searching for records
     * @return A vector of ProjectInfo matching the criteria
     */            
    std::vector<HRSObject*> find(std::string searchCriteria);

    /**@fn findByAll
     * @brief Retrieve all records from the Project table
     * @param none
     * @return A vector of all ProjectInfo found in the table 
     */            
    std::vector<HRSObject*> findByAll();

    /**@fn  findByPK
     * @brief Fetch Projects whose primary key value matches the passed one
     * @param pkValue - Value of the primary key (Project Id)
     * @return ProjectInfo - Record Matching the pkValue 
     */            
    HRSObject* findByPK(std::string pkValue);     

    /**@fn remove(std::string pkValue)
     * @brief Remove the ProjectInfo from the Project table given the ProjectId
     * @param pkValue - Delete the record corresponding to pkValue
     * @return bool - Status of deletion
     */            
    bool remove(std::string pkValue);       
      
    /**@fn update(ProjectInfo& piSet)
     * @brief Update those records that match piWhere with piSet
     * @param piSet - the SET part of the UPDATE statement
     * @return bool - status of updatiom
     */            
    bool update(HRSObject& piSet);      
  };

} // namespace dao
#endif     //PROJECTDAO_H
