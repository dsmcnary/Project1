// Daniel McNary
// CS 303: Data Structures
// Prof. Kuhail
// 10/07/2015
// Project 1A: Assignment Tracker

#include "assignmentHandler.h"

#pragma once

class user_interface
{
public:
	user_interface();                       // Default Constructor
	void displayMenu();                     // Shows the menu on screen
	char getMenuChoice();                   // gets input from the user based on which menu item
	void processMenuChoice(char choice);    // processes a specific menu item

private: 
	assignmentHandler assnHand;             // Assignment Handler
};