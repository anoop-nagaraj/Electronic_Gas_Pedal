/*
 * Course.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include <map>
#include<string>
#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
using namespace std;

#ifndef COURSE_H_
#define COURSE_H_

class Course
{
private:
	/**
	 * @brief majorById : static map<unsigned char, string> - stores the major mapped with the first letter of the major
	 */
	map<unsigned char, string> majorById;

	/**
	 * @brief courseKey : unsigned int - stores the course ID of the course
	 */
	unsigned int courseKey;

	/**
	 * @brief title : string - stores the title of the course
	 */
	string title;

	/**
	 * @brief major : unsigned char - stores the first letter of the major
	 */
	unsigned char major;

	/**
	 * @brief creditPoints : float - stores the credit points of the course
	 */
	float creditPoints;

public:
	/**
	 * @brief Constructor
	 * @param courseKey : unsigned int - stores the course ID of the course
	 * @param title : string - stores the title of the course
	 * @param major : unsigned char - stores the first letter of the major
	 * @param creditPoints : float - stores the credit points of the course
	 */
	Course(unsigned int courseKey, string title, string major, float creditPoints);

	/**
	 * @brief Destructor
	 */
	virtual ~Course() = 0;

	/**
	 * @brief Getter function to get the course key.
	 */
	unsigned int getCourseKey() const;

	/**
	 * @brief Getter function to get the course title.
	 */
	const string& getTitle() const;

	/**
	 * @brief Getter function to get the credit points.
	 */
	float getCreditPoints() const;

	/**
	 * @brief Getter function to get the major.
	 */
	string getMajor() const;

	/**
	 * @brief Function to print the course details
	 */
	virtual void print() const;

	/**
	 * @brief Function to write to Database file
	 * @param out : ostream& - stores the file to be written to
	 */
	virtual void write(ostream &out) const;

};

#endif /* COURSE_H_ */
