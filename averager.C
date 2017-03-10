/**********************************************
* Program:  averager.C                        *
* Author:   Autumn Anthony                    *   
* Date:     02/22/2017                        *
*                                             *
* Abstract: Program to calculate              *
*           averages for student              *
**********************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[]) 
{
	int nbrOfTests(0);         // number of grades per student
	string name;               // name of current student
	int grade;                 // individual grade entered
	double sum;                // sum of grades for this student
	ifstream inFile;		   // input file
	string fileName;		   // name of file

	if (argc == 1)		// If the user does not enter the name of the file on the command line 
	{
		cout << "Enter the name of the file you want to open: ";		// Ask the user what file to open 
		cin >> fileName;
		inFile.open(fileName.c_str());		// Open the file 
	}
	
	else		// If the user enters the name of the file on the command line 
	{
		fileName = argv[1];		// The name of the file becomes the argument they entered on the command line 
		inFile.open(fileName.c_str());		// Open the file 
	}
	
	if (!inFile)		// If the file does not exist 
	{
		cerr << "File could not be opened" << endl;		// Error message
		return 1;
	}
	
	inFile >> nbrOfTests;
	inFile >> name;
	while (!inFile.eof())
	{
		sum = 0;
		
		for (int i = 1; i <= nbrOfTests; i++)
		{
			inFile >> grade;
			sum = sum + grade;
		}
		
		cout << name << "'s average is " << sum / nbrOfTests << endl << endl;
		inFile >> name;
	}
	
	cout << endl;
	return 0;
}

