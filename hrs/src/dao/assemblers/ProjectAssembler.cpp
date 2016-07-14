#include <fstream>
#include <iostream>
#include <string>

#include<dao/assemblers/ProjectAssembler.h>
#include<common/ProjectInfo.h>
#include<dbaccess/ODBCResultSet.h>

std::string ProjectAssembler::assemble(ProjectInfo& projects,std::string query)

{
	char buf[1024];

	sprintf(buf,query.c_str(),	  
				      projects.getProjectId().c_str(),
					  projects.getProjectName().c_str(),
					  projects.getProjectDescription().c_str(),
					  projects.getStartDate().c_str(),
					  projects.getEndDate().c_str(),
					  projects.getClient().c_str(),
					  projects.getStatus().c_str());

	return std::string(buf);
}


  ProjectInfo ProjectAssembler::disAssemble(dbaccess::ODBCResultSet* rs)
  {

	  ProjectInfo proj;

	
	   proj.setProjectId( rs->getString( rs->getColNum("ID")) );             
	   proj.setProjectName( rs->getString( rs->getColNum("NAME")) );
	   proj.setProjectDescription( rs->getString( rs->getColNum("DESCRIPTION")) );
	   proj.setStartDate( rs->getDate( rs->getColNum("STARTDATE") ));      
	   proj.setEndDate( rs->getDate( rs->getColNum("ENDDATE")) );        
	   proj.setClient( rs->getString( rs->getColNum("CLIENTNAME")) );    
	   proj.setStatus( rs->getString( rs->getColNum("STATUS") ));

	   return proj;
  }

