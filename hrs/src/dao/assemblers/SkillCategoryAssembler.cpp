#include <fstream>
#include <iostream>
#include <string>

#include<dao/assemblers/SkillCategoryAssembler.h>
#include<common/SkillCategory.h>
#include<dbaccess/ODBCResultSet.h>

std::string SkillCategoryAssembler::assemble(SkillCategory& SkillCategorys,std::string query)

{
	char buf[1024];

	sprintf(buf,query.c_str(),
				    SkillCategorys.getSkillCategoryId().c_str(),
					  SkillCategorys.getSkillCategoryName().c_str(),
					  SkillCategorys.getSkillCategoryDescription().c_str(),
					  SkillCategorys.getStatus().c_str());

	return std::string(buf);
}


  SkillCategory SkillCategoryAssembler::disAssemble(dbaccess::ODBCResultSet* rs)
  {

	  SkillCategory skillcat;


	   skillcat.setSkillCategoryId( rs->getString( rs->getColNum("ID")) );
	   skillcat.setSkillCategoryName( rs->getString( rs->getColNum("NAME")) );
	   skillcat.setSkillCategoryDescription( rs->getString( rs->getColNum("DESCRIPTION")) );
	   skillcat.setStatus( rs->getString( rs->getColNum("STATUS") ));

	   return skillcat;
  }
