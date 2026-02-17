/*
 * WeeklyCourse.cpp
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include "WeeklyCourse.h"
#include <iostream>
using namespace std;

/*
 * Constructor
 */
WeeklyCourse::WeeklyCourse(unsigned int courseKey, string title, string major,
		float creditPoints, Poco::DateTime::DaysOfWeek daysOfWeek,
		Poco::Data::Time startTime, Poco::Data::Time endTime):Course(courseKey, title, major, creditPoints)
{

	this->daysOfWeek = daysOfWeek;
	this->startTime = startTime;
	this->endTime = endTime;
}

/*
 * Destructor
 */
WeeklyCourse::~WeeklyCourse()
{
	// TODO Auto-generated destructor stub
}

/*
 * Function to get the days of the week
 */
Poco::DateTime::DaysOfWeek WeeklyCourse::getDaysOfWeek() const
{
	return daysOfWeek;
}

/*
 * Function to get the end time of the course
 */
const Poco::Data::Time& WeeklyCourse::getEndTime() const
{
	return endTime;
}

/*
 * Function to get the start time of the course
 */
const Poco::Data::Time& WeeklyCourse::getStartTime() const
{
	return startTime;
}

/*
 * Function to print the course details
 */
void WeeklyCourse::print() const
{
	string weekDay;

	cout << "   Course type: Weekly Course" << endl;
	Course::print();
	switch(daysOfWeek)
	{
	case 0:
		weekDay = "Sunday";
		break;
	case 1:
		weekDay = "Monday";
		break;
	case 2:
		weekDay = "Tuesday";
		break;
	case 3:
		weekDay = "Wednesday";
		break;
	case 4:
		weekDay = "Thursday";
		break;
	case 5:
		weekDay = "Friday";
		break;
	case 6:
		weekDay = "Saturday";
		break;
	}

	cout << "Classes takes place on every : " << weekDay << endl;

	int hour = startTime.hour();
	int minute = startTime.minute();
	int second = startTime.second();
	cout << "Start Time : " << hour << ":" << minute << ":" << second << endl;

	hour = endTime.hour();
	minute = endTime.minute();
	second = endTime.second();
	cout << "End Time : " << hour << ":" << minute << ":" << second << endl;
	cout << endl;
}

/*
 * Function to write to the file
 */
void WeeklyCourse::write(std::ostream &out) const
{
	out << 'W' << ";";
	Course::write (out);
	out << daysOfWeek << ";" << startTime.hour() << ":" << startTime.minute() << ";"
							<< endTime.hour() << ":" << endTime.minute() << ";" << std::endl;
}
