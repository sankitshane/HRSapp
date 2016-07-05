#ifndef GENERALEXCEPTION_H
#define GENERALEXCEPTION_H

/**
* @file GeneralException.h
* @brief This implementation would handle all the general exceptions that arise from the HRS component.
* 
* NAME: GeneralException
* $Header: GeneralException.h
* BASE CLASSES: Exception
* 
* PURPOSE: This implementation would handle all the general exceptions that arise from 
*		the ADBC component. 
* 
* AUTHOR: Gowri Ramasubramanian
* 
* $Revision: 1.8 $
* 
* $Log: GeneralException.h,v $
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

#include <common/Exception.h>
	
	/**@class GeneralException
	 * @brief This is an implementation for the general exceptions class.
	 */
	class GeneralException : public Exception
	{
	//Constructor and destructor
	public:		

		/** Overloaded default Constructor.
		* <BR>NAME: GeneralException
		* <BR>DESCRIPTION: Constructor for the GeneralException Object.
		* <BR>SIDE EFFECTS: Nil
		* <BR>PARAMETERS: 
		* 	@param Nil
		* 
		*/
		GeneralException();

		/** Overloaded constructor.
		* <BR>NAME: GeneralException(const string)
		* <BR>DESCRIPTION: constructor for the GeneralException Object.
		* <BR>SIDE EFFECTS: Nil
		* <BR>@param Nil
		*/
		GeneralException(const string str);

		/** Default Destructor.
		* <BR>NAME: ~GeneralException
		* <BR>DESCRIPTION: Destructor for the GeneralException Object.
		* <BR>SIDE EFFECTS: Nil
		* <BR>PARAMETERS: 
		* 	@param Nil
		* 
		*/
		virtual ~GeneralException();

	//Protected Functions
	protected:	

		/** Overloaded copy constructor.
		* <BR>NAME: GeneralException(const GeneralException &)
		* <BR>DESCRIPTION: Copy Constructor for the GeneralException Object.
		* <BR>SIDE EFFECTS: Being protected and overloaded the user cannot call this. Hence empty implementation.
		* <BR>PARAMETERS: 
		* 	@param Const reference to GeneralException object
		* 
		*/
		GeneralException(const GeneralException & other);

		/** Overloaded assignment operator.
		* <BR>NAME: GeneralException & operator=(const GeneralException &)
		* <BR>DESCRIPTION: Assignment operator overload for the GeneralException Object.
		* <BR>SIDE EFFECTS: Being protected and overloaded the user cannot call this. Hence empty implementation.
		* <BR>PARAMETERS: 
		* 	@param const reference to GeneralException object
		* <BR>RETURN: 
		* 	@return Reference to GeneralError Object
		* 
		*/
		GeneralException & operator =(const GeneralException & other);

	}; //class GeneralException
#endif  //EXCEPTION_H
