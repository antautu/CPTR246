/************************************************
     tree.h - binary tree that holds integers
************************************************/
 
#ifndef _TREE_H
#define _TREE_H

#include <fstream>
using namespace std;

class BinaryTreeNode{
   friend class BinaryTree;
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
		int data;						// value at node
		BinaryTreeNode * leftChild;		// points to left child
		BinaryTreeNode * rightChild;	// points to right child
};


class BinaryTree{
   public:
		BinaryTree() {root = 0;}		// CONSTRUCTOR
		~BinaryTree();					// DESTRUCTOR
		int IsEmpty()		
			{return (root == 0);}		// {return !root;}
		void MakeTree(ifstream & inFile);
		int InTree(int x);
		void Preorder();
		void Postorder();
		void Inorder();
		void Largest();
		int SumTree();
		int Below(int x);
		bool DeleteLeaf(int x);
   private:
		BinaryTreeNode * root;			// points to root of tree
										// "helper" functions - needed
										//    when recursion is used!
		int InTreeHelper(BinaryTreeNode * root, int x);
		void PreorderHelper(BinaryTreeNode * root);
		void PostorderHelper(BinaryTreeNode * root);
		void InorderHelper(BinaryTreeNode * root);
		int LargestHelper(BinaryTreeNode * root);
		int SumTreeHelper(BinaryTreeNode * root);
		int BelowHelper(BinaryTreeNode * root, int x);
		void DestructorHelper(BinaryTreeNode * root);

};

BinaryTree::~BinaryTree(){
// pre:		none
// post:  	all memory utilized by the tree is returned to the free store
	DestructorHelper(root);
}

void BinaryTree::DestructorHelper(BinaryTreeNode * root){
// pre:  root must be a valid tree node 
// post:  all memory utilized by the tree is returned to the free store
	if (root)
	{
		if (!root -> leftChild && !root -> rightChild)		// If there are no children
		{
			cout << "Deleting " << root -> data << endl;		// Shows what is being deleted 
			delete root;		// Deletes the root 
		}
		
		else		// If there are children 
		{
			if (root -> leftChild)		// If there is a leftChild to be deleted 
				DestructorHelper(root -> leftChild);
			
			if (root -> rightChild)		// If there is a rightChild to be deleted 
				DestructorHelper(root -> rightChild); 
			
			cout << "Deleting " << root -> data << endl;		// Shows what is being deleted 
			delete root;		// Deletes the root 
		}
	}
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
        thisOne = new BinaryTreeNode;   	// allocate memory for it
        thisOne->data = value;          	// initialize the values
        thisOne->leftChild = 0;
        thisOne->rightChild = 0;
        current = first;                	// look for its spot in the tree
        found = 0;                      	// set found flag to 0
        while (!found){                 	// found a spot for it yet?
            if (value < current->data)      // go left if value is less than this node
                if (current->leftChild) 	// is there a node there already?
                    current = current->leftChild;
                else                    	//  if not, we've found the spot
                    found = 1;
            else                            // go right of value is > this node
                if (current->rightChild)	// is there a node there already?
                    current = current->rightChild;
                else                    	// if not, we've found our spot
                    found = 1;
        }
        if (value < current->data)       	// was is supposed to be the left child
            current->leftChild = thisOne;
        else                             	//   or the right child?
            current->rightChild = thisOne;
        inFile >> value;                	// get the next value to insert
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
     return 0;                    // if nowhere, return false
}

void BinaryTree::Preorder(){
// pre:   none
// post:  a preorder listing of the tree is displayed
	PreorderHelper(root);		// call helper function
	cout << endl;				// go to a new line
}

void BinaryTree::PreorderHelper(BinaryTreeNode * root){
// pre:  root must be a valid tree node
// post: a "preorder" listing is given

    if (root){					// if this is not a NULL pointer
		cout << root->data << " ";
								//   print the data in this node
								//   then print the nodes in the
								//   "tree" rooted at each child
		if (root->leftChild)
			PreorderHelper(root->leftChild);
		if (root->rightChild)
			PreorderHelper(root->rightChild);
    }
}

