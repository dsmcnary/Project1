// Daniel McNary
// CS 303: Data Structures
// Prof. Kuhail
// 10/07/2015
// Project 1A: Assignment Tracker

#include "assignment.h"
#include <iostream>

// Constructors
assignment::assignment()
{
	;
}

assignment::assignment(Date due, string desc, Date assign, statusOptions sts)
{
	setDueDate(due);			// Just call setters for input values
	setDescription(desc);
	setAssignedDate(assign);
	setStatus(sts);
}

assignment::assignment(Date due, string desc, Date assign, string sts)
{
	setDueDate(due);			// Just call setters for input values
	setDescription(desc);
	setAssignedDate(assign);

	if (sts == "assigned")		// Since sts is a string, convert to an enum type StatusOptions
		setStatus(assigned);
	else if (sts == "completed")
		setStatus(completed);
	else if (sts == "late")
		setStatus(late);
}

// Getters
Date assignment::getDueDate() const
{
	return dueDate;
}

string assignment::getDescription() const
{
	return description;
}

Date assignment::getAssignedDate() const
{
	return assignedDate;
}

statusOptions assignment::getStatus() const
{
	return status;
}


// Setters
void assignment::setDueDate(Date d)
{
	dueDate = d;
}

void assignment::setDescription(string d)
{
	description = d; 
}

void assignment::setAssignedDate(Date d)
{
	assignedDate = d;
}

void assignment::setStatus(statusOptions s)
{
	status = s;
}


// Other Functions
// Prints the assignment to screen as required
void assignment::printAssignment()
{
	// print attributes separated by ','
	cout << dueDate.toString() << ", " << description << ", " << assignedDate.toString() << ", ";
	
	if (status == 0)			// Convert status to a string based on index in enum declaration
		cout << "assigned";
	else if (status == 1)
		cout << "completed";
	else if (status == 2)
		cout << "late";
	cout << endl;
}

// Constructs a display string, similar to printAssignment()
string assignment::displayString()
{
	string s; 
	s = dueDate.toString() + ", " + description + ", " + assignedDate.toString() + ", ";

	if (status == 0)
		s += "assigned\n";
	else if (status == 1)
		s += "completed\n";
	else if (status == 2)
		s += "late\n";			// Only difference is newline character at end '\n'

	return s;					// return string
}

// Just another format for printing an assignment to screen - easier to read for troubleshootig
void assignment::prettyPrintAssignment()
{
	// Display field name and its value
	cout << "\t\t\tAssigned Date  : " << assignedDate.toString() << endl
		<< "\t\t\tDue Date       : " << dueDate.toString() << endl
		<< "\t\t\tDescription    : " << description << endl
		<< "\t\t\tStatus         : ";

	if (status == 0)				// Convert status to string
		cout << "Assigned";
	else if (status == 1)
		cout << "Late";
	else if (status == 2)
		cout << "Completed";
	cout << endl;
}