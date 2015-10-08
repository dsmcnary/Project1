// Daniel McNary
// CS 303: Data Structures
// Prof. Kuhail
// 10/07/2015
// Project 1A: Assignment Tracker

#include "assignmentHandler.h"
#include <iostream>
#include <fstream>
using namespace std;

// Default constructor
assignmentHandler::assignmentHandler()
{
	load();			// Automatically load assignments from file when starting
}

// Inserts an assignment in order of dueDate to the list
void assignmentHandler::insert(assignment assn)
{
	// Check if Assigned Date already exists
	for (itr = assnList.begin(); itr != assnList.end(); itr++)
	{
		if (itr->getAssignedDate() == assn.getAssignedDate())
		{
			cerr << "ERROR: Assignment already exists with that Assigned Date" << endl;
			return;
		}
	}

	// Make sure Due Date is after Assigned Date
	if (assn.getDueDate() <= assn.getAssignedDate())
	{
		cerr << "ERROR: Due Date must be greater than the Assigned Date" << endl;
		return;
	}
	
    // If the list is empty, just add the assignment
    if (assnList.empty())
        assnList.push_back(assn);
        
    // Special case for only one assn in the list
    else if (assnList.size() == 1)
    {
		// Either put new assn after or before the only item in the list as necessary
        if (assn.getDueDate() > assnList.begin()->getDueDate())
            assnList.push_back(assn);
        else
            assnList.push_front(assn);
    }

	// No more special cases
	// Check whether or not the assn should be at the front or back of the list and add as applicable
	else if (assn.getDueDate() > (--assnList.end())->getDueDate())
			assnList.push_back(assn);

	else if (assn.getDueDate() <= assnList.begin()->getAssignedDate())
			assnList.push_front(assn);

	// If still not added, then add as appropriate in the middle of the list
	else
	{
	// As long as there are multiple assn's in the list
		list<assignment>::iterator itr2;
		for (itr = assnList.begin(); itr != --assnList.end(); itr++)
		{
			itr2 = itr;	// copy current iterator
			itr2++;		// increment to point at next item
			// Advance the iterator until just before where it should be added
			if (assn.getDueDate() > itr->getDueDate() && assn.getDueDate() <= itr2->getDueDate())
			{
				// add the assignment and exit the loop
				assnList.insert(itr2, assn);
				break;
			}
		}
	}
}

// Gets the data for an assignment from the user standard input
assignment assignmentHandler::getAssnData()
{ 
	// Initialize
	assignment assn;
	string desc, clearBuffer;

	// Get Assigned Date from User and Set to Assignment
	cout << "Assigned Date \"01-01-2015\": ";
	assn.setAssignedDate(inputDateFromUser());

	// Get Due Date from User and Set to Assignment
	cout << "Due Date \"01-01-2015\": "; 
	assn.setDueDate(inputDateFromUser());

	// Get Description from User and Set to Assignment
	cout << "Description: ";
	getline(cin, clearBuffer);		// Clear buffer
	getline(cin, desc);				// get description
	assn.setDescription(desc);

	// Automatically set status to being assigned
	assn.setStatus(assigned);		
	
	return assn; 
}

// Prints the requested assn's to screen
void assignmentHandler::printAssignments()
{
	// Prompts user for status of assignments to be printed to screen
	char choice = '\0';
	cout << "Display 1) All Assignments 2) Assigned Assignments 3) Completed Assignments" << endl;
	cin >> choice;

	// Iterates through list and prints items with specified status
	switch (choice)
	{
	case '1':
	{
		// Iterate through list and display each assignment screen (ALL Assignments)
		for (itr = assnList.begin(); itr != assnList.end(); itr++)
		{
			itr->printAssignment();
		}
		break;
	}
	case '2':
	{
		// Iterate through list and display each assignment screen (Assigned status)
		for (itr = assnList.begin(); itr != assnList.end(); itr++)
		{
			if (itr->getStatus() == assigned)
				itr->printAssignment();
		}
		break;
	}
	case '3':
	{
		// Iterate through list and display each assignment screen (Completed or Late status)
		for (itr = assnList.begin(); itr != assnList.end(); itr++)
		{
			if (itr->getStatus() == completed || itr->getStatus() == late)
				itr->printAssignment();
		}
		break;
	}
	}

	return;
}