void BinaryTree::Postorder(){
// pre:  none
// post: a postorder listing of the tree is displayed
	PostorderHelper(root);		// call helper function
	cout << endl;				// go to a new line
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
	cout << endl;			// go to a new line
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

void BinaryTree::Largest(){
// pre:  none
// post: the largest value in the tree is displayed
	if (!root)		// If the list is empty tell the user
		cout << "The tree is empty" << endl;
	else		// Tells the user what the largest value is if the tree is not empty 
	{
		cout << "The largest value is " << LargestHelper(root) << endl;
		cout << endl;
	}
}

int BinaryTree::LargestHelper(BinaryTreeNode * root){
// pre:  root must be a valid tree node
// post: the largest value in the tree is 
	if (!root -> leftChild && !root -> rightChild)		// If there are no children
	{
		return root -> data;
	}
	
	int LargestSoFar = root -> data;		// LargestSoFar is set to the root 
	
	if (root -> leftChild)		// If the root has a leftChild
	{
		if (LargestSoFar < LargestHelper(root -> leftChild));		// If the leftChild is larger than the root 
			LargestSoFar = LargestHelper(root -> leftChild);		// Set LargestSoFar to the leftChild
	}
	
	if (root -> rightChild)		// If the root has a rightChild
	{
		if (LargestSoFar < LargestHelper(root -> rightChild));		// If the rightChild is larger than the root 
			LargestSoFar = LargestHelper(root -> rightChild);		// Set LargestSoFar to the rightChild
	}
	
	return LargestSoFar;
}

int BinaryTree::SumTree(){
// pre:  none
// post: returns the sum of the values in the tree 
	if (root)		// If there is a root 
		return SumTreeHelper(root);		// Returns the sum of the values 
		
	else		// If the list is empty 
		return 0;		// The sum is zero because the list is empty 	
}

int BinaryTree::SumTreeHelper(BinaryTreeNode * root){
// pre: root must be a valid tree node 
// post: returns the sum of the values in the tree 
	if (!root -> leftChild && !root -> rightChild)		// If there are no children
	{
		return root -> data;		// The root is equal to the sum 
	}
	
	if (root -> leftChild)		// If the root has a leftChild
	{
		if (root -> rightChild)		// If the root has a rightChild
			return root -> data + SumTreeHelper(root -> leftChild) + SumTreeHelper(root -> rightChild);		// Adds children to the sum if both exist 
			
		return root -> data + SumTreeHelper(root -> leftChild);		// Adds leftChild to sum if it exists 
	}
	
	else 
		return root -> data + SumTreeHelper(root -> rightChild);		// Adds rightChild to sum if it exists 	
}

int BinaryTree::Below(int x){
// pre:  the user enters an integer 
// post: returns the number of values in the tree less than the entered value 
	if (root)		// If there is a root check to see if it is less than the value
		return BelowHelper(root, x);
	else	// If there are no roots
		return 0;		// There are no numbers less then the value
}

int BinaryTree::BelowHelper(BinaryTreeNode * root, int x){
// pre: root must be a valid tree node 
// post: returns the number of values in the tree less than the entered value
	if (!root -> leftChild && !root -> rightChild)		// If there are no children	
	{
		if (root -> data < x)		// If the value is less than the root 
			return 1; 		// There is one value in the tree less then the value 
		else 		// If the value is greater than the root 
			return 0;		// There are no values in the tree less than the value 
	}
	
	if (root -> leftChild)		// If the root has a leftChild
	{
		if (root -> rightChild)		// If the root has a rightChild
		{
			if (root -> data < x)
				return 1 + BelowHelper(root -> leftChild, x) + BelowHelper(root -> rightChild, x);		// Adds one to the number of values less than the number 
			else
				return BelowHelper(root -> leftChild, x) + BelowHelper(root -> rightChild, x);		// Does not add anything to the number of values less than the number 
		}
		
		if (root -> data < x)
			return 1 + BelowHelper(root -> leftChild, x);		// Adds one to the number of values less than the number 
		else
			return BelowHelper(root -> leftChild, x);		// Does not add anything to the number of values less than the number 	
	}
	
	else		// If there is just a rightChild
	{
		if (root -> data < x)
			return 1 + BelowHelper(root -> rightChild, x);		// Adds one to the number of values less than the number 
		else
			return BelowHelper(root -> rightChild, x);		// Does not add anything to the number of values less than the number 
	}		
}

bool BinaryTree::DeleteLeaf(int x){
// pre:  the user enters an integer of a leaf they wish to delete 
// post: returns true if the leaf was deleted and false otherwise 
	if (!InTree(x))		// If the entered number is not in the tree 
		return false;		// Return false because it could not be deleted 
	
	BinaryTreeNode * newRoot;
	BinaryTreeNode * current;
	current = root;		// Sets current to the root we start at
	 
	while (current -> data != x)		// While the current root is not the number we are looking for 
	{
		if (x > current -> data)		// If the value we are looking for is greater than the current root, go to the rightChild
		{
			newRoot = current;		// Updates the root 
			current = current -> rightChild;		// Go to the rightChild
		}
			
		if (x < current -> data)		// If the value we are looking for is less than the current root, go to the leftChild
		{
			newRoot = current; 		// Updates the root 
			current = current -> leftChild;		// Go to the leftChild
		}
	}
	
	if (current -> leftChild || current -> rightChild)		// If the value we were looking for has a child, it is not a leaf
		return false;		// Return false because the value was not a leaf
		
	if (newRoot -> leftChild == current)		// If the value we were looking for is a leftChild and a leaf
	{
		newRoot -> leftChild = 0;		// Gets rid of the pointer
		delete current;		// Deletes the leaf
		return true;		// Return true because we deleted the leaf 
	}
	
	if (newRoot -> rightChild == current)		// If the value we were looking for is a rightChild and a leaf
	{
		newRoot -> rightChild = 0;		// Gets rid of the pointer
		delete current;		// Deletes the leaf
		return true;		// Return true because we deleted the leaf 
	}
}
#endif
