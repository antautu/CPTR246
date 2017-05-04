/**********************************************
* Program:  Maze.h                            *
* Author:   Autumn Anthony                    *
* Date:     03/03/2017                        *
*                                             *
* Abstract:  Class used to create the maze to *
*            be used with aMazing.C.          *
**********************************************/
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <string>
#include <cstdlib>

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
		int rowPos;
		int colPos;
		char direction;
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
	sleep(1);
	system("clear");
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
// Intent: Prompts the user for the position of the mouse, puts it in the maze, and moves it
// Pre: The maze is created and displayed  
// Post: The mouse moves through the maze until the user stops playing 
{
	int rowPosUser, colPosUser;		// Starts at one for the user 
	cout << "Please enter the row (between 1 and " << row << "), the column (between 1 and " << col << "), and the direction (N, S, E, W) that you would like the mouse to face" << endl;
	cin >> rowPosUser;
	cin >> colPosUser;
	cin >> direction;

	rowPos = rowPosUser - 1;		// Changes the value the user gave us to numbers we can use 
	colPos = colPosUser - 1;
	
	while (cin.fail() || cin.peek() != '\n')		// Checks to see if the user enters a non integer 
	{
		if (cin.fail() || cin.peek() != '\n')
		{
			cin.clear();
			cin.ignore(80, '\n');
			cerr << "You did not enter an integer." << endl;		// Error message because an integer was not entered 
		}
		cout << "Please enter the row (between 1 and " << row << "), the column (between 1 and " << col << "), and the direction (N, S, E, W) that you would like the mouse to face" << endl;		// Reprompts the user for input 
		cin >> rowPosUser;
		cin >> colPosUser;
		cin >> direction;
		
		rowPos = rowPosUser - 1;
		colPos = colPosUser - 1;
	}
	while (rowPosUser < 1 || rowPosUser > row || colPosUser < 1 || colPosUser > col || *(mazeptr + (rowPos * col) + colPos) == '#' || (direction != 'N' && direction != 'E' && direction != 'S' && direction != 'W'))
	{
		if (rowPosUser < 1 || rowPosUser > row)		
			cerr << "The row you entered is outside of the maze." << endl;		// Error message if the entered row is not in the maze 
		if (colPosUser < 1 || colPosUser > col)
			cerr << "The column you entered is outside of the maze." << endl;		// Error message if the entered column is not in the maze 
		if (*(mazeptr + (rowPos * col) + colPos) == '#')
			cerr << "You dropped the mouse on the wall." << endl;		// Error message if the mouse was dropped on the wall 
		if (direction != 'N' && direction != 'E' && direction != 'S' && direction != 'W')
			cerr << "You did not enter a correct direction for the mouse to face." << endl;		// Error message if a correct direction was not entered 
		
		cout << "Please enter the row (between 1 and " << row << "), the column (between 1 and " << col << "), and the direction (N, S, E, W) that you would like the mouse to face" << endl;		// Reprompts the user for input 
		cin >> rowPosUser;
		cin >> colPosUser;
		cin >> direction;
		
		rowPos = rowPosUser - 1;
		colPos = colPosUser - 1;
	}
	
	
	
	
	if (direction == 'N')		// If the user chooses North 
	{
		*(mazeptr + (rowPos * col) + colPos) = '^';		// Point the mouse North 
		DisplayMaze();
		
		// If the mouse is not dropped touching any walls, move him North one space 
		if(*(mazeptr + ((rowPos - 1) * col) + colPos) == '.' || *(mazeptr + ((rowPos + 1) * col) + colPos) == '.' || *(mazeptr + (rowPos * col) + (colPos - 1)) == '.' ||  *(mazeptr + (rowPos * col) + (colPos + 1)) == '.')
		{
			*(mazeptr + (rowPos * col) + colPos) = '.';
			rowPos --;
			*(mazeptr + (rowPos * col) + colPos) = '^';
			DisplayMaze();
			MoveNorth();
		}
		if(*(mazeptr + ((rowPos - 1) * col) + colPos) == '#')		// If you drop the mouse facing the North wall, turn West 
		{
			direction = 'W';
			*(mazeptr + (rowPos * col) + colPos) = '<';		// Point the mouse West 
			DisplayMaze();
			MoveWest();
		}
		else
			MoveNorth();
	}
	if (direction == 'E')		// If the user chooses East 
	{
		*(mazeptr + (rowPos * col) + colPos) = '>';		// Point the mouse East 
		DisplayMaze();
		
		// If the mouse is not dropped touching any walls, move him East one space 
		if(*(mazeptr + ((rowPos - 1) * col) + colPos) == '.' || *(mazeptr + ((rowPos + 1) * col) + colPos) == '.' || *(mazeptr + (rowPos * col) + (colPos - 1)) == '.' ||  *(mazeptr + (rowPos * col) + (colPos + 1)) == '.')
		{
			*(mazeptr + (rowPos * col) + colPos) = '.';
			colPos ++;
			*(mazeptr + (rowPos * col) + colPos) = '>';
			DisplayMaze();
			MoveEast();
		}
		if(*(mazeptr + (rowPos * col) + (colPos + 1)) == '#')		// If you drop the mouse facing the East wall, turn North 
		{
			direction = 'N';
			*(mazeptr + (rowPos * col) + colPos) = '^';		// Point the mouse North 
			DisplayMaze();
			MoveNorth();
		}
		else
			MoveEast();
	}
	if (direction == 'S')		// If the user chooses South 
	{
		*(mazeptr + (rowPos * col) + colPos) = 'v';		// Point the mouse South 
		DisplayMaze();
		
		// If the mouse is not dropped touching any walls, move him South one space 
		if(*(mazeptr + ((rowPos - 1) * col) + colPos) == '.' || *(mazeptr + ((rowPos + 1) * col) + colPos) == '.' || *(mazeptr + (rowPos * col) + (colPos - 1)) == '.' ||  *(mazeptr + (rowPos * col) + (colPos + 1)) == '.')
		{
			*(mazeptr + (rowPos * col) + colPos) = '.';
			rowPos ++;
			*(mazeptr + (rowPos * col) + colPos) = 'v';
			DisplayMaze();
			MoveSouth();
		}
		if(*(mazeptr + ((rowPos + 1) * col) + colPos) == '#')		// // If you drop the mouse facing the South wall, turn East 
		{
			direction = 'E';
			*(mazeptr + (rowPos * col) + colPos) = '>';		// Point the mouse East 
			DisplayMaze();
			MoveEast();
		}
		else
			MoveSouth();
	}
	if (direction == 'W')		// If the user chooses West 
	{
		*(mazeptr + (rowPos * col) + colPos) = '<';		// Point the mouse West 
		DisplayMaze();
		
		// If the mouse is not dropped touching any walls, move him West one space 
		if(*(mazeptr + ((rowPos - 1) * col) + colPos) == '.' || *(mazeptr + ((rowPos + 1) * col) + colPos) == '.' || *(mazeptr + (rowPos * col) + (colPos - 1)) == '.' ||  *(mazeptr + (rowPos * col) + (colPos + 1)) == '.')
		{
			*(mazeptr + (rowPos * col) + colPos) = '.';
			colPos --;
			*(mazeptr + (rowPos * col) + colPos) = '<';
			DisplayMaze();
			MoveWest();
		}
		if(*(mazeptr + (rowPos * col) + (colPos - 1)) == '#')		// If you drop the mouse facing the West wall, turn South 
		{
		direction = 'S';
		*(mazeptr + (rowPos * col) + colPos) = 'v';		// Point the mouse South 
		DisplayMaze();
		MoveSouth();
		}
		else
			MoveWest();
	}	
}

