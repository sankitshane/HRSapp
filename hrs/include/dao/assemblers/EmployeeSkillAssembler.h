
#include<string>
class ODBCResultSet;

class EmployeeSkillProfile;

class EmployeeSkillAssembler
{
	
  public:

	  static std::string assemble(EmployeeSkillProfile& skills,std::string query);
				   

	  static EmployeeSkillProfile disAssemble(ODBCResultSet* rs);

	 
};