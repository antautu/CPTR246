/**********************************************
* Program:  array2d6.C                        *
* Author:   Eileen Peluso                     *
*                                             *
* Abstract: Multiplication table (no zeroes)  *
*               parameterized                 *
**********************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

void display2D(int * values, int n){
  // pre:   values is a 2 dimensional array with n items per row
  //            and n rows
  // post:  the array is displayed on the screen in table form
  int i, j;		       // define indices
  for (i = 0; i < n; i++){
    for (j = 0; j < n; j++){
      cout << setw(5) << *(values + (i * n) + j);
    }
    cout << endl;
  }
}

int main(int argc, char * argv[]) {
  if (argc != 2){
    cerr << "Invalid invocation:  Specify table size" << endl;
    return 1;
  }  
  int n = atoi(argv[1]);		// free function "alpha to integer"
  int * value;					// define integer array pointer
  value = new int[n*n];			// get needed memory
  int i, j;						// define indices

  for (i = 0; i < n; i++){		// for each row
    for (j = 0; j < n; j++){	// for each column
      *(value + (i * n) + j) = (i+1) * (j+1);  // setting value[i][j]
    }
  }

  display2D(value, n);			// display array
  return 0;
}

