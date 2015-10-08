// Daniel McNary
// CS 303: Data Structures
// Prof. Kuhail
// 10/07/2015
// Project 1A: Assignment Tracker

#include "user_interface.h"
#include "assignmentHandler.h"
#include <iostream>
using namespace std;

// Default Constructor
user_interface::user_interface()
{
	;
}

// Displays Menu Options to Screen
void user_interface::displayMenu()
{
	cout << endl; 

	for (int i = 0; i < 40; i++)
		cout << "//";

	cout << endl
		<< "\t\t\t1. Display Assignments" << endl			// Assignment Options
		<< "\t\t\t2. Add Assignment" << endl
		<< "\t\t\t3. Edit Due date" << endl
		<< "\t\t\t4. Edit Description" << endl
		<< "\t\t\t5. Complete Assignment" << endl
		<< "\t\t\t6. Number of Late Assignments" << endl
		<< "\t\t\t7. Save" << endl
		<< "\t\t\t8. Exit" << endl
		<< endl;

	for (int i = 0; i < 40; i++)
		cout << "//";

	cout << endl;
}

// Get the users choice and return that value
char user_interface::getMenuChoice()
{
	cout << "Enter Menu Choice: ";					// Prompt user for input

	char menuChoice = '\0';
	cin >> menuChoice;								// Get the input

	if (menuChoice > '0' && menuChoice < '9')		// Check if valid
		return menuChoice;

	else
	{
		cerr << "Invalid Input" << endl;			// If not valid, prompt again
		return getMenuChoice();						// If repeated many times, may cause stack overflow
	}
}

// Accepts the users menu choice and process the appropriate functions
void user_interface::processMenuChoice(char choice)
{
	switch (choice)
	{
	case '1':
		assnHand.printAssignments();				// Displays assignments to screen
		break;
	case '2':
		assnHand.insert(assnHand.getAssnData());	// Inserts an assignment after getting the users input for an assignment
		break;
	case '3':
		assnHand.editAssignment(1);					// Call editAssignment() to edit the dueDate
		break;
	case '4':
		assnHand.editAssignment(2);					// Call editAssignment() to edit the description
		break;
	case '5':
		assnHand.completeAssignment();				// Mark an assignment as completed / late
		break;
	case '6':
		assnHand.countLate();						// Count the number of late assignments
		break;
	case '7':
		assnHand.save();							// Manually save the assignments to file
		break;
	case '8':
		assnHand.save();							// Auto Save on Exit
		exit(0);									// Force an exit of the program
		break;
	}
}