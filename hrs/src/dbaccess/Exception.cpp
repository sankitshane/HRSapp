/**
* @file $Header: Exception.cpp
* 
* NAME: Exception
* 
* BASE CLASSES: None
* 
* PURPOSE: Class for exceptions generated by ADBC component.
* 
* AUTHOR: Gowri Ramasubramanian
* 
* $Revision: 1.9 $
* 
* $Log: Exception.cpp,v $
* Revision 1.9  2005/09/01 05:40:48  Jignesh.Kanchanlal
* Documentation modified for the Release
*
* Revision 1.8  2005/08/30 05:23:25  Jignesh.Kanchanlal
* Bugs after Testing fixed
*
* Revision 1.7  2005/08/23 11:57:15  Jignesh.Kanchanlal
* Code Review Comments Incorporated
*
* Revision 1.6  2005/08/23 04:35:17  Jignesh.Kanchanlal
* Code Review Comments Incorporated
*
* Revision 1.4  2005/08/12 12:29:56  Jignesh.Kanchanlal
* Added for the first time
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/


///////////////////////////////////////////////////////////////
// Includes
#include <dbaccess/Exception.h>
#ifdef ALOGGER
	#include <logger/Logger.h> ///<logging comments
#endif

namespace dbaccess {

	/** Overloaded default Constructor.
	* <BR>NAME: Exception
	* <BR>DESCRIPTION: Constructor for the Exception Object.
	* <BR>SIDE EFFECTS: Nil
	* <BR>PARAMETERS: 
	* 	@param Nil
	* 
	*/
	Exception::Exception() : errorMessage_("")
	{	
		#ifdef ALOGGER
			logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
		#endif
	}

	/** Default Destructor.
	* <BR>NAME: ~Error
	* <BR>DESCRIPTION: Destructor for the Exception Object.
	* <BR>SIDE EFFECTS: Nil
	* <BR>@param Nil
	*/
	Exception::~Exception()
	{
		#ifdef ALOGGER
			logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
		#endif
	}

	/** Overloaded copy constructor.
	* <BR>NAME: Exception(const Exception &)
	* <BR>DESCRIPTION: Copy Constructor for the Exception Object.
	* <BR>SIDE EFFECTS: Being protected and overloaded the user cannot call this. Hence empty implementation.
	* <BR>@param Const reference to exception object
	*/
	Exception::Exception(const Exception&)
	{
		#ifdef ALOGGER
			logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, 
							"Copy Constructor");
		#endif
	}


	/** Overloaded constructor
	* <BR>NAME: Exception(const string)
	* <BR>DESCRIPTION: Overloaded constructor to set the exception string.
	* <BR>SIDE EFFECTS: Nil
	* <BR>@param const string - exception string
	* 
	*/
	Exception::Exception(const string str)
	{
		#ifdef ALOGGER
			logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, 
							"Overloaded Constructor with string");
		#endif
		errorMessage_ = str;
	}

	/** Gets the exception message
	* <BR>NAME: string getMessage(void)
	* <BR>DESCRIPTION: Getter function to retrieve the exception message
	* <BR>SIDE EFFECTS: Nil
	* <BR>RETURN: 
	* <BR>	@return const string - exception string
	* 
	*/
	const string Exception::getMessage(void) const
	{	
		#ifdef ALOGGER
			logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
		#endif
		return errorMessage_;
	}
	
	/** Sets the exception message
	* <BR>NAME: void setMessage(const string str)
	* <BR>DESCRIPTION: Setter function to fill in the exception message
	* <BR>SIDE EFFECTS: Nil
	* <BR>PARAMETERS: 
	* <BR>	@param const string - exception string
	* 
	*/
	void Exception::setMessage(const string str)
	{
		#ifdef ALOGGER
			logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, "");
		#endif
		errorMessage_ = str;
	}

	/** Overloaded assignment operator.
	* <BR>NAME: Exception & operator=(const Exception &)
	* <BR>DESCRIPTION: Assignment operator overload for the Exception Object.
	* <BR>SIDE EFFECTS: Being protected and overloaded the user cannot call this. Hence empty implementation.
	* <BR>@param const Reference to Exception object
	* <BR>RETURN: 
	* 	@return Reference to Exception Object
	*/
	Exception& Exception::operator =(const Exception&)
	{
		#ifdef ALOGGER
			logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, 
							"Overloaded Assignment operator");
		#endif
		return *this;
	}

}	//namespace dbaccess
