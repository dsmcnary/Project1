#include <iostream>
using namespace std;

void displayMenu();

int main()
{
	displayMenu();

	system("PAUSE");
	return 0;
}

void displayMenu()
{
	for (int i = 0; i < 40; i++)
		cout << "//";

	cout << endl << endl << endl << endl
		<< "\t\t\t1. Display Assignments" << endl
		<< "\t\t\t2. Add Assignment" << endl
		<< "\t\t\t3. Edit Due date" << endl
		<< "\t\t\t4. Edit Description" << endl
		<< "\t\t\t5. Complete Assignment" << endl
		<< "\t\t\t6. Number of Late Assignments" << endl
		<< "\t\t\t7. Save" << endl
		<< "\t\t\t8. Exit" << endl
		<< endl << endl << endl << endl; 

	for (int i = 0; i < 40; i++)
		cout << "//";
}