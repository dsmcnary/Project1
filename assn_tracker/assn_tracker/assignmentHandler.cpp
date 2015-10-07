#include "assignmentHandler.h"
#include <iostream>
using namespace std;

assignmentHandler::assignmentHandler()
{
	return;
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
	assignment assn;

	Date temp; 
	string temp2, clearBuffer;

	
	cout << "Assigned Date \"01-01-2015\": ";
	try
	{
		cin >> temp;
	}
	catch (std::exception)
	{
		cout << "ERROR: Invalid Date" << endl;
		return assn;
	}
	
	assn.setAssignedDate(temp);

	cout << "Due Date \"01-01-2015\": "; 
	try
	{
		cin >> temp;
	}
	catch (std::exception)
	{
		cout << "ERROR: Invalid Date" << endl;
		return assn;
	}

	assn.setDueDate(temp);

	cout << "Description: ";
	getline(cin, clearBuffer);
	getline(cin, temp2);
	assn.setDescription(temp2);

	assn.setStatus(assigned);
	
	return assn; 
}

void assignmentHandler::printAssignments()
{
	itr = assnList.begin();
	while (itr != assnList.end())
	{
		itr->printAssignment();
		itr++;
	}
}

void assignmentHandler::editAssignment()
{
	Date assignedDate; 
	char choice = '\0';
	Date dueDate;
	string desc = "", clearBuffer;

	cout << "// Editing Assignment //" << endl
		<< "Assigned Date \"01-01-2015\": ";
	cin >> assignedDate;

	for (itr = assnList.begin(); itr != assnList.end(); itr++)
	{
		if (itr->getAssignedDate() == assignedDate)
		{
			cout << "\t\t\tCurrent Assignment: " << endl;
			itr->prettyPrintAssignment();

			cout << "Edit 1) Due Date or 2) Description or 3) Both: ";
			cin >> choice;

			switch (choice)
			{
				case '1':
					cout << "New Due Date: ";
					cin >> dueDate;
					itr->setDueDate(dueDate);
					break;
				case '2':
					cout << "New Description: ";
					getline(cin, clearBuffer);
					getline(cin, desc);
					itr->setDescription(desc);
					break;
				case '3':
					cout << "New Due Date: ";
					cin >> dueDate;
					itr->setDueDate(dueDate);
					cout << "New Description: ";
					getline(cin, clearBuffer);
					getline(cin, desc);
					itr->setDescription(desc);
					break;
			}
			
			return;
		}
	}

	cerr << "ERROR: No assignment has been assigned on: " << assignedDate.toString() << endl;

	return;
}