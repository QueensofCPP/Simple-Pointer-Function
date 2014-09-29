#ifndef POINTERFUNCTIONS_H
#define POINTERFUNCTIONS_H


#include <iostream>		// Necessary for cout and cin
#include <windows.h>	// Necessary for HANDLE, SetConsoleTextAttribute, Sleep,
						// COORD, BACKGROUND_ and FOREGROUND_ consts
#include <string>		// Necessary for string variables
#include <mmsystem.h>	// Necessary for PlaySound
#include <vector>		// For vectors
#include <fstream>		// For reading an writing to disk files

#pragma comment(lib, "winmm.lib")  //Necessary for PlaySound

using namespace std;


/**************************************************
***           GLOBAL CONSTANTS					***
**************************************************/

const string PROGRAMMERNAME = "Queens of CPP";	// The name of the programmer; displayed in several functions


/**************************************************************
***           FUNCTION PROTOTYPE DECLARATIONS				***
**************************************************************/


void hitEnter();		//Pause the screen to wait for user to hit Enter To continue


void gotoXY(int x, int y);	// Position the cursor to the column (x) and row (y)
							// This function was borrowed from Professor Larry Forman's code in project HO_1_4


void P1TT_Plus_Menu();
void SimplePointer();

/***********************************************************************************************************************/

#endif	//POINTERFUNCTIONS_H