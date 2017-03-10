/*************************************************
* Program:  towers.C                             *
* Author:   Autumn Anthony                       *
* Date:     01/29/2017                           *
*                                                *
* Abstract:  Creates the pegs and disks for the  *
			 Towers of Hanoi problem using user  * 
			 input to choose the number of disks.*
			 Checks to make sure the user entered*
			 an acceptable integer.              *
*                                                *
**********************************************/
#include <iostream>
using namespace std;

void towers(int num, int initialPeg, int finalPeg, int tempPeg) // Creates the function and sets parameters
{
	if (num >= 1)		// Without this I received a segmentation fault
	{	
		towers(num - 1, initialPeg, tempPeg, finalPeg); 		// First recursive step to move disk
		cout << initialPeg << " -> " << finalPeg << endl;		// Prints out the movement of the disk from the old peg to the new peg
		towers(num - 1, tempPeg, finalPeg, initialPeg);		// Sets new recursion to change what peg is used next 
	}
}

int main()
{
    int num;		

    cout << "Enter a number greater than or equal to 1: ";		// Prompts the user for the number of disks
    cin >> num;		// User inputed number of disks 
	
	while (num < 1 || cin.fail() || cin.peek() != '\n')		// Checks to make sure the user input is valid
		{
		cout << "That was not an integer greater than or equal to 1. Try again: ";		// Prompts the user for another integer if they input in invalid one 
		cin.clear();
		cin.ignore(80, '\n');
		cin >> num;		// Resets the value of num to the new input 
	}
	
	towers(num, 1, 3, 2);		// Once the user has input a valid integer it will go to the function and run for the entered number of disks
	
    return 0;
}

