/*
 * StudentDb.cpp
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include "StudentDb.h"
#include <iostream>
#include <sstream>
using namespace std;

/**
 * Default Constructor
 */
StudentDb::StudentDb()
{
	// TODO Auto-generated constructor stub

}

/**
 * Destructor
 */
StudentDb::~StudentDb()
{
	// TODO Auto-generated destructor stub
}

/**
 * Function to add Weekly course to the database
 */
void StudentDb::addWeeklyCourse(const WeeklyCourse &course)
{
	unique_ptr<const Course> weeklyCoursePtr (new WeeklyCourse(course));
	courses.insert(make_pair(course.getCourseKey(), move(weeklyCoursePtr)));
}

/**
 * Function to add Blocked course to the database
 */
void StudentDb::addBlockCourse(const BlockCourse &course)
{
	unique_ptr<const Course> blockCoursePtr (new BlockCourse(course));
	courses.insert(make_pair(course.getCourseKey(), move(blockCoursePtr)));
}

/**
 * Function to add student to the database
 */
void StudentDb::addStudent(Student &student)
{
	students.insert(make_pair(student.getMatrikelNumber(), student));
}

/**
 * Function to list courses in the database.
 */
void StudentDb::listCourses() const
{
	int index = 1;
	cout << "Courses present in Database : " << endl;
	for(auto const &courseAdded : courses)
	{
		cout << index << ") ";
		courseAdded.second->print();
		index++;
	}
}

/**
 * Function to check whether a matrikel number is present in the database
 */
bool StudentDb::checkMatrikelNumber(unsigned int matrikelNumber) const
{
	bool query;
	for(auto matrikel : students)
	{
		if (matrikelNumber == matrikel.second.getMatrikelNumber())
		{
			query = true;
			break;
		}
		else
		{
			query = false;
		}
	}
	return query;
}

/**
 * Function to check if a course key is present in the database.
 */
bool StudentDb::checkCourseKey(unsigned int courseID) const
{
	bool query;
	for(auto &courseKey : courses)
	{
		if (courseID == courseKey.second->getCourseKey())
		{
			query = true;
			break;
		}
		else
		{
			query = false;
		}
	}
	return query;
}

/**
 * Function to enroll a student into the database
 */
void StudentDb::enrollStudendToDb(unsigned int matrikelNumber, unsigned int courseKey, string semester)
{
	Enrollment newEnrol(0.0, semester, courses.find(courseKey)->second.get());
	students.at(matrikelNumber).updateEnrollments(newEnrol);

}

/**
 * Function to print student information of a particular matrikel number.
 */
void StudentDb::printStudent(unsigned int matrikelNumber) const
{
	students.at(matrikelNumber).print();
}

/**
 * Function to search if a student is present in the database by name.
 */
void StudentDb::searchStudentInDb(string name)
{
	bool query = false;
	for (auto student : students)
	{
		if(student.second.getFirstName().find(name) < student.second.getFirstName().length()
				|| student.second.getLastName().find(name) < student.second.getLastName().length())
		{
			cout << "Student found : " << endl;
			cout << "First Name :" << student.second.getFirstName() << endl <<
					"Last Name :" << student.second.getLastName() << endl;
			cout << "Matrikel Number :" << student.second.getMatrikelNumber() << endl;
			query = true;
		}
	}
	if (query == false)
	{
		cout << "Student not found by the entered Name.";
	}
}

/**
 * Function to update the information of students in database.
 */
