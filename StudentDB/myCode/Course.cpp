/*
 * Course.cpp
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include "Course.h"
#include <utility>
#include <iostream>
using namespace std;

/*
 * Default Constructor
 */
Course::Course(unsigned int courseKey, string title, string major, float creditPoints)
{
	this->courseKey = courseKey;
	this->title = title;
	this->major = major[0];
	this->creditPoints = creditPoints;
	this->majorById.insert(pair<unsigned char, string>(this->major, major));

}

/*
 * Function to return the credit points.
 */
float Course::getCreditPoints() const
{
	return creditPoints;
}

/*
 * Function to return the title.
 */
const string& Course::getTitle() const
{
	return title;
}

/*
 * Function to return the course key.
 */
unsigned int Course::getCourseKey() const
{
	return courseKey;
}

/*
 * Function to return the major.
 */
string Course::getMajor() const
{
	auto iterator = majorById.find(major)->second;
	return iterator;

}

/*
 * Destructor
 */
Course::~Course()
{
	// TODO Auto-generated destructor stub
}

/*
 * Function to print the course details
 */
void Course::print() const
{
	string majorStr;
	cout << "Course title: " << title << endl;
	cout << "Course Key : " << courseKey << endl;
	majorStr = getMajor();
	cout << "Major : " << majorStr << endl;
	cout << "Credit Points : " << creditPoints << endl;

}

/*
 * Function to write to Database file.
 */
void Course::write(ostream& out) const
{
	out << courseKey << ";" << title << ";" << getMajor() << ";" << creditPoints << ";";
}
