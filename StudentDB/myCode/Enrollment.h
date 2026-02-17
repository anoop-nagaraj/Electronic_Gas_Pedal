/*
 * Enrollment.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include <string>
using namespace std;
#include"Course.h"

#ifndef ENROLLMENT_H_
#define ENROLLMENT_H_

class Enrollment
{
private:
	/**
	 * @brief grade : float - stores the grade of the course
	 */
	float grade;

	/**
	 * @brief semester : string - stores the semester of the enrolled course
	 */
	string semester;

	/**
	 * @brief course : Course* - pointer of the class Course
	 */
	const Course *course;


public:
	/**
	 * @brief Constructor of the enrollment
	 * @param semester : string - stores the semester of the enrolled course
	 * @param course : Course* - pointer of the class Course
	 * @param grade : float - stores the grade of the course
	 */
	Enrollment(float grade, string semester, const Course *course );

	/**
	 * @brief Destructor
	 */
	virtual ~Enrollment();

	/**
	 * @brief Function to get the semester
	 */
	const string& getSemester() const;

	/**
	 * @brief Function to get the object of the Course
	 */
	const Course* getCourse() const;

	/**
	 * @brief Function to get the grade
	 */
	float getGrade() const;

	/**
	 * @brief Function to set the grade
	 * @param grade : float - stores the grade of the course
	 */
	void setGrade(float grade);

	/**
	 * @brief Function to overload the == operator for Enrollment type objects
	 * @param other : Enrollment - object of the Class Enrollment
	 */
	bool operator==(Enrollment other) const;

};

#endif /* ENROLLMENT_H_ */
