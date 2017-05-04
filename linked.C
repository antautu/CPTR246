/**********************************************
* Program:  linked.C                          *
* Author:   Autumn Anthony                    *
*                                             *
* Abstract: Practice with linked lists,       *
*              structs, and recursion         *
**********************************************/
#include <iostream>
#include <fstream>
 
using namespace std;

struct intNode{
	int value;
	intNode * next;
};

intNode * loadList(ifstream & inFile){
// pre:    inFile has been opened successfully and contains a bunch
//                    of integers
// post:   a linked list of intNode's is created with the integer values
//                    from the file in the order they appear on file
	intNode * first;		// always points to the first node on the list
	intNode * last;			// always points to the last node on the list
	intNode * newOne;		// pointer to the node being added
	int newValue;			// holds integer to be added
	inFile >> newValue;		// get first integer
	if (inFile.eof())		// if the file has no integer
		return 0;			//	return a null pointer
	newOne = new intNode;	// allocate space for the first node
	first = newOne;			// it will be the first one on the list
	first->value = newValue;// load it's values
	first->next = 0;
	last = first;			// as of now, it also the last item
	inFile >> newValue;		// get the second integer for the list
							//  (the primal extraction)
	while (!inFile.eof()){			// are there more items?
		newOne = new intNode;		// get memory for the node
		newOne->value = newValue;	// load it with values
		newOne->next = 0; 			// null pointer - it will be last
									//   at least for now
		last->next = newOne;		// connect it to the bottom of
									//   the list
		last = newOne;				// the new one is not last
		inFile >> newValue;			// bottom extraction
	}
	return first;
}


void printList(intNode * list){
// pre:    list points to a link list of integers
// post:   the list is printed out

	intNode * current = list;
	
	while (current != 0)		// While current is pointing to something - Could also use while(current)
	{
		cout << current -> value << " ";
		current = current -> next;
	}
	cout << endl;
}

void printListRecursively(intNode * list){
// pre:    list points to a link list of integers
// post:   the list is printed out
	
	if (list == 0)		// Base Case 
	{
		cout << endl;
	}
	
	else		// General Case 
	{
		cout << list -> value << " ";
		printListRecursively(list -> next);
	}
}

int sumList(intNode * list){	// return the total of the items in the list
// pre:    list points to a link list of integers
// post:   the sum of the integers in the list is returned
	
	intNode * current = list;
	int total = 0;
	
	while (current != 0)		// While current is pointing to something - Could also use while(current)
	{
		total = total + current -> value;
		current = current -> next;
	}
	return total;
}

int sumListRecursively(intNode * list){	// WRITE THIS RECURSIVELY
// pre:    list points to a link list of integers
// post:   the sum of the integers in the list is returned
	
	if (list == 0)		// Base Case 
	{
		return 0;
	}
	
	else		// General Case 
	{
		return list -> value + sumListRecursively(list -> next);
	}
}

int smallest(intNode * list){	// return the smallest item in the list
// pre:    list points to a link list of integers
// post:   the smallest value in the list is returned
	
	intNode * current = list;
	if (current == 0)		// If the list is empty
	{
		cout << "This is an empty list. Smallest is set to 0." << endl;
		return 0;
	}
	int smallestSoFar = current -> value;
	
	while (current != 0)		// While current is pointing to something - Could also use while(current)
	{
		if (current -> value < smallestSoFar)
		{
			smallestSoFar = current -> value;
		}
		current = current -> next;
	}
	return smallestSoFar;
}

int smallestRecursively(intNode * list){	// WRITE THIS RECURSIVELY
// pre:    list points to a link list of integers
// post:   the smallest value in the list is returned
	
	if (list == 0)
	{
		cout << "The list is empty. Smallest is set to 0." << endl;
		return 0;
	}
	
	if (list -> next == 0)		// Base Case 
	{
		return list -> value;
	}
	
	else		// General Case 
	{
		int smallestInRestOfList = smallestRecursively(list -> next);
		if (list -> value < smallestInRestOfList)
			return list -> value;
		else
			return smallestInRestOfList;
	}
}

int size(intNode * list){	// return the number of items in the list
// pre:    list points to a link list of integers
// post:   the number of integers in the list is returned
	
	intNode * current = list;
	int numInts = 0;
	
	while (current != 0)		// While current is pointing to something - Could also use while(current)
	{
		current = current -> next;
		numInts ++;
	}
	return numInts;
}

int sizeRecursively(intNode * list){	// WRITE THIS RECURSIVELY
// pre:    list points to a link list of integers
// post:   the number of integers in the list is returned
	
	if (list == 0)		// Base Case 
	{
		return 0;
	}
	
	else		// General Case 
	{
		return (1 + sizeRecursively(list -> next));
	}
}

void printReversedRecursively(intNode * list){	// WRITE THIS RECURSIVELY
// pre:    list points to a link list of integers
// post:   the integers in the list are displayed in reverse order
	
	if (list == 0)		// Base Case
	{
		cout << endl;
	}
	
	else		// General Case 
	{
		printReversedRecursively(list -> next);
		cout << list -> value << " ";
	}
}

int main(int argc, char * argv[]) {	// file name must be on the commandline
	if (argc == 1){
		cerr << "Improper usage.  Enter file name on the command line." << endl;
		return 1;
	}
 	intNode * list;				// linked list of integers
	ifstream inFile(argv[1]);	// input file
	if (!inFile){				// did it open?
		cout << "Could not open " << argv[1] << endl;
		return 1;
	}
	list = loadList(inFile);	// build the linked list
	
	// Call the functions we're writing to test them

	cout << "The contents of the list: ";
	printList(list);
	cout << endl;
	
	cout << "The same output, only done with a recursive function: ";
	printListRecursively(list);
	cout << endl;
	
	cout << "The sum of the items in the list is "
		<< sumList(list) << endl;
	
	cout << "The sum of the items in the list (recursively) is "
		<< sumListRecursively(list) << endl;

	cout << "The smallest item in the list is "
		<< smallest(list) << endl;

	cout << "The smallest item in the list (recursively) is "
		<< smallestRecursively(list) << endl;

	cout << "The number of items in the list is "
		<< size(list) << endl;

	cout << "The number of items in the list (recursively) is "
		<< sizeRecursively(list) << endl;

	cout << "The list backwards is: ";
	printReversedRecursively(list);
	cout << endl;
	
	return 0;
}

