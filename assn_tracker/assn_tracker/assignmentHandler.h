#include <list>
#include "assignment.h"
using namespace std;

#pragma once
class assignmentHandler
{
public:
	assignmentHandler();
	void addItem(assignment assn);
	void removeItem(list<assignment>::iterator iter);
	~assignmentHandler();

private:
	list<assignment> assnList;
	list<assignment>::iterator itr;
};