void Maze::MoveNorth()
// Intent: Moves the mouse North 
// Pre: The direction of the mouse is set to North 
// Post: Moves the mouse North and then changes its direction when necessary  
{
	// While the mouse can keep moving North
	while (direction == 'N' && *(mazeptr + ((rowPos - 1) * col) + colPos) == '.' && *(mazeptr + (rowPos * col) + (colPos + 1)) == '#' && rowPos != 0)
	{
		*(mazeptr + (rowPos * col) + colPos) = '.';		// Change the current position back to a .
		rowPos --;		// Goes up a row 
		*(mazeptr + (rowPos * col) + colPos) = '^';		// Changes the postion of the mouse 
		DisplayMaze();
	}
	
	int playAgain = 0;
	if (rowPos ==0)		// If the mouse finds its way out of the top of the maze 
	{
		cout << "Your mouse made it out of the maze." << endl;
		cout << "If you would like to play again enter 1: ";		// Prompt the user if they want to play again 
		cin >> playAgain;
		if (playAgain == 1)		// If they want to play again 
		{
			*(mazeptr + (rowPos * col) + colPos) = '.'; // Resets the board if you play again
			DropMouse();		// Drops a new mouse 
		}
		else 
			std::exit(0); // Exits the program 
	}
	else
	{
		// If the mouse has to turn West
		if (direction == 'N' && *(mazeptr + ((rowPos - 1) * col) + colPos) == '#' && *(mazeptr + (rowPos * col) + (colPos + 1)) == '#')
		{
			direction = 'W';
			*(mazeptr + (rowPos * col) + colPos) = '<';			// Point the mouse West 
			DisplayMaze();
			MoveWest();
		}
		
		// If the mouse has to turn East 
		if (direction == 'N' && *(mazeptr + ((rowPos + 1) * col) + (colPos + 1)) == '#' && *(mazeptr + (rowPos * col) + (colPos + 1)) == '.')
		{
			direction = 'E';
			*(mazeptr + (rowPos * col) + colPos) = '>';		// Point the mouse East 
			DisplayMaze();
			*(mazeptr + (rowPos * col) + colPos) = '.';
			colPos ++; 		// Go to the next column to start moving 
			*(mazeptr + (rowPos * col) + colPos) = '>';
			DisplayMaze();
			MoveEast();
		}
	}
}

 
void Maze::MoveWest()
// Intent: Moves the mouse West  
// Pre: The direction of the mouse is set to West  
// Post: Moves the mouse West and then changes its direction when necessary  
{
	// While the mouse can keep moving West  
	while (direction == 'W' && *(mazeptr + (rowPos * col) + (colPos - 1)) == '.' && *(mazeptr + ((rowPos- 1) * col) + colPos) == '#' && colPos != 0)
	{
		*(mazeptr + (rowPos * col) + colPos) = '.';		// Change the current position back to a .
		colPos --; // Goes left a column 
		*(mazeptr + (rowPos * col) + colPos) = '<';		// Changes the postion of the mouse 
		DisplayMaze();
			
	}
	
	int playAgain = 0;
	if (colPos ==0)		// If the mouse finds its way out of the left side of the maze 
	{
		cout << "Your mouse made it out of the maze." << endl;
		cout << "If you would like to play again enter 1: ";		// Prompt the user if they want to play again 
		cin >> playAgain;
		if (playAgain == 1)		// If they want to play again 
		{
			*(mazeptr + (rowPos * col) + colPos) = '.'; // Resets the board if you play again
			DropMouse();		// Drops a new mouse 
		}
		else 
			std::exit(0); // Exits the program 
	}
	else
	{
		// If the mouse has to turn South 
		if (direction == 'W' && *(mazeptr + (rowPos * col) + (colPos - 1)) == '#' && *(mazeptr + ((rowPos - 1) * col) + colPos) == '#')
		{
			direction = 'S';
			*(mazeptr + (rowPos * col) + colPos) = 'v';		// Point the mouse South 
			DisplayMaze();
			MoveSouth();
		}
		
		// If the mouse has to turn North
		if (direction == 'W' && *(mazeptr + ((rowPos - 1) * col) + (colPos + 1)) == '#' && *(mazeptr + ((rowPos - 1) * col) + colPos) == '.')
		{
			direction = 'N';
			*(mazeptr + (rowPos * col) + colPos) = '^';		// Point the mouse North 
			DisplayMaze();
			*(mazeptr + (rowPos * col) + colPos) = '.';
			rowPos --; 		// Go up a row to start moving 
			*(mazeptr + (rowPos * col) + colPos) = '^';
			DisplayMaze();
			MoveNorth();
		}
	}
}

 
void Maze::MoveSouth()
// Intent: Moves the mouse South 
// Pre: The direction of the mouse is set to South 
// Post: Moves the mouse South and then changes its direction when necessary  
{
	// While the mouse can keep moving South 
	while (direction == 'S' && *(mazeptr + ((rowPos + 1) * col) + colPos) == '.' && *(mazeptr + (rowPos * col) + (colPos - 1)) == '#' && rowPos != row - 1)
	{
		*(mazeptr + (rowPos * col) + colPos) = '.';		// Change the current position back to a .
		rowPos ++; // Goes down a row
		*(mazeptr + (rowPos * col) + colPos) = 'v';		// Changes the postion of the mouse 
		DisplayMaze();
	}
	
	int playAgain = 0;
	if (rowPos == row - 1)		// If the mouse finds its way out of the bottom of the maze 
	{
		cout << "Your mouse made it out of the maze." << endl;
		cout << "If you would like to play again enter 1: ";		// Prompt the user if they want to play again 
		cin >> playAgain;
		if (playAgain == 1)		// If they want to play again 
		{
			*(mazeptr + (rowPos * col) + colPos) = '.'; // Resets the board if you play again
			DropMouse();		// Drops a new mouse 
		}
		else 
			std::exit(0); // Exits the program 
	}
	else
	{
		// If the mouse has to turn East
		if (direction == 'S' && *(mazeptr + ((rowPos + 1) * col) + colPos) == '#' && *(mazeptr + (rowPos * col) + (colPos - 1)) == '#')
		{
			direction = 'E';
			*(mazeptr + (rowPos * col) + colPos) = '>';		// Point the mouse East 
			DisplayMaze();
			MoveEast();
		}
		
		// If the mouse has to turn West 
		if (direction == 'S' && *(mazeptr + ((rowPos - 1) * col) + (colPos - 1)) == '#' && *(mazeptr + (rowPos * col) + (colPos - 1)) == '.')
		{
			direction = 'W';
			*(mazeptr + (rowPos * col) + colPos) = '<';		// Point the mouse West 
			DisplayMaze();
			*(mazeptr + (rowPos * col) + colPos) = '.';
			colPos --;  		// Go left a column to start moving 
			*(mazeptr + (rowPos * col) + colPos) = '<';
			DisplayMaze();
			MoveWest();
		}
	}
}	

