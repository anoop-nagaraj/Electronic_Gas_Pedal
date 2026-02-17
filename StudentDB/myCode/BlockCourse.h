/*
 * BlockCourse.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include "Course.h"

#ifndef BLOCKCOURSE_H_
#define BLOCKCOURSE_H_

class BlockCourse: public Course
{
private:

	/**
	 * @brief startDate : Poco::Data::Date - stores the start date of the course
	 */
	Poco::Data::Date startDate;

	/**
	 * @brief endDate : Poco::Data::Date - stores the end date of the course
	 */
	Poco::Data::Date endDate;

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
	 * @param startDate : Poco::Data::Date - stores the start date of the course
	 * @param endDate : Poco::Data::Date - stores the end date of the course
	 * @param startTime : Poco::Data::Time - stores the start time of the course
	 * @param endTime : Poco::Data::Time - stores the end time of the course
	 */
	BlockCourse(unsigned int courseKey, string title, string major, float creditPoints,
			    Poco::Data::Date startDate, Poco::Data::Date endDate,
				Poco::Data::Time startTime, Poco::Data::Time endTime);

	/**
	 * @brief Destructor
	 */
	virtual ~BlockCourse();

	/**
	 * @brief Function to get the start time of the course
	 */
	const Poco::Data::Time& getStartTime() const;

	/**
	 * @brief Function to get the end time of the course
	 */
	const Poco::Data::Time& getEndTime() const;

	/**
	 * @brief Function to get the start date of the course
	 */
	const Poco::Data::Date& getStartDate() const;

	/**
	 * @brief Function to get the end date of the course
	 */
	const Poco::Data::Date& getEndDate() const;

	/**
	 * @brief Function to print the course details
	 */
	void print() const;

	/**
	 * @brief Function to write to the file
	 * @param out : ostream& - stores the file to be written to
	 */
	void write(ostream &out) const;

};

#endif /* BLOCKCOURSE_H_ */
