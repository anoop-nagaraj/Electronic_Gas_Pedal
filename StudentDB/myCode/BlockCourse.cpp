/*
 * BlockCourse.cpp
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include "BlockCourse.h"
#include <iostream>
using namespace std;

/*
 * Constructor
 */
BlockCourse::BlockCourse(unsigned int courseKey, string title, string major, float creditPoints,
		Poco::Data::Date startDate, Poco::Data::Date endDate,
		Poco::Data::Time startTime, Poco::Data::Time endTime):Course(courseKey, title, major, creditPoints)
{
	this->startDate = startDate;
	this->endDate = endDate;
	this->startTime = startTime;
	this->endTime = endTime;
}

/*
 * Function to return End date of blocked course
 */
const Poco::Data::Date& BlockCourse::getEndDate() const
{
	return endDate;
}

/*
 * Function to return End time of blocked course
 */
const Poco::Data::Time& BlockCourse::getEndTime() const
{
	return endTime;
}

/*
 * Function to return Start date of blocked course
 */
const Poco::Data::Date& BlockCourse::getStartDate() const
{
	return startDate;
}

/*
 * Function to return End Time of blocked course
 */
const Poco::Data::Time& BlockCourse::getStartTime() const
{
	return startTime;
}

/*
 * Function to print details of blocked course
 */
void BlockCourse::print() const
{
	cout << "   Course type: Block Course" << endl;
	Course::print();

	cout << "Start Date : ";
	int day = startDate.day();
	int month = startDate.month();
	int year = startDate.year();
	cout << day << "/" << month << "/" << year << endl;

	cout << "End Date : ";
	day = endDate.day();
	month = endDate.month();
	year = endDate.year();
	cout << day << "/" << month << "/" << year << endl;

	cout << "Start Time : ";
	int hour = startTime.hour();
	int minute = startTime.minute();
	int second = startTime.second();
	cout << hour << ":" << minute << ":" << second << endl;

	cout << "End Time : ";
	hour = endTime.hour();
	minute = endTime.minute();
	second = endTime.second();
	cout << hour << ":" << minute << ":" << second << endl;
	cout << endl;
}

/*
 * Function to write to Database file
 */
void BlockCourse::write(ostream &out) const
{
	out << 'B' << ";";
	Course::write(out);
	out << startDate.day() << "." << startDate.month() << "." << startDate.year() << ";"
			<< endDate.day() << "." << endDate.month() << "." << endDate.year() << ";"
			<< startTime.hour() << ":" << startTime.minute() << ";"
			<< endTime.hour() << ":" << endTime.minute() << endl;
}

/*
 * Destructor
 */
BlockCourse::~BlockCourse()
{
	// TODO Auto-generated destructor stub
}
