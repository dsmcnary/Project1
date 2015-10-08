// Daniel McNary
// CS 303: Data Structures
// Prof. Kuhail
// 10/07/2015
// Project 1A: Assignment Tracker

#include <list>
#include "assignment.h"
using namespace std;

#pragma once
class assignmentHandler
{ 
public:
	assignmentHandler();				// Default Constructor
	void insert(assignment assn);		// Insert assignment in order
	assignment getAssnData();			// Gets data from user about an assignment
	void printAssignments();			// Display list of assignments to screen
	void editAssignment(int choice);	// Edit an assignments attributes
	void completeAssignment();			// Change status to completed/late
	int countLate();					// How many late assignments stored
	void save();						// Saves each assignment to file
	void load();						// Loads assignments from a file

private:
	list<assignment> assnList;			// List of assignments
	list<assignment>::iterator itr;		// Iterator for assnList
	Date inputDateFromUser();			// Prompt user for date and return Date type
	Date convertStrToDate(string s);	// Converts a string "01/01/2015" to a Date type
};