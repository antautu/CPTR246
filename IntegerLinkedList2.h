/***************************************************
*     IntegerLinkedList2.h                         *
*     Author:  Eileen Peluso                       *
***************************************************/
#ifndef _INTEGERLINKEDLIST_H
#define _INTEGERLINKEDLIST_H

#include <iostream>
#include "IntegerNode.h"
#include <fstream>

using namespace std;

class IntegerLinkedList{
	public:
		IntegerLinkedList();
		bool Load(char * filename);
		void Display();
		bool IsThere(int whichOne);
		bool InsertNode(int newValue);
		bool RemoveNode(int whichOne);
		bool LoadUnsorted(char * filename);
		void Sum();
		int Length();
		void Average();
		void HowManyEven();
		void Empty();
		~IntegerLinkedList();
	private:
		IntegerNode * first;
		IntegerNode * last;
};

IntegerLinkedList::IntegerLinkedList(){
// pre:		none
// post:	the private data variables are set to default values.  in this case
//			the default is an "empty list"
// purpose:	constructor
	first = 0;
	last = 0;
}

bool IntegerLinkedList::Load(char * filename){
// pre:		none
// post:	the linked list is loaded with integers from the file whose name is passes
//				as a parameter.  a 1 is returned if the process is successful.  if either the
//				file is not found or there are non-integers on the file, a 0 is returned
// purpose:	to build a linked list of integers
	ifstream fileOfIntegers(filename);	// defines and opens the file
	if (!fileOfIntegers){				// the file is not there
		return 0;						//    so return false, indicating that Load failed
	}

	int value;							// holds the integer read from the file
	IntegerNode * newNode;				// holds the address of the node we're building

 	fileOfIntegers >> value;			// primal extraction
  	while (!fileOfIntegers.eof()){		// stay in the loop until all integers are read from the file

		if (fileOfIntegers.fail()){		// there was something besides integers on the file
			cerr << "Got hold of some bad stuff!" << endl;
			return 0;					// return false, indicating that Load failed
		}
		newNode = new IntegerNode;		// get memory to hold a new node
		newNode->setValue(value);		// that node is to hold the value just read from the file
		newNode->setNext(0);			// it will be added to the bottom of the linked list,
										//    so it's "next" pointer will be 0
		if (first == 0)					// if this is the first value read from the file
			first = newNode;			//    we now know where "first" should point to
		else							// otherwise, we have to link this new node up
			last->setNext(newNode);		//    to the rest of the list (at the end)
		last = newNode;					// in either case, this node is now the last on the list
		fileOfIntegers >> value;		// bottom extraction
   	}
	return 1;							// all of the integers on the file have successfully been loaded
}

void IntegerLinkedList::Display(){
// pre:		none
// post:	all of the integers in the link list have been displayed on the screen
// purpose:	to display the contents the linked list

	IntegerNode * current;			// a "work" pointer to keep track of where we are
									//    in the linked list
	cout << endl << "The values in the Integer Linked List are:" << endl;	// a nice, little heading

	current = first;				// a "primal extract" if you will, starts us off
									//    at the beginning of the linked list
	while (current != 0){			// either the list is empty (if true first time through)
									//    or we are at the end of the linked list
		cout << current->getValue() << endl;	// spit out the value at this node
		current = current->getNext();			// "go to" the next node in the list
	}
	cout << endl;					// give a blank line at the end for readability
}	

bool IntegerLinkedList::IsThere(int whichOne){
// pre:		none
// post:	returns true if whichOne is in the linked list, false otherwise
// purpose:	to determine if whichOne is in the linked list
	IntegerNode * current;			// a "work" pointer to keep track of where we are
									//    in the linked list
	current = first;				// a "primal extract" if you will, starts us off
									//    at the beginning of the linked list
	while (current != 0){			// either the list is empty (if true first time through)
									//    or we are at the end of the linked list
		if (whichOne == current->getValue())
			return true;
		
		current = current->getNext();			// "go to" the next node in the list
	}
	return false;
}

