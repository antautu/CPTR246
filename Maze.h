
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
		void DropMouse();
		void MoveNorth();
		void MoveEast();
		void MoveSouth();
		void MoveWest();
		
	private:	
		int row;
		int col;
		char * mazeptr;		
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
	ifstream inFile;
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
void Maze::DropMouse()
{
	int rowPosUser, colPosUser; // Starts at one for the user 
	int rowPos, colPos; // Starts at zero for us 
	char direction;
	cout << "Please enter the row (between 1 and " << row << "), the column (between 1 and " << col << "), and the direction (N, S, E, W) that you would like the mouse to face" << endl;
	cin >> rowPosUser;
	cin >> colPosUser;
	cin >> direction;
	
	while (rowPosUser < 1 || rowPosUser > row || colPosUser < 1 || colPosUser > col || *(mazeptr + (rowPosUser * col) + colPosUser) == '#' || (direction != 'N' && direction != 'E' && direction != 'S' && direction != 'W'))
	{
		if (rowPosUser < 1 || rowPosUser > row)
			cerr << "The row you entered is outside of the maze." << endl;
		if (colPosUser < 1 || colPosUser > col)
			cerr << "The column you entered is outside of the maze." << endl;
		if (*(mazeptr + (rowPosUser * col) + colPosUser) == '#')
			cerr << "You dropped the mouse on the wall." << endl;
		if (direction != 'N' && direction != 'E' && direction != 'S' && direction != 'W')
			cerr << "You did not enter a correct direction for the mouse to face." << endl;
		
		cout << "Please enter the row (between 1 and " << row << "), the column (between 1 and " << col << "), and the direction (N, S, E, W) that you would like the mouse to face" << endl;
		cin >> rowPosUser;
		cin >> colPosUser;
		cin >> direction;
	}
	
	//while (the row or column are not real numbers)
	
	rowPos = rowPosUser - 1;
	colPos = rowPosUser - 1;
	if (direction == 'N')
	{
		*(mazeptr + (rowPos * col) + colPos) = '^';
		DisplayMaze();
	}
	if (direction == 'E')
	{
		*(mazeptr + (rowPos * col) + colPos) = '>';
		DisplayMaze();
	}
	if (direction == 'S')
	{
		*(mazeptr + (rowPos * col) + colPos) = 'v';
		DisplayMaze();
	}
	if (direction == 'W')
	{
		*(mazeptr + (rowPos * col) + colPos) = '<';
		DisplayMaze();
	}	
}
// North
void Maze::MoveNorth()
while (direction == 'N' && *(mazeptr + ((rowPos - 1) * col) + colPos) = '*' && *(mazeptr + (rowPos * col) + (colPos + 1)) = '#')
{
	rowPos --; // Goes up a row 
	*(mazeptr + (rowPos * col) + colPos) = '^';
	DisplayMaze();
}
if (direction == 'N' && *(mazeptr + ((rowPos - 1) * col) + colPos) = '#' && *(mazeptr + (rowPos * col) + (colPos + 1)) = '#')
{
	direction = 'W';
	*(mazeptr + (rowPos * col) + colPos) = '<';	
	DisplayMaze();
	MoveWest();
}


// West 
void Maze::MoveWest()
while (direction == 'W' && *(mazeptr + (rowPos * col) + (colPos - 1)) = '*' && *(mazeptr + ((rowPos- 1) * col) + colPos) = '#')
{
	colPos --; // Goes left a column 
	*(mazeptr + (rowPos * col) + colPos) = '<';
	DisplayMaze();
}
if (direction == 'W' && *(mazeptr + (rowPos * col) + (colPos - 1)) = '#' && *(mazeptr + ((rowPos- 1) * col) + colPos) = '#')
{
	direction = 'S';
	*(mazeptr + (rowPos * col) + colPos) = 'v';
	DisplayMaze();
	MoveSouth();
}

// South 
void Maze::MoveSouth()
while (direction == 'S' && *(mazeptr + ((rowPos + 1) * col) + colPos) = '*' && *(mazeptr + (rowPos * col) + (colPos - 1)) = '#')
{
	rowPos ++; // Goes down a row
	*(mazeptr + (rowPos * col) + (colPos - 1)) = '<';
	DisplayMaze();
}
if (direction == 'S' && *(mazeptr + ((rowPos + 1) * col) + colPos) = '#' && *(mazeptr + (rowPos * col) + (colPos - 1)) = '#')
{
	direction = 'E';
	*(mazeptr + (rowPos * col) + colPos) = '>';
	DisplayMaze();
	MoveEast();
}
	
// East 
void Maze::MoveEast()
while (direction == 'E' && *(mazeptr + (rowPos * col) + (colPos + 1)) = '*' && *(mazeptr + ((rowPos+ 1) * col) + colPos) = '#')
{
	colPos ++; // Goes right a column 
	*(mazeptr + (rowPos * col) + colPos) = '<';
	DisplayMaze();
}
if (direction == 'W' && *(mazeptr + (rowPos * col) + (colPos + 1)) = '#' && *(mazeptr + ((rowPos+ 1) * col) + colPos) = '#')
{
	direction = 'N';
	*(mazeptr + (rowPos * col) + colPos) = '^';
	DisplayMaze();
	MoveNorth();
}	
	
	
	
	
	
