// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//


// TODO: reference additional headers your program requires here
#ifndef LOGGER_H
#define LOGGER_H

#include <fstream>
#include <iostream>
#include <string>



/**
   \brief
   A logging/trace system

   For now this simply decides whether to print a given message,
   and if so, prepends a label before passing it on to standard
   output or standard error.

   There's plenty of room to grow here, clearly.

   To further centralize the message-handling, this object is
   implemented as a GoF-style singleton.
*/

namespace logger{
  const int SUCCESS = 0;
  class Logger {
  public:

    /**
       \brief message types

       Entries here must correspond to those in _labels
    */
    enum MessageLevel {
      LevelNothing = 0 ,	///< don't report any messages
      LevelError ,	///< report only errors
      LevelWarn ,		///< report errors and warnings
      LevelInfo ,		///< report errors, warnings, and info messages
      LevelDebug ,	///< report error, warning, info, and debug messages
    } ;


  private:

    /// match message types to a label, which prefixes the printed message
    static const char* _labels[] ;

    /// the sole instance of this class
	static Logger _instance ;

	/// stores the logger file name
	static std::string _fileName;

	/// stores the stream object
	static std::ofstream _fp_out;

	/// determines which messages get printed, based on their index in the <TT>labels[]</TT> array
	static MessageLevel _level ;

	/*
	    \brief
	     constructor -- labeled "private" because this is a singleton
	*/
	  Logger(); 

	  /**
	     \brief
	     destructor -- this method should never be called by client code
	  */
	  ~Logger()  ; 

	 static const MessageLevel
	    LEVEL_MIN ,		///< minimum message severity level
	    LEVEL_MAX ;		///< maximum message severity level
	  /**
	     \brief print the provided message, based on its severity level
	  */
	  int printMessage( MessageLevel level , const char* message );

	  /**
	     \brief print the provided message and a brief identifier, based on its severity level

	     The "identifier" in this case would be the name of the calling method or object.
	  */
	  int printMessage( MessageLevel level , const char* id , const char* message ) ;
	  int printMessage(MessageLevel level, const char* fileName, int lineNo, const char* funName, const char* message);

  protected:
	  /*
	  stores the logger filename along with path in member variable _fileName 
	  */
	  static void setFileLocn( const char* fileName);
  public:
	  /// stores error messages, if any
	  static std::string _errMsg;

	  /// to decrement the message level 		
	  void Logger::levelDown( void ) ;
	  /// to increment the message level 
	  void Logger::levelUp( void ) ;

	  /// brief fetch a reference to the singleton Logger instance
	  static Logger& getInstance()  ;
	  /// brief fetch a reference to the singleton Logger instance, 
	  /// if user wants to log in a file
	  static Logger& getInstance(const char* fileName, 
		  MessageLevel Lvl_Slctd=_level)  ;

	  /// print debug-level messages
	  void debug( const char* message )   ;
	  /// print debug-level messages, with an identifier
	  void debug( const char* id , const char* message )   ;
	  /// print filename, line number, function name, message
	  void debug(const char* fileName, int lineNo, const char* funName, const char* message) ;
	  
		
      /// print info-level messages
	  void info( const char* message )   ;
      /// print info-level messages, with an identifier
	  void info( const char* id , const char* message )   ;
	  void info(const char* fileName, int lineNo, const char* funName, const char* message) ;

	  /// print warn-level messages
	  void warn( const char* message )   ;
      /// print warn-level messages, with an identifier
	  void warn( const char* id , const char* message )   ;
	  void warn(const char* fileName, int lineNo, const char* funName, const char* message)  ;

	  /// print error-level messages
	  void error( const char* message )   ;
      /// print error-level messages, with an identifier
	  void error( const char* id , const char* message )   ;
	  void error(const char* fileName, int lineNo, const char* funName, const char* message) ;

	  /// Generic function to print value of a variable in logger file
	  template<class Type> void print_value( MessageLevel level, Type Value)
	  {
		if( level <= _level )
		{
			if (!_fileName.length())
			{
				if( LevelError == _level )
					std::cerr << _labels[ level ] << Value << std::endl ; 
				else std::cout << _labels[ level ] << Value << std::endl ;
			}
			else _fp_out << _labels[ level ] << Value << std::endl;
		}
		/*if (!_fileName.length()) std::cout << Message << " : " << Value << std::endl;
		else _fp_out << Message << " : " << Value << std::endl;*/
	  }	

	  /**
		\brief explicitly set the message level

		The compiler should catch attempts to use values other than
		those provided in the MessageLevel enum.

		*/
	  void setLevel( MessageLevel newLevel )  ; 

  } ;
}

/* EOF Logger.h */

#endif // #ifndef LOGGER_H
