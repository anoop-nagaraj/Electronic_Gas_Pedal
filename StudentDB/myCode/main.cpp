// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include "SimpleUI.h"

#include <Poco/Data/Date.h>
#include <Poco/Data/Time.h>
#include <Poco/DateTime.h>

using namespace std;

// Main program
int main (void)
{
	cout << "The following functions can be performed on the Database. " << endl;
	cout << "Please choose an operation :" << endl;

	StudentDb dataBase;
	SimpleUi userInterface(dataBase);

	while (true)
	{
		userInterface.run();
		cout << endl;
	}
}
