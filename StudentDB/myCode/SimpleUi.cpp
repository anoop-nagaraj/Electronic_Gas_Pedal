/*
 * SimpleUi.cpp
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include "SimpleUi.h"
using namespace std;

/*
 * Constructor
 */
SimpleUi::SimpleUi(StudentDb &db)
	:db{db}
{

}

/*
 * Destructor
 */
SimpleUi::~SimpleUi()
{
	// TODO Auto-generated destructor stub
}


/*
 * Function to choose Database operations
 */
void SimpleUi::run()
{
	printDatabaseOperations();

	int command;
	cout << "Enter the command : ";
	cin >> command;
	cout << endl;

	switch(command)
	{
	/* Add new Course */
	case 1:
	{
		addNewCourse();
		cout << "New course added." << endl;
		break;
	}

	/* List courses */
	case 2:
	{
		db.listCourses();
		break;
	}

	/* Add new student */
	case 3:
	{
		addNewStudent();
		break;
	}

	/* Add enrollment */
	case 4:
	{
		unsigned int matrikelNumber, courseKey;
		bool matrikel, courseID;
		string semester;

		cout << "Please enter your Matrikel Number : ";
		cin >> matrikelNumber;
		cout << endl;

		cout << "Please enter the Course ID : ";
		cin >> courseKey;
		cout << endl;

		cout << "Please enter the Semester : ";
		cin >> semester;
		cout << endl;

		matrikel = db.checkMatrikelNumber(matrikelNumber);
		courseID = db.checkCourseKey(courseKey);

		if ((matrikel ==  true) && (courseID == true))
		{
			db.enrollStudendToDb(matrikelNumber, courseKey, semester);
		}

		break;
	}

	/* Print student */
	case 5:
	{
		bool query = false;
		unsigned int matrikelNumber;
		cout << "Enter the matrikel number: ";
		cin >> matrikelNumber;

		if(db.checkMatrikelNumber(matrikelNumber))
		{
			db.printStudent(matrikelNumber);
			query = true;
		}
		if (query == false)
		{
			cout << "Please enter a valid Matrikel Number" << endl;
		}

		break;
	}

	/* Search student */
	case 6:
	{
		string name;
		cout << "Enter the Students name to be searched : ";
		cin >> name;
		db.searchStudentInDb(name);
		break;
	}

	/* Update student */
	case 7:
	{
		unsigned int matrikelNumber, attribute;
		cout << "Please enter the Matrikel Number of the Student : ";
		cin >> matrikelNumber;

		if(db.checkMatrikelNumber(matrikelNumber) ==  true)
		{
			cout << "Please select the Attribute you wish to update : " << endl
					  << "0 - Exit" 	<< endl
					  << "1 - First Name" 	<< endl
					  << "2 - Last Name" 	<< endl
					  << "3 - Date Of Birth"<< endl
					  << "4 - Enrollment" 	<< endl
					  << "5 - Address"		<< endl;

			cin >> attribute;
			if(attribute == 0)
			{
				cout << "No Attributes Updated";
				break;
			}
			else
			{
				db.updateStudentInDb(matrikelNumber, attribute);
			}
		}
		else
		{
			cout << "Please enter a valid Matrikel Number";
		}
		break;
	}

	/* Write to Database File */
	case 8:
	{
		writeToFile();
		cout << "Write to file successful." << endl;
		break;
	}

	/* Read from Database File */
	case 9:
	{
		readFile();
		cout << "Read from file successfully." << endl;
		break;
	}

	/* Fetch Data from mnl.de server and add to Database */
	case 10:
	{
		// https://pocoproject.org/slides/200-Network.pdf

		int noOfStudents;
		cout << "Enter the Number of Students data to be fetched :";
		cin >> noOfStudents;

		for (int i =0; i < noOfStudents; i++)
		{
			db.connectToServerDatabase();
		}

		break;

	}

	default:
	{
		cout << "Invalid Command" << endl;
	}
	break;

	}

}

/**
 * Function to print database operations.
 */
