/**********************************************
* Program:  displayDistance.C                 *
* Author:   Autumn Anthony                    *
* Date:     01/25/2017                        *
*                                             *
* Abstract: Program to demonstrate function   *
*           definitions and calls             *
**********************************************/
#include <iostream>
#include <cmath>		// Needed to include the math class to use the square root
 
using namespace std;

void displayDistance(double xa, double ya, double xb, double yb);
// pre:	  parameters have been given values
// post:  distance between (xa,ya) and (xb,yb) is displayed on the screen


int main () {
	double x1 ,y1;     	// coordinates of first point
	double x2, y2; 		// coordinates of second point
				// prompt user for two points
	cout << "Enter the coordinates of the first point." << endl;
	cin >> x1 >> y1;
	cout << "Enter the coordinates of the second point." << endl;
	cin >> x2 >> y2;

				// call function to display distance

//*************************************************************************

	displayDistance(x1, y1, x2, y2);		// Calls the displayDistance function to show the distance between the two points


//*************************************************************************

	return 0;
}


void displayDistance(double xa, double ya, double xb, double yb)
// pre:	  parameters have been given values
// post:  distance between (xa,ya) and (xb,yb) is displayed on the screen
{
//*************************************************************************

	cout << "The distance between the two points is " << sqrt(pow(xb - xa, 2) + pow(yb - ya, 2)) << endl;		// Prints out the distance between the two points 


//*************************************************************************

}




