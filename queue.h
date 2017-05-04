/**************************************************************
*      queue.h      Class that implements a queue             *
**************************************************************/
#ifndef _QUEUE_H
#define _QUEUE_H

using namespace std;

class Node {
	friend class Queue;
	private:
		int data;			// information held in Node
		Node * next;		// points to next node in list
};	

class Queue {
   public:					// see function def's for pre and post
		Queue() { top = 0;}
		~Queue();
		bool IsEmpty() {return (top == 0);}  // return (!top);
		bool IsFull();
		bool Peek(int &);
		void Enqueue(int);
		bool Dequeue(int &);
		void Display();

   private:
		Node * top;			// points to the first Node in the queue
		Node * bottom;		// points to the last Node in the queue
};

Queue::~Queue(){
// pre:  none
// post: queue is destroyed, memory is released

	Node * next;				// temp value to hold pointer
	cout << "destructor is called" << endl;
	while (top){				// while still some to delete
		next = top->next;		// save pointer to next one
		cout << "Deleting " << top->data << endl;
		delete top;				// delete this one
		top = next;				// the "next one" is now on top
	}   
}

bool Queue::IsFull(){
// pre:   none
// post:  returns true if there is insufficient memory to allocate
//          another node
	Node * newSpace;			// hold address of new node
	newSpace = new Node;		// is there space for another one?
	if (newSpace){				// any non-NULL value indicates "new"
								//    was successful
		delete newSpace;		// we didn't want the space
		return 0;				//   we just wanted to see if there was
								//   enough
	}
	return 1;					// return true if there wasn't enough space
}


bool Queue::Peek(int & x){
// pre:  none
// post: sets parameter to top of queue and returns true (1).  If queue
//             is empty it returns false;
	if (!top)					// top == 0 indicates empty queue
		return 0;
	else {						// show data, don't delete the node
		x = top->data;
		return 1;
	}
}

void Queue::Enqueue(int x){
// pre:	  x is an integer and there is room in memory for it
// post:  x is added to bottom of queue.
	Node * newOne;				// hold address of new Node
	newOne = new Node;			// allocate memory for the new Node
	newOne->data = x;			// set up it's data
	newOne->next = 0;			// it should point to the old "top"
	
	if (top == 0)		// If the queue is empty
	{
		top = newOne;		// Top and bottom are the same 
		bottom = newOne;
	}
	else
	{	
	bottom -> next = newOne;
	bottom = newOne;		// this newOne is now on "bottom" of the queue
	}
}

bool Queue::Dequeue(int & x){
// pre:	  none
// post:  x is updated to the value removed from the queue and
//              true is returned
//        if the queue was empty, false is returned
	Node * removed;				// save address of one to be removed
	if (top){					// if the queue was not empty
		removed = top;			//    save pointer to top Node
		x = top->data;			//    get the data that was in it
		top = top->next;		//    top is now the address of what was the
								//         second Node on the list
		delete removed;			//    free up memory for removed Node
		return 1;				//    return true (successful)
	}
	else return 0;				// return false if the queue had nothing to dequeue
}

void Queue::Display(){
// pre:   none
// post:  contents of queue have been displayed on the screen
	Node * current;				// points to the current node being displayed in loop
	current = top;				// start at the top of the queue
	cout << "Current contents of queue: ";
	while (current){			// while there are still more to be printed
		cout << current->data << "  ";
		current = current->next;// point to the next in the list
	}
	cout << endl;				// go to a new line at end of list
}

#endif
