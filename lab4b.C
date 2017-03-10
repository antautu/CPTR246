/**********************************************
* Program:  lab4b.C                           *
* Author:   Autumn Anthony                    *
* Date:     02/10/2017                        *
*                                             *
* Abstract: Practices formatting using        *
			justification, setting the width, *
			showing decimal points, setting   *
			the precision, and converting     *
			decimals into hexadecimal.        *
**********************************************/
#include <iostream>
#include <iomanip>		// Need to change formatting 

using namespace std;

int main() 
{ 
	int num_13_6a = 40000;
	cout << left << setw(15) << num_13_6a << endl;		// Sets width and left justifies 
	cout << right << setw(15) << num_13_6a << endl;		// Sets width and right justifies 
	
	int num_13_6c = 200;
	cout << num_13_6c << " " << showpos << num_13_6c << endl;		// Specifies that the positive number should have a +
	cout << noshowpos;		// Resets so it does not show a positive anymore 

	int num_13_6d = 100;
	cout << hex << showbase << num_13_6d << endl;		// Changes the integer to hexidecimal and shows the base 
	
	double num_13_6f = 1.234;
	cout << setfill('0') << setw(10) << num_13_6f << endl;		// Sets the width and fills the open spaces with zeroes
	cout << setfill(' ');
	
	double num_13_10 = 100.453627;
	cout << setprecision(3) << showpoint << num_13_10 << endl;		// Sets precision to just get whole number and shows decimal point
	cout << setprecision(4) << num_13_10 << endl;		// Sets precision to show tenths place
	cout << setprecision(5) << num_13_10 << endl;		// Sets precision to show hundredths place
	cout << setprecision(6) << num_13_10 << endl;		// Sets precision to show thousandths place
	cout << setprecision(7) << num_13_10 << endl;		// Sets precision to show ten-thousandths place
	
	cout << endl;		// Line for readability
	cout << "ASCII Table" << endl;
	for (int i = 33; i < 100; i++)		// Goes from 33 to 99
	{
		cout << dec << i 
			<< setw(7) << right << hex << i
			<< setw(4) << right << (char)i << endl;		// Prints out the decimal value, hex value, and chracter value in columns
	}
	for (int i = 100; i <= 126; i++)		// Goes from 100 to 126 with changed column widths for readability 
	{
		cout << dec << i 
			<< setw(6) << right << hex << i
			<< setw(4) << right << (char)i << endl;
	}
	
	
	return 0;
}

