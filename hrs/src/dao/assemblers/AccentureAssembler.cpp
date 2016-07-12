#include <fstream>
#include <iostream>
#include <string>

#include<dao/assemblers/EmpAccentureAssembler.h>
#include<common/AccentureDetails.h>
#include<dbaccess/ODBCResultSet.h>

std::string AccentureAssembler::assemble(AccentureDetails& AccDetails,std::string query)

{
	char buf[1024];

	sprintf(buf,query.c_str(),
				      AccDetails.getEmployeeNo().c_str(),
					  AccDetails.getEnterpriseId().c_str(),
					  AccDetails.getDateHired().c_str(),
					  AccDetails.getEnterpriseAddress().c_str(),
					  AccDetails.getGMU().c_str(),
					  AccDetails.getLevel().c_str(),
					  AccDetails.getLMU().c_str());
            AccDetails.getServiceLine().c_str());
            AccDetails.getSpecialty().c_str());
            AccDetails.getStatus().c_str());
            AccDetails.getWorkGroup().c_str());


	return std::string(buf);
}


  AccentureDetails AccentureAssembler::disAssemble(dbaccess::ODBCResultSet* rs)
  {

	   AccentureDetails AccDetails;


	   AccDetails.setEmployeeNo( rs->getString( rs->getColNum("EMPNO")) );
	   AccDetails.setEnterpriseId( rs->getString( rs->getColNum("ENTERPRISEID")) );
	   AccDetails.setDateHired( rs->getString( rs->getColNum("DATEHIRED")) );
	   AccDetails.setEnterpriseAddress( rs->getDate( rs->getColNum("ENTERPRISEID") ));
	   AccDetails.setGMU( rs->getDate( rs->getColNum("GMU")) );
	   AccDetails.setLevel( rs->getString( rs->getColNum("LEVEL")) );
	   AccDetails.setLMU( rs->getString( rs->getColNum("LMU") ));
     AccDetails.setServiceLine( rs->getString( rs->getColNum("SERVICELINE")));
     AccDetails.setSpecialty( rs->getString( rs->getColNum("SPECIALTY")));
     AccDetails.setStatus( rs->getString( rs->getColNum("STATUS")));
     AccDetails.setWorkGroup( rs->getString( rs->getColNum("WORKGROUP")));

	   return AccDetails;
  }
