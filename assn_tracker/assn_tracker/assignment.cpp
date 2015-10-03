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
	cout << dueDate.toString() << ', ' << description << ', ' << assignedDate.toString() << ', ' << status << endl;
}