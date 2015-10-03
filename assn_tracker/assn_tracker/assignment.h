#include "Date.h"
#include <string>
using namespace std;

#pragma once
class assignment
{
public:
	assignment();
	Date getDueDate() const;

private:
	Date dueDate;
	string description;
	Date assignedDate;
	enum status
	{
		assigned,
		completed,
		late
	};
};