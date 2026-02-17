/*
 * Enrollment.cpp
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include "Enrollment.h"

/*
 * Constructor
 */
Enrollment::Enrollment(float grade, string semester, const Course *course)
{
	this->grade = grade;
	this->semester = semester;
	this->course = course;
}

/*
 * Function to return Grade
 */
float Enrollment::getGrade() const
{
	return grade;
}

/*
 * Function to return enrolled semester
 */
const string& Enrollment::getSemester() const
{
	return semester;
}

/*
 * Function to return enrolled course
 */
const Course* Enrollment::getCourse() const
{
	return course;
}

/*
 * Function to set Grade
 */
void Enrollment::setGrade(float grade)
{
	this->grade = grade;
}

/*
 * Destructor
 */
Enrollment::~Enrollment()
{
	// TODO Auto-generated destructor stub
}

/*
 * Function to overload the == operator for Enrollment type objects
 */
bool Enrollment::operator ==(Enrollment other) const
{
	bool query;

	if (grade == other.grade && semester == other.semester && course == other.course)
	{
		query = true;
	}
	else
	{
		query = false;
	}
	return query;
}

