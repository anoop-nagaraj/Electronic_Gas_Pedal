/*
 * Student.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include<string>
#include <Poco/Data/Date.h>
#include<vector>
#include"Enrollment.h"
#include"Address.h"
#include "course.h"

using namespace std;

#ifndef STUDENT_H_
#define STUDENT_H_

class Student
{
private:
	/**
	 * @brief nextMatrikelNumber : static unsigned int - stores the next matrikel number
	 */
	static unsigned int nextMatrikelNumber;

	/**
	 * @brief matrikelNumber : unsigned int - stores the matrikel number of the student
	 */
	unsigned int matrikelNumber;

	/**
	 * @brief firstName : string - stores the first name of the student
	 */
	string firstName;

	/**
	 * @brief lastName : string - stores the last name of the student
	 */
	string lastName;

	/**
	 * @brief dateOfBirth : Poco::Data::Date - stores the date of birth of the student
	 */
	Poco::Data::Date dateOfBirth;

	/**
	 * @brief enrollments : vector<Enrollment> - stores the enrollments of the student
	 */
	vector<Enrollment> enrollments;

	/**
	 * @brief address : Address - stores the address of the student
	 */
	Address address;

public:
	/**
	 * @brief Constructor
	 * @param firstName : string - stores the first name of the student
	 * @param lastName : string - stores the last name of the student
	 * @param dateOfBirth : Poco::Data::Date - stores the date of birth of the student
	 * @param address : Address - stores the address of the student
	 */
	Student(string firstName, string lastName, Poco::Data::Date dateOfBirth, Address address);

	/**
	 * @brief Destructor
	 */
	virtual ~Student();

	/**
	 * @brief Function to get the first name
	 */
	const string& getFirstName() const;

	/**
	 * @brief Function to set the first name
	 * @param firstName : string - stores the first name
	 */
	void setFirstName(const string &firstName);

	/**
	 * @brief Function to get the last name
	 */
	const string& getLastName() const;

	/**
	 * @brief Function to set the last name
	 * @param lastname : string - stores the last name
	 */
	void setLastName(const string &lastName);

	/**
	 * @brief Function to get the date of the birth of the student
	 */
	const Poco::Data::Date& getDateOfBirth() const;

	/**
	 * @brief Function to set the date of birth of the student
	 * @param dateOfBirth : Poco::Data::Date - stores the date of birth of the student
	 */
	void setDateOfBirth(const Poco::Data::Date &dateOfBirth);

	/**
	 * @brief Function to get the matrikel number
	 */
	unsigned int getMatrikelNumber() const;

	/**
	 * @brief Function to set the matrikel number
	 * @param matrikelNumber : unsigned int - stores the matrikel number of the student
	 */
	void setMatrikelNumber(unsigned int matrikelNumber);

	/**
	 * @brief Function to set the next matrikel number
	 * @param nextMatrikelNumber : unsigned int - stores the next matrikel number
	 */
	void setNextMatrikelNumber(unsigned int nextMatrikelNumber);

	/**
	 * @brief Function to get the enrollments of the student
	 */
	const vector<Enrollment>& getEnrollments() const;

	/**
	 * @brief Function to set the enrollments of the student
	 * @param semester : string - stores the semester of the enrollment
	 * @param course : const Course* - stores the course enrolled by the student
	 * @param grade : float - stores the grade attained in the course
	 */
	void setEnrollments(const vector<Enrollment> &enrollments);

	void updateEnrollments(Enrollment& enrollment);

	/**
	 * @brief Function to get the address of the student
	 */
	const Address& getAddress() const;

	/**
	 * @brief Function to set the address of the student
	 */
	void setAddress(const Address &address);

	/**
	 * @brief Function to delete the enrollment
	 * @param courseKey : unsigned int - stores the course key
	 */
	void deleteEnrollment (unsigned int courseKey);

	/**
	 * @brief Function to update the grade of the student
	 * @param courseKey : unsigned int - stores the course key
	 * @param newGrade : float - new grade
	 */
	void updateGrade (unsigned int courseKey, float newGrade);

	/**
	 * @brief Function to print the student data
	 */
	void print() const;

	/**
	 * @brief Function to write to the file
	 * @param out : ostream& - stores the file to be written to
	 */
	void write(ostream &out) const;
};

#endif /* STUDENT_H_ */