void StudentDb::updateStudentInDb(unsigned int matrikelNumber, unsigned int attribute)
{
	switch(attribute)
	{
	// 1 - First Name
	case 1:
	{
		string newFirstName;
		cout << "Enter the new First Name : ";
		cin >> newFirstName;

		for (auto eachStudent = students.begin(); eachStudent != students.end(); eachStudent++)
		{
				eachStudent->second.setFirstName(newFirstName);
		}

		break;
	}
	// 2 - Last Name
	case 2:
	{
		string newLastName;
		cout << "Enter the new Last Name : ";
		cin >> newLastName;

		for (auto eachStudent = students.begin(); eachStudent != students.end(); eachStudent++)
		{
			eachStudent->second.setLastName(newLastName);
		}

		break;
	}
	// 3 - Date Of Birth
	case 3:
	{
		int newDate, newMonth, newYear;
		cout << "Enter the new date of birth (dd mm yyyy) : ";
		cin >> newDate;
		cin >> newMonth;
		cin >> newYear;

		for (auto eachStudent = students.begin(); eachStudent != students.end(); eachStudent++)
		{
			eachStudent->second.setDateOfBirth(Poco::Data::Date (newYear, newMonth, newDate));
		}

		break;
	}
	// 4 - Enrollment
	case 4:
	{
		unsigned int courseKey, enrollmentAction;
		float newGrade;

		cout << "Select an Option : " << endl
			 << "1. Delete Enrollment" << endl
			 << "2. Update Grade " << endl;
		cin >> enrollmentAction;
		cout << "Enter the Course Key : ";
		cin >> courseKey;

		switch(enrollmentAction)
		{
		//Delete Enrollment
		case 1:
		{
			for(auto editStudent : students)
			{
				if(matrikelNumber == editStudent.second.getMatrikelNumber())
				{
					editStudent.second.deleteEnrollment(courseKey);
				}
			}
			break;
		}

		//Update Grade
		case 2:
		{
			cout << "Please enter the new grade : ";
			cin >> newGrade;

			for(auto editStudent : students)
			{
				if(matrikelNumber == editStudent.second.getMatrikelNumber())
				{
					editStudent.second.updateGrade(courseKey, newGrade);
				}
			}
			break;
		}

		default:
			cout << "Invalid Atrribute.";
			break;
		}
		break;
	}

	// 5 - Address
	case 5:
	{
		string newStreetName, newCityName, newAdditionalInfo;
		unsigned int newPostalCode;
		cout << "Enter the new address : " << endl;

		cout << "Street Name : ";
		cin >> newStreetName;

		cout << "City Name : ";
		cin >> newCityName;

		cout << "Postal Code : ";
		cin >> newPostalCode;

		cout << "Additional Info : ";
		cin >> newAdditionalInfo;

		for (auto eachStudent = students.begin(); eachStudent != students.end(); eachStudent++)
		{
			if (matrikelNumber == eachStudent->second.getMatrikelNumber())
			{
				eachStudent->second.setAddress(Address(newStreetName, newPostalCode, newCityName, newAdditionalInfo));
			}
		}

		break;
	}

	}
}

/**
 * @brief Funtion to write content to database.csv file.
 */
void StudentDb::write(ostream &out) const
{
	size_t studentSize = students.size();
	size_t courseSize = courses.size();

	out << courseSize << endl;
	for (auto &course : courses)
	{
		course.second.get()->write(out);
	}

	out << studentSize << endl;
	for (auto student : students)
	{
		student.second.write(out);
	}

	for (auto student : students)
	{
		out << student.second.getEnrollments().size() << endl;
			for (auto enrollment : student.second.getEnrollments())
			{
				out << student.second.getMatrikelNumber() << ";"
						<< enrollment.getCourse()->getCourseKey() << ";"
						<< enrollment.getSemester() << ";"
						<< enrollment.getGrade() << endl;
			}
	}
}

/**
 * @brief Function to read content from database.csv file.
 */
