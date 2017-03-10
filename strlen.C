/**********************************************
* Program:  strlen.C                          *
* Author:   Autumn Anthony                    *
* Date:     03/01/2017                        *
*                                             *
* Abstract: Returns the string length using   *
*           arrays and pointers               *
**********************************************/
#include <iostream>

using namespace std;

int strlen_array(char * s){ 

	int count1 = 0;
	for (int i = 0; s[i] != '\0'; i ++)
		count1 ++;
	return count1;
}

int strlen_pointer(char * s){
	
	int count2 = 0;
	for (; *s != '\0'; ++s)
		count2 ++;
	return count2;
}

int main() {
	char theString[120];
	cout << "Enter a string: " << endl;
	cin.getline(theString, 120);
	cout << "Array-based strlen returns " << strlen_array(theString) << endl;
	cout << "Pointer-based strlen returns " << strlen_pointer(theString) << endl;
	return 0;
}

