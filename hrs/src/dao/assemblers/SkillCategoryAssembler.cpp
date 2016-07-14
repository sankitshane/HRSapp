#include <fstream>
#include <iostream>
#include <string>

#include<dao/assemblers/SkillCategoryAssembler.h>
#include<common/SkillCategory.h>
#include<dbaccess/ODBCResultSet.h>

std::string SkillCategoryAssembler::assemble(SkillCategory& category, std::string query)
		
{
	char buf[1024];

	sprintf(buf,query.c_str(),
		 category.getCategoryId().c_str(),
		 category.getCategoryName().c_str(),
		 category.getCategoryDescription().c_str(),
		 category.getStatus().c_str());

	return std::string(buf);
}

SkillCategory SkillCategoryAssembler::disAssemble(dbaccess::ODBCResultSet* rs)

 {
		
	 SkillCategory cat;

	 cat.setCategoryId( rs->getString( rs->getColNum("ID") ));
	 cat.setCategoryName( rs->getString( rs->getColNum("NAME")) );          
	 cat.setCategoryDescription(rs->getString( rs->getColNum("DESCRIPTION")) );
	 cat.setStatus(rs->getString( rs->getColNum("STATUS")) );

	 return cat;
 }

