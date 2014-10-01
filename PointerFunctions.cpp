#include "PointerFunctions.h"

#include <iostream>		// Necessary for cout and cin
#include <windows.h>	// Necessary for HANDLE, SetConsoleTextAttribute, Sleep,
						// COORD, BACKGROUND_ and FOREGROUND_ consts
#include <string>		// Necessary for string variables
#include <vector>		// For vectors
#include <mmsystem.h>	// Necessary for PlaySound
#include <fstream>		// For reading an writing to disk files

#pragma comment(lib, "winmm.lib")  //Necessary for PlaySound

using namespace std;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		START FUNCTION DEFINITIONS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/******************************************************************************

FUNCTION NAME:	hitEnter
DESCRIPTION:	Pause the screen to wait for user to hit Enter To continue
CREDIT:			The inital function was borrowed from Professor Larry Forman's
code in project HO_1_1_COLOR

******************************************************************************/

void hitEnter()
{
	/**************************************************************
	***		LOCAL CONSTANT DECLARATIONS AND DEFINITIONS		***
	**************************************************************/
	// no constants

	/**************************************************************
	***			LOCAL VARIABLE DECLARATIONS					***
	**************************************************************/
	// no local variables


	cout << "\n\n\t\t     << Hit ENTER to Continue >> \n";

	cin.ignore();	// Clear out the keyboard input buffer, so <return> won't impact hitEnter()
	// This is here for extra protection

	return;		//return is optional in a void function, but kept for consistancy
}



/******************************************************************************

NAME:			gotoXY
DESCRIPTION:	Position the cursor to the column (x) and row (y)
CREDIT:			This function was borrowed from Professor Larry Forman's
				code in project HO_1_4

******************************************************************************/

void gotoXY(int x, int y)
{
	/**************************************************************
	***				LOCAL VARIABLE DECLARATIONS					***
	**************************************************************/
	COORD  xy = { x, y };
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	/////////////////////////////////////////////////////////////////////////

	SetConsoleCursorPosition(hConsole, xy);
	//Wow, isn't this cool?
}


/******************************************************************************

FUNCTION NAME:	P1TT_Plus_Menu
DESCRIPTION:	Onscreen menu for Affirmative Interaction Program,
to select Sign in, Logo, Affirmative Interaction, Display Dictionary, or Exit

******************************************************************************/

void P1TT_Plus_Menu()
{
	/**************************************************************
	***		LOCAL CONSTANT DECLARATIONS AND DEFINITIONS		***
	**************************************************************/
	// no constants

	/**************************************************************
	***			LOCAL VARIABLE DECLARATIONS					***
	**************************************************************/
	char selection;					// User input character for menu selection
	string userName = "John Doe";	// User name (default value) 

	do
	{
		// Clear the screen and put the cursor in the top left corner
		system("CLS");
		gotoXY(0, 0);

		// Draw the menu
		cout << "\n\t\t MENU";
		cout << "\n\t P - Simple Pointer Demonstration";
		cout << "\n\t A - Pointer Arithmetic";
		cout << "\n\t C - Pointers to Constants";
		cout << "\n\t X - Exit Program";
		cout << "\n\t ";
		cout << "\n\t Please enter your selection and hit RETURN : ";

		cin >> selection;


		switch (toupper(selection))
		{
		case 'P':
			cout << "\n\t You chose to start the Simple Pointer Presentation \n\n";
			SimplePointer();		// Call function to run the Simple Pointer Presentation
			break;
		case 'A':
			cout << "\n\t You chose to start the Pointer Arithmetic Presentation \n\n";
			PointerArithmetic();		// Call function to run the Pointer Arithmetic Presentation
			break;
		case 'C':
			cout << "\n\tYou chose the Pointers to Constants Presentation \n\n";
			ConstantsPointers();		// Call function to run the Pointers to Constants Presentation
			break;
		case 'X':
			cout << "\n\t You chose to exit\n\n";
			Sleep(1400);
			break;

		default:
			cout << "\n\t Sorry, but " << selection << " is not a valid entry.";
			cout << "\n\t Please try again . . . \n\n";
			Sleep(2200);	// Pause for short time before message is erased when menu is redrawn
			break;
		}

	} while (toupper(selection) != 'X');

	return;
}


/******************************************************************************

FUNCTION NAME:	SimplePointer
DESCRIPTION:	Function to use and describe use of simple pointer functions
DEVELOPER: 	Chris Myers, for Team "Queens of CPP"

******************************************************************************/

