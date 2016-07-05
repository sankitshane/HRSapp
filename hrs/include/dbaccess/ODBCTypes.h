#ifndef ODBCTYPES_H
#define ODBCTYPES_H

/**@file ODBCTypes.h
*@brief  Contains all the types internally used for ODBC connectivity.
* $Header: ODBCTypes.h 
*
* NAME: ODBCTypes
*  
* PURPOSE:This file contains all the types internally used for ODBC connectivity.
* 
* AUTHOR: Gowri Ramasubramanian
* 
* $Revision: 1.9 $
* 
* $Log: ODBCTypes.h,v $
* Revision 1.9  2005/09/02 11:40:12  Jignesh.Kanchanlal
* Ready for Final Release
*
* Revision 1.1  2005/08/11 10:27:27  Jignesh.Kanchanlal
* Added for the first time
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

///////////////////////////////////////////////////////////////

///Typedefs

///Constants and defines

///Includes

///Externals

///Variables

///Enumerations and Classes
/// ADBC::Types  Contains the enums/types used by ADBC across different connectivities like ODBC etc
/// ADBC::Types::ODBC  Contains ODBC specific enums to denote handletypes, cursortypes etc.

///Enumerations and Classes
/// ADBC::Types::ODBC::HANDLE_TYPE : enum to denote Handle types like connection handle, statement handle - used by Error::getErrorMessage()
/// ADBC::Types::ODBC::SCROLL_TYPE : enum to denote Cursor types like Scroll_Sensitive, Forward_Only etc
/// ADBC::Types::ODBC::CONCURRENT_TYPE : enum to denote Cursor types like Concurrent with Read_Only, Updatable etc.

namespace dbaccess {

/**@namespace dbaccess::Types
*@brief Contains the enums/types used by ADBC across different connectivities like ODBC etc.
*/
namespace Types
{
		/**@namespace dbaccess::Types::ODBC
		 *@brief dbaccess::Types::ODBC  Contains ODBC specific enums to denote handletypes, cursortypes etc.
		*/
		namespace ODBC
		{
			/** @enum ADBC::Types::ODBC::HANDLE_TYPE 
			*@brief enum to denote Handle types like connection handle, statement handle - used by Error::getErrorMessage().
			*/
			enum HANDLE_TYPE
			{
				ENV_HDL = 1,
				CONN_HDL,
				STMT_HDL,
				DESC_HDL
			};
			/** @enum ADBC::Types::ODBC::SCROLL_TYPE 
			*   enum to denote Cursor types like Scroll_Sensitive, Forward_Only etc.
			*/
			enum SCROLL_TYPE
			{
				FORWARD_ONLY,
				SCROLL_SENSITIVE ,
				SCROLL_INSENSITIVE
			};
			/** @enum ADBC::Types::ODBC::CONCURRENT_TYPE 
			*	enum to denote Cursor types like Concurrent with Read_Only, Updatable etc.
			*/
			enum CONCURRENT_TYPE
			{
				READ_ONLY,
				UPDATABLE
			};
		}//namespace ODBC
}

} //namespace dbaccess
#endif  //ODBCTYPES_H

