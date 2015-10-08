#include "assignment.h"
#include <iostream>

// Constructors
assignment::assignment()
{
	;
}

assignment::assignment(Date due, string desc, Date assign, statusOptions sts)
{
	setDueDate(due);
	setDescription(desc);
	setAssignedDate(assign);
	setStatus(sts);
}

assignment::assignment(Date due, string desc, Date assign, string sts)
{
	setDueDate(due);
	setDescription(desc);
	setAssignedDate(assign);

	if (sts == "assigned")
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
void assignment::printAssignment()
{
	cout << dueDate.toString() << ", " << description << ", " << assignedDate.toString() << ", ";
	
	if (status == 0)
		cout << "assigned";
	else if (status == 1)
		cout << "completed";
	else if (status == 2)
		cout << "late";
	
	cout << endl;
}

string assignment::displayString()
{
	string s; 

	s = dueDate.toString() + ", " + description + ", " + assignedDate.toString() + ", ";

	if (status == 0)
		s += "assigned\n";
	else if (status == 1)
		s += "completed\n";
	else if (status == 2)
		s += "late\n";

	return s;
}

void assignment::prettyPrintAssignment()
{
	cout << "\t\t\tAssigned Date  : " << assignedDate.toString() << endl
		<< "\t\t\tDue Date       : " << dueDate.toString() << endl
		<< "\t\t\tDescription    : " << description << endl
		<< "\t\t\tStatus         : ";

	if (status == 0)
		cout << "Assigned";
	else if (status == 1)
		cout << "Late";
	else if (status == 2)
		cout << "Completed";

	cout << endl;
}