void SimplePointer()
{
	/**************************************************************
	***		LOCAL CONSTANT DECLARATIONS AND DEFINITIONS		***
	**************************************************************/
	// no constants

	/**************************************************************
	***			LOCAL VARIABLE DECLARATIONS					***
	**************************************************************/
	// Local variables declared below inside portions of code that explains their functions


	Sleep(1500);
	system("cls");
	gotoXY(0, 0);

	cin.ignore();	// Clear out the keyboard buffer


	//text
	int example1 = 10;	// .....

	cout << "\n\nThe variable \"example1\" is an integer.\n\n";
	cout << " \tValue = " << example1 << "\n\tMemory Address = " << &example1;
	cout << "\n\n \"example1\" in code gives the value.";
	cout << "\n \"&example1\" in code gives the memory address.";
	cout << "\n\nThe memory address is in hexadecimal.";
	cout << "\n\n\tCode: \"long (&example1)\" gives the memory address in base-10: " << long(&example1);

	hitEnter();		//pause for user to hit enter
	cout << "\n\n-------------------------------------------------------------------\n";

	//text
	string example2 = "Hello";	// .....

	cout << "\n\n\nThe variable \"example2\" is a string.\n\n";

	cout << " \tValue = " << example2 << "\n\tMemory Address = " << &example2;

	cout << "\n\n \"example2\" in code gives the value.\n \"&example2\" in code gives the memory address.";
	cout << "\n\nThe memory address is just a few locations after the address for \"example1\".\n\n";

	hitEnter();		//pause for user to hit enter
	cout << "\n\n-------------------------------------------------------------------\n";

	int *thePointer;
	thePointer = &example1;

	cout << "\n\n Variable \"thePointer\" is a pointer to an integer.\n\n";
	cout << " In code it's declared: \n\t\t\t\"int *thePointer;\".\n\n\n";
	cout << " It can be loaded with the memory address of \"Example1\" by coding: \n\n\t\t\t\"thePointer = &example1;\"";

	cout << "\n\n\nYou can see here they now have the the same memory address";
	cout << " \n\n\t\t&example1  = " << &example1;
	cout << " \n\t\tthePointer = " << thePointer;

	hitEnter();		//pause for user to hit enter
	cout << "\n\n-------------------------------------------------------------------\n";

	cout << " \n\nThe asterix(*) allows pointer \"thePointer\" to access the VALUE of \"example1\"";
	cout << " \n\n\texample1    = " << example1;
	cout << " \n\t*thePointer = " << *thePointer;

	cout << " \n\nThis becomes useful later on when doing pointer arithmetic. ";

	hitEnter();		//pause for user to hit enter

	// text
	*thePointer = 77;

	cout << "\n\nFor instance, you can indirectly change the value of example1 by assigning a \n new value to \"*thePointer\"";
	cout << " with this code: \n\n\t\t\t\"*thePointer = 77;\"\n";
	cout << "\n\nChecking the value shows it's changed, accessing it either way.\n";
	cout << "\n\t example1    = " << example1;
	cout << "\n\t *thePointer = " << *thePointer;

	hitEnter();		//pause for user to hit enter
	cout << "\n\n-------------------------------------------------------------------\n";


	cout << "\n\n\nThank you" << " \n";

	hitEnter();		//pause for user to hit enter

	return;	//return to the mainMenu function

}


/******************************************************************************

FUNCTION NAME:	PointerArithmetic
DESCRIPTION:	Function to use and describe use of pointer arithmetic functions
DEVELOPER: 	Chris Myers, for Team "Queens of CPP"

******************************************************************************/
void PointerArithmetic()
{
	/**************************************************************
	***		LOCAL CONSTANT DECLARATIONS AND DEFINITIONS		***
	**************************************************************/
	// no constants

	/**************************************************************
	***			LOCAL VARIABLE DECLARATIONS					***
	**************************************************************/
	// Local variables declared below inside portions of code that explains their functions


	Sleep(1500);
	system("cls");
	gotoXY(0, 0);

	cin.ignore();	// Clear out the keyboard buffer


	//text

	cout << "\n\n Let's look at some artithmetic aspects of using pointers.";
	cout << "\n\n\n An integer array is set up with five values";

	int exampleArray[] = { 10, 20, 30, 40, 50 };	// .....
	cout << "\n\n\tCode: exampleArray[] = { 10, 20, 30, 40, 50 }";
	cout << "\n\n The pointer for the array points to the first address.";
	cout << "\n\n\tResult: Memory Address = " << &exampleArray <<" (using &exampleArray)";

	cout << "\n\n We can set up a pointer variable for the array that we can increment.";

	int *arrayPointer;
	arrayPointer = exampleArray;
	cout << " \n\n\tCode: int *arrayPointer;";
	cout << " \n\tCode: arrayPointer = exampleArray;";
	cout << "\n\n\tResult: arrayPointer = " << arrayPointer;
	cout << "\n\tResult: *arrayPointer = " << *arrayPointer;

	hitEnter();		//pause for user to hit enter

	cout << "\n\n Because \"exampleArray\" is an array of integers, incrementing a variable that ";
	cout << "\n points to it jumps to the next integer, not to the next address byte location.";

	arrayPointer++;
	cout << "\n\n\tCode: arrayPointer++;";
	cout << "\n\n\tResult: arrayPointer = " << arrayPointer;
	cout << "\n\tResult: *arrayPointer = " << *arrayPointer;

	cout << "\n\n If you check the hexadecimal address, you'll see it has jumped by four,";
	cout << "\n the number of bytes in memory for an integer.";

	cout << "\n\n An array of doubles (instead of integers) would jump by a larger amount.";

	hitEnter();		//pause for user to hit enter

	cout << "\n\n The pointer variable can be incremented or decremented,";
	cout << "\n but not multiplied or divided.";
	cout << "\n\n Here it has three added to it, resuling in: ";

	arrayPointer += 3;
	cout << " \n\n\tCode: arrayPointer += 3;";
	cout << "\n\n\tResult: arrayPointer = " << arrayPointer;
	cout << "\n\tResult: *arrayPointer = " << *arrayPointer;

	cout << "\n\n You'll notice that the byte address has incremented by 12 (decimal),";
	cout << "\n or 0xC (hex).";

	hitEnter();		//pause for user to hit enter

	cout << "\n\n Decrement works the same way: ";

	arrayPointer -= 2;
	cout << " \n\n\tCode: arrayPointer -= 2;";
	cout << "\n\n\tResult: arrayPointer = " << arrayPointer;
	cout << "\n\tResult: *arrayPointer = " << *arrayPointer;


	cout << "\n\n\n\n\n\n ";

	

	hitEnter();		//pause for user to hit enter
	cout << "\n\n-------------------------------------------------------------------\n";



	cout << "\n\n\nThank you" << " \n";

	hitEnter();		//pause for user to hit enter

	return;	//return to the mainMenu function

}


