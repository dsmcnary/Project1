// Daniel McNary
// CS 303: Data Structures
// Prof. Kuhail
// 10/07/2015
// Project 1A: Assignment Tracker

#include "Date.h"
#include <string>
using namespace std;

#pragma once
enum statusOptions		// Declares an enum type for the status of an assignment
{
	assigned,			// Default value
	completed,			// Completed by due date
	late				// Completed after due date
};

class assignment
{
public:
	assignment();							// Default constructors
	assignment(Date due, string desc, Date assign, statusOptions sts);
	assignment(Date due, string desc, Date assign, string sts);
	Date getDueDate() const;				// Getters
	string getDescription() const;
	Date getAssignedDate() const;
	statusOptions getStatus() const;
	void setDueDate(Date d);				// Setters
	void setDescription(string d);
	void setAssignedDate(Date d);
	void setStatus(statusOptions s);
	void printAssignment();					// Print assignment to screen, as required
	string displayString();					// Returns a string similar to printAssignment() displays
	void prettyPrintAssignment();			// Prints an assignment to screen, in convienent form

private:
	Date dueDate;				// Assignment attributes as required
	string description;
	Date assignedDate;
	statusOptions status;
};