bool IntegerLinkedList::InsertNode(int newValue){
// pre:		the linked list is sorted
// post:	returns true if newValue could be inserted, false otherwise
// purpose:	to insert newValue in the linked list 

	// SET UP THE MEMORY FOR THE NEW NODE
	IntegerNode * newNode;			// holds the address of the node we're building

	newNode = new IntegerNode;		// get memory to hold a new node
	if (!newNode)					// the OS said it was out of memory
		return false;
	newNode->setValue(newValue);	// that node is to hold the value that came in as a parameter
	newNode->setNext(0);			// it might be added to the bottom of the linked list

	// SEARCH TO SEE WHERE IT GOES
	IntegerNode * current;			// a "work" pointer to keep track of where we are
	IntegerNode * previous;			// another "work" pointer to keep track of the node before current
	
	previous = 0;					// to begin with, previous points to nothing
	current = first;				// starts us off at the beginning of the linked list
	
	while (current != 0){			// either the list is empty (if true first time through)
									//    or we are at the end of the linked list
		if (newNode->getValue() < current->getValue())
			break;
		previous = current;
		current = current->getNext();			// "go to" the next node in the list
	}

	// THIS VALUE GOES BETWEEN THE NODE POINTED TO BY previous AND THE NODE POINTED TO BY current
	
	// Is it a new first node?
	//		Special case:  Is it going to be the only node?  That is, was the list empty?
	if (!first){		// this is an empty list
		first = newNode;
		last = newNode;
		return true;
	}
	
	if (current == first)		// or if (previous == 0) or if (!previous)
	{
		first = newNode;
		newNode->setNext(current);
		return true;
	}
	
	// Is it a new last node?
	if (current == 0){ // previous == last){		// or current == 0
		last = newNode;
		previous->setNext(newNode);
		return true;		
	}
	
	// It must be going in the middle somewhere.
	previous->setNext(newNode);
	newNode->setNext(current);
	return true;
	
}

bool IntegerLinkedList::RemoveNode(int whichOne){
// pre:		the linked list is sorted
// post:	returns true if whichOne was successfully removed, false otherwise
// purpose:	to remove the first occurrence of whichOne the linked list 
	
	if (!IsThere(whichOne))
		return false;
	
	// SEARCH TO F
	IntegerNode * current;			// a "work" pointer to keep track of where we are
	IntegerNode * previous;			// another "work" pointer to keep track of the node before current
	
	previous = 0;					// to begin with, previous points to nothing
	current = first;				// starts us off at the beginning of the linked list
	
	while (whichOne != current->getValue()){			// either the list is empty (if true first time through)
									//    or we are at the end of the linked list
		previous = current;
		current = current->getNext();			// "go to" the next node in the list
	}

	// ARE WE REMOVING THE FIRST NODE?
	if (previous == 0){  // or if (current == first)  or if (!previous)
		
		// BUT WHAT IF IT WAS THE LAST ITEM TOO <----- I DID THIS FOR YOU :)
		if (first == last){ // You're removing the one and only node in the list
			last = 0;
		}
		first = current->getNext();
		delete current;
		return true;
	}
	
	// ARE WE REMOVING THE LAST NODE?
	if (current->getNext() == 0){  	// or if (current == last)
		last = previous;
		previous->setNext(0);
		delete current;
		return true;
	}
	
	// WE'RE REMOVING A NODE FROM THE MIDDLE.  <--------- YOU NEED TO DO THE GENERAL CASE :)
	previous -> setNext(current -> getNext());
	current -> setNext(0);
	delete current;
	return true;
}

bool IntegerLinkedList::LoadUnsorted(char * filename){
// pre:		none
// post:	the linked list is loaded with integers from the file whose name is passed
//				as a parameter.  a 1 is returned if the process is successful.  if either the
//				file is not found or there are non-integers on the file, a 0 is returned. InsertNode
//				is called to add the nodes to the list in numerical order
// purpose:	to build a linked list of integers
	ifstream fileOfIntegers(filename);	// defines and opens the file
	if (!fileOfIntegers){				// the file is not there
		return 0;						//    so return false, indicating that Load failed
	}

	int value;							// holds the integer read from the file
	IntegerNode * newNode;				// holds the address of the node we're building

 	fileOfIntegers >> value;			// primal extraction
  	while (!fileOfIntegers.eof()){		// stay in the loop until all integers are read from the file

		if (fileOfIntegers.fail()){		// there was something besides integers on the file
			cerr << "Got hold of some bad stuff!" << endl;
			return 0;					// return false, indicating that Load failed
		}
		InsertNode(value);		// Calls the method InsertNode with the value taken from the file to put the numbers in order 
		fileOfIntegers >> value;		// Goes to the next value in the file 
   	}
	return 1;							// all of the integers on the file have successfully been loaded
}

