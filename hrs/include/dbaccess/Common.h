#ifndef COMMON_H
#define COMMON_H
/** @file Common.h
*@brief Contains Date, Time, Byte, Bytes types required by ADBC
*
* $Header: Common.h 
* NAME: Common
*  
* PURPOSE: This file contains Date, Time, Byte, Bytes types required by ADBC
* 
* AUTHOR: Gurudutt Mallapur, Nitesh Sahu
* 
* DATE: 16-08-2005
*
* $Revision: 1.7 $
* 
* $Log: Common.h,v $
* Revision 1.7  2005/09/02 11:40:12  Jignesh.Kanchanlal
* Ready for Final Release
*
* Revision 1.4  2005/08/12 12:31:37  Jignesh.Kanchanlal
* Added for the first time after integration
*
* Revision 1.1  2005/08/11 10:27:27  Jignesh.Kanchanlal
* Added for the first time
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/


#ifdef WIN32
//required by sql.h etc.
#include <windows.h>
#endif

#include <sql.h>
#include <sqlext.h>

namespace dbaccess {


#include <dbaccess/ODBCTypes.h>

	/**@struct Date
	* @brief used by ResultSet::getDate() method and overriding methods.
	*/
	struct Date { 
			short year;		
			short month;
			short day;
	};
	
	/** @struct Time 
	* @brief used by ResultSet::getTime() method and overriding methods.
	*/	
	struct Time { 
			short hour;
			short minute;
			short second;
	};

} //namespace dbaccess

#endif  //COMMON_H

