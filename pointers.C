// This program written by Dr. Peluso as an lab exercise to
// test understanding of pointer operations.  Step through the 
// program and write next to each number on the handout what 
// the output will be for that line.

#include <iostream>
using namespace std;

void fun1(int * value){
  *value = 100;
}

int main() {
  int a = 6;
  int b = 10;
  int *aPtr;
  int *bPtr;
  int c[] = {21, 45, 32, 16, 9};
  
  aPtr = &a;
  bPtr = &b;
  cout << "Line 1:  " << *aPtr << " " << *bPtr << endl;
  
  *aPtr = 5;
  cout << "Line 2:  " << *aPtr << " " << *bPtr << endl;
  
  bPtr = aPtr;
  cout << "Line 3:  " << *aPtr << " " << *bPtr << endl;
  cout << "Line 4:  " << a << " " << b << endl;
  
  cout << "Line 5:  " << *c << endl;
  cout << "Line 6:  " << *(c + 2) << endl;
  cout << "Line 7:  " << *c + 2 << endl;
  
  bPtr = c;
  cout << "Line  8: " << bPtr[1] << endl;
  
  fun1(&b);
  cout << "Line  9: " << b << endl;
  
  fun1(aPtr);
  cout << "Line 10: " << a << endl;
  
  fun1(c);
  cout << "Line 11: " << c[0] << " " << c[1] << endl;
  
  return 0;
}

