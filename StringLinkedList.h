/***************************************************
*     StringLinkedList.h                           *
*     Author:  Eileen Peluso                       *
***************************************************/
#ifndef _STRINGLINKEDLIST_H
#define _STRINGLINKEDLIST_H

#include <iostream>

using namespace std;

struct StringNode{
	string data;
	StringNode * next;
};

class StringLinkedList{
	friend ostream & operator << (ostream & os, StringLinkedList);
	public:
		StringLinkedList();
		void Output(ostream & os);
		bool IsThere(string whichOne);
		int Size();
		bool InsertNode(string newValue);
		bool RemoveNode(string whichOne);
   private:
		StringNode * first;
		StringNode * last;
};

StringLinkedList::StringLinkedList(){
// pre:		none
// post:		the private data variables are set to default values.  in this case
//				the default is an "empty list"
// purpose:	constructor
   first = 0;
   last = 0;
}

void StringLinkedList::Output(ostream & os){
// pre:		none
// post:	all of the strings in the link list have been displayed on the screen
// purpose:	to display the contents the linked list, one string per line tabbed in

	StringNode * current = first;	// a "work" pointer to keep track of where we are
									//    in the linked list
	while (current){				// we are not at the end of the linked list
		os << "\n\t\t" << current->data;	// spit out the string at this node
		current = current->next;		// "go to" the next node in the list
	}
}

bool StringLinkedList::IsThere(string whichOne){
// pre:		none
// post:	returns true if the string is in the list, false otherwise
// purpose:	to determine if a particular string is in the linked list
 	StringNode * current = first;	// a "work" pointer to keep track of where we are
									//    in the linked list
	while (current){				// we are not at the end of the linked list
		if(current->data == whichOne)
			return 1;
		current = current->next;	// "go to" the next node in the list
	}
	return 0;						// it's not there	

}

int StringLinkedList::Size(){
// pre:		none
// post:	returns the number of items in the list
// purpose:	to determine the size of the list
	int counter = 0;
 	StringNode * current = first;	// a "work" pointer to keep track of where we are
									//    in the linked list
	while (current){				// we are not at the end of the linked list
		counter++;
		current = current->next;	// "go to" the next node in the list
	}
	return counter;					// return the number of items in the list	

}

bool StringLinkedList::InsertNode(string newValue){
// pre:		none
// post:	the string has been added to the end of the linked list, if there was sufficient memory available
// purpose:	to add a string to the bottom of the linked list
	StringNode * newOne = new StringNode;
	if (!newOne)
		return false;
	newOne->data = newValue;
	newOne->next = 0;
	
	if (first == 0)				// was the list empty?
		first = last = newOne;
	else
	{
		last->next = newOne;	// previous last points to the new node
		last = newOne;			// this new node is now last
	}
	return true;
}

bool StringLinkedList::RemoveNode(string whichOne){
// pre:		none
// post:	removes the string from the linked list, if it is there
// purpose:	to remove a string from the list
	if (!IsThere(whichOne)){			
		return false;
	}
	StringNode * previous = 0;
	StringNode * current = first;		// a "work" pointer to keep track of where we are
  	
	while (current){					// we are not at the end of the linked list
		if(current->data == whichOne)
			break;
		previous = current;
		current = current->next;		// "go to" the next node in the list
	}

	if (previous == 0){					// deleting the first node
		if (first == last)				// which is also the last node
			last = 0;
		first = current->next;
    	delete current;
	}
	else if (current == last) {			//deleting the last node
		last = previous;
		previous->next = 0;
  		delete current;
	}
	else {							// goes in the middle somewhere
		previous->next = current->next;
  		delete current;
	}

	return true;
}

ostream & operator << (ostream & os, StringLinkedList theList){
	theList.Output(os);
	return os;
}

#endif
