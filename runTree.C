/**********************************************
* Program:  runTree.C                         *
* Author:   Eileen Peluso                     *
*                                             *
* Abstract: Driver for (int) tree class       *
**********************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <unistd.h>	// needed for sleep function
#include "tree.h"

using namespace std;

int userMenu();			// prototype
int getValue();			// prototype

int main() {
 	BinaryTree myTree;	// the tree!
	int option;			// option entered by user
	int value;			// value entered by the user
    ifstream inFile("tree.dat");   // file of integers to insert
    if (!inFile){                  // did file open properly?
        cout << "Couldn't find input file \"tree.dat\"" << endl;
        exit(1);
    }
	option = userMenu();	// display menu and get user request
	while (option){			// if they didn't pick 0

		switch (option){
			case 1: myTree.MakeTree(inFile);		// BUILD
				break;
			case 2: value = getValue();				// LOOK UP VALUE
				if (myTree.InTree(value))	
					cout << value << " is in the tree." << endl;
				else
					cout << value << " is not in the tree." << endl;
				cout << "Processing will resume shortly ..." << endl;
				sleep(7);			
				break;
			case 3: myTree.Preorder();				// PREORDER	
				cout << "Processing will resume shortly ..." << endl;
				sleep(7);
				break;
            case 4: myTree.Postorder();				// POSTORDER
                cout << "Processing will resume shortly ..." << endl;
                sleep(7);
                break;
            case 5: myTree.Inorder();				// INORDER
                cout << "Processing will resume shortly ..." << endl;
                sleep(7);
                break;
			case 6: myTree.Largest();				
                cout << "Processing will resume shortly ..." << endl;
                sleep(7);
                break;
			case 7: 
				cout << "The sum of the values is " << myTree.SumTree() << endl;
                cout << "Processing will resume shortly ..." << endl;
                sleep(7);
                break;
			case 8: value = getValue();		// Gets the input 
				cout << "There are " << myTree.Below(value) << " values less than the entered number in the tree." << endl;
                cout << "Processing will resume shortly ..." << endl;
                sleep(7);
                break;
			case 9: value = getValue();		// Gets the input
				if (!myTree.InTree(value))	
					cout << value << " is not in the tree." << endl;
				else
				{
					if (myTree.DeleteLeaf(value))
						cout << value << " was deleted." << endl;
					else 
						cout << value << " was not a leaf and could not be deleted." << endl;
				}
                cout << "Processing will resume shortly ..." << endl;
                sleep(7);
                break;
		}

		option = userMenu();			// get next request
	}
	return 0;
}

int userMenu(){
// pre:	none
// post:menu of options displayed on the screen, user selection returned
	int option;
	system("clear");		// clear screen
							// and set up menu
	cout << endl << endl << endl << endl;
	cout << setw(50) << "Try Out My Tree Processor" << endl;
	cout << endl << endl;
	cout << setw(50) << "Options                    " << endl;
	cout << setw(50) << "   0      End              " << endl;
	cout << setw(50) << "   1      Build            " << endl;
	cout << setw(50) << "   2      Look up value    " << endl;
	cout << setw(50) << "   3      Preorder listing " << endl;
	cout << setw(50) << "   4      Postorder listing" << endl;
	cout << setw(50) << "   5      Inorder listing  " << endl;
	cout << setw(50) << "   6      Largest value    " << endl;
	cout << setw(50) << "   7      Sum of values    " << endl;
	cout << setw(50) << "   8      Vaules below     " << endl;
	cout << setw(50) << "   9      Delete leaf      " << endl;
	cout << endl << endl;
	cout << "Select your option: ";
	cin >> option;				// get option from user
								// did they enter a good value
	while (cin.fail() || option > 9  ||  option < 0){
		cin.clear();			// reset flags
		cin.ignore(80, '\n');	// skip bad data
		cout << "Invalid option.  Please select again: ";
		cin >> option;			// get new value
	}
	return option;				// send option back
}
 
int getValue(){
// pre:  none
// post: return value to be checked
	int value;					// holds value entered by user
	cout << "Enter value to be checked: ";	// prompt user
	cin >> value;				// get value from user
	while (cin.fail()){			// did they enter bad data
		cin.clear();			// clear flags
		cin.ignore(80, '\n');	// ingore bad data
		cout << "Invalid input.  Try again: " << endl;
		cin >> value;			// get another value
	}
	return value;				// send value back
}