// Edits the dueDate or description based on input from the menu
void assignmentHandler::editAssignment(int choice)
{
	// Initialize
	Date assignedDate;
	string desc = "", clearBuffer;

	// Get Assigned Date from User
	cout << "// Editing Assignment //" << endl
		<< "Assigned Date \"01-01-2015\": ";
	assignedDate = inputDateFromUser();

	// Find desired assignment in list
	for (itr = assnList.begin(); itr != assnList.end(); itr++)
	{
		if (itr->getAssignedDate() == assignedDate)
		{
			// Display current assignmnet
			cout << "\t\t\tCurrent Assignment: " << endl;
			itr->prettyPrintAssignment();

			// Change Due Date / Description based on input
			switch (choice)
			{
				case 1:
					// Get New Date from user
					cout << "New Due Date: ";
					if (itr->getDueDate() <= itr->getAssignedDate())
					{
						cerr << "ERROR: Due Date must be greater than the Assigned Date" << endl;
						return;
					}
					else
					{
						itr->setDueDate(inputDateFromUser());	// Set new due date
						break;
					}

				case 2:
					// Get New Description from user
					cout << "New Description: ";
					getline(cin, clearBuffer);	// empty buffer
					getline(cin, desc);
					itr->setDescription(desc);	// Set the new description
					break;
			}
			
			return;	// return after finding assignment in list
		}
	}

	// Assignment with given assigned date not found in list
	cerr << "ERROR: No assignment has been assigned on: " << assignedDate.toString() << endl;
	return;
}

// Marks an assignment as complete or late
void assignmentHandler::completeAssignment()
{
	// Initialize
	Date assignedDate, completeDate;
	char choice = '\0';

	// Get assignedDate for assignment to complete
	cout << "// Completing Assignment //" << endl
		<< "Assigned Date \"01-01-2015\": ";
	assignedDate = inputDateFromUser();

	cout << "Completed Date \"01-01-2015\": ";
	completeDate = inputDateFromUser();

	// Find assignment in list
	for (itr = assnList.begin(); itr != assnList.end(); itr++)
	{
		if (itr->getAssignedDate() == assignedDate)
		{
			// Complete the assignment
			if (completeDate > itr->getDueDate())
				itr->setStatus(late);
			else
				itr->setStatus(completed);
			return;		// return after finding assignment in list
		}
	}

	// Assignment with given assigned date not found in list 
	cerr << "ERROR: No assignment has been assigned on: " << assignedDate.toString() << endl;
}

// Gets a date from the user and returns it
Date assignmentHandler::inputDateFromUser()
{
	// Initialize
	Date inputDate;

	// Try to accept a date from the user
	try
	{
		cin >> inputDate;
	}
	// If it throws an exception, catch it and let the user know
	catch (std::exception)
	{
		cerr << "ERROR: Invalid Date" << endl;
	}

	// Return the date - the main program will handle it further
	return inputDate;
}

// Adds up how many late assignments exist
int assignmentHandler::countLate()
{
	int lateCount = 0; // start count at zero

	// Iterate through assignment list
	for (itr = assnList.begin(); itr != assnList.end(); itr++)
	{
		if (itr->getStatus() == late)
			lateCount++;		// if late then increment lateCount
	}

	cout << "Late Assignments: " << lateCount << endl;

	return lateCount;
}

// Saves all of the assignments to file
void assignmentHandler::save()
{
	// Initialization
	ofstream fout;
	fout.open("assignment_list.csv");	// open file

	// Iterate through the list of assignments
	for (itr = assnList.begin(); itr != assnList.end(); itr++)
	{
		fout << itr->displayString();	// print displayString to file
	}

	fout.close();	// close file
}

// Loads all of the assignments from a file
void assignmentHandler::load()
{
	// Initialization
	ifstream fin;
	string assignDateStr, dueDateStr, stsStr;
	Date assignDate, dueDate;
	string desc;
	assignment assn;
	
	fin.open("assignment_list.csv");	// Open input stream


	while (!fin.eof())	// Keep reading until end of file
	{
		if (fin >> dueDateStr >> desc >> assignDateStr >> stsStr)		// as long as more inputs
		{
			// remove the comma at the end of each field for first three fields
			dueDateStr = dueDateStr.substr(0, dueDateStr.length() - 1);
			assignDateStr = assignDateStr.substr(0, assignDateStr.length() - 1);
			desc = desc.substr(0, desc.length() - 1);

			// convert the string 01/01/2015 to a Date item
			assignDate = convertStrToDate(assignDateStr);
			dueDate = convertStrToDate(dueDateStr);

			// Call the assignment constructor and pass it to be inserted to the list
			insert( assignment(dueDate, desc, assignDate, stsStr));
		}

		// Ignore the last empty line in a file or any line without proper input fields
		else
			break;
	}

	fin.close();	// Close the files
}

// Converts a string 01/01/2015 to a Date item
Date assignmentHandler::convertStrToDate(string s)
{
	// Initialize
	int day, month, year;

	// month is upto the first '/'
	month = stoi(s.substr(0, s.find('/')));

	// Set the remaining part of the string to s (excluding the /)
	s = s.substr(s.find('/')+1);
	
	// day is upto the first '/'
	day = stoi(s.substr(0, s.find('/')));

	// Set the remaining part of the string to year (excluding the /)
	year = stoi(s.substr(s.find('/')+1));

	// construct a date and pass it back to caller
	return Date(year, month, day);
}