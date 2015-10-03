#include "assignmentHandler.h"
using namespace std;

assignmentHandler::assignmentHandler()
{

}


void assignmentHandler::addItem(assignment assn)
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

assignmentHandler::~assignmentHandler()
{

}