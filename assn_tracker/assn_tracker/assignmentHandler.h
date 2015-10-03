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
	//void removeItem(list<assignment>::iterator iter);
	//~assignmentHandler();

private:
	list<assignment> assnList;
	list<assignment>::iterator itr;
};