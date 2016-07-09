#include <fstream>
#include <iostream>
#include <string>

#include<dao/assemblers/SkillAssembler.h>
#include<common/SkillInfo.h>
#include<dbaccess/ODBCResultSet.h>

std::string SkillAssembler::assemble(SkillInfo& Skills,std::string query)

{
	char buf[1024];

	sprintf(buf,query.c_str(),
				      Skills.getSkillId().c_str(),
					  Skills.getSkillName().c_str(),
					  Skills.getSkillDescription().c_str(),
					  Skills.getStartDate().c_str(),
					  Skills.getEndDate().c_str(),
					  Skills.getClient().c_str(),
					  Skills.getStatus().c_str());

	return std::string(buf);
}


  SkillInfo SkillAssembler::disAssemble(dbaccess::ODBCResultSet* rs)
  {

	  SkillInfo proj;


	   proj.setSkillId( rs->getString( rs->getColNum("ID")) );
	   proj.setSkillName( rs->getString( rs->getColNum("NAME")) );
	   proj.setSkillDescription( rs->getString( rs->getColNum("DESCRIPTION")) );
	   proj.setStartDate( rs->getDate( rs->getColNum("STARTDATE") ));
	   proj.setEndDate( rs->getDate( rs->getColNum("ENDDATE")) );
	   proj.setClient( rs->getString( rs->getColNum("CLIENTNAME")) );
	   proj.setStatus( rs->getString( rs->getColNum("STATUS") ));

	   return proj;
  }
