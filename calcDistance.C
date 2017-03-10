/**********************************************
* Program:  calcDistance.C                    *
* Author:   Autumn Anthony                    *
* Date:     01/25/2017                        *
*                                             *
* Abstract: Program to demonstrate function   *
*           definitions and calls             *
**********************************************/
#include <iostream>
#include <cmath>		// Needed to include the math class to use the square root

using namespace std;

double distance(double xa, double ya, double xb, double yb)
// pre:   parameters have been given values
// post:  returns distance between (xa,ya) and (xb,yb)
{
// *******************************************************************

	return sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));		// Returns the distance between the two points


// *******************************************************************
}

int main () {
	double x1 ,y1;     	// coordinates of first point
	double x2, y2; 		// coordinates of second point
				// prompt user for two points
	cout << "Enter the coordinates of the first point." << endl;
	cin >> x1 >> y1;
	cout << "Enter the coordinates of the second point." << endl;
	cin >> x2 >> y2;
				// NOTE: a variable definition here!?!
 	double theDistance;	// the distance between the two points
				// call function to get distance
// *******************************************************************

	theDistance = distance(x1, y1, x2, y2);		// Calls the distance function and sets it equal to theDistance
	



// *******************************************************************
				// now display the distance
	cout << "The distance between the two points is " << theDistance
	     << endl;
	return 0;
}

