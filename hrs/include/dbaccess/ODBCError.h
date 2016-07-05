#ifndef ODBCERROR_H
#define ODBCERROR_H

/**
* @file ODBCError.h
* @brief Retrives the error messages specific to ODBC.
* 
* NAME: ODBCError
* $Header: ODBCError.h
* BASE CLASSES: Error
* 
* PURPOSE: Error details are retrived from ODBC.
* 
* AUTHOR: Gowri Ramasubramanian
* 
* $Revision: 1.13 $
* 
* $Log: ODBCError.h,v $
* Revision 1.13  2005/09/02 11:40:12  Jignesh.Kanchanlal
* Ready for Final Release
*
* Revision 1.12  2005/08/30 05:21:26  Jignesh.Kanchanlal
* Bugs after Testing fixed
*
* Revision 1.11  2005/08/23 11:55:48  Jignesh.Kanchanlal
* Code Review Comments Incorporated
*
* Revision 1.8  2005/08/17 09:56:18  Jignesh.Kanchanlal
* changed to work with test application
*
* Revision 1.6  2005/08/12 12:31:37  Jignesh.Kanchanlal
* Added for the first time after integration
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/


///////////////////////////////////////////////////////////////

//Includes
#include <string>
#include <fstream>
#include <iostream>

using std::string;


#ifdef WIN32
	#include <windows.h> ///<required by sql.h etc
#endif
#include <sql.h> ///<for ODBC related includes
#include <sqlext.h> ///<for ODBC related includes

#include <dbaccess/ODBCTypes.h> ///<common types used by ADBC

#ifdef ALOGGER
	#include <logger/Logger.h> ///<logging comments
#endif

	
//Constants and defines
const int ID_RETURN_CODE = SQL_DIAG_RETURNCODE;	///< isError() and isWarning()
const int ID_ERROR_CODE = SQL_DIAG_SQLSTATE;	///< getErrorCode()
const int ID_ERROR_MSG = SQL_DIAG_MESSAGE_TEXT; ///< getErrorMessage()

#ifdef CPPUNIT_TESTING
	namespace ADBC_TEST
	{
		class ODBCErrorTest;
	}
#endif

namespace dbaccess  {

    /** @class ODBCError
     * @brief Implementation of Error class for ODBC connectivity.
     */
	class ODBCError
	{
	//Constructor and destructor
	public:		

			/** Overloaded default Constructor.
			* <BR>NAME: ODBCError
			* <BR>DESCRIPTION: Constructor for the ODBCError Object. 
			* <BR> Initialises the handle (statement, descriptor, environment
			* <BR> or connection) and the handle type to identify the handles.
			* <BR>SIDE EFFECTS: Nil
			* <BR>PARAMETERS: 
			* 	@param Nil
			* 
			*/
			ODBCError();

			/** Default Destructor.
			* <BR>NAME: ~ODBCError
			* <BR>DESCRIPTION: Destructor for the ODBCError Object.
			* <BR>SIDE EFFECTS: Nil
			* <BR>PARAMETERS: 
			* 	@param Nil
			* 
			*/
			virtual ~ODBCError();
	
	//Public variables
	public:
		friend class ODBCConnection; ///<So that Connection object can set handle and handle type
		friend class ODBCStatement; ///<So that Statement object can set handle and handle type
		friend class ODBCResultSet; ///<So that ResultSet object can set handle and handle type
		#ifdef CPPUNIT_TESTING	
			friend class ADBC_TEST::ODBCErrorTest; ///<So that ODBCErrorTest can acess the private variables
		#endif
	//Public Functions
	public:	
			/** Implementation in ODBC to check if there was an error.
			* <BR>NAME: isError
			* <BR>DESCRIPTION: Uses SQLGetDiagField with SQL_DIAG_RETURNCODE as the identifer. 
			* <BR> After executing any ADBC API it is recommended that the user should check whether there 
			* <BR> there was an error due to the connectivity, in this case ODBC with isError().
			* <BR> Record Number is 0 since SQL_DIAG_RETURNCODE is a header field and is ignored.
			* <BR>SIDE EFFECTS: Throws GeneralException if SQLGetDiagField returns error/invalid handle.
			* <BR>PARAMETERS: 
			* 	@param void
			* <BR>RETURN: 
			* 	@return bool - true if SQLGetDiagField returns SQL_ERROR else false.
			*/
			virtual bool isError();	

			/** Implentation in ODBC to check if there was a warning.
			* <BR>NAME: isWarning
			* <BR>DESCRIPTION: Uses SQLGetDiagField with SQL_DIAG_RETURNCODE as the identifer.
		 	* <BR> After executing any ADBC API it is recommended that the user should check whether there 
			* <BR> there was a warning due to the connectivity, in this case ODBC with isWarning().
			* <BR> Record Number is 0 since SQL_DIAG_RETURNCODE is a header field and is ignored. 
			* <BR>SIDE EFFECTS: Throws GeneralException if SQLGetDiagField returns error/invalid handle.
			* <BR>PARAMETERS: 
			* 	@param void
			* <BR>RETURN: 
			* 	@return bool - true if SQLGetDiagField returns SQL_SUCCESS_WITH_INFO else false.
			*/
			virtual bool isWarning();

			/** Implentation in ODBC to get the error code.
			* <BR>NAME: getErrorCode
			* <BR>DESCRIPTION: Uses SQLGetDiagField with SQL_DIAG_SQLSTATE as the identifer. 
			* <BR> After executing any ADBC API it is recommended that the user should check whether there 
			* <BR> was an Error due to the connectivity, in this case ODBC, using isError then use 
			* <BR> getErrorCode to retrieve the error code.
			* <BR> Record Number is 1 since ID_ERROR_CODE is not a header field and hence not ignored. 
			* <BR>SIDE EFFECTS: Throws GeneralException if SQLGetDiagField returns error/invalid handle.
			* <BR>PARAMETERS: 
			* 	@param void
			* <BR>RETURN: 
			* 	@return string - Returns the last returned error code.
			*/
			virtual const string getErrorCode() const;
			
			/** Implentation in ODBC to get the error message.
			* <BR>NAME: getErrorMessage
			* <BR>DESCRIPTION: Uses SQLGetDiagField with SQL_DIAG_MESSAGE_TEXT as the identifer.
			* <BR> After executing any ADBC API it is recommended that the user should check whether there 
			* <BR> was an Error due to the connectivity, in this case ODBC, using isError then use 
			* <BR> getErrorMessage to retrieve the error message.
			* <BR> Record Number is 1 since ID_ERROR_CODE is not a header field and hence not ignored.  
			* <BR>SIDE EFFECTS: Throws GeneralException if SQLGetDiagField returns error/invalid handle.
			* <BR>PARAMETERS: 
			* 	@param void
			* <BR>RETURN: 
			* 	@return string - Returns the last returned error message.
			*/
			virtual const string getErrorMessage() const;

	//Protected Functions
	protected:

			/** Overloaded copy constructor.
			* <BR>NAME: ODBCError(const ODBCError &)
			* <BR>DESCRIPTION: Copy Constructor for the ODBCError Object.
			* <BR>SIDE EFFECTS: Being protected and overloaded the user cannot call this. Hence empty implementation.
			* <BR>PARAMETERS: 
			* 	@param Const reference to ODBCError object
			* 
			*/
			ODBCError(const ODBCError & other);

			/** Overloaded assignment operator.
			* <BR>NAME: ODBCError & operator=(const ODBCError &)
			* <BR>DESCRIPTION: Assignment operator overload for the ODBCError Object.
			* <BR>SIDE EFFECTS: Being protected and overloaded the user cannot call this. 
			* Hence empty implementation.
			* <BR>PARAMETERS: 
			* 	@param const Reference to ODBCError object
			* <BR>RETURN: 
			* 	@return Reference to ODBCError Object
			* 
			*/
			ODBCError & operator =(const ODBCError & other);

	//Private Functions
	private:
			/** Sets details for Error object
			* <BR>NAME: setError(SQL_HANDLE, HANDLE_TYPE)
			* <BR>DESCRIPTION: After calling any ODBC function it is mandatory that setError needs to be called.
			* <BR>Handle and handle type to retrieve error code and message from
			* <BR>connectivity, in this case ODBC. Handle type can be Types::ODBC::DESC_HDL, Types::ODBC::CONN_HDL,
			* <BR>Types::ODBC::ENV_HDL or Types::ODBC::STMT_HDL.
			* <BR>SIDE EFFECTS: Nil
			* <BR>@param SQL_HANDLE - handle with respect to the function last executed
			* <BR>@param int - handle type, descriptor, connection, statement or environment as defined in enum
			* <BR>RETURN:@return Nil
			*/
			void setError(const SQLHANDLE & hdl, const int & handleType)
			{
						
				#ifdef ALOGGER
					logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
				#endif
				ODBCError::hdl_ = hdl;
				switch(handleType)
				{
				case dbaccess::Types::ODBC::CONN_HDL:
					handleType_ = SQL_HANDLE_DBC;
					break;
				case dbaccess::Types::ODBC::DESC_HDL:
					handleType_ = SQL_HANDLE_DESC;
					break;
				case dbaccess::Types::ODBC::ENV_HDL:
					handleType_ = SQL_HANDLE_ENV;
					break;
				case dbaccess::Types::ODBC::STMT_HDL:
					handleType_ = SQL_HANDLE_STMT;
					break;
				default:
					handleType_ = -1;
				}//end of switch
			}

	//Private variables
	private:
			SQLHANDLE hdl_;
			int handleType_;

	}; //class ODBCError
}	//namespace dbaccess
#endif  //ODBCERROR_H
