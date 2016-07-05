#include <dao/DAOConstants.h>

std::string DAOConstants::SKILL_UPDATE_MAIN = "UPDATE skill SET %s WHERE ID='%s'";
std::string DAOConstants::SKILL_DELETE = "DELETE skill WHERE  id =  '%s' ";
std::string DAOConstants::SKILL_FIND_MAIN = "SELECT * FROM skill WHERE %s ";
std::string DAOConstants::SKILL_FIND_BYPK = "SELECT * FROM skill WHERE  id =  '%s'";
std::string DAOConstants::SKILL_FIND_ALL = "SELECT * FROM skill";


std::string DAOConstants::SKILLCAT_UPDATE_MAIN = "UPDATE skillcategory SET %s WHERE ID='%s'";
std::string DAOConstants::SKILLCAT_DELETE = "DELETE skillcategory WHERE id =  '%s' ";
std::string DAOConstants::SKILLCAT_FIND_MAIN = "SELECT * FROM skillcategory WHERE %s";
std::string DAOConstants::SKILLCAT_FIND_BYPK =  "SELECT * FROM skillcategory WHERE id =  '%s' ";
std::string DAOConstants::SKILLCAT_FIND_ALL = "SELECT * FROM skillcategory";




std::string DAOConstants::PROJ_UPDATE_MAIN =  "UPDATE project SET %s WHERE ID='%s'";
std::string DAOConstants::PROJ_DELETE = "DELETE project WHERE id =  '%s' ";
std::string DAOConstants::PROJ_FIND_MAIN = "SELECT * FROM project WHERE %s ";
std::string DAOConstants::PROJ_FIND_BYPK = "SELECT * FROM project WHERE id =  '%s' ";
std::string DAOConstants::PROJ_FIND_ALL = "SELECT * FROM project";



	// constants for employee sql create, update, delete, queries
			
std::string DAOConstants::EMPSQL_UPDATE = "UPDATE employee SET %s WHERE EMPNO='%s'";
std::string DAOConstants::EMPSQL_DELETE = "DELETE employee WHERE empno = '%s'";
/*
std::string DAOConstants::EMPSQL_FIND_MAIN = "SELECT EMPNO,FIRSTNAME,LASTNAME,MIDDLENAME,DATEOFBIRTH,  round( months_between(sysdate, dateofbirth)/12) AGE,GENDER,CIVILSTATUS,CITIZENSHIP,SSSNO,TINNO,MOBILENO,HOMENO,STADD1,STADD2,CITY,PROVINCE,COUNTRY,EDUCATTAINMENT,RECOGNITION FROM employee WHERE %s";
std::string DAOConstants::EMPSQL_FIND_BYPK = "SELECT EMPNO,FIRSTNAME,LASTNAME,MIDDLENAME,DATEOFBIRTH,  round( months_between(sysdate, dateofbirth)/12) AGE,GENDER,CIVILSTATUS,CITIZENSHIP,SSSNO,TINNO,MOBILENO,HOMENO,STADD1,STADD2,CITY,PROVINCE,COUNTRY,EDUCATTAINMENT,RECOGNITION FROM employee WHERE empno = '%s'";
std::string DAOConstants::EMPSQL_FIND_ALL = "SELECT EMPNO,FIRSTNAME,LASTNAME,MIDDLENAME,DATEOFBIRTH,  round( months_between(sysdate, dateofbirth)/12) AGE,GENDER,CIVILSTATUS,CITIZENSHIP,SSSNO,TINNO,MOBILENO,HOMENO,STADD1,STADD2,CITY,PROVINCE,COUNTRY,EDUCATTAINMENT,RECOGNITION FROM employee";
*/

std::string DAOConstants::EMPSQL_FIND_MAIN = "SELECT EMPNO,FIRSTNAME,LASTNAME,MIDDLENAME,DATEOFBIRTH, AGE,GENDER,CIVILSTATUS,CITIZENSHIP,SSSNO,TINNO,MOBILENO,HOMENO,STADD1,STADD2,CITY,PROVINCE,COUNTRY,EDUCATTAINMENT,RECOGNITION FROM employee WHERE %s";
std::string DAOConstants::EMPSQL_FIND_BYPK = "SELECT EMPNO,FIRSTNAME,LASTNAME,MIDDLENAME,DATEOFBIRTH, AGE,GENDER,CIVILSTATUS,CITIZENSHIP,SSSNO,TINNO,MOBILENO,HOMENO,STADD1,STADD2,CITY,PROVINCE,COUNTRY,EDUCATTAINMENT,RECOGNITION FROM employee WHERE empno = '%s'";
std::string DAOConstants::EMPSQL_FIND_ALL = "SELECT EMPNO,FIRSTNAME,LASTNAME,MIDDLENAME,DATEOFBIRTH,AGE,GENDER,CIVILSTATUS,CITIZENSHIP,SSSNO,TINNO,MOBILENO,HOMENO,STADD1,STADD2,CITY,PROVINCE,COUNTRY,EDUCATTAINMENT,RECOGNITION FROM employee";

	// constants for employee accenture details create, update, delete, queries

