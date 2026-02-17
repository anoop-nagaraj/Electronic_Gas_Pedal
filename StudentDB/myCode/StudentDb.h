/*
 * StudentDb.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include "Student.h"
#include "Course.h"
#include "BlockCourse.h"
#include "WeeklyCourse.h"
#include "Course.h"
#include <memory>
#include <map>

#include <Poco/Net/SocketAddress.h>
#include <Poco/Net/StreamSocket.h>
#include <Poco/Net/SocketStream.h>
#include <Poco/StreamCopier.h>
#include <Poco/Net/Socket.h>
#include <Poco/JSON/Parser.h>
#include <Poco/Dynamic/Var.h>
#include <Poco/JSON/Object.h>
#include <Poco/JSON/Array.h>

using namespace std;

#ifndef STUDENTDB_H_
#define STUDENTDB_H_

class StudentDb
{
private:
	/**
	 * @brief students : map<int,Student> - stores the student data
	 */
	map<int, Student> students;

	/**
	 * @brief courses : map<int,unique_ptr<const Course>> - stores the list of courses
	 */
	map<int, unique_ptr<const Course>> courses;

public:
	/**
	 * @brief Constructor
	 */
	StudentDb();

	/**
	 * @brief Destructor
	 */
	virtual ~StudentDb();

	/**
	 * @brief Function to add Weekly course to the database
	 */
	void addWeeklyCourse(const WeeklyCourse &course);

	/**
	 * @brief Function to add Blocked course to the database
	 */
	void addBlockCourse(const BlockCourse &course);

	/**
	 * @brief Function to add student to the database
	 */
	void addStudent (Student &student);

	/**
	 * @brief Function to list courses in the database.
	 */
	void listCourses() const;

	/**
	 * @brief Function to check whether a matrikel number is present in the database
	 */
	bool checkMatrikelNumber(unsigned int matrikelNumber) const;

	/**
	 * @brief Function to check if a course key is present in the database.
	 */
	bool checkCourseKey(unsigned int courseID) const;

	/**
	 * @brief Function to enroll a student into the database
	 */
	void enrollStudendToDb(unsigned int matrikelNumber, unsigned int courseKey, string semester);

	/**
	 * @brief Function to print student information of a particular matrikel number.
	 */
	void printStudent(unsigned int matrikelNumber) const;

	/**
	 * @brief Function to search if a student is present in the database by name.
	 */
	void searchStudentInDb(string name);

	/**
	 * @brief Function to update the information of students in database.
	 */
	void updateStudentInDb(unsigned int matrikelNumber, unsigned int attribute);

	/**
	 * @brief Funtion to write content to database.csv file.
	 */
	void write(ostream &out) const;

	/**
	 * @brief Funtion to read content from database.csv file.
	 */
	void read(istream& in);

	/**
	 * @brief Function to connect to server "mnl.de" at port 4242
	 */
	void connectToServerDatabase();

	/**
	 * @brief Function to parse JSON string to cpp file
	 */
	string JSONparser(string json, string data);

	/**
	 * @brief Function to extract data from a JSON file from the server.
	 */
	void extractJSONData(string json);
};

#endif /* STUDENTDB_H_ */
