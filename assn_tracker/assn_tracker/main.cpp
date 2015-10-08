// Daniel McNary
// CS 303: Data Structures
// Prof. Kuhail
// 10/07/2015
// Project 1A: Assignment Tracker

#include <iostream>
#include "user_interface.h"
#include "date.h"
using namespace std;

void displayMenu();

int main()
{
	// Initialize
	user_interface userInterface; 

	// Loop that continuously shows the menu, gets the user input, and processes the command
	while (true)
	{
		userInterface.displayMenu();
		userInterface.processMenuChoice(userInterface.getMenuChoice());
	}

	return 0;
}