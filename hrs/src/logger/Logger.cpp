// TODO: reference any additional headers you need in STDAFX.H
/**
* \file $Header: Logger.cpp
* 
* NAME: Logger.cpp
* 
* BASE CLASSES: None
* 
* PURPOSE: To log debug, error , warning or information statements
* 
* AUTHOR: Swetha Kishan. V
* 
* $Revision: $ 1.1
* 
* $Log: $ 
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/


#include <logger/Logger.h>
// and not in this file
#include <iostream>
#include <cstdio>

/*
Entries in _labels must correspond to
those in MessageLevel
*/

namespace logger{
const char* Logger::_labels[] = {

	""     ,	// not used -- for "LevelNothing"
	"[E] " ,    // Level Error
	"[W] " ,	// Level Warning
	"[I] " ,	// Level Information
	"[D] " ,	// Level Debug
} ;

// shall get it from command line.

const Logger::MessageLevel Logger::LEVEL_MIN = Logger::LevelNothing ;
const Logger::MessageLevel Logger::LEVEL_MAX = Logger::LevelDebug ;

Logger Logger::_instance ;
std::string Logger::_fileName ;
std::ofstream Logger::_fp_out; 
Logger::MessageLevel Logger::_level = Logger::LevelNothing ;
std::string Logger::_errMsg;
/* - - - - - - - - - - - - - - - - - - - - */

/** Default constructor.
* <BR>NAME: Logger()
* <BR>DESCRIPTION: Constructor for Logger Object.
* <BR>SIDE EFFECTS: Nil
* <BR>@param Nil
*/

Logger::Logger()
{
  /*	
	empty constructor
  */
} // Logger ctor

/* - - - - - - - - - - - - - - - - - - - - */

/** Default Destructor.
* <BR>NAME: ~Logger
* <BR>DESCRIPTION: Destructor for Logger Object.
* <BR>SIDE EFFECTS: Nil
* <BR>@param Nil
*/
Logger::~Logger()
{
	if (_fp_out.is_open()) _fp_out.close();
	else 
	{
		_errMsg = "Logger file is not opened to close !";
		exit(1);
	}
} // Logger dtor

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: getInstance
 *	<BR>DESCRIPTION: gets the unique instance of Logger object
 *	<BR>SIDE EFFECTS: Nil
 *	<BR>PARAMETERS: None
 *	<BR>@return RETURN:Logger - Unique logger object instance.
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
Logger& Logger::getInstance()
	
{
	return( _instance ) ;
} // Logger::getInstance()

/* - - - - - - - - - - - - - - - - - - - - */
/**	
 *	<BR>NAME: getInstance
 *	<BR>DESCRIPTION: gets the unique instance of Logger object, if 
 *  <BR> user wants to log in a file instead on a console
 *	<BR>SIDE EFFECTS: Nil
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - String representing Logger filename with path
 *	<BR>@param MessageLevel - level of messages. Default (current level)is 
 *	<BR> taken if value is not mentioned
 *	<BR>@return RETURN:Logger - Unique logger object instance.
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
Logger& Logger::getInstance(const char* fileName, 
							MessageLevel Lvl_Slctd) 
{
	_level = Lvl_Slctd;
	/*
	 Ensuring logger file to be opened only for once
	*/
	if (!_fp_out.is_open()) 
		_fp_out.open(fileName, std::ios::app);
	setFileLocn(fileName);
	return ( _instance );
} // Logger::getInstance(const char* fileName) 

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: setFileLocn
 *	<BR>DESCRIPTION: sets the input file name in Logger 
 *  <BR> object's filename
 *	<BR>SIDE EFFECTS: 
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - String representing Logger filename with path
 *	<BR>@param MessageLevel - level of messages. Default (current level)is 
 *	<BR> taken if value is not mentioned
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::setFileLocn( const char* fileName) 
{
	if (fileName != NULL) _fileName.assign(fileName);
}
/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: printMessage
 *	<BR>DESCRIPTION: prints input message either to console or to log file
  *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param MessageLevel - Message level to be prefixed to message
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: 0 for success, non-zero otherwise
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
int Logger::printMessage( MessageLevel level , const char* message ) 
{
	/*
	see note in setLevel() for explanation of why
	we don't check the provided message level
	*/

	if( level <= _level )
	{
		if (!_fileName.length())
		{
			if( LevelError == _level )
				std::cerr << _labels[ level ] << message << std::endl ; 
			else std::cout << _labels[ level ] << message << std::endl ;
		}
		else _fp_out << _labels[ level ] << message << std::endl;
	}
	return SUCCESS;
} // Logger::printMessage( MessageLevel , const char* )

 /*- - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: printMessage (overloaded function)
 *	<BR>DESCRIPTION: prints input message either to console or to log file
  *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param MessageLevel - Message level to be prefixed to message
 *	<BR>@param const char* - fileName from which a statement is logged
 *	<BR>@param int - Line number at which the log statement is executed
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: 0 for success, non-zero otherwise
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
int Logger::printMessage( MessageLevel level , const char* fileName, int lineNo, const char* funName, const char* message )
{
	/*
	see note in setLevel() for explanation of why
	we don't check the provided message level
	*/
	
	if( level <= _level )
	{
		if (!_fileName.length())
		{
			if( LevelError == _level )
				std::cerr << _labels[ level ] << fileName << " | " 
					<< lineNo << " | " << funName << " | " << message << std::endl ; 
			else 
				std::cout << _labels[ level ] << fileName << " | "
					<< lineNo << " | " << funName << " | " << message << std::endl ; 
		}
		else _fp_out << _labels[ level ] << fileName << " | " 
					<< lineNo << " | " << funName << " | " << message << std::endl;
	}
	return SUCCESS;
} // Logger::printMessage( MessageLevel , const char*, int , const char*, const char* )

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: printMessage (overloaded function)
 *	<BR>DESCRIPTION: prints input message either to console or to log file
  *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param MessageLevel - Message level to be prefixed to message
 *	<BR>@param const char* - function Name from which a statement is logged
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: 0 for success, non-zero otherwise
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
int Logger::printMessage( MessageLevel level , const char* id , const char* message ) 
{
	/*
	see note in setLevel() for explanation of why
	we don't check the provided message level
	*/
	if( level <= _level )
	{
		if (!_fileName.length())
		{
			if( LevelError == _level )
				std::cerr << _labels[ level ] << id << ": " << message << std::endl ; 
			else 
				std::cout << _labels[ level ] << id << ": " << message << std::endl ; 
		}
		else _fp_out << _labels[ level ] << id << ": " << message << std::endl;
	}
	return SUCCESS;
} // Logger::printMessage( MessageLevel , const char* , const char* )

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: debug
 *	<BR>DESCRIPTION: logs debug messages
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::debug( const char* message ) 
{
  if (printMessage( LevelDebug , message ) != SUCCESS)
  {
	  _errMsg = "Unable to print the message in debug !";
	  exit(1);
  }
} // Logger::debug( const char* ) 

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: debug (overloaded function)
 *	<BR>DESCRIPTION: logs debug messages along with function name
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - function name from which the statement is logged
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::debug( const char* id , const char* message ) 
{
  if (printMessage( LevelDebug , id , message ) != SUCCESS)
  {
	  _errMsg = "Unable to print the message in debug !";
	  exit(1);
  }
} // Logger::debug( const char* , const char* ) 


