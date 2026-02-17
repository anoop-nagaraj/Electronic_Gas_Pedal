/*
 * Student.cpp
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include "Student.h"
#include <iostream>
using namespace std;

unsigned int Student::nextMatrikelNumber = 100000;

/*
 * Constructor
 */
Student::Student(string firstName, string lastName, Poco::Data::Date dateOfBirth, Address address)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->dateOfBirth = dateOfBirth;
	this->address = address;
	this->matrikelNumber = nextMatrikelNumber ++;
}

/*
 * Function to set the first name of the student
 */
void Student::setFirstName(const string &firstName)
{
	this->firstName = firstName;
}

/*
 * Function to set the last name of the student
 */
void Student::setLastName(const string &lastName)
{
	this->lastName = lastName;
}

/*
 * Function to set the date of birth of the student
 */
void Student::setDateOfBirth(const Poco::Data::Date &dateOfBirth)
{
	this->dateOfBirth = dateOfBirth;
}

/*
 * Function to set the enrollments
 */
void Student::setEnrollments(const vector<Enrollment> &enrollments)
{
	this->enrollments = enrollments;
}


/*
 * Function to set the next matrikel number
 */
void Student::setNextMatrikelNumber(unsigned int nextMatrikelNumber)
{
	this->nextMatrikelNumber = nextMatrikelNumber;
}

/*
 * Function to set the matrikel number
 */
void Student::setMatrikelNumber(unsigned int matrikelNumber)
{
	this->matrikelNumber = matrikelNumber;
}

/*
 * Function to get the first name
 */
const string& Student::getFirstName() const
{
	return firstName;
}

/*
 * Function to get the last name
 */
const string& Student::getLastName() const
{
	return lastName;
}

/*
 * Function to get the date of the birth of the student
 */
const Poco::Data::Date& Student::getDateOfBirth() const
{
	return dateOfBirth;
}

/*
 * Function to get the matrikel number
 */
unsigned int Student::getMatrikelNumber() const
{
	return matrikelNumber;
}

/*
 * Function to get the enrollments
 */
const vector<Enrollment>& Student::getEnrollments() const
{
	return enrollments;
}

/*
 * Function to get the address of the student
 */
const Address& Student::getAddress() const
{
	return address;
}

/*
 * Destructor
 */
Student::~Student()
{
	// TODO Auto-generated destructor stub
}

void Student::setAddress(const Address &address)
{
	this->address = address;
}

/*
 * Function to update the enrollments of the student
 */
void Student::updateEnrollments(Enrollment &newEnrollment)
{
	if(enrollments.empty())
	{
		enrollments.push_back(newEnrollment);
		cout << "Student has been successfully Enrolled." << endl;
	}

	else
	{
		for(auto enrol : enrollments)
		{
			if(newEnrollment == enrol)
			{
				cout << "Student is already Enrolled. ";
			}
			else
			{
				enrollments.push_back(newEnrollment);
				cout << "Student has been successfully Enrolled." << endl;
			}
		}
	}

}

/**
 * Function to update the grade of a student.
 */
void Student::updateGrade(unsigned int courseKey, float newGrade)
{
	for (auto enrol : enrollments)
	{
		if(courseKey == enrol.getCourse()->getCourseKey())
		{
			enrol.setGrade(newGrade);
		}
		else
		{
			cout << "Course not found.";
		}
	}
}

/**
 * Function to delete the enrollment of the student in a particular course.
 */
void Student::deleteEnrollment(unsigned int courseKey)
{
	for (vector<Enrollment>::iterator enrollment = enrollments.begin(); enrollment != enrollments.end();)
	{
		if(courseKey == (*enrollment).getCourse()->getCourseKey())
		{
			enrollment = enrollments.erase(enrollment);
			cout << "Enrollment Deleted";
			return;
		}
	}
}

/**
 * Function to Print student data.
 */
void Student::print() const
{
	cout << "Name : " << firstName << " " << lastName << endl;
	int day = dateOfBirth.day(), month = dateOfBirth.month(), year = dateOfBirth.year();
	cout << "Date of Birth : ";
	cout << day << "/" << month << "/" << year << endl;
	cout << "Address " << endl;
	cout << "Street : ";
	cout << address.getStreet() << endl;
	cout << "City name : ";
	cout << address.getCityName() << endl;
	cout << "Postal code : ";
	cout << address.getPostalCode() << endl;
	cout << "Additional information : ";
	cout << address.getAdditionalInfo() << endl;
}

/**
 * Function to write student data to Database file.
 */
void Student::write(ostream &out) const
{
	out << matrikelNumber << ";" << lastName << ";" << firstName  << ";"
			<< dateOfBirth.day() << "." << dateOfBirth.month() << "." << dateOfBirth.year() << ";"
			<< address.getStreet() << ";" << address.getPostalCode() << ";"
			<< address.getCityName() << ";" << address.getAdditionalInfo() << endl;
}
