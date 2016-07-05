#ifndef VALIDATOR_H
#define VALIDATOR_H

/**
* @file Validator.h
* @brief Used to Validate the UI input.
* 
* NAME: Validator
* $Header: Validator.h
* BASE CLASSES: None
* 
* PURPOSE: Used to Validate the UI input.
* 
* AUTHOR: Arun Veeramany
* 
* $Revision: 1.10 $
* 
* $Log: Validator.h,v $
*
* 
* COPYRIGHT NOTICE:
* Copyright (c) 2005 C++ Capability team at Accenture. All rights reserved.
*/

#include <string>

/**@class Validator
 * @brief Used to Validate the UI input.
 **/
  class Validator
  {
  public:

    /**@fn notNull(std::string value)
     * @brief checks the entered string is null or not.
     * @param value - string to be validated
     * @return valid - true if value is not null,false if the value is null.
     **/	  
    static bool notNull(std::string value) {return !value.empty(); }
//    static bool null(std::string value) { return true; }


    /**@fn A(std::string value)
     * @brief checks the entered string for numbers.
     * @param value - string to be validated
     * @return valid - true if value is valid,false if the value is invalid.
     **/
    static	bool A(std::string value);

    /**@fn B
     * @brief checks the entered string for numbers,spaces and dashes.
     * @param value - string to be validated
     * @return valid - true if value is valid,false if the value is invalid.
     **/
    static	bool B(std::string value);

    /**@fn C(std::string value)
     * @brief checks the entered string for letters and numbers.
     * @param value - string to be validated
     * @return valid - true if value is valid,false if the value is invalid.
     **/
    static	bool C(std::string value);
	
    /**@fn D(std::string value)
     * @brief checks the entered string for letters,numbers,underscores,dashes,spaces and dots.
     * @param value - string to be validated
     * @return valid - true if value is valid,false if the value is invalid.
     **/
    static	bool D(std::string value);

    /**@fn E(std::string value)
     * @brief checks the entered string for letters,numbers,underscores,dashes,spaces dots,\n,\r,comma,slashes,plus,pounds and parenthesis.
     * @param value - string to be validated.
     * @return valid - true if value is valid,false if the value is invalid.
     **/
    static	bool E(std::string value);
 
    /**@fn F(std::string value)
     * @brief checks the entered string for letters,numbers,underscores,dashes,spaces,dots and at the rate symbol.
     * @param value - string to be validated
     * @return valid - true if value is valid,false if the value is invalid.
     **/
    static  bool F(std::string value);

    /**@fn gender(std::string value)
     * @brief checks the entered string for M or F
     * @param value - string to be validated
     * @return valid - true if value is valid,false if the value is invalid.
     **/
    static  bool gender(std::string value);

    /**@fn status(std::string value)
     * @brief checks the entered string for ACTIVE or INACTIVE
     * @param value - string to be validated
     * @return valid - true if value is valid,false if the value is invalid.
     **/
    static  bool status(std::string value);

  /**@fn civilStatus(std::string value)
   * @brief checks the entered string for SINGLE MARRIED DIVORCED WIDOW
   * @param value - string to be validated
   * @return valid - true if value is valid,false if the value is invalid.
   **/
     static bool civilStatus(std::string value);

    /**@fn date(std::string date)
     * @brief checks the entered string for Date.
     * @param value - string to be validated
     * @return valid - true if value is valid,false if the value is invalid.
     **/
    static  bool date(std::string date);

  };


#endif //VALIDATOR_H
