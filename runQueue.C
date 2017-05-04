/**********************************************
* Program:  runQueue.C                        *
* Author:   Eileen Peluso                     *
*                                             *
* Abstract: Driver for (int) queue class      *
**********************************************/
#include <iostream> 
#include <iomanip>
#include <cstdlib>
#include <unistd.h>	// needed for sleep function
#include "queue.h"

using namespace std;

int userMenu();			// prototype
int getEnqueueValue();		// prototype
void displayDequeued(int x);	// prototype
int getValue();			// prototype
int getPlace();			// prototype

int main() {
 	Queue myQueue;		// the queue!
	int option;		// option entered by user
	int dequeuedValue;	// value dequeued from queue
	int enqueueValue;	// value to be enqueued into the queue
	int insertValue;	// value to insert
	int place;		// line jumper place
	option = userMenu();	// display menu and get user request
	while (option){		// if they didn't pick 0

		switch (option){
			case 1: enqueueValue = getEnqueueValue();  	// ENQUEUE
				myQueue.Enqueue(enqueueValue);
				break;
			case 2: if(myQueue.Dequeue(dequeuedValue)){	// DEQUEUE
				    displayDequeued(dequeuedValue);
				}
				else{
				    cout << "Queue is empty" << endl;
				    cout << "Processing will resume shortly ...." << endl;
				    sleep(4);
				}
				break;
			case 3: myQueue.Display();			// DISPLAY QUEUE
				cout << "Processing will resume shortly ..." << endl;
				sleep(4);
				break;
			case 4:
				myQueue.LineJumper(getValue(), getPlace());
				cout << "Processing will resume shortly ..." << endl;
				sleep(4);
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
	cout << setw(50) << "Try Out My Queue Processor" << endl;
	cout << endl << endl;
	cout << setw(50) << "Options                 " << endl;
	cout << setw(50) << "   0      End           " << endl;
	cout << setw(50) << "   1      Enqueue       " << endl;
	cout << setw(50) << "   2      Dequeue       " << endl;
	cout << setw(50) << "   3      Display Queue " << endl;
	cout << setw(50) << "   4      Line Jumper   " << endl;
	cout << endl << endl;
	cout << "Select your option: ";
	cin >> option;			// get option from user
					// did they enter a good value
	while (cin.fail() || option > 4  ||  option < 0){
		cin.clear();
		cin.ignore(80, '\n');	// skip bad data
		cout << "Invalid option.  Please select again:";
		cin >> option;		// get new value
	}
	return option;			// send option back
}

int getEnqueueValue(){
// pre:  none
// post: return value to be added to the queue
	int value;			// holds value entered by user
	cout << "Enter value to be enqueued: ";	// prompt user
	cin >> value;			// get value from user
	while (cin.fail()){		// did they enter bad data
		cin.ignore(80, '\n');	// ingore bad data
		cin.clear();		// clear flags
		cout << "Invalid input.  Try again: " << endl;
		cin >> value;		// get another value
	}
	return value;			// send value back
}


void displayDequeued(int x){
// pre:  x is some integer value
// post: x is displayed on the screen, then the program is suspended breifly
//             giving the user time to see what has been displayed
	cout << "The dequeued value was " << x << endl;
	cout << "Processing will resume shortly ...." << endl;
	sleep(4);			// give user time to read it!
}

int getValue(){
// pre:   none
// post:  returns the an integer value entered by the user
	int value;
	cout << "Enter value to be inserted:";
	cin >> value;
	return value;
}

int getPlace(){
// pre:   none
// post:  returns an integer value entered by the user
	int place;
	cout << "Enter position to insert the value:";
	cin >> place;
	return place;
}
