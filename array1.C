/**********************************************
* Program:  array1.C                          *
* Author:   Autumn Anthony                    *
* Date:     02/22/2017                        *
*                                             *
* Abstract: Load an array of test scores      *
*           User will input an unknown number *
*           (but less than 50).  Then we      *
*           print them back out.              *
**********************************************/
#include <iostream>

using namespace std;

int main() {
  int testScores[50];    	// define array to hold 50 ints
  int index(0);				// used as the subscript
  int numberOfScores;		// how many end up being input by the user
  int thisScore;			// holds the one the user just entered
  
  cout << "Please enter the testscores(max of 50) (ctrl-d to end)"
       << endl;				// prompt the user
  cin >> thisScore;			// get value from the user
  while (!cin.eof()){		// while the user has entered another score
    testScores[index] = thisScore;	// put it in the array
    index++;				// get index ready for the next score
    cin >> thisScore;   	// get the next score from the user
  }
  
  numberOfScores = index;	// remember how many scores were entered
  cout << endl << endl;	    // print two blank lines
  
  cout << "Here is what you entered:" << endl;	// print a heading

  // print out each score on a separate line
  for (index = 0; index < numberOfScores; index++){
    cout << testScores[index] << endl;	
  }
  
  return 0;		        // end of program
}

