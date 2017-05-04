/**********************************************
 * Program:  IntegerDriver2.C                  *
 * Author:   Eileen Peluso                     *
 *                                             *
 * Abstract: Driver program to demonstrate     *
 *           linked lists *
 **********************************************/
#include <iostream>
#include <cstdlib> 
#include "IntegerLinkedList2.h"
 
using namespace std;

int DisplayMenu(){
// Intent:  To display the menu of options,
//            get the user's choice and return it to the calling function
// Pre: None
// Post: The integer entered by the user is returned
  
	int option;			// holds the user's choice
  
	system("clear");
	cout << endl << endl;
	cout << "\t\t\tWelcome to IntegerDriver2.C!" << endl;
	cout << endl;
	cout << "\t\t\tPlease consider the following options:" << endl;
	cout << endl;
	cout << "\t\t\t\t1  Display the linked list" << endl;
	cout << "\t\t\t\t2  Check if a number is there" << endl;
	cout << "\t\t\t\t3  Add a number" << endl;
	cout << "\t\t\t\t4  Remove a number" << endl;
	cout << "\t\t\t\t5  Sum of the numbers" << endl;
	cout << "\t\t\t\t6  Length of the linked list" << endl;
	cout << "\t\t\t\t7  Average of the numbers" << endl;
	cout << "\t\t\t\t8  Number of even integers" << endl;
	cout << "\t\t\t\t9  Empty the linked list" << endl;
	cout << "\t\t\t\t10  Sum of the numbers recursively" << endl;
	cout << "\t\t\t\t0  Enough already!" << endl;
	cout << endl;
	cout << "\t\t\tPlease make your selection: ";
	cin >> option;
	cout << endl << endl;
	return option;
}

int getANumber(){
// pre:		none
// post:	an integer value entered by the user is returned
// purpose:	To prompt the user for an integer, make sure that they enter
//             a valid integer, and return that value
	int value;
  
	cout << "Enter an integer: ";
	cin >> value;
	while (cin.fail() || cin.peek() != '\n'){
		cin.clear();
		cin.ignore(80, '\n');
		cout << "That was not an integer.  Please try again: " << endl;
		cin >> value;
	}
	return value;
}
 
int main(int argc, char * argv[]) {
  
	IntegerLinkedList myList;	// Define the list object
  
	if (argc < 2){		// If the user did not enter the file name on the command line
						//    give an error message and terminate the program
		cerr << "You must enter the name of the file on the command line" << endl;
		cerr << "Program is terminating" << endl;
		return 1;
	}
  
	if (!myList.LoadUnsorted(argv[1])){	// Load returns true if the file exists and contains all integers
		cerr << "File did not load properly" << endl;
		exit(1);		        // Abnormal program termination
	}
  
	char option;
	int workNumber;
  
	option = DisplayMenu();
	while (option != 0){
		switch (option)
		{
			case 1:	myList.Display();
				break;

			case 2:	workNumber = getANumber();
				if (myList.IsThere(workNumber))
					cout << "Yes, it was there." << endl;
				else
					cout << "No, it was not there." << endl;
				break;

			case 3:	workNumber = getANumber();
				if (myList.InsertNode(workNumber))
					cout << "That number was successfully added." << endl;
				else
					cout << "That number was not added.  Memory exhausted." << endl;
				break;

			case 4:	workNumber = getANumber();
				if (myList.RemoveNode(workNumber))
					cout << "That number was successfully removed." << endl;
				else
					cout << "That number was not in the list." << endl;
				break;
			
			case 5: myList.Sum();
				break;
				
			case 6: 
				cout << "The length of the linked list is " << myList.Length() << endl;
				break;
			
			case 7: myList.Average();
				break;
			
			case 8: myList.HowManyEven();
				break;
				
			case 9: myList.Empty();
				break;
				
			case 10: myList.SumRecursively();
				break;
				
			default:cerr << "That was not a valid option." << endl;
				break;
		}
		cout << endl << "Hit enter to continue ... ";
		cin.ignore(80, '\n');
		char x;
		cin.get(x);
		option = DisplayMenu();
	}
  
  
	return 0;	// Normal program termination
}

