/**********************************************
* Program:  lab4a.C                           *
* Author:   Autumn Anthony                    *
* Date:     02/08/2017                        *
*                                             *
* Abstract: The user inputs a file and the    *
			program finds the number of ints  *
			and chars as well as finding the  *
			averge of the ints.               *
*                                             *
**********************************************/
#include <iostream>
#include <fstream>		// Need to include to input a file 
using namespace std;

int main() 
{
	string fileName; 		// The name of the file to be read 
	ifstream inFile;		// Name to represent the input file 
	int next;		// The value in the file to be read 
	int numChars = 0;		// Count of the number of characters in the file 
	int numInts = 0;		// Count of the number of integers in the file 
	char bufferValue;		// The non integer value in the buffer to be ignored 
	double sum = 0;		// Sum of all the integers
	double average = 0;		// Average of all the integers 
	
	cout << "Enter the name of the input file: "; 		// Asks the user to input the file name 
	cin >> fileName;
	
	inFile.open(fileName.c_str());		// Opens the file
	if (!inFile)		// If the file cannot be found give an error and end program 
	{
		cout << "The file was not found" << endl;
		return 1;
	}
	
	inFile >> next;		// If the file is found, read the first value
	while (!inFile.eof())		// While we have not reached the end of the file 
	{
		if (inFile.fail())		// If the program fails to get an integer 
		{
			numChars ++;		// Increment the number of characters we have 
			inFile.get(bufferValue);		// Get the character out of the buffer
			inFile.clear();		// Clears the buffer 
			inFile.ignore();		// Ignores the character 
		}
		else		// If the program finds an integer 
		{
			numInts ++;		// Increment the number of integers we have 
			sum = sum + next;		// Adds the integer to the sum 
			cout << next << endl;		// Prints out the integers
		}
		inFile >> next;		// Goes to the next value in the file 
	}
	cout << "The number of integers is: " << numInts << endl;		// Prints out the number of integers
	cout << "The number of characters is: " << numChars << endl;		// Prints out the number of characters
	average = sum / numInts;		// Averages the integers 
	cout << "The average of the numbers is: " << average << endl;		//Prints the average 
	return 0;
}

