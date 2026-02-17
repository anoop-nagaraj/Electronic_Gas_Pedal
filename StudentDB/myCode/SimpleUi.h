/*
 * SimpleUi.h
 *
 *  Created on: Jan 7, 2022
 *      Author: Anoop K N
 */

#include "StudentDb.h"
#include "WeeklyCourse.h"
#include "BlockCourse.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <boost/algorithm/string.hpp>

#ifndef SIMPLEUI_H_
#define SIMPLEUI_H_

class SimpleUi
{
private:
	//StudentDb *dataBase;
	StudentDb &db;

public:
	/**
	 * @brief Constructor
	 * @param db : StudentDb& - reference of the StudentDb class
	 */
	SimpleUi(StudentDb &db);

	/**
	 * @brief Destructor.
	 */
	virtual ~SimpleUi();

	/**
	 * @brief Function to handle the database.
	 */
	void run();

	/**
	 * @brief Function to print database operations.
	 */
	void printDatabaseOperations();

	/**
	 * @brief Function to add new course.
	 */
	void addNewCourse();

	/**
	 * @brief Function to add new course.
	 */
	void addNewStudent();

	/**
	 * @brief Function to write to Database file.
	 */
	void writeToFile();

	/**
	 * @brief Function to read from database file.
	 */
	void readFile();

};

#endif /* SIMPLEUI_H_ */
