/**@file Validator.cpp
 * @brief Declares the Validator
 *
 * <BR>NAME:Validator
 * 
 * <BR>BASE CLASSES:None
 * 
 * <BR>PURPOSE:To validate the entered string.
 *
 * <BR>AUTHOR:Smitha Manjunath	
 * <BR>
 * <BR>$Revision: $12/14/2005
 * 
 * <BR>$Log:01/06/2006
 * 
 * <BR>COPYRIGHT NOTICE:
 * <BR>Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
 */


#include<iostream>
#include<string>
#include<ctype.h>
#include<common/Validator.h>

#ifdef ALOGGER
#include<logger/Logger.h>
#endif


std::string convertToUpper(std::string str)
{
  int size = str.length();
  char temp[100];
  int i = 0;
  for(i = 0; i < size ; ++i)
  {
    temp[i] = ::toupper(str[i]);
  }
  temp[i] = '\0';

  return temp;
}


  /**@class Validator
   * @brief Declaration of Validator
   * <PRE>The participants will be give following Activity.
   * 1. Write a class Validator, which will enforce encapsulation.
   * 2. Declare a function that will check if the entered string is a number.
   * 3. Declare a function that will check if the entered string contains numbers,spaces and dashes only.
   * 4. Declare a function that will check if the entered string contains letters and numbers only.
   * 5. Declare a function that will check if the entered string contains letters,numbers,underscores,dashes,spaces and dots only.
   * 6. Declare a function that will check if the entered string contains the characteristics of the above function and (\n\r),slashes,pounds,parenthesis only
   * 7. Declare a function that will check if the entered string contains the characteristics of the above function and @.
   </PRE>
  */



  /**@fn A
   * @brief checks the entered string for numbers.
   * @param value - string to be validated
   * @return valid - true if value is valid,false if the value is invalid.
   */
  bool Validator::A(std::string value)
  {
    if( value.empty() )
      return false;
     
    for(unsigned int i=0;i<value.length();i++)
      if(! isdigit( value[i]) )
	return false;
		
    return true;	
  }

  /**@fn B
   * @brief checks the entered string for numbers,spaces and dashes.
   * @param value - string to be validated
   * @return valid - true if value is valid,false if the value is invalid.
   */
  bool Validator::B(std::string value)
  {
    if( value.empty() )
      return false;

    for(unsigned int i=0;i<value.length();i++)
      if(! (isdigit( value[i] ) || (value[i]==' ') || (value[i]=='-')) )
	return false;
		
    return true;	
  }


  /**@fn C
   * @brief checks the entered string for letters and numbers.
   * @param value - string to be validated
   * @return valid - true if value is valid,false if the value is invalid.
   */
  bool Validator::C(std::string value)
  {
    if( value.empty() )
      return false;

    for(unsigned int i=0;i<value.length();i++)
      if(! isalnum(value[i])  )
	return false;
		
    return true;	
  }

  /**@fn D
   * @brief checks the entered string for letters,numbers,underscores,dashes,spaces and dots.
   * @param value - string to be validated
   * @return valid - true if value is valid,false if the value is invalid.
   */
  bool Validator::D(std::string value)
  {
#ifdef ALOGGER
    logger::Logger::getInstance().debug(__FILE__, __LINE__, __FUNCTION__, value.c_str());
#endif	

    if( value.empty() )
      return false;

    int index;
    std::string set = " -_.";

    for(unsigned int i=0;i<value.length();i++)
      {
        index = set.find(value[i]);
	if(!isalnum(value[i]) &&  index<0 )
	  return false;
      }
		
    return true;	
  }

  /**@fn E
   * @brief checks the entered string for letters,numbers,underscores,dashes,spaces dots,\n,\r,comma,slashes,plus,pounds and parenthesis.
   * @param value - string to be validated.
   * @return valid - true if value is valid,false if the value is invalid.
   */
  bool Validator::E(std::string value)
  {
    if( value.empty() )
      return false;

    int index;
    std::string set = ",/\\+#()";

    for(unsigned int i=0;i<value.length();i++)
      {
	index = set.find(value[i]);
	if(index<0 && !D(value.substr(i,1)) )
	  return false;
      }
		
    return true;	
  }


  /**@fn F
   * @brief checks the entered string for letters,numbers,underscores,dashes,spaces,dots and at the rate symbol.
   * @param value - string to be validated
   * @return valid - true if value is valid,false if the value is invalid.
   */
  bool Validator::F(std::string value)
  {
    if( value.empty() )
      return false;

    for(unsigned int i=0;i<value.length();i++)
      if(  value[i]!='@' && !D(value.substr(i,1)) )
	return false;
		     
    return true;	
  }	

  /**@fn gender
   * @brief checks the entered string for M or F
   * @param value - string to be validated
   * @return valid - true if value is valid,false if the value is invalid.
   */
  bool Validator::gender(std::string value)
  {
    return ( (value == "M") || (value=="F") );
  }

  /**@fn status
   * @brief checks the entered string for ACTIVE or INACTIVE
   * @param value - string to be validated
   * @return valid - true if value is valid,false if the value is invalid.
   */
  bool Validator::status(std::string value)
  {
    return ( (value == "ACTIVE") || (value=="INACTIVE") );
  }

  /**@fn civilStatus
   * @brief checks the entered string for SINGLE MARRIED DIVORCED WIDOW
   * @param value - string to be validated
   * @return valid - true if value is valid,false if the value is invalid.
   */
  bool Validator::civilStatus(std::string value)
  {
    return ( (value == "SINGLE") || (value=="MARRIED") || (value=="DIVORCED") || (value=="WIDOW") );
  }

  /**@fn date
   * @brief checks the entered string for Date.
   * @param value - string to be validated
   * @return valid - true if value is valid,false if the value is invalid.
   */
  bool Validator::date(std::string date)
  {
    if( date.empty() )
      return false;
     
    std::string months = "JAN,FEB,MAR,APR,MAY,JUN,JUL,AUG,SEP,OCT,NOV,DEC";
    std::string day, month, year;

    int len = date.length() ;

    ///The primary check..Whether the date is in correct format
      if(11!=len)
	return false;

      ///The month part of std::string is converted to uppercase..
      //	char* tempDate = new char[ len + 1];
	//	strcpy( tempDate, date.c_str() );
	//	strupr( tempDate);
	date = convertToUpper(date);
	//	delete[] tempDate;


	// Extract the year out of the string
	year=date.substr(7,4);
	int y = atoi( year.c_str() );
	//The string year takes the value of the year part of the string date
	if(y<1900||y>2050)
	  return false;
	
	///The string day takes the value of the day part of the string date
	  day=date.substr(0,2);
	  int d = atoi( day.c_str() );
	
	  if( d < 1 || d > 31)
	    return false;

	  ///The string month takes the value of the month part of the string date
	    month=date.substr(3,3);
	    int index = months.find(month);
    
	    if(index < 0)
	      return false;	

	    return true;
  }

 //namespace ui