void SimpleUi::printDatabaseOperations()
{
	cout << "1. Add new Course" << endl;
	cout << "2. List courses"   << endl;
	cout << "3. Add new student" << endl;
	cout << "4. Add enrollment" << endl;
	cout << "5. Print student" << endl;
	cout << "6. Search student" << endl;
	cout << "7. Update student" << endl;
	cout << "8. Write to Database file" << endl;
	cout << "9. Read Database file" << endl;
	cout << "10. Get student data from server" << endl;
}

/**
 * Function to handle the database.
 */
void SimpleUi::addNewCourse()
{
	Poco::Data::Time startTime, endTime;

	unsigned int courseKey, dd, mm, yyyy, hour, minute, second;
	string title, major;
	float creditPoints;
	char courseType;

	cout << "Enter the Course Key : ";
	cin >> courseKey;

	cout << "Enter the Title of the course : ";
	cin >> title;

	cout << "Enter the Major : ";
	cin >> major;

	cout << "Enter the Credit Points : ";
	cin >> creditPoints;

	cout << "Enter the Start time of the course : ";
	cin >> hour >> minute >> second;
	startTime.assign(hour, minute, second);

	cout << "Enter the End time of the course : ";
	cin >> hour >> minute >> second;
	endTime.assign(hour, minute, second);

	cout << "Enter the type of Course " << endl;
	cout << "Select 'B' for Block Course or 'W' for Weekly Course : ";
	cin >> courseType;

	switch(courseType)
	{
	case 'B':
	{
		Poco::Data::Date startDate;
		Poco::Data::Date endDate;

		cout << "Enter the Start date in dd mm yyyy format : ";
		cin >> dd >> mm >> yyyy;
		startDate.assign(yyyy, mm, dd);
		cout << "Enter the End date in dd mm yyyy format : ";
		cin >> dd >> mm >> yyyy;
		endDate.assign(yyyy, mm, dd);

		BlockCourse blockcourse(courseKey, title, major, creditPoints,
				startDate, endDate, startTime, endTime);
		db.addBlockCourse(blockcourse);

		break;
	}
	case 'W':
	{
		int dayOfWeek;
		cout << "Select number which Day of the week the course takes place : " << endl;
		cout << "SUNDAY=0, MONDAY=1, TUESDAY=2,	WEDNESDAY=3, THURSDAY=4, FRIDAY=5, SATURDAY=6" << endl;
		cin >> dayOfWeek;

		WeeklyCourse weeklycourse(courseKey, title, major, creditPoints,
				(Poco::DateTime::DaysOfWeek) dayOfWeek, startTime, endTime);
		db.addWeeklyCourse(weeklycourse);

		break;
	}
	default:
	{
		cout << "Invalid Command" << endl;
	}

	break;
	}
}

/**
 * @brief Function to add new course.
 */
void SimpleUi::addNewStudent()
{
	string firstName, lastName;
	Poco::Data::Date dateOfBirth;
	int dd, mm, yyyy;
	string street, cityName, additionalInfo;
	unsigned short postalCode;

	cout << "Enter First Name : ";
	cin >> firstName;

	cout << "Enter Last Name : ";
	cin >> lastName;

	cout << "Enter Date of Birth (dd mm yyyy) : ";
	cin >> dd >> mm >> yyyy;
	dateOfBirth.assign(yyyy, mm, dd);

	cout << "Enter Street name : ";
	cin >> street;

	cout << "Enter City name : ";
	cin >> cityName;

	cout << "Enter Postal-Code : ";
	cin >> postalCode;

	cout << "Enter Additional Info : ";
	cin >> additionalInfo;

	Address address(street, postalCode, cityName, additionalInfo);

	Student student(firstName, lastName, dateOfBirth, address);

	db.addStudent(student);

}

/* Function to Write to Database File */
void SimpleUi::writeToFile()
{
	ofstream myFile;
	myFile.open("Database.csv");

	db.write(myFile);
	myFile.close();
}

/* Function to Read from Database File */
void SimpleUi::readFile()
{
	ifstream myFile;
	myFile.open("Database.csv");

	if(myFile.good())
	{
		db.read(myFile);
		myFile.close();
	}
}
