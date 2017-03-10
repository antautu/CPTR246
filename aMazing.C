/*************************************************
* Program:  aMazing.C                            *
* Author:   Autumn Anthony                       *
* Date:     03/03/2017                           *
*                                                *
* Abstract: Driver for the Maze class. Opens     *
*			a data file containind the blueprints*
*			of the maze and prints it to the     *
*			screen.                              *
*************************************************/
#include <iostream>
#include "Maze.h"
#include <iomanip>
#include <cstdlib>

using namespace std;

int main(int argc, char * argv[]) 
{
	Maze myMaze;		// Declares a new maze 
	char * filename;		// Character pointer for the name of the file to be opened
	
	if (argc == 1)		// If the user does not enter the name of the file on the command line
	{
		cout << "Enter the name of the file to be opened: ";		// Ask the user for the name of the file
		cin >> filename;
		
		myMaze.OpenAndLoad(filename);		// Calls the method to open the file 
		myMaze.DisplayMaze();		// Calls the method to display the maze
	}
	
	else		// If the user enters the name of the file on the command line 
	{
		filename = argv[1];		// The name of the file is what is entered on the command line 
		myMaze.OpenAndLoad(filename);		// Calls the method to open the file 
		myMaze.DisplayMaze();		// Calls the method to display the maze
	}
	
	
	return 0;
}