std::string DAOConstants::EMPACC_UPDATE = "UPDATE empaccenturedetail SET %s WHERE EMPNO='%s'";
std::string DAOConstants::EMPACC_DELETE = "DELETE empaccenturedetail WHERE empno =  '%s' ";
std::string DAOConstants::EMPACC_FIND_MAIN = "SELECT * FROM empaccenturedetail WHERE %s";
std::string DAOConstants::EMPACC_FIND_BYPK = "SELECT * FROM empaccenturedetail WHERE empno =  '%s'";
std::string DAOConstants::EMPACC_FIND_ALL = "SELECT * FROM empaccenturedetail";


std::string DAOConstants::EMPSQL_CREATE  = "INSERT INTO employee (" 
			" empno, firstname, lastname, middlename, dateofbirth, age,"
			" gender, civilstatus, citizenship, sssno, tinno,"
			" mobileno, homeno, stadd1, stadd2, city, province,"
			" country, educattainment, recognition )" 
			"VALUES ('%s', '%s', '%s', '%s', '%s', %s, '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s', '%s',"
			" '%s', '%s' ,'%s','%s', '%s') ";


std::string DAOConstants::EMPACC_CREATE = "INSERT INTO empaccenturedetail(empno, enterpriseid, " 
		"emailadd, emplevel, lmu, status, datehired, gmu, workgroup, specialty, serviceline )" 
		" VALUES ( '%s' , '%s' , '%s' , '%s' , '%s' , '%s', '%s' , '%s', '%s' ,'%s' ,'%s' )";

/*protected static String EMPACC_UPDATE = "UPDATE empaccenturedetail SET @@ WHERE @@ ";
	protected static String EMPACC_DELETE = "DELETE empaccenturedetail WHERE empno =  ? ";
	protected static String EMPACC_FIND_MAIN = "SELECT * FROM empaccenturedetail WHERE @@";
	protected static String EMPACC_FIND_BYPK = "SELECT * FROM empaccenturedetail WHERE empno =  ? ";
	protected static String EMPACC_FIND_ALL = "SELECT * FROM empaccenturedetail";*/

std::string DAOConstants::SKILL_CREATE = "INSERT INTO skill (id, catid, name, description, status)" 
			" VALUES ( '%s' , '%s' , '%s' , '%s', '%s')";


/*protected static String SKILL_UPDATE_MAIN = "UPDATE skill SET @ WHERE @ ";
	protected static String SKILL_DELETE = "DELETE skill WHERE  id =  ? ";
	protected static String SKILL_FIND_MAIN = "SELECT * FROM skill WHERE @ ";
	protected static String SKILL_FIND_BYPK = "SELECT * FROM skill WHERE  id =  ? ";
	protected static String SKILL_FIND_ALL = "SELECT * FROM skill";*/

std::string DAOConstants::SKILLCAT_CREATE = "INSERT INTO skillcategory(id, name, description, status)" 
				" VALUES ( '%s' , '%s' , '%s', '%s')";

/*protected static String SKILLCAT_UPDATE_MAIN = "UPDATE skillcategory SET @ WHERE @ ";
	protected static String SKILLCAT_DELETE = "DELETE skillcategory WHERE id =  ? ";
	protected static String SKILLCAT_FIND_MAIN = "SELECT * FROM skillcategory WHERE @";
	protected static String SKILLCAT_FIND_BYPK =  "SELECT * FROM skillcategory WHERE id =  ? ";
	protected static String SKILLCAT_FIND_ALL = "SELECT * FROM skillcategory";*/

std::string DAOConstants::PROJ_CREATE =	"INSERT INTO project (id, name, description," 
		" startdate, enddate, clientname, status)" 
		" VALUES ( '%s' , '%s' , '%s' ,  '%s' ,  '%s' , '%s', '%s' )";

/*protected static String PROJ_UPDATE_MAIN =  "UPDATE project SET @ WHERE @ ";
	protected static String PROJ_DELETE = "DELETE project WHERE id =  ? ";
	protected static String PROJ_FIND_MAIN = "SELECT * FROM project WHERE @ ";
	protected static String PROJ_FIND_BYPK = "SELECT * FROM project WHERE id =  ? ";
	protected static String PROJ_FIND_ALL = "SELECT * FROM project";*/






//ALL ID GENERATORS FOLLOW

std::string DAOConstants::EMPSQL_GETID = "SELECT seq_employee.nextval FROM Dual";

std::string DAOConstants:: CATSQL_GETID = "SELECT seq_skillcategory.nextval FROM Dual";

std::string DAOConstants:: PROJSQL_GETID= "SELECT seq_project.nextval FROM Dual";

std::string DAOConstants:: SKILLSQL_GETID= "SELECT seq_skills.nextval FROM Dual";
