/**********************************************
* Program:  string3.C                         *
* Author:   Autumn Anthony                    *
* Date:     02/27/2017                        *
*                                             *
* Abstract: Determines how many times a string* 
*			appears within another string.    *
**********************************************/
#include <iostream>
#include <cstring>

using namespace std;

int main() {
  char string1[50];
  char string2[50];
  int count(0);
  
  cout << "Enter two strings (the second a potential substring of the first): " << endl;
  cin.getline(string1, 50);
  cin.getline(string2, 50);
  
  // use the strstr function to determine how many times the string2 appears in string1
  // hint:  a loop will be required
  
  char * x = strstr(string1, string2);
  while (x != '\0')
  {
	  count ++;
	  x = strstr(x + 1, string2);
  }
  
  cout << "I found \"" << string2 << "\" in there " << count
       << " times." << endl;
  return 0;
}

