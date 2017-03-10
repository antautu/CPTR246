/***************************************************
* Program:  problem5.19.C                          *
* Author:   Autumn Anthony                         *
* Date:     01/27/2017                             *
*                                                  *
* Abstract:  Calculates the value of Pi from an    *
			 infinite series. Prints a table that  *
			 shows the iteration and the value of  *
			 Pi approximated by computing the first*
			 200,000 terms of the series.          *
***************************************************/
#include <iostream>

using namespace std;

int main() 
{
	double approximation = 4.0;		// Sets the initial approximation for the first iteration
	
	cout << "1\t" << approximation << endl;		// Prints out the first iteration 
	
	for (int i = 2; i <= 200000; i ++)		// Loops through the rest of the iterations
	{
		cout << i << "\t"; 		// Shows the number of the iteration 
		
		if (i % 2 == 0)		// For even terms 
		{
			approximation = approximation - (4 / ((i * 2) - 1.0));		// Calculates the even terms and updates the approximation with the newest iteration
		}
		else		// For odd terms
		{
			approximation = approximation + (4 / ((i * 2) - 1.0));		// Calculates the odd terms and updates the approximation with the newest iteration
		}
		
		cout << approximation << endl;		// Prints out the iteration to the table 
		
	}
	
	return 0;
}

