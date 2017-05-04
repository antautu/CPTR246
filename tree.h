/************************************************
     tree.h - binary tree that holds integers
************************************************/

#ifndef _TREE_H
#define _TREE_H

#include <fstream>
#include "queue.h"

using namespace std;

class BinaryTree{
   public:
		BinaryTree() {root = 0;}		// CONSTRUCTOR
		~BinaryTree();				// DESTRUCTOR
		int IsEmpty()		
			{return (root == 0);}
		void MakeTree(ifstream & inFile);
		int InTree(int x);
		void Preorder();
		void Postorder();
		void Inorder();
		void BreadthFirst();
   private:
		BinaryTreeNode * root;			// points to root of tree
							// "helper" functions - needed
							//    when recursion is used!
		int InTreeHelper(BinaryTreeNode * root, int x);
		void PreorderHelper(BinaryTreeNode * root);
		void PostorderHelper(BinaryTreeNode * root);
		void InorderHelper(BinaryTreeNode * root);
};

BinaryTree::~BinaryTree(){
// pre:	  none
// post:  all memory utilized by the tree is returned to the free store
		// NOT YET COMPLETED
}


void BinaryTree::MakeTree(ifstream & inFile){
// pre:   inFile is a file containing integers that has been opened
// post:  the tree is built, loaded from inFile

        BinaryTreeNode * first;                 // points to root
        BinaryTreeNode * current;               // used when searching where to insert a node
        BinaryTreeNode * thisOne;               // points to memory allocated for this node
        int value;                              // value to be inserted
        int found;                              // flag - location to insert found
        first = new BinaryTreeNode;             // allocate memory for the root node
        inFile >> value;                        // get the first value
        first->data = value;                    // set up root
        first->leftChild = 0;
        first->rightChild = 0;
        inFile >> value;                        // get next value to insert
        while (!inFile.eof()){                  // if there are more to insert
                thisOne = new BinaryTreeNode;   // allocate memory for it
                thisOne->data = value;          // initialize the values
                thisOne->leftChild = 0;
                thisOne->rightChild = 0;
                current = first;                // look for its spot in the tree
                found = 0;                      // set found flag to 0
                while (!found){                 // found a spot for it yet?
                        if (value < current->data)      // go left if value is less than this node
                                if (current->leftChild) // is there a node there already?
                                        current = current->leftChild;
                                else                    //  if not, we've found the spot
                                        found = 1;
                        else                            // go right of value is > this node
                                if (current->rightChild)// is there a node there already?
                                       current = current->rightChild;
                                else                    // if not, we've found our spot
                                        found = 1;
                }
                if (value < current->data)       // was is supposed to be the left child
                        current->leftChild = thisOne;
                else                             //   or the right child?
                        current->rightChild = thisOne;
                inFile >> value;                // get the next value to insert
        }
        root = first;                           // set up root
}

int BinaryTree::InTree(int x){
// pre:  none
// post: returns true if x is in the tree, false if not
        if (!root)			// tree is empty
		return 0;
	return InTreeHelper(root, x);

}

int BinaryTree::InTreeHelper(BinaryTreeNode * root, int x){
// pre:    root is loaded and x is an integer
// post:   returns true if x is in the tree, false otherwise


	if (root->data == x)            // is x at this node?
                return 1;               //   if yes, return true
                                        // if not, is it in either of
                                        //   of the "trees" below it?
                // first test if there is a child, then if x is in
                //   the "tree" rooted at that child
        if (root->leftChild && InTreeHelper(root->leftChild, x))
                return 1;
        if (root->rightChild && InTreeHelper(root->rightChild, x))
                return 1;
        return 0;                       // if nowhere, return false
}

void BinaryTree::Preorder(){
// pre:   none
// post:  a preorder listing of the tree is displayed
	PreorderHelper(root);		// call helper function
	cout << endl;			// go to a new line
}

void BinaryTree::PreorderHelper(BinaryTreeNode * root){
// pre:  root must be a valid tree node
// post: a "preorder" listing is given

        if (root){                      // if this is not a NULL pointer
                cout << root->data << " ";
					//   print the data in this node
                                        //   then print the nodes in the
                                        //   "tree" rooted at each child
        //        if (root->leftChild)
                        PreorderHelper(root->leftChild);
        //        if (root->rightChild)
                        PreorderHelper(root->rightChild);
        }
}

void BinaryTree::Postorder(){
// pre:  none
// post: a postorder listing of the tree is displayed
	PostorderHelper(root);		// call helper function
	cout << endl;					// go to a new line
}

void BinaryTree::PostorderHelper(BinaryTreeNode * root){
// pre:  root must be a valid tree node
// post: a "postorder" listing is given

        if (root){              // if this is not a NULL pointer
				//    then print the nodes in each of the
				//    children then print this node
                if (root->leftChild)
                        PostorderHelper(root->leftChild);
                if (root->rightChild)
                        PostorderHelper(root->rightChild);
                cout << root->data << " ";
        }
}


void BinaryTree::Inorder(){
// pre:  none
// post: an inorder listing of the tree is displayed
	InorderHelper(root);	// call helper function
	cout << endl;		// go to a new line
}

void BinaryTree::InorderHelper(BinaryTreeNode * root){
// pre:  root must be a valid tree node
// post: an "inorder" listing is given

        if (root){              // if this is not a NULL pointer
                                //    then print the nodes in the left
				//    child then this node then the
                                //    children in the right node
                if (root->leftChild)
                        InorderHelper(root->leftChild);
                cout << root->data << " ";
                if (root->rightChild)
                        InorderHelper(root->rightChild);
        }
}

void BinaryTree::BreadthFirst(){
// pre:
// post:
	
	Queue myQueue;		// Create a queue object to use the Queue class 
	myQueue.Enqueue(root);		// Enqueue the root 
	BinaryTreeNode * x;
	x = root;		// Declare a new variable to hold the information at root so we don't overwrite it 
	
	while(!myQueue.IsEmpty())		// While the queue is not empty 
	{
		myQueue.Dequeue(x);		// Dequeue the node 
		cout << x -> data << " ";		// Prints the node 
		
		if (x->leftChild)		// If the node has a leftChild
			myQueue.Enqueue(x -> leftChild);		// Go to the leftChild
		if (x->rightChild)		// If the node 
			myQueue.Enqueue(x -> rightChild);		// Go to the rightChild
	}	
	cout << endl;
	
	
	
	
	

}

#endif
