#ifndef DAOCONSTANTS_H
#define DAOCONSTANTS_H

#include<string>

#include<iostream>

class DAOConstants 
{
    public:// constants for employee sql create, update, delete, queries
	   static std::string EMPSKILLSQL_CREATE;

	   static std::string	EMPPROJ_CREATE;	

	   static std::string	EMPACC_CREATE;

	   static std::string	SKILL_CREATE;

	   static std::string	SKILLCAT_CREATE;



	   static std::string	PROJ_CREATE;



	   //ALL ID GENERATOR STATEMENTS

	   static std::string EMPSQL_GETID;

   	   static std::string CATSQL_GETID;

   	   static std::string PROJSQL_GETID;

   	   static std::string SKILLSQL_GETID;

	   

	   static std::string EMPACC_UPDATE;

	   static std::string EMPACC_DELETE;

	   static std::string EMPACC_FIND_MAIN;

	   static std::string EMPACC_FIND_BYPK;

	   static std::string EMPACC_FIND_ALL;
	   

	   static std::string EMPSQL_CREATE;
			
	   static std::string EMPSQL_UPDATE;
	
	   static std::string EMPSQL_DELETE ;
	
	   static std::string EMPSQL_FIND_MAIN;
	   	
	   static std::string EMPSQL_FIND_BYPK;

	   static std::string EMPSQL_FIND_ALL;


   	   static std::string PROJ_UPDATE_MAIN;

	   static std::string PROJ_DELETE ;

	   static std::string PROJ_FIND_MAIN ;

	   static std::string PROJ_FIND_BYPK ;

	   static std::string PROJ_FIND_ALL ;
	   

	   static std::string SKILLCAT_UPDATE_MAIN ;

   	   static std::string SKILLCAT_DELETE ;

	   static std::string SKILLCAT_FIND_MAIN ;
	   
	   static std::string SKILLCAT_FIND_BYPK ;

	   static std::string SKILLCAT_FIND_ALL; 

	   
	   static std::string SKILL_UPDATE_MAIN;
		   
	   static std::string SKILL_DELETE ;
	   
	   static std::string SKILL_FIND_MAIN;
	   
   	   static std::string SKILL_FIND_BYPK ;

   	   static std::string SKILL_FIND_ALL ;
		   

	   
};
#endif //DAOCONSTANTS_H