/******************************************************************************

FUNCTION NAME:	ConstantsPointers
DESCRIPTION:	Function to use and describe use of constants with pointers
DEVELOPER: 	Chris Myers, for Team "Queens of CPP"

******************************************************************************/
void ConstantsPointers()
{
	/**************************************************************
	***		LOCAL CONSTANT DECLARATIONS AND DEFINITIONS		***
	**************************************************************/
	// no constants

	/**************************************************************
	***			LOCAL VARIABLE DECLARATIONS					***
	**************************************************************/
	// Local variables declared below inside portions of code that explains their functions


	Sleep(1500);
	system("cls");
	gotoXY(0, 0);

	cin.ignore();	// Clear out the keyboard buffer


	//text

	cout << "\n\n Let's look at using pointers with constants.";

	cout << "\n\n\n If you want to create a pointer to a constant, then the pointer";
	cout << "\n has to be created as a \"Pointer to Constant\"";
	cout << "\n\n For example, if example1 had been declared a constant:";
	cout << "\n\n\tCode: const int example1 = 10;";
	cout << "\n\n Then a pointer to example1 would need to be created:";
	cout << "\n\n\tCode: const int *thePointer;";
	cout << "\n\tCode: thePointer = &example1;";

	const int example1 = 10;
	const int *thePointer;
	thePointer = &example1;

	hitEnter();		//pause for user to hit enter

	cout << "\n\n\n Earlier we said that you could indirectly change the value";
	cout << "\n\ of a variable by using a pointer to that variable. ";

	cout << "\n\n\n\t\" For instance, you can indirectly change the value of example1";
	cout << "\n\t  by assigning a new value to \"*thePointer\" with this code:  \"";
	cout << "\n\n\t\t\t\"*thePointer = 77;\"\n";
	
	cout << "\n\n However, if example1 is declared a constant, then the compiler";
	cout << "\n\ will not allow the value of example1 to be changed: ";
	cout << "\n\n\tCode: *thePointer = 77;  <-- Causes compile error.";
	
	//*thePointer = 77;  //<-- Causes compile error.

	cout << "\n\n";

	hitEnter();		//pause for user to hit enter

	cout << "\n\n\n But this doesn't mean that there aren't other cases where a";
	cout << "\n \"Pointer to Constant\" can't be changed";
	cout << "\n\n\n For example, Set up an array as a constant and make a pointer to it:";
	cout << "\n\n\tCode: int exampleArray[] = { 10, 20, 30, 40, 50 }; ";
	cout << "\n\tCode: int *arrayPointer;";
	cout << "\n\tCode: thePointer = &exampleArray;";
	
	const int exampleArray[] = { 10, 20, 30, 40, 50 };
	const int *arrayPointer;
	arrayPointer = exampleArray;

	cout << " \n\n\n\n";

	hitEnter();		//pause for user to hit enter


	cout << "\n\n\n The pointer can be incremented to point at the next value in the array";
	cout << "\n\t*arrayPointer = " << *arrayPointer;
	cout << "\n\tMemory Address = " << arrayPointer;
	cout << "\n\n\tCode: arrayPointer++;";
	arrayPointer++;
	cout << "\n\n\t*arrayPointer = " << *arrayPointer;
	cout << "\n\tMemory Address = " << arrayPointer;

	cout << "\n\n\n";

	hitEnter();		//pause for user to hit enter

	cout << "\n\n\n\n\n\n ";

	cout << "\n\n\nThank you" << " \n";
	cout << "\n\n\n\n\n\n ";

	hitEnter();		//pause for user to hit enter

	return;	//return to the mainMenu function

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		END FUNCTION DEFINITIONS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

