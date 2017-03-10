/***********************************************
* Program:  string1.C                          *
* Author:   Autumn Anthony                     *
* Date:     02/27/2017                         *
*                                              *
* Abstract: Adds a string to the end of anthoer*
*			string. 						   *
***********************************************/
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char string1[40];
  char string2[40];
  cout << "Enter two strings and I will concatenate them: " << endl;
  cin.getline(string1,40);
  cin.getline(string2,40);
  
  cout << endl << "Using the strcat function in a cout statement, we get: " << endl;
  
  // enter a single cout statement that calls the strcat function, concatenating
  //    string 2 onto the end of string 1

  cout << strcat(string1, string2);
  
  cout << endl << "After that function is called, the two strings look like this:" << endl;
  cout << "String 1: " << string1 << endl;
  cout << "String 2: " << string2 << endl;
  return 0;
}