void StudentDb::read(std::istream &in)
{
	students.clear();
	courses.clear();

	Poco::Data::Time startTime;
	Poco::Data::Time endTime;
	Poco::Data::Date startDate, dateOfBirth;
	Poco::Data::Date endDate;

	string line, number, courseType, subject, major, firstName, lastName, street, cityName, additionalInfo, semester;
	unsigned int courseKey, hour, minute, second = 0, dd, mm, yyyy, matrikelNumber;
	unsigned short postalCode;
	int noOfCouses, noOfStudents, noOfEnrollments, i, days;
	float credits /*,grade*/;

	getline(in, line);
	noOfCouses = stoi(line);

	for (i = 0; i < noOfCouses; i++)
	{
		getline(in, line, ';');
		courseType = line;
		if (courseType == "W")
		{
			getline(in, line, ';');
			courseKey = stoi(line);
			getline(in, line, ';');
			subject = line;
			getline(in, line, ';');
			major = line;
			getline(in, line, ';');
			credits = stoi(line);
			getline(in, line, ';');
			days = stoi(line);
			getline(in, line, ':');

			hour = stoi(line);
			getline(in, line, ';');
			minute = stoi(line);
			startTime.assign(hour, minute, second);

			getline(in, line, ':');
			hour = stoi(line);
			getline(in, line);
			minute = stoi(line);
			endTime.assign(hour, minute, second);

			WeeklyCourse weeklycourse(courseKey, subject, major, credits,
								(Poco::DateTime::DaysOfWeek) days, startTime, endTime);
			addWeeklyCourse(weeklycourse);
		}

		if (courseType == "B")
		{
			getline(in, line, ';');
			courseKey = stoi(line);
			getline(in, line, ';');
			subject = line;
			getline(in, line, ';');
			major = line;
			getline(in, line, ';');
			credits = stoi(line);

			getline(in, line, '.');
			dd = stoi(line);
			getline(in, line, '.');
			mm = stoi(line);
			getline(in, line, ';');
			yyyy = stoi(line);
			startDate.assign(yyyy, mm, dd);

			getline(in, line, '.');
			dd = stoi(line);
			getline(in, line, '.');
			mm = stoi(line);
			getline(in, line, ';');
			yyyy = stoi(line);
			endDate.assign(yyyy, mm, dd);

			getline(in, line, ':');
			hour = stoi(line);
			getline(in, line, ';');
			minute = stoi(line);
			startTime.assign(hour, minute, second);

			getline(in, line, ':');
			hour = stoi(line);
			getline(in, line);
			minute = stoi(line);
			endTime.assign(hour, minute, second);

			BlockCourse blockcourse(courseKey, subject, major, credits, startDate, endDate, startTime, endTime);
			addBlockCourse(blockcourse);
		}

	}

	getline(in, line);
	noOfStudents = stoi(line);

	for(i = 0; i < noOfStudents; i++)
	{
		getline(in, line, ';');
		getline(in, line, ';');
		lastName = line;
		getline(in, line, ';');
		firstName = line;

		getline(in, line, '.');
		dd = stoi(line);
		getline(in, line, '.');
		mm = stoi(line);
		getline(in, line, ';');
		yyyy = stoi(line);
		dateOfBirth.assign(yyyy, mm, dd);

		getline(in, line, ';');
		street = line;
		getline(in, line, ';');
		postalCode = stoi(line);
		getline(in, line, ';');
		cityName = line;
		getline(in, line);
		additionalInfo = line;

		Address address(street, postalCode, cityName, additionalInfo);
		Student student(firstName, lastName, dateOfBirth, address);
		addStudent(student);

	}

	getline(in, line);
	noOfEnrollments = stoi(line);

	for(i = 0; i < noOfEnrollments; i++)
	{
		getline(in, line, ';');
		matrikelNumber = stoi(line);
		getline(in, line, ';');
		courseKey = stoi(line);
		getline(in, line, ';');
		semester = line;
		getline(in, line);
		enrollStudendToDb(matrikelNumber, courseKey, semester);
	}
}

/**
 * Function to connect to server "mnl.de" at port 4242
 */
void StudentDb::connectToServerDatabase()
{
	Poco::Net::SocketAddress host("mnl.de", 4242);
	Poco::Net::StreamSocket socket(host);
	Poco::Net::SocketStream serverStream(socket);

	serverStream << "generate" << endl;

	/*
	 * Data written to a network stream is buffered internally before being sent. If
	 * writing a single character to a network stream led to immediate transmission
	 * of the character, the network would be congested with packets containing only
	 * a small amount of useful information.
	 * The buffered data will therefore only be written to the network when the
	 * buffer becomes full or you trigger writing by calling the flush method.
	 */
	serverStream.flush();

	string receivedJsonData;

	for(int i = 0; i < 2; i++)
	{
		getline(serverStream, receivedJsonData);
	}

	extractJSONData(receivedJsonData);
	serverStream << "quit" << endl;
	serverStream.flush();

}

/**
 * Function to extract data from a JSON file from the server.
 */
void StudentDb::extractJSONData(string json)
{
	string name, firstName, lastName, dob, addr, street, city, additionalInfo;
	int day, month, year;
	unsigned short postalCode;
	Poco::Data::Date dateOfBirth;

	name = JSONparser(json, "name");
	firstName = JSONparser(name, "firstName");
	lastName = JSONparser(name, "lastName");

	dob = JSONparser(json, "dateOfBirth");
	day = stoi(JSONparser(dob, "day"));
	month = stoi(JSONparser(dob, "month"));
	year = stoi(JSONparser(dob, "year"));
	dateOfBirth.assign(year, month, day);

	addr = JSONparser(json, "location");
	street = JSONparser(addr, "street");
	city = JSONparser(addr, "city");
	postalCode = (short) stoi(JSONparser(addr, "postCode"));
	additionalInfo = JSONparser(addr, "state");

	Address address(street, postalCode, city, additionalInfo);
	Student student(firstName, lastName, dateOfBirth, address);
	addStudent(student);
}

/**
 * Function to parse JSON string to cpp file
 */
string StudentDb::JSONparser(string json, string data)
{
	Poco::JSON::Parser parser;
	Poco::Dynamic::Var variable = parser.parse(json);
	Poco::JSON::Object::Ptr object = variable.extract<Poco::JSON::Object::Ptr>();
	return object->getValue<string>(data);
}
