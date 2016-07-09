#include <fstream>
#include <iostream>
#include <string>

#include<dao/assemblers/SkillCategoryAssembler.h>
#include<common/SkillCategoryInfo.h>
#include<dbaccess/ODBCResultSet.h>

std::string SkillCategoryAssembler::assemble(SkillCategoryInfo& SkillCategorys,std::string query)

{
	char buf[1024];

	sprintf(buf,query.c_str(),
				      SkillCategorys.getSkillCategoryId().c_str(),
					  SkillCategorys.getSkillCategoryName().c_str(),
					  SkillCategorys.getSkillCategoryDescription().c_str(),
					  SkillCategorys.getStartDate().c_str(),
					  SkillCategorys.getEndDate().c_str(),
					  SkillCategorys.getClient().c_str(),
					  SkillCategorys.getStatus().c_str());

	return std::string(buf);
}


  SkillCategoryInfo SkillCategoryAssembler::disAssemble(dbaccess::ODBCResultSet* rs)
  {

	  SkillCategoryInfo proj;


	   proj.setSkillCategoryId( rs->getString( rs->getColNum("ID")) );
	   proj.setSkillCategoryName( rs->getString( rs->getColNum("NAME")) );
	   proj.setSkillCategoryDescription( rs->getString( rs->getColNum("DESCRIPTION")) );
	   proj.setStartDate( rs->getDate( rs->getColNum("STARTDATE") ));
	   proj.setEndDate( rs->getDate( rs->getColNum("ENDDATE")) );
	   proj.setClient( rs->getString( rs->getColNum("CLIENTNAME")) );
	   proj.setStatus( rs->getString( rs->getColNum("STATUS") ));

	   return proj;
  }
