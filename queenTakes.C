/**********************************************
* Program: queenTakes.C                       *
* Author:  Autumn Anthony                     *
* Date:    02/01/2017                         *
*                                             *
* Abstract: Lab 3  Part 2                     *
**********************************************/
#include <iostream>

using namespace std;

void queenTakes(char chessboard[][8], int i, int j){
  // pre:   chessboard has been initialized to spaces, i and j are between 0 and 7
  // post:  a 'Q' is placed where the queen is and *'s are placed on all of the
  //          positions that she can take
  // purpose: to give you more practice with arrays!
  
	for (int index = 0; index < 8; index ++)		// For loop to create the vertical and horizontal lines
	{
		chessboard[i][index] = '*';		// Creates the horizontal line
		chessboard[index][j] = '*';		// Creates the vertical line
	}
	int row = i;		// Keeps an original copy of i
	int column = j;		// Keeps an original copy of j 
	
	while (i >= 0 && i <= 7 && j >= 0 && j <= 7)		// Creates the diagonal that goes down to the right 
	{
		chessboard[i][j] = '*';
		i ++;
		j ++;
	}
	
	i = row;		// Resets i to the original value
	j = column;		// Resets j to the original value
	
	while (i >= 0 && i <= 7 && j >= 0 && j <= 7)		// Creates the diagonal that goes up to the left
	{
		chessboard[i][j] = '*';
		i --;
		j --;
	}
	
	i = row;		// Resets i to the original value
	j = column;		// Resets j to the original value
	
	while (i >= 0 && i <= 7 && j >= 0 && j <= 7)		// Creates the diagonal that goes down to the left 
	{
		chessboard[i][j] = '*';
		i ++;
		j --;
	}
	
	i = row;		// Resets i to the original value
	j = column;		// Resets j to the original value
	
	while (i >= 0 && i <= 7 && j >= 0 && j <= 7)		// Creates the diagonal that goes up to the right 
	{
		chessboard[i][j] = '*';
		i --;
		j ++;
	}
	
	i = row;		// Resets i to the original value
	j = column;		// Resets j to the original value
	
	chessboard[i][j] = 'Q';		// Marks the queen on the board at the given location 
}

int main() {
  char chessboard[8][8];	// array to model the chessboard
  int row, column;		// indexes to tell where the queen is
  int i, j;			// indexes to work with
  
  for (i = 0; i < 8; i++)	// clear chessboard making it all spaces
    for (j = 0; j < 8; j++)
      chessboard[i][j] = ' ';
  
  // Get the location of the queen from the user
  cout << "Enter the row and column (0 - 7) to indicate the location of the queen." << endl;
  cin >> i >> j;

  // Validate the input that the user entered - integers between 0 and 7 only
  while (cin.fail() || cin.peek() != '\n' ||
	 !(i >= 0 && i <= 7) || !(j >= 0 && j <= 7)){
    cout << "That was an invalid response.  Please enter the row and column again." << endl;
    cin.clear();             // clear the flags (e.g. fail)
    cin.ignore(80, '\n');    // clar the buffer
    cin >> i >> j;           // get the user's input again
  }                   // stay in the while loop until the user enters valid input

  queenTakes(chessboard, i, j);	// call function to mark queen and *'s

  cout << endl;
  for (i = 0; i < 8; i++){	// display the chessboard
    for (j = 0; j < 8; j++){
      cout << chessboard[i][j]; // print what's in row i, column j
    }
    cout << endl;               // go to a newline after each row
  }
  cout << endl;
  return 0;
}

