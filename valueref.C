/************************************************
* Program:  valueref.C                          *
* Author:   Autumn Anthony                      *
* Date:     02/22/2017                          *
*                                               *
* Abstract: Program to modify to demonstrate    *
*           call by value and call by reference *
*           Modify it so that the parameters of *
*           getData are call by reference using *
*           pointers (the old C way)            *
************************************************/
#include <iostream>

using namespace std;

void getData(int * aptr, int * bptr) {
  cout << "Enter two ints: ";
  cin >> *aptr >> *bptr;
}

int main() {
  int arg1 = 0, arg2 = 0;
  getData(&arg1, &arg2);
  cout << " You entered " << arg1 << " and " << arg2 << endl;
  return 0;
}

