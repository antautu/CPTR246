/**********************************************
* Program:  Maze.h                            *
* Author:   Autumn Anthony                    *
* Date:     03/03/2017                        *
*                                             *
* Abstract:  Class used to create the maze to *
*            be used with aMazing.C.           *
**********************************************/
#include <iostream>
#include <fstream>

using namespace std;

class Maze{
	public:
		Maze();
		bool OpenAndLoad(char * filename);
		void DisplayMaze();
		
	private:
	char filename[30];
		int row;
		int col;
		char * mazeptr;
		ifstream inFile;
};

Maze::Maze()
// Intent: Constructor
// Pre: None
// Post: Data members initialized properly
{
	int row = 0;
	int col = 0;
	mazeptr = new char[row * col];
}

bool Maze::OpenAndLoad(char * filename)
// Intent: Opens and loads the maze from a file 
// Pre: Takes in a file name from the command line or from the user
// Post: Opens the file if the user entered a valid file name 
{
	inFile.open(filename);		// Attempts to open the file 
		
	while (!inFile)		// While the file cannot be opened 
	{
		cerr << "File could not be opened." << endl;		// Error message 
		cout << "Enter the name of the file to be opened: ";		// Reprompt for the name of the file
		cin >> filename;
		inFile.open(filename);		// Attempt to open the file again
	}
	
	inFile >> row;		// Reads in the number of rows 
	inFile >> col;		// Reads in the number of columns 
	
	mazeptr = new char[row * col];		// Creates a pointer to the size of the maze
	char mazeChar;		// Character read in from the final at the specified position 
	for (int i = 0; i < row; i ++)
	{
		for (int j = 0; j < col; j ++)
		{
			inFile >> mazeChar;		// Character read in from the file to be printed to the screen
			*(mazeptr + (i * col) + j) = mazeChar;
		}
	}
	return true;
}

void Maze::DisplayMaze()
// Intent: Prints the maze to the screen
// Pre: The array containing the characters is filled 
// Post: Prints the maze to the screen 
{
	for (int i = 0; i < row; i ++)
	{
		for (int j = 0; j < col; j ++)
		{
			cout << *(mazeptr + (i * col) + j);		// Prints out the maze 
		}
		cout << endl;
	}
}
