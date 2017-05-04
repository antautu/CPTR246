/***************************************************
 *     IntegerNode.h                                *
 *     Author:  Eileen Peluso                       *
 ***************************************************/
#ifndef _INTEGERNODE_H
#define _INTEGERNODE_H

#include <iostream>
#include <fstream>
using namespace std;

class IntegerNode{
	public:
		IntegerNode();
		int getValue();										
		IntegerNode * getNext();
		void setValue(int newValue);
		void setNext(IntegerNode * newPointer);
	private:
		int value;				// The integer held in this node
		IntegerNode * next;		// Points to the next node;  0 if last item in the list
};

IntegerNode::IntegerNode(){
// pre:		none
// post:	default node is set up
// purpose:	this is the default constructor
	value = 0;
	next = 0;
}

int IntegerNode::getValue(){
// pre:		none
// post:	the value of the integer held at this node is returned
// purpose:	this is an "accessor" function to get the value at the node
	return value;
}

IntegerNode * IntegerNode::getNext(){
// pre:		none
// post:	the pointer to (address of) the node following this one is returned
// purpose:	this is an "accessor" function to get the pointer at the node
	return next;
}

void IntegerNode::setValue(int newValue){
// pre:		none
// post:	the value of the integer held at this node is set to newValue
// purpose:	to change the value of the integer held at this node
	value = newValue;
}

void IntegerNode::setNext(IntegerNode * newPointer){
// pre:		none
// post:	the pointer to (address of) the node following this one is changed to newPointer
// purpose:	to establish the links between nodes.  if newPointer is 0, it means that
//		this node is at the end of the list
	next = newPointer;
}
#endif

