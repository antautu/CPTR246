/**********************************************
* Program:  hello.C                           *
* Author:   Group effort                      *
* Date:     01/18/17                          *
*                                             *
* Abstract: Let's get some practice with C++  *
*           and UNIX                          *
**********************************************/
#include <iostream>
#include <string>

using namespace std;

int main() {
	string firstName, lastName;
	cout << "Enter your first name: ";
	cin >> firstName;
	cout << "Enter your last name: ";
	cin >> lastName;

	cout << "Hello, " << firstName << " " << lastName << "!" << endl;
	cout << "I am coding. I am Lycoming." << endl;
	return 0;
}

