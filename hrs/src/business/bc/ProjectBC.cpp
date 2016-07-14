#include<business/ProjectBC.h>
#include<common/ProjectInfo.h>
#include<dao/ProjectDAO.h>
#include<business/idgen/ProjectIdGen.h>

/**@file ProjectBC.cpp
* @brief HRS Application : Defines the ProjectBC Class.
*
* <BR>NAME:ProjectBC
* 
* <BR>BASE CLASSES:None
* 
* <BR>PURPOSE:To do the effective communication bitween the HRManager class and the ProjectDAO class
*
* <BR>AUTHOR:Vinoj.V.S
* <BR>
* <BR>$Revision: $6/12/2005
* 
* <BR>$Log:6/12/2005
* 
* <BR>COPYRIGHT NOTICE:
* <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/
#ifdef ALOGGER
#include<logger/Logger.h>
#endif


namespace bc{

 /**@fn ProjectBC
   * @brief Default Constructor.
   * This constructor will not take any argument.
   * It will initialize both the variable to ZERO.
   * @param none
   * @return none
   */

  ProjectBC::ProjectBC()
  {
  }

		    


 /**@fn createProject
   * @brief it creats the project 
   * It create the project data
   * returns nothing.
   * @param reference to the objectof ProjectInfo
   * @return nothing.
   */
  void ProjectBC::createProject(ProjectInfo& info)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "About to get unique id");
#endif

    std::string id=(idgen::ProjectIdGen::getInstance())->getNextId();

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str());
#endif

    info.setProjectId(id);//proj is an instance of the class ProjectInfo and id is a string
    m_projectDAO.create(info); 

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
#endif
	
	
  }
	


  /**@fn searchProject
   * @brief it seerchs for a project 
   * @param std::string id
   * @return an object of the class Projectinfo.
   */
  ProjectInfo ProjectBC::searchProject(std::string id)
  {
    ProjectInfo pInfo;
    ProjectInfo* pInfoPtr = NULL;
	

#ifdef ALOGGER
    //logger::Logger::getInstance().info("EmployeeBC::searchEmployee::searching an Employee");
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, id.c_str() );
#endif	
    pInfoPtr = static_cast<ProjectInfo*>(m_projectDAO.findByPK(id));//we may overload == operator in projectInfo

    pInfo = *pInfoPtr;
    delete pInfoPtr;

    return pInfo;
  }

 /**@fn searchProjects
   * @brief it seerchs for a collection of projects 
   * @param an reference to the object of ProjectInfo.
   * @return a set of objects to the class Projectinfo.
   */
  std::vector<ProjectInfo> ProjectBC::searchProjects(std::string name)
  {

#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, name.c_str() );
#endif

    std::vector<ProjectInfo> prjList;

    std::vector<HRSObject*> prjListPtr;


      prjListPtr = m_projectDAO.find(name);

    int size = prjListPtr.size();
    for(int i = 0; i < size; ++i)
      {
	prjList.push_back( *(static_cast<ProjectInfo*>(prjListPtr[i])) );
      }
    for(int i = 0; i < size; ++i)
      delete prjListPtr[i];
    prjListPtr.clear();
	
    return prjList;
  }


   
  /**@fn updateProject
   * @brief it updtes the project
   * This function updates the information of the project records in the database.
   * Returns nothing
   * @param an reference to the object of Projectinfo
   * @return none
   */
  void ProjectBC::updateProject(ProjectInfo& info)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
    //logger::Logger::getInstance().info("EmployeeBC::updateEmployee::About to updatet the Employee");
#endif	
    m_projectDAO.update(info);
  }
  
}//namespace bc

