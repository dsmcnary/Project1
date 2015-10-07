#include <list>
#include "assignment.h"
using namespace std;

#pragma once
class assignmentHandler
{ 
public:
	assignmentHandler();
	void insert(assignment assn);
	assignment getAssnData();
	void printAssignments();
	void editAssignment(int choice);
	void completeAssignment();
	int countLate();
	void save();
	void load();

private:
	list<assignment> assnList;
	list<assignment>::iterator itr;
	Date inputDateFromUser();
	Date convertStrToDate(string s);
};