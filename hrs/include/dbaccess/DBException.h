#ifndef DBEXCEPTION_H
#define DBEXCEPTION_H

/**
* @file DBException.h
* @brief This implementation would handle all the general exceptions that arise from the ADBC component.
* 
* NAME: DBException
* $Header: DBException.h
* BASE CLASSES: Exception
* 
* PURPOSE: This implementation would handle all the general exceptions that arise from 
*		the ADBC component. 
* 
* AUTHOR: Gowri Ramasubramanian
* 
* $Revision: 1.8 $
* 
* $Log: DBException.h,v $
* Revision 1.8  2005/09/02 11:40:12  Jignesh.Kanchanlal
* Ready for Final Release
*
* Revision 1.7  2005/08/30 05:21:26  Jignesh.Kanchanlal
* Bugs after Testing fixed
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
#include <dbaccess/Exception.h>
namespace dbaccess {
	
	/**@class DBException
	 * @brief This is an implementation for the general exceptions class.
	 */
	class DBException : public Exception
	{
	//Constructor and destructor
	public:		

		/** Overloaded default Constructor.
		* <BR>NAME: DBException
		* <BR>DESCRIPTION: Constructor for the DBException Object.
		* <BR>SIDE EFFECTS: Nil
		* <BR>PARAMETERS: 
		* 	@param Nil
		* 
		*/
		DBException();

		/** Overloaded constructor.
		* <BR>NAME: DBException(const string)
		* <BR>DESCRIPTION: constructor for the DBException Object.
		* <BR>SIDE EFFECTS: Nil
		* <BR>@param Nil
		*/
		DBException(const string str);

		/** Default Destructor.
		* <BR>NAME: ~DBException
		* <BR>DESCRIPTION: Destructor for the DBException Object.
		* <BR>SIDE EFFECTS: Nil
		* <BR>PARAMETERS: 
		* 	@param Nil
		* 
		*/
		virtual ~DBException();

	//Protected Functions
	protected:	

		/** Overloaded copy constructor.
		* <BR>NAME: DBException(const DBException &)
		* <BR>DESCRIPTION: Copy Constructor for the DBException Object.
		* <BR>SIDE EFFECTS: Being protected and overloaded the user cannot call this. Hence empty implementation.
		* <BR>PARAMETERS: 
		* 	@param Const reference to DBException object
		* 
		*/
		DBException(const DBException & other);

		/** Overloaded assignment operator.
		* <BR>NAME: DBException & operator=(const DBException &)
		* <BR>DESCRIPTION: Assignment operator overload for the DBException Object.
		* <BR>SIDE EFFECTS: Being protected and overloaded the user cannot call this. Hence empty implementation.
		* <BR>PARAMETERS: 
		* 	@param const reference to DBException object
		* <BR>RETURN: 
		* 	@return Reference to DBError Object
		* 
		*/
		DBException & operator =(const DBException & other);

	}; //class DBException
}	//namespace dbaccess 
#endif  //EXCEPTION_H
