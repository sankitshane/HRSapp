
#include<string>
class ODBCResultSet;

class EmployeeSkillCategoryProfile;

class EmployeeSkillCategoryAssembler
{

  public:

	  static std::string assemble(EmployeeSkillCategoryProfile& SkillCategorys,std::string query);


	  static EmployeeSkillCategoryProfile disAssemble(ODBCResultSet* rs);


};
