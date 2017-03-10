/******************************************************
* Program:  problem4.26.C                             *
* Author:   Autumn Anthony                            *
* Date:     01/27/2017                                *
*                                                     *
* Abstract:  Reads in the size of the side of a       *
             square, then prints a hollow square of   *
			 that size out of asterisks and blanks.   *
			 Should work for squares of all sides     *
			 bewteen 1 and 20. Verify with while loop.*
******************************************************/
#include <iostream>

using namespace std;

int main() 
{
	int side;		// Creates variable to contain the length of the side
	int numSpaces;		/* Creates variable to contain the number of spaces 
						   to be printed to make the square hollow */
	
	cout << "Enter the size of the side of a square between 1 and 20: ";  // Asks user for input
	cin >> side;		// Store input in the variable 
	
	while (side > 20 || side < 1)		// Checks to see if input is within bounds
	{
		cout << "" << endl;			// Line for readability
		cout << "You gave an invalid answer. Please try again." << endl;
		cout << "Enter the size of the side of a square between 1 and 20: ";		// Prompts user for new input 
		cin >> side;		// Reassigns to variable with new input
	}
	
	numSpaces = (2 * side) - 3;		// Sets the number of white spaces needed to craete square
	
	for (int i = 1; i <= side; i ++)		// Creates the top line of the square
	{
		cout << "* ";		// Made a space after each * to create the square shape
	}
	
	cout << endl;		// Starts a new line for the side of the square to start
	
	for (int i = 1; i < side - 1; i ++)		// Creates the sides of the square and prints out white spaces
	{
		cout << "*";		// Creates the left side
		
		for (int i =1; i <= numSpaces; i ++)
		{
			cout << " ";		// Creates the white space
		}
		cout << "*" << endl;		// Creates the right side
	}
	
	if (side > 1)		// Creates bottom of square only if side is greater than 1 
	{
		for (int i = 1; i <=side; i ++)
		{
			cout << "* ";		// Creates the bottom line of the square
		}
		
		cout << endl;		// Space at the end for readability 
	}
	
	
	
	return 0;
}

