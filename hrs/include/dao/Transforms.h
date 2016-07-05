#ifndef ACCENTUREDETAILSTRANSFORM_H
#define ACCENTUREDETAILSTRANSFORM_H

#include<string>


class ProjectInfo;
class AccentureDetails;
class EmployeeInfo;
class SkillsInformation;
class SkillCategory;

class Transform
{

 public:

      std::string transform(AccentureDetails& info);
      std::string transform(EmployeeInfo& info);
      std::string transform(ProjectInfo& info);
      std::string transform(SkillsInformation& info);
      std::string transform(SkillCategory& info);
};


#endif // ACCENTUREDETAILSTRANSFORM_H
