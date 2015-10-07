#include "assignment.h"
#include <iostream>

// Constructors
assignment::assignment()
{

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
	/*try
	{
		d.check_valid();
	}
	catch (std::exception)
	{
		cout << "ERROR: Invalid Date" << endl;
		return;
	}*/

	dueDate = d;
}

void assignment::setDescription(string d)
{
	description = d; 
}

void assignment::setAssignedDate(Date d)
{
	/*try
	{
		d.check_valid();
	}
	catch (std::exception)
	{
		cout << "ERROR: Invalid Date" << endl;
		return;
	}*/

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
		cout << "late";
	else if (status == 2)
		cout << "completed";
	
	cout << endl;
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