/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: debug (overloaded function)
 *	<BR>DESCRIPTION: logs debug messages along with function name
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - file name from which the statement is logged
 *	<BR>@param int - Line number at which the statement is logged 
 *	<BR>@param const char* - function name from which the statement is logged
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::debug( const char* fileName, int lineNo, const char* funName, const char* message ) 	
{
  if (printMessage( LevelDebug, fileName, lineNo, funName, message) != SUCCESS)
  {
	  _errMsg = "Unable to print the message in debug !";
	  exit(1);
  }
} // Logger::debug( const char* fileName, ...);	

/* - - - - - - - - - - - - - - - - - - - - */
/**	
 *	<BR>NAME: info
 *	<BR>DESCRIPTION: logs information messages
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::info( const char* message ) 
{
  if (printMessage( LevelInfo , message ) != SUCCESS)
  {
	  _errMsg = "Unable to print the message in info !";
	  exit(1);
  }
} // Logger::info( const char* ) 

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: info (overloaded function)
 *	<BR>DESCRIPTION: logs information messages along with function name
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - function name from which the statement is logged
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::info( const char* id , const char* message ) 
{
  if (printMessage( LevelInfo , id , message ) != SUCCESS)
  {
	  _errMsg = "Unable to print the message in info !";
	  exit(1);
  }
} // Logger::info( const char* , const char* ) 

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: info (overloaded function)
 *	<BR>DESCRIPTION: logs information messages along with other specifications
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - file name from which the statement is logged
 *	<BR>@param int - Line number at which the statement is logged 
 *	<BR>@param const char* - function name from which the statement is logged
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::info( const char* fileName, int lineNo, 
				   const char* funName, const char* message ) 	
{
  if (printMessage( LevelInfo, fileName, lineNo, funName, message) != SUCCESS)
  {
	  _errMsg = "Unable to print the message in info !";
	  exit(1);
  }
}

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: warn
 *	<BR>DESCRIPTION: logs warning messages
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::warn( const char* message ) 
{
  if (printMessage( LevelWarn , message ) != SUCCESS)
  {
	  _errMsg = "Unable to print the message in warn !";
	  exit(1);
  }
} // Logger::warn( const char* ) 

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: warn (overloaded function)
 *	<BR>DESCRIPTION: logs warning messages along with function name
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - function name from which the statement is logged
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::warn( const char* id , const char* message ) 
{
  if (printMessage( LevelWarn , message ) != SUCCESS)
  {
	  _errMsg = "Unable to print the message in warn !";
	  exit(1);
  }
} // Logger::warn( const char* , const char* ) 

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: warn (overloaded function)
 *	<BR>DESCRIPTION: logs warning messages along with other specifications
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - file name from which the statement is logged
 *	<BR>@param int - Line number at which the statement is logged 
 *	<BR>@param const char* - function name from which the statement is logged
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::warn( const char* fileName, int lineNo, const char* funName, const char* message ) 
{
  if (printMessage( LevelWarn, fileName, lineNo, funName, message) != SUCCESS)
  {
	  _errMsg = "Unable to print the message in warn !";
	  exit(1);
  }
} // Logger::warn( const char* fileName, int lineNo, ...);

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: error
 *	<BR>DESCRIPTION: logs error messages
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::error( const char* message ) 
{
  if (printMessage( LevelError , message ) != SUCCESS)
  {
	  _errMsg = "Unable to print the message in error !";
	  exit(1);
  }
} // Logger::error( const char* ) 

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: error (overloaded function)
 *	<BR>DESCRIPTION: logs error messages along with function name
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - function name from which the statement is logged
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::error( const char* id , const char* message ) 
{
  if (printMessage( LevelError , id , message ) != SUCCESS)
  {
	  _errMsg = "Unable to print the message in error !";
	  exit(1);
  }
} // Logger::error( const char* , const char* ) 

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: error (overloaded function)
 *	<BR>DESCRIPTION: logs error messages along with other specifications
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS:
 *	<BR>@param const char* - file name from which the statement is logged
 *	<BR>@param int - Line number at which the statement is logged 
 *	<BR>@param const char* - function name from which the statement is logged
 *	<BR>@param const char* - message to be logged
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::error( const char* fileName, int lineNo, const char* funName, const char* message ) 
{
  if (printMessage( LevelError, fileName, lineNo, funName, message) != SUCCESS)
  {
	  _errMsg = "Unable to print the message in error !";
	  exit(1);
  }
}

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: setLevel
 *	<BR>DESCRIPTION: sets the current level with user specified value
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS: 
 *	<BR>@param MessageLevel - level of messages logged
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::setLevel( MessageLevel newLevel )
{
	/*
	Purists beware -- we don't check the array index here because
	setLevel() should only be called using the predefined constants
	in MessageLevel. -eqm
	*/

	_level = newLevel ;

} // setLevel()

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: operator++ (overloaded function)
 *	<BR>DESCRIPTION: defines an operator to increment message level
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS: 
 *	<BR>@param MessageLevel - level of messages logged (o/p)
 *	<BR>@param int - a dummy parameter 
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
inline Logger::MessageLevel operator++( Logger::MessageLevel &lvl, int)
{
   return lvl = (Logger::MessageLevel)(lvl + 1);
}

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: operator-- (overloaded function)
 *	<BR>DESCRIPTION: defines an operator to decrement message level
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS: 
 *	<BR>@param MessageLevel - level of messages logged (o/p)
 *	<BR>@param int - a dummy parameter 
 *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
inline Logger::MessageLevel operator--( Logger::MessageLevel &lvl, int)
{
   return lvl = (Logger::MessageLevel)(lvl - 1);
}

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: levelUp
 *	<BR>DESCRIPTION: message level is incremented in one level up
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS: None
  *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::levelUp( void )
{
	if( _level < LEVEL_MAX ) _level++ ;
} // levelUp

/* - - - - - - - - - - - - - - - - - - - - */

/**	
 *	<BR>NAME: levelDown
 *	<BR>DESCRIPTION: message level is decremented in one level down
 *	<BR>SIDE EFFECTS: None
 *	<BR>PARAMETERS: None
  *	<BR>@return RETURN: None
 *	<BR>
 *	<BR>TEST CASES
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 *	<BR>
 */
void Logger::levelDown( void )
{
	if( _level > LEVEL_MIN )_level-- ;
} // levelDown

/* - - - - - - - - - - - - - - - - - - - - */
}

/* - - - - - - - - - - - - - - - - - - - - */
/* EOF Logger.cc */

