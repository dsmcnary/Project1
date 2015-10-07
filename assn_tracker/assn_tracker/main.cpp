#include <iostream>
#include "user_interface.h"
#include "date.h"
using namespace std;

void displayMenu();

int main()
{
	user_interface userInterface; 

	while (true)
	{
		userInterface.displayMenu();
		userInterface.processMenuChoice(userInterface.getMenuChoice());
	}
	return 0;
}