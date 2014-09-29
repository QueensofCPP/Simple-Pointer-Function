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
***															***
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

	return(0);	// End the program

	// Not much to it; It's all in the functions (in the header file)
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		START FUNCTION DEFINITIONS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	// No local functions
	// All functions included in header file ChrisOOPSfunc.h

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//		END FUNCTION DEFINITIONS
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

