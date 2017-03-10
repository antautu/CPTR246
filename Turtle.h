/***********************************************
* Program:  Turtle.h                           *
* Author:   Autumn Anthony                     *
* Date:     02/18/2017                         *
*                                              *
* Abstract: Creates the Turtle class to be used*
*			in turtle.C                        *
***********************************************/
#include <iostream>
#include <fstream>
 
using namespace std;

class Turtle{
	public:
		Turtle();
		bool Open();
		void ProcessInput();
		void DisplayFloor();
	private:
		char board[20][20];
		int row;
		int col;
		bool penPos;
		ifstream inFile;
		
		int getDigits(string instruction);
		void Pen(string line);
		void verifyMove(string line);
		void move(string line);
};

Turtle::Turtle()
// Intent: Constructor
// Pre: None
// Post: Data members initialized properly
{
	for (int i = 0; i < 20; i ++)		// Initialzes the board to spaces
	{
		for (int j = 0; j < 20; j ++)
		{
			board[i][j] = ' ';
		}
	}	
		
	row = 0;		// Sets the turtles position to the top left corner of the board
	col = 0;
	penPos = false;		// Sets the pens inital position of up to false
}

bool Turtle::Open()
// Intent: Asks the user for an input file and checks to see if it opens
// Pre: None
// Post: Returns true if the file opens and returns false if it does not 
{
	string fileName;
	
	cout << "Enter the name of the input file: "; 		// Asks the user to input the file name 
	cin >> fileName;
	
	inFile.open(fileName.c_str());		// Opens the file
	if (!inFile)		// If the file cannot be found return false 
		return false;
	else
		return true;
}

int Turtle::getDigits(string instruction)
// pre:  instruction is a string for an N, S, E, or W command
// post: if it's a valid command, it returns the number of positions to
//       move, otherwise it returns -1

// purpose:  This is a private member function that you can copy into your Turtle.h file.  
//            It will take a string (one line from the input file) as a parameter and
//            pick out the number of positions to move and return it.  
//            If there is a problem with that number, it will return a -1.

{
	if ((instruction.length() < 3))
		return -1;
	if (!isdigit(instruction[2]))
        	return -1;
	if ((instruction.length() == 3) || !isdigit(instruction[3])){
		return (instruction[2] - '0');
	}
	return (10 * (instruction[2] - '0')  +  (instruction[3] - '0'));
}

void Turtle::Pen(string line)
// Intent: Sets the pens position 
// Pre: Reads the first character in the line of the file
// Post: Returns true if the pen position is down and false if the position is up
{
	if (line[0] == 'U')
		penPos = false;
	if (line[0] == 'D')
		penPos = true;
}


void Turtle:: verifyMove(string line)
// Intent: Verifies that the movement of the turtle will not take it off the board
// Pre: Pen is used 
// Post: Gives different errors depending on if the input is good 
{
	bool movement = false;
	
	if (line[0] == 'N' || line[0] == 'E' || line[0] == 'S' || line[0] == 'W')		// If it is a direction command
	{
		if (line[1] != '\n' && line[1] != ' ')		// If there is no space or new line character 
		{
			movement = false;		// Turtle does not move
			cerr << "There is no space after the starting letter." << endl;		// Gives the user an error
		}
		if (getDigits(line) == -1)		// If the line does not have a digit telling the turtle how far to move
		{
			movement = false;		// Turtle does not move
			cerr << "There is an invalid integer." << endl;		// Gives the user an error
		}
		else
			movement = true;		// If the input is good, the turtle moves 
	}
	if (line[0] == 'N')		// Moving north 
	{
		if (row - getDigits(line) < 0)
		{
			cerr << "The turtle went off the top of the board." << endl;		// Error if the turtle will go too far north 
			movement = false;		// Turtle does not move 
		}
		else
			movement = true;		// The turtle stays on the board and will move 
	}
	
	if (line[0] == 'E')		// Moving east
	{
		if (col + getDigits(line) > 20)
		{
			cerr << "The turtle went off the right side of the board." << endl;		// Error if the turtle will go too far east
			movement = false;		// Turtle does not move 
		}	
		else
			movement = true;		// The turtle stays on the board and will move 
	}
	
	if (line[0] == 'S')		// Moving south 
	{
		if (row + getDigits(line) > 20)
		{
			cerr << "The turtle went off the bottom of the board." << endl;		// Error if the turtle will go too far south
			movement = false;		// Turtle does not move 
		}
		else
			movement = true;		// The turtle stays on the board and will move 
	}
	
	if (line[0] == 'W')		// Moving west 
	{
		if (col - getDigits(line) < 0)
		{
			cerr << "The turtle went off the left side of the board." << endl;		// Error if the turtle will go too far west 
			movement = false;		// Turtle does not move 
		}
		else
			movement = true;		// The turtle stays on the board and will move 
	}
	
	if (line[0] == 'D' || line[0] == 'U')		// If the line has a pen up or down command
	{
		Pen(line);		// Go to Pen to see what to do 
		movement = true;
	}
}

void Turtle:: move(string line)
// Intent: Move the turtle and draws on the board if the pen is down 
// Pre: verifyMove is used 
// Post: The turtle moves and asterisks are printed to the board 
{
	bool movement;
	verifyMove(line);		// Go to verifyMove to see if the turtle will move 
	
	if(movement == true)
	{
		if (line[0] == 'N')
		{
			if (penPos == true)
			{
				for (int i = row; i >= row - getDigits(line); i --)		// Draws the path if the pen is down 
					board[i][col] = '*';
			}
			row = row - getDigits(line);		// Sets the new row of the turtle 
		}
		
		if (line[0] == 'E')
		{
			if (penPos == true)
			{
				for (int i = col; i <= col + getDigits(line); i ++)		// Draws the path if the pen is down 
					board[row][i] = '*';
			}
			col = col + getDigits(line);		// Sets the new column of the turtle 
		}
		
		if (line[0] == 'S')
		{
			if (penPos == true)
			{
				for (int i = row; i <= row + getDigits(line); i ++)		// Draws the path if the pen is down 
					board[i][col] = '*';
			}
			row = row + getDigits(line);		// Sets the new row of the turtle
		}
		
		if (line[0] == 'W')
		{
			if (penPos == true)
			{
				for (int i = col; i >= col - getDigits(line); i --)		// Draws the path if the pen is down 
					board[row][i] = '*';
			}
			col = col - getDigits(line);		// Sets the new column of the turtle 
		}
	}
	else
		cerr << "There is no U, D, N, S, W, or E." << endl;		// Error if there is not a valid command 
}

void Turtle::ProcessInput()
// Intent: Goes through the lines of the file and processes the commands 
// Pre: move is used 
// Post: Went through the file 
{
	bool movement;
	string line;
	
	getline(inFile, line);
	while(!inFile.eof())		// Goes through each line of the file until it is done and executes the commands 
	{
		move(line);		// Goes to move to move the turtle 
		getline(inFile, line);
	}	
}

void Turtle::DisplayFloor()
// Intent: Shows the movement of the turtle and shows the path it takes if the pen is down 
// Pre: None
// Post: Displays the board on the screen  
{
	for (int i = 0; i < 20; i ++)	
	{
		for (int j = 0; j < 20; j ++)
		{
			cout << board[i][j];		// Displays the board 
		}
		cout << endl;
	}
	cout << endl;
}
