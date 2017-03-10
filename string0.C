/**********************************************
* Program:  string0.C                         *
* Author:   Autumn Anthony                    *
* Date:     02/27/2017                        *
*                                             *
* Abstract: Copies the contents of one string *
*			and places them inside another.   *
**********************************************/
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char string1[40];
  char string2[40];
  cout << "Enter one string and I will copy it into another: " << endl;
  cin.getline(string1,40);
  
  // use the strcpy function to copy the contents of string1 into string2
  
  strcpy(string2, string1);
  
  cout << endl << "After that function is called, the two strings look like this:" << endl;
  cout << "String 1: " << string1 << endl;
  cout << "String 2: " << string2 << endl;
  return 0;
}

