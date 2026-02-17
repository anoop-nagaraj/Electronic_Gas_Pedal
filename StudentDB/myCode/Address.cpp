/*
 * Address.cpp
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include "Address.h"

/*
 * Default constructor
 */
Address::Address()
{
	this->street = " ";
	this->postalCode = -1;
	this->cityName = " ";
	this->additionalInfo = " ";
}

/*
 * Parameterised Constructor
 */
Address::Address(string street, unsigned short postalCode, string cityName, string additionalInfo)
{
	this->street = street;
	this->postalCode = postalCode;
	this->cityName = cityName;
	this->additionalInfo = additionalInfo;
}

/*
 * Function to return Additional info
 */
const string& Address::getAdditionalInfo() const
{
	return additionalInfo;
}

/*
 * Function to return City Name
 */
const string& Address::getCityName() const
{
	return cityName;
}

/*
 * Function to return Postal code
 */
unsigned short Address::getPostalCode() const
{
	return postalCode;
}

/*
 * Function to return Street name
 */
const string& Address::getStreet() const
{
	return street;
}

/*
 * Destructor
 */
Address::~Address()
{
	// TODO Auto-generated destructor stub
}

