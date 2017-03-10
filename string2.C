/*************************************************
* Program:  string2.C                            *
* Author:   Autumn Anthony                       *
* Date:     02/27/2017                           *
*                                                *
* Abstract: Determines whether or not two strings*
*			are equal, or which is greater.      *
*************************************************/
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char string1[40];
  char string2[40];
  cout << "Enter two strings and I will compare them: " << endl;
  cin.getline(string1,40);
  cin.getline(string2,40);
  cout << endl;
  
  // use the strcmp function to determine whether these strings are equal,
  //   or if string1 comes before string2 or string2 comes before string1
  
  if (strcmp(string1, string2) == 0)
	  cout << "string1 and string2 are equal." << endl;
  
  if (strcmp(string1, string2) < 0)
	  cout << "string1 is less than string2." << endl;
  
  if (strcmp(string1, string2) > 0)
	  cout << "string1 is greater than string2." << endl;
  
  cout << endl;
  return 0;
}