void IntegerLinkedList::Sum(){
// pre:		None	
// post: 	Displays the sum of the numbers in the list on the screen	
// purpose:	To find the sum of the numbers in the list and display it to the user 

	IntegerNode * current;			// a "work" pointer to keep track of where we are
	IntegerNode * previous;			// another "work" pointer to keep track of the node before current
	
	int sum = 0;
	previous = 0;					// to begin with, previous points to nothing
	current = first;				// starts us off at the beginning of the linked list
	
	while (current != 0){			// either the list is empty (if true first time through)
									//    or we are at the end of the linked list
		sum = sum + current -> getValue();		// Add the current value to the sum 
		current = current->getNext();			// "go to" the next node in the list
	}
	
	cout << "The sum of the integers in the list is " << sum << endl;		// Displays the sum
}

int IntegerLinkedList::Length(){
// pre:		None	
// post:	Returns the length of the list	
// purpose: To find the length of the list and returns it to be used in the driver 

	IntegerNode * current;			// a "work" pointer to keep track of where we are
	IntegerNode * previous;			// another "work" pointer to keep track of the node before current
	
	int count = 0;
	previous = 0;					// to begin with, previous points to nothing
	current = first;				// starts us off at the beginning of the linked list
	
	while (current != 0){			// either the list is empty (if true first time through)
									//    or we are at the end of the linked list
		count ++;		// Increments the count for every number in the list 
		current = current->getNext();			// "go to" the next node in the list
	}
	return count;		// Returns the length of the list 
}

void IntegerLinkedList::Average(){
// pre:		None	
// post:	Displays the average of the numbers in the list on the screen 
// purpose: To find the average of the numbers in the list and display it to the user 

	IntegerNode * current;			// a "work" pointer to keep track of where we are
	IntegerNode * previous;			// another "work" pointer to keep track of the node before current
	
	double sum = 0;
	double count = 0;
	double average = 0;
	previous = 0;					// to begin with, previous points to nothing
	current = first;				// starts us off at the beginning of the linked list
	
	while (current != 0){			// either the list is empty (if true first time through)
									//    or we are at the end of the linked list
		sum = sum + current -> getValue();		// Finds the sum of all the numbers 
		count ++;		// Counts the numbers to find the length of the list 
		current = current->getNext();			// "go to" the next node in the list
	}
	
	if (sum == 0 && count == 0)		// If we have an empty list 
		average = 0;		// Set the average to 0 to avoid division by zero 
	else
		average = sum / count;		// Finds the average of the numbers 
	cout << "The average of the integers in the list is " << average << endl;		// Displays the average 
}

void IntegerLinkedList::HowManyEven(){
// pre:		None
// post:	Displays the number of even numbers on the screen 	
// purpose: To find the number of even numbers in the list and display it to the user 

	IntegerNode * current;			// a "work" pointer to keep track of where we are
	IntegerNode * previous;			// another "work" pointer to keep track of the node before current
	
	int count = 0;
	previous = 0;					// to begin with, previous points to nothing
	current = first;				// starts us off at the beginning of the linked list
	
	while (current != 0){			// either the list is empty (if true first time through)
									//    or we are at the end of the linked list
		if (current -> getValue() % 2 == 0)		// Checks to see if the current number is even 
			count ++;		// If the number is even add one to the count 
		current = current->getNext();			// "go to" the next node in the list
	}
	
	cout << "The number of even integers in the list is " << count << endl;		// Display the number of even numbers 
}

void IntegerLinkedList::Empty(){
// pre:		None	
// post:	Deletes all of the numbers from the list 	
// purpose: To delete all of the numbers from the list 

	IntegerNode * next;

	while (first)		// When there is still a number in the list to be deleted 
	{
		next = first -> getNext();			
		cout << "Deleting " << first -> getValue() << endl;		// Displays what number is being deleted from the top of the list 
		delete first;		// Deletes the top number in the list 
		first = next;		// We get a new first number 
	}
}

IntegerLinkedList::~IntegerLinkedList(){
// pre:		Empty() was defined 
// post:	Deletes all of the numbers from the list when the user quits 
// purpose: To clear us space in memory 

	Empty();		// Calls the method Empty() to delete all of the numbers in the list when the user quits the program 
}
#endif
