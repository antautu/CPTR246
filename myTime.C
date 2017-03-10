/**********************************************
* Program:  myTime.C                          *
* Author:   Autumn Anthony                    *
* Date:     03/08/2017                        *
*                                             *
* Abstract:  Formats different times.         *
**********************************************/
#include <iostream>
#include <ctime>

using namespace std;

int main() 
{
	time_t secondsSince;					// to hold the number of seconds since Jan. 1, 1970
	tm * rightNow;							// pointer to a time struct(ure)
  
	secondsSince = time(0);					// get the current date and
											//   time in terms of seconds
	rightNow = localtime(&secondsSince);	// convert the seconds into the tm structure
											//   and set rightNow to point to it
																	
	
	cout << "Today is " << asctime(rightNow) << endl;		// Prints out the current date and time
	
	cout << "The number of seconds since 01/01/70 is " << secondsSince << endl;
	cout << "The number of days since January 1 is " << rightNow -> tm_yday << endl;
	cout << "The number of years since 1900 is " << rightNow -> tm_year << endl;
	cout << "The number of days since Sunday [0,6] is " << rightNow -> tm_wday << endl << endl;
	
	char buildTime1[200];
	char formatMilTime[] = "The time here in Williamsport is %H:%M in military time.";
	strftime(buildTime1, 200, formatMilTime, rightNow);		// Formats the current military time 
	cout << buildTime1 << endl;		// Prints out the formatted string 
	
	char buildTime2[200];
	char formatClockTime[] = "That would be %I:%M %p in wall clock time.";
	strftime(buildTime2, 200, formatClockTime, rightNow);		// Formats the current clock time
	cout << buildTime2 << endl;		// Prints out the formatted string 
	
	char buildDate[200];
	char formatDate[] = "Today is %A %B %d, %Y, or %a %b %d '%y for short.";
	strftime(buildDate, 200, formatDate, rightNow);		// Formats the current date 
	cout << buildDate << endl << endl;		// Prints out the formatted string 
	
	cout << "Greenwich Meridian Time is " << asctime(gmtime(&secondsSince)) << endl;
	
	char buildTime3[200];
	char formatGMilTime[] = "The time in Greenwich is %H:%M in military time.";
	strftime(buildTime3, 200, formatGMilTime, gmtime(&secondsSince));		// Formats the Greenwich military time
	cout << buildTime3 << endl;		// Prints out the formatted string 
	
	char buildTime4[200];
	char formatGClockTime[] = "That would be %I:%M %p in wall clock time.";
	strftime(buildTime4, 200, formatGClockTime, gmtime(&secondsSince));		// Formats the Greenwich clock time
	cout << buildTime4 << endl << endl;		// Prints out he formatted string 
	
	cout << "I'm building a tm object with my birthday, February 5, 1995." << endl;
	
	tm  myBirthday;		// Creates a struct for my birthday 
	myBirthday.tm_sec = 0;		// Second 
	myBirthday.tm_min = 0;		// Minute
	myBirthday.tm_hour = 3;		// Hour 
	myBirthday.tm_mon = 1;		// Month 
	myBirthday.tm_mday = 5;		// Day of the month 
	myBirthday.tm_year = 95;	// Year
	myBirthday.tm_wday = 0;		// Day of the week 
	
	cout << "When I display the tm object, I get " << asctime(&myBirthday) << endl;
	
	
	
	
	
	return 0;
}

