#include <fstream>
#include <iostream>
#include <string>

#include <dao/assemblers/AccentureDetailsAssembler.h>
#include <common/AccentureDetails.h>
#include <dbaccess/ODBCResultSet.h>
#include <string>



std::string AccentureDetailsAssembler::assemble(AccentureDetails& accenture,std::string query)

{
  char buf[1024];

  sprintf(buf,
	  query.c_str(),
	  accenture.getEmployeeNo().c_str(),
	  accenture.getEnterpriseId().c_str(),
	  accenture.getEnterpriseAddress().c_str(),
	  accenture.getLevel().c_str(),
	  accenture.getLMU().c_str(),
	  accenture.getStatus().c_str(),
	  accenture.getDateHired().c_str(),
	  accenture.getGMU().c_str(),
	  accenture.getWorkGroup().c_str(),
	  accenture.getSpecialty().c_str(),
	  accenture.getServiceLine().c_str()  );

  return std::string(buf);
}
	

AccentureDetails AccentureDetailsAssembler::disAssemble(dbaccess::ODBCResultSet* rs)
{
  AccentureDetails acc;

  acc.setEmployeeNo(rs->getString( rs->getColNum("EMPNO")) );
  acc.setEnterpriseId(rs->getString( rs->getColNum("ENTERPRISEID")) );
  acc.setEnterpriseAddress(rs->getString( rs->getColNum("EMAILADD")) );        
  acc.setLevel(rs->getString( rs->getColNum("EMPLEVEL") ));
  acc.setLMU(rs->getString( rs->getColNum("LMU")) );  
  acc.setStatus(rs->getString( rs->getColNum("STATUS")) );         
  acc.setDateHired(rs->getDate( rs->getColNum("DATEHIRED")) );      
  acc.setGMU(rs->getString( rs->getColNum("GMU")) );            
  acc.setWorkGroup(rs->getString( rs->getColNum("WORKGROUP") ));      
  acc.setSpecialty(rs->getString( rs->getColNum("SPECIALTY") ));      
  acc.setServiceLine(rs->getString( rs->getColNum("SERVICELINE")) );    

  return acc;
} 
