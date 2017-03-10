/**********************************************
* Program:  recursionsRus.C                   *
* Author:   Autumn Anthony                    *
* Date:     01/25/2017                        *
*                                             *
* Abstract: Lots of practice with recursive   *
*              functions                      *
**********************************************/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

int getInt(string prompt){
// pre:   prompt contains instructions for the user
// post:  returns an integer entered by the user
	int n;						// hold user's input
 	cout << prompt;				// display prompt
	cin >> n;					// extraction
	while (cin.fail()){         // was it successful?
         	cout << "Invalid input.  Enter an integer: ";
		cin.clear();
		cin.ignore(80,'\n');
		cin >> n;
	}
	return n;					// return the value entered
}

double getDouble(string prompt){
// pre:   prompt contains instructions for the user
// post:  returns a double entered by the user
	double n;								// hold user's input
 	cout << prompt;				// display prompt
	cin >> n;					// extraction
	while (cin.fail()){			// was it successful?
         	cout << "Invalid input.  Enter a real number: ";
		cin.clear();
		cin.ignore(80,'\n');
		cin >> n;
	}
	return n;					// return the value entered
}

int Menu(){
// pre:   none
// post:  returns the value entered by the user in response to menu
	int option;
	system("clear");
	cout << endl;
	cout << "\t\t\tWelcome to Recursions 'R' Us" << endl;
	cout << endl;
	cout << "\t\t\tSelect from the following options:" << endl << endl;
	cout << "\t\t\t1 - Factorial of x" << endl;
	cout << "\t\t\t2 - Take x to the y power" << endl;
	cout << "\t\t\t3 - Fibonacci(x)" << endl;
	cout << "\t\t\t4 - Print x reversed" << endl;
	cout << "\t\t\t5 - Greatest common divisor of x and y" << endl;
	cout << "\t\t\t6 - End program" << endl;
	cout << endl;
	option = getInt("Option: ");
	return option;
}

int factorial(int x)
{
    if (x == 0)		// Base case
		return 1;		// Returns 1 if we have the base case
	else 
		return x * factorial(x - 1);		// Returns the factorial of the entered integer using the base case
}

double exponent(double x, int y)
{
	if (y == 1)		// Base case
		return x;		// Returns the entered double if we have the base case
	else
		return x * exponent(x, y - 1);		// Returns the double raised to the integer power using the base case
}

int fib(int n)
{
	if (n == 0)		// Base case 1
		return 0;		// Returns 0 if we have the first base case
	if (n == 1)		// Base case 2
		return 1;		// Returns 1 if we have the second base case
	else
		return fib(n - 1) + fib(n - 2);		// Returns the Fibonacci of the entered integer using the base cases 
}

void printReversed(int x)
{
	if (x <= 9)		// Base case
		cout << x;		// Prints out the integer if we have the base case 
	else
	{
		cout << (x % 10);		// Prints out the remainder of the integer to get the last digit
		printReversed(x / 10);		// Goes to next digit to finish printing out the reversed integer
	}	
}

int gcd(int x, int y)
{
	if (y == 0)		// Base case
		return x;		// Returns the first integer if we have the base case
	else
		return gcd(y, x % y);		// Returns the greatest commom denominator of the two entered integers
		
}

int main() {
	int menuOption(0);       		// holds user's choice
	char anyKey;                    // used for "Hit enter to continue ..."
	int a;							// variables to hold user input
	int b;							//   . . .
	double x;						//   . . .
	double y;						//   . . .

	while (menuOption != 6){
       	menuOption = Menu();    	// Get thue user's next option
		system("clear");			// clear the screen
		switch (menuOption){		// processing is based on choice
			case 1: a = getInt("Enter an integer: ");
				cout << a << "! is " << factorial(a) << endl;
				break;
			case 2: x = getDouble("Enter the value for x: ");
				a = getInt("Enter the exponent: ");
				cout << x << " raised to the " << a
					<< " power is " << exponent(x,a) << endl;
				break;
			case 3: a = getInt("Enter an integer: ");
				cout << "Fibonacci(" << a << ") is "
					<< fib(a) << endl;
				break;
			case 4: a = getInt("Enter an integer: ");
				cout << a << " reversed is ";
				printReversed(a);
				cout << endl;
				break;
			case 5: a = getInt("Enter the first integer: ");
				b = getInt("Enter the second integer: ");
				cout << "The greatest common divisor of " <<
					a << " and " << b << " is " <<
					gcd(a,b) << endl;
				break;
			case 6: break;
			default:
				cout << "Invalid menu option" << endl;
		}
		if (menuOption != 6){		// pause screen in user
									//   has not opted to quit
			cin.ignore(80,'\n');
			cout << "\n\nStrike enter to continue ..." << endl;
			cin.get(anyKey);
		}
	}
	system("clear");				// clear screen
	return 0;
}

