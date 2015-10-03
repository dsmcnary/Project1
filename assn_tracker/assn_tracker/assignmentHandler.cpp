#include "assignmentHandler.h"
#include <iostream>
using namespace std;

assignmentHandler::assignmentHandler()
{
	return;
}


void assignmentHandler::insert(assignment assn)
{
	if (assnList.empty())
		assnList.push_back(assn);

	else
	{
		itr = assnList.begin();
		while (assn.getDueDate() > itr->getDueDate() || itr == assnList.end() )
			itr++;

		assnList.insert(itr, assn);
	}
}

assignment assignmentHandler::getAssnData()
{ 
	assignment assn;

	Date temp; 
	string temp2;

	
	cout << "Assigned Date \"01-01-2015\": ";
	cin >> temp;
	assn.setAssignedDate(temp);

	cout << "Due Date \"01-01-2015\": "; 
	cin >> temp;
	assn.setDueDate(temp);

	cout << "Description: ";
	cin >> temp2;
	assn.setDescription(temp2);

	assn.setStatus(assigned);
	
	return assn; 
}