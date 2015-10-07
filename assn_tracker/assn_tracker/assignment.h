#include "Date.h"
#include <string>
using namespace std;

#pragma once
enum statusOptions
{
	assigned,
	completed,
	late
};

class assignment
{
public:
	assignment();
	assignment(Date due, string desc, Date assign, statusOptions sts);
	assignment(Date due, string desc, Date assign, string sts);
	Date getDueDate() const;
	string getDescription() const;
	Date getAssignedDate() const;
	statusOptions getStatus() const;
	void setDueDate(Date d);
	void setDescription(string d);
	void setAssignedDate(Date d);
	void setStatus(statusOptions s);
	void printAssignment();
	string displayString();
	void prettyPrintAssignment();

private:
	Date dueDate;
	string description;
	Date assignedDate;
	statusOptions status;
};