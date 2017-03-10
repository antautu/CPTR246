/**********************************************
* Program:  twoD.C                            *
* Author:   Autumn Anthony                    *
* Date:     02/01/2017                        *
*                                             *
* Abstract: Lab 3  Part 1                     *
**********************************************/
#include <iostream>
#include <iomanip>

using namespace std;

// ****************************************************************
void rowSum(int theArray[][16], int n)		// Function that calculates the sum of the values in the rows
{
	for (int i = 0; i < n; i ++)		// Goes through the rows
	{
		int sum = 0;
		for (int j = 0; j < 16; j ++)		// Goes through the columns
		{
			sum = sum + theArray[i][j];		// Adds the number at the given location of the array to the sum
		}
		cout << "row " << i << " total is " << sum << endl;		// Prints out the sum 
	}
}

void columnSum(int theArray[][16], int n)		// Function that calculates the sum of the values in the columns
{
	for (int j = 0; j < 16; j ++)		// Goes through the columns
	{
		int sum = 0;
		for (int i = 0; i < n; i ++)		// Goes through the rows 
		{
			sum = sum + theArray[i][j];		// Adds the number at the given location of the array to the sum
		}
		cout << "column " << j << " total is " << sum << endl;		// Prints out the sum 
	}
}
// ****************************************************************


int main() {
  int values[12][16];                     // define the array

  // Initialize the array with values
  for (int i = 0; i < 12 ; i++){         // for each of the 12 rows
    for (int j = 0; j < 16; j ++){       // for each of the 16 columns in the ith row
      values[i][j] = ((i + j) * 25) % 17;// I made this up just to give the array #s
      cout << setw(3) << values[i][j];   // print the value - width set to 3
    } 
    cout << endl;                        // go to a new line at the end of each row
  }

  // Call the two functions that students are to write
  cout << endl << "Row Sums:" << endl;
  rowSum(values, 12);
  cout << endl << "Column Sums:" << endl;
  columnSum(values, 12);
  return 0;
}

