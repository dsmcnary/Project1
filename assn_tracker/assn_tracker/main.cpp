#include <iostream>
#include "user_interface.h"
#include "date.h"
using namespace std;

void displayMenu();

int main()
{
	user_interface userInterface; 
	userInterface.displayMenu();
	userInterface.getMenuChoice();
	userInterface.processMenuChoice(userInterface.getMenuChoice());

	system("PAUSE");
	return 0;
}