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
					  Skills.getSkillCatId().c_str(),
					  Skills.getSkillName().c_str(),
					  Skills.getSkillDescription().c_str(),
					  Skills.getStatus().c_str());

	return std::string(buf);
}


  SkillInfo SkillAssembler::disAssemble(dbaccess::ODBCResultSet* rs)
  {

	  SkillInfo skill;


	   skill.setSkillId( rs->getString( rs->getColNum("ID")) );
	   skill.setSkillId( rs->getString( rs->getColNum("CATID")));
	   skill.setSkillName( rs->getString( rs->getColNum("NAME")) );
	   skill.setSkillDescription( rs->getString( rs->getColNum("DESCRIPTION")) );
	   skill.setStatus( rs->getString( rs->getColNum("STATUS") ));

	   return skill;
  }
