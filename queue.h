/**************************************************************
*      queue.h      Class that implements a queue             *
**************************************************************/
#ifndef _QUEUE_H
#define _QUEUE_H

using namespace std;

class BinaryTreeNode{
   friend class BinaryTree;
   friend class Queue;
   public:
						// CONSTRUCTORS
		BinaryTreeNode() {data = 0; leftChild = rightChild = 0;}
		BinaryTreeNode(int x)
			{data = x;
		 	 leftChild = rightChild = 0;
			}
		BinaryTreeNode(int x, BinaryTreeNode * l, BinaryTreeNode * r)
			{data = x;
			 leftChild = l;
			 rightChild = r;
			}
   private:
		int data;				// value at node
		BinaryTreeNode * leftChild;		// points to left child
		BinaryTreeNode * rightChild;		// points to right child
};


class Node {
	friend class Stack;
	friend class Queue;
	private:
		BinaryTreeNode * data;		// information held in Node
		Node * next;		// points to next node in list
};	

class Queue {
   public:				// see function def's for pre and post
	Queue() { top = 0; bottom = 0;}
	~Queue();
	bool IsEmpty() {return (top == 0);}
	bool IsFull();
	bool Peek(BinaryTreeNode * & x);
	void Enqueue(BinaryTreeNode * x);
	bool Dequeue(BinaryTreeNode * & x);
	void Display();
 private:
	Node * top;			// points to first Node in queue
	Node * bottom;			// points to last Node in queue
};

Queue::~Queue(){
// pre:  none
// post: queue is destroyed, memory is released

	Node * next;			// temp value for looping
	while (top){			// while still some to delete
		next = top->next;	// save pointer to next one
		delete top;		// delete this one
		top = next;		// the "next one" is now on top
	}
}

bool Queue::IsFull(){
// pre:   none
// post:  returns true if there is insufficient memory to allocate
//          another node
	Node * newSpace;		// hold address of new node
	newSpace = new Node;		// is there space for another one?
	if (newSpace){			// any non-NULL value indicates "new"
					//    was successful
		delete newSpace;	// we didn't want the space
		return 0;		//   we just wanted to see if there was
					//   enough
	}
	return 1;			// return true if there wasn't enough space
}


bool Queue::Peek(BinaryTreeNode * & x){
// pre:  assumes queue is not empty
// post: sets parameter to top of queue, return true (1).  If queue
//             is empty it returns false;
	if (!top)			// top == 0 indicates empty queue
		return 0;
	else {				// show data, don't delete the node
		x = top->data;
		return 1;
	}
}

void Queue::Enqueue(BinaryTreeNode * x){
// pre:	  x is an integer
// post:  x is added to end of queue.
	Node * newOne;			// hold address of new Node
	newOne = new Node;		// allocate memory for the new Node
	newOne->data = x;		// set up it's data
	newOne->next = 0;		// it should point to the old "top"
	if (top){			// if queue is NOT empty
		bottom->next = newOne;	//   last one should point to new one
		bottom = newOne;	//   the newOne is now last
	}
	else{				// else this will be the only one
		top = newOne;		//   so its both top
		bottom = newOne;	//   and bottom!
	}
}

bool Queue::Dequeue(BinaryTreeNode * & x){
// pre:	  none
// post:  x is updated to the value removed from the queue and
//              true is returned
//        if the queue was empty, false is returned
	Node * removed;			// save address of one to be removed
	if (top){			// if the stack was not empty
		removed = top;		//    save pointer to top Node
		x = top->data;		//    get the data that was in it
		top = top->next;	//    top is now the address of what was the
					//         second Node on the list
		if (!top)		//    if top is zero (meaning empty queue)
			bottom = 0;	//         correct bottom pointer
		delete removed;		//    free up memory for removed Node
		return 1;		//    return true (successful)
	}
	else return 0;			// return false if the Stack had nothing to pop
}

void Queue::Display(){
// pre:   none
// post:  contents of queue have been displayed on the screen
	Node * current;			// points to the current node being displayed in loop
	current = top;			// start at the top of the queue
	cout << "Current contents of queue: ";
	while (current){		// while there are still more to be printed
		cout << (current->data)->data << "  ";
		current = current->next;	// point to the next in the list
	}
	cout << endl;			// go to a new line at end of list
}


#endif
