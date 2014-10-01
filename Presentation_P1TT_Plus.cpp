/**************************************************************
***************************************************************
***************************************************************
***                                                         ***
***                   		ID INFORMATION					***
***															***
***   Programmers			:		Chris Myers        		***
***									Eduardo ______			***
***									Eddie ________			***
***   Assignment #		 	:   	P#1TT					***
***   Course # and Title	:	    CISC 205 – OOPS			***
***   Class Meeting Time	:	    TTH 9:35 – 12:45		***
***   Instructor			:	    Professor Forman 		***
***   Hours			   		:		xxx						***
***   Difficulty			:	    1-10					***
***   Completion Date		:	    30 Sept 2014  			***
***   Project Name			:  	    Pointer Presentation	***
***                                                         ***
***************************************************************
***************************************************************
***                                                         ***
***					PROGRAM DESCRIPTION						***
***                                                         ***
***   	In your own words, describe with non-technical 		***
***   	terms what your program does.  Learn how to KISS	***
***		(Keep It Simple and Sweet)							***
***															***
***************************************************************
***************************************************************
***                                                         ***
***				CUSTOM-DEFINED FUNCTION LIST                ***
***									                        ***
***				ConstantsPointers							***
***				gotoXY										***
***             hitEnter                                    ***
***				P1TT_Plus_Menu								***
***				void PointerArithmetic						***
***				SimplePointer								***
***                                                         ***
***                                                         ***
***************************************************************
***************************************************************
***                                                         ***
***						CREDITS								***
***                                                         ***
***   	Thanks for assistance and inspiration from:			***
***															***
***					Professor Forman        				***

***															***
***                                                         ***
***   Thanks for the opportunity to assist and inspire:     ***
***                                                         ***
***		Professor Forman, and the sudents of his			***
***				CISC 205 OOPS class							***
***															***
***************************************************************
***************************************************************
**************************************************************/

#include "PointerFunctions.h"	// Contains all functions used in program
#include <iostream>			// Necessary for cout and cin
#include <windows.h>		// Necessary for HANDLE, SetConsoleTextAttribute, Sleep,
							// COORD, BACKGROUND_ and FOREGROUND_ consts
#include <string>			// Necessary for string variables
#include <mmsystem.h>		// Necessary for PlaySound
#include <vector>			// For vectors
#include <fstream>			// For reading an writing to disk files

#pragma comment(lib, "winmm.lib")  //Necessary for PlaySound

using  namespace  std;	// Allows the "std::" prefix to be assumed on C++ std functions


/**************************************************************
***           FUNCTION PROTOTYPE DECLARATIONS				***
**************************************************************/
	// No local functions
	// All functions included in header file PointerFunctions.h

/**************************************************
***           GLOBAL CONSTANTS					***
**************************************************/
	//	All global constants included in header file PointerFunctions.h


//Credits:
//-Gaddis, Starting Out With C++ From Control Structures through Objects 6th ed.
//-http://www.cprogramming.com/tutorial/function-pointers.html

void doubleValue(int *val);
void pauseFunc();
char *getName();
void my_int_func(int x);

void doubleValue(int *val) //function that takes pointer to an int in parameter
{
	*val *= 2;
}

void my_int_func(int x) //function pointed to by pointer, this function is only called indirectly via the pointer
{
	cout << "Before: \n";
	cout << "Value: " << x << "\n";
	cout << "Address: " << &x << "\n";
	doubleValue(&x);
	cout << "After: \n";
	cout << "Value: " << x << "\n";
	cout << "Address: " << &x << "\n";
}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		BEGINNING OF MAIN PROGRAM
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	/**************************************************************
	***		LOCAL CONSTANT DECLARATIONS AND DEFINITIONS		***
	**************************************************************/
	// no local constants

	/**************************************************************
	***			LOCAL VARIABLE DECLARATIONS					***
	**************************************************************/
	// no local Variables


	// Begin the program

	//welcome();	// Welcome message to user. It contains the programmer's name.

	P1TT_Plus_Menu(); //Run the function that shows the menu for selecting program functions
	cin.ignore();

	//4. pointer parameters
	cout << "4. pointer parameters" << "\n";

	int number = 10;
	cout << "Value: " << number << "\n";
	cout << "Address: " << &number << "\n";

	doubleValue(&number); //looks like simply passing by reference? however, inspect the function definition,
	//notice the * operator on the parameter val, indicating the function will only take
	//a pointer

	cout << "Value: " << number << "\n";
	cout << "Address: " << &number << "\n";
	pauseFunc();

	//6. dynamic memory allocation

	cout << "6. dynamic memory allocation" << "\n";

	int *iptr; //declare pointer to an int

	int *arrayIntPtr[3]; //declare array of pointers to int
	int i = 0;
	iptr = new int; //define pointer with 'new' keyword---key to allocating new memory, dynamically
	//*iptr = 0;
	while (i < 3){
		*iptr += 1;


		arrayIntPtr[i] = iptr;
		cout << "Address: " << arrayIntPtr[i] << "\n";
		cout << "Value: " << *arrayIntPtr[i] << "\n";

		i++;
		iptr++;

	}


	pauseFunc();

	//5. Functions that return pointers

	cout << "5. Functions that return pointers" << "\n";

	char *name; //Declare pointer with * operator
	name = getName(); //Pointer is initialized as return value from *getName, which returns a pointer
	cout << "Value: " << name << "\n"; //Prints value pointed to (i.e., whole c-string)
	cout << "Address/Value? : " << *name << "\n"; //Prints value pointed to (i.e., first char of input)
	cout << "Address: " << &name << "\n"; //Prints address pointed to (i.e.,
	pauseFunc();

	//11. Pointers to functions

	cout << "11. Pointers to functions" << "\n";

	void(*pointerFunc)(int); //Declare pointer with * operator and function with (), parameters and return type
	//--like a normal function, but doesn't need to be declared with a prototype
	pointerFunc = &my_int_func; //this ampersand is optional
	pointerFunc(1000); //Deploy function that is pointed to by function pointer

	pauseFunc();

	return(0);	// End the program

	// Not much to it; It's all in the functions (in the header file)
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		START FUNCTION DEFINITIONS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

char *getName()
{
	char *name;
	name = new char[81];
	cout << "Enter your name : ";
	cin.getline(name, 81);
	return name;
}

void pauseFunc()
{
	cout << "\n\t\t\t>>> HIT ENTER TO CONTINUE <<<\n";
	cin.ignore();
	return;
}//M

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		END FUNCTION DEFINITIONS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

