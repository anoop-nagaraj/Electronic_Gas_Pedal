/*
 * WeeklyCourse.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include "Course.h"

#ifndef WEEKLYCOURSE_H_
#define WEEKLYCOURSE_H_

class WeeklyCourse: public Course
{

private:
	/**
	 * @brief daysOfWeek : Poco::DateTime::DaysOfWeek - stores the days of the week the course takes place
	 */
	Poco::DateTime::DaysOfWeek daysOfWeek;

	/**
	 * @brief startTime : Poco::Data::Time - stores the start time of the course
	 */
	Poco::Data::Time startTime;

	/**
	 * @brief endTime : Poco::Data::Time - stores the end time of the course
	 */
	Poco::Data::Time endTime;

public:
	/**
	 * @brief Constructor
	 * @param courseKey : unsigned int - stores the weekly course key
	 * @param title : string - stores the title of the weekly course
	 * @param major : string - stores the major
	 * @param creditPoints : float - sotres the credit points
	 * @param daysOfWeek : Poco::DateTime::DaysOfWeek - stores the days of the week the course takes place
	 * @param startTime : Poco::Data::Time - stores the start time of the course
	 * @param endTime : Poco::Data::Time - stores the end time of the course
	 */
	WeeklyCourse(unsigned int courseKey, string title, string major, float creditPoints,
			     Poco::DateTime::DaysOfWeek daysOfWeek, Poco::Data::Time startTime, Poco::Data::Time endTime);

	/**
	 * @brief Destructor
	 */
	virtual ~WeeklyCourse();

	/**
	 * @brief Function to get the days of the week
	 */
	Poco::DateTime::DaysOfWeek getDaysOfWeek() const;

	/**
	 * @brief Function to get the end time of the course
	 */
	const Poco::Data::Time& getEndTime() const;

	/**
	 * @brief Function to get the start time of the course
	 */
	const Poco::Data::Time& getStartTime() const;

	/**
	 * @brief Function to print the course details
	 */
	void print() const;

	/**
	 * @brief Function to write to the file
	 * @param out : ostream& - stores the file to be written to
	 */
	virtual void write (std::ostream& out) const override;
};

#endif /* WEEKLYCOURSE_H_ */
