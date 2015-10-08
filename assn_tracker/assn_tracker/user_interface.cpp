#include "user_interface.h"
#include "assignmentHandler.h"
#include <iostream>
using namespace std;

user_interface::user_interface()
{
	;
}

void user_interface::displayMenu()
{
	cout << endl; 

	for (int i = 0; i < 40; i++)
		cout << "//";

	cout << endl
		<< "\t\t\t1. Display Assignments" << endl
		<< "\t\t\t2. Add Assignment" << endl
		<< "\t\t\t3. Edit Due date" << endl
		<< "\t\t\t4. Edit Description" << endl
		<< "\t\t\t5. Complete Assignment" << endl
		<< "\t\t\t6. Number of Late Assignments" << endl
		<< "\t\t\t7. Save" << endl
		<< "\t\t\t8. Exit" << endl
		<< endl;

	for (int i = 0; i < 40; i++)
		cout << "//";

	cout << endl;
}

char user_interface::getMenuChoice()
{
	cout << "Enter Menu Choice: ";

	char menuChoice = '\0';
	cin >> menuChoice;

	if (menuChoice > '0' && menuChoice < '9')
		return menuChoice;

	else
	{
		cerr << "Invalid Input" << endl;
		return getMenuChoice();
	}
}

void user_interface::processMenuChoice(char choice)
{
	switch (choice)
	{
	case '1':
		assnHand.printAssignments();
		break;
	case '2':
		assnHand.insert(assnHand.getAssnData());
		break;
	case '3':
		assnHand.editAssignment(1);
		break;
	case '4':
		assnHand.editAssignment(2);
		break;
	case '5':
		assnHand.completeAssignment();
		break;
	case '6':
		assnHand.countLate();
		break;
	case '7':
		assnHand.save();
		break;
	case '8':
		assnHand.save(); // Auto Save on Exit
		exit(0);
		break;
	}
}