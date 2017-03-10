/************************************************
* Program:  problem2.18.C                       *
* Author:   Autumn Anthony                      * 
* Date:     01/18/2017                          *
*                                               *
* Abstract:  Get 2 integers from the user and   *
*            display the larger if there is one.*
*            If not, disply that they are equal.*
************************************************/
#include <iostream>

using namespace std;

int main() {
	int num1, num2;
	
	cout << "Enter the first number: ";
	cin >> num1;
	
	cout << "Enter the second number: ";
	cin >> num2;
	
	if (num1 > num2)
		cout << num1 << " is larger than " << num2 << "." << endl;
	else if (num1 < num2)
		cout << num2 << " is larger than " << num1 << "." << endl;
	else
		cout << "You gave me two of the same number." << endl;
	
	return 0;
}

