/*
 * Address.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include <string>
using namespace std;

#ifndef ADDRESS_H_
#define ADDRESS_H_

class Address
{
private:
	/**
	 * @brief street : string -   details of the street
	 */
	string street;

	/**
	 * @brief postalCode : unsigned short -   details of postal code
	 */
	unsigned short postalCode;

	/**
	 * @brief cityName : string -   details of city name
	 */
	string cityName;

	/**
	 * @brief additionalInfo : string -   details of additional information
	 */
	string additionalInfo;

public:
	/**
	 * @brief Default constructor
	 */
	Address();

	/**
	 * @brief Constructor
	 * @param street : string -   details of the street
	 * @param postalCode : unsigned short -   details of postal code
	 * @param cityName : string -   details of city name
	 * @param additionalInfo : string -   details of additional information
	 */
	Address(string street, unsigned short postalCode, string cityName, string additionalInfo);

	/**
	 * @brief Destructor
	 */
	virtual ~Address();
	
	/**
	 * @brief Getter function to get the street details.
	 */
	const string& getStreet() const;

	/**
	 * @brief Getter function to get the Postal code details.
	 */
	unsigned short getPostalCode() const;

	/**
	 * @brief Getter function to get the City name details.
	 */
	const string& getCityName() const;

	/**
	 * @brief Getter function to get additional information.
	 */
	const string& getAdditionalInfo() const;
};

#endif /* ADDRESS_H_ */