void Maze::MoveEast()
// Intent: Moves the mouse East 
// Pre: The direction of the mouse is set to East 
// Post: Moves the mouse East and then changes its direction when necessary  
{
	// While the mouse can keep moving East 
	while (direction == 'E' && *(mazeptr + (rowPos * col) + (colPos + 1)) == '.' && *(mazeptr + ((rowPos+ 1) * col) + colPos) == '#' && colPos != col - 1)
	{
		*(mazeptr + (rowPos * col) + colPos) = '.';		// Change the current position back to a .
		colPos ++; // Goes right a column 
		*(mazeptr + (rowPos * col) + colPos) = '>';		// Changes the postion of the mouse 
		DisplayMaze();
	}
	
	int playAgain = 0;
	if (colPos == col - 1)		// If the mouse finds its way out of the right side of the maze 
	{
		cout << "Your mouse made it out of the maze." << endl;
		cout << "If you would like to play again enter 1: ";		// Prompt the user if they want to play again 
		cin >> playAgain;
		if (playAgain == 1)		// If they want to play again
		{
			*(mazeptr + (rowPos * col) + colPos) = '.'; // Resets the board if you play again
			DropMouse();		// Drops a new mouse 
		}
		else 
			std::exit(0); // Exits the program 
	}
	else
	{
		// If the mouse has to turn North 
		if (direction == 'E' && *(mazeptr + (rowPos * col) + (colPos + 1)) == '#' && *(mazeptr + ((rowPos+ 1) * col) + colPos) == '#')
		{
			direction = 'N';
			*(mazeptr + (rowPos * col) + colPos) = '^';		// Point the mouse North 
			DisplayMaze();
			MoveNorth();
		}
		
		// If the mouse has to turn South
		if (direction == 'E' && *(mazeptr + ((rowPos + 1) * col) + (colPos - 1)) == '#' && *(mazeptr + ((rowPos + 1) * col) + colPos) == '.')
		{
			direction = 'S';
			*(mazeptr + (rowPos * col) + colPos) = 'v';		// Point the mouse South 
			DisplayMaze();
			*(mazeptr + (rowPos * col) + colPos) = '.';
			rowPos ++;  		// Go down a row to start moving
			*(mazeptr + (rowPos * col) + colPos) = 'v';
			DisplayMaze();
			MoveSouth();
		}
	}
}	
