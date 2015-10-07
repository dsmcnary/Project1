#include "assignmentHandler.h"
#include <iostream>
#include <fstream>
using namespace std;

assignmentHandler::assignmentHandler()
{
	load();
}


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
	else
	{
		assnList.push_back(assn);
	}
	/*
	if (assnList.empty())
		assnList.push_back(assn);

	else
	{
		itr = assnList.begin();
		while (assn.getDueDate() > itr->getDueDate() || itr == assnList.end() )
			itr++;

		assnList.insert(itr, assn);
	}*/
}

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

void assignmentHandler::printAssignments()
{
	// Iterate through list and display each assignment screen
	for (itr = assnList.begin(); itr != assnList.end(); itr++)
	{
		itr->printAssignment();
	}
}

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
				itr->setStatus(completed);
			else
				itr->setStatus(late);
			return;		// return after finding assignment in list
		}
	}

	// Assignment with given assigned date not found in list 
	cerr << "ERROR: No assignment has been assigned on: " << assignedDate.toString() << endl;
}

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

void assignmentHandler::save()
{
	ofstream fout;
	fout.open("assignment_list.csv");

	for (itr = assnList.begin(); itr != assnList.end(); itr++)
	{
		fout << itr->displayString();
	}

	fout.close();
}

void assignmentHandler::load()
{
	ifstream fin;
	string assignDateStr, dueDateStr, stsStr;
	Date assignDate, dueDate;
	string desc;
	statusOptions sts;
	assignment assn;
	
	fin.open("assignment_list.csv");


	while (!fin.eof())
	{
		if (fin >> dueDateStr >> desc >> assignDateStr >> stsStr)
		{
			dueDateStr = dueDateStr.substr(0, dueDateStr.length() - 1);
			assignDateStr = assignDateStr.substr(0, assignDateStr.length() - 1);
			desc = desc.substr(0, desc.length() - 1);

			assignDate = convertStrToDate(assignDateStr);
			dueDate = convertStrToDate(dueDateStr);

			assn = assignment(dueDate, desc, assignDate, stsStr);

			assn.prettyPrintAssignment();

			insert(assn);

			system("PAUSE");
		}
		else
			break;
	}

	fin.close();
}

Date assignmentHandler::convertStrToDate(string s)
{
	// Input String: 01/01/2015
	// Output: Date object

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