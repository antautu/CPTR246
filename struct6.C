/**********************************************
* Program:  struct6.C                         *
* Author:   Eileen Peluso                     *
*                                             *
* Abstract: An array within a structure       *
**********************************************/
#include <iostream>
#include <iomanip>

using namespace std;

struct student{
  int ID;         // student id number
  int exams[4];   // array of exams
  bool didPass;   // did s/he pass?
};

void getStudentData(student & myStudent){
  // pre:   none, but VALID INPUT by user is assumed! 
  // post:  myStudent's data has been filled in, input from cin
  
  //  cout << "Please enter the student's name and 4 grades"<< endl;
  //    prompt commented out because we're using redirection for input
  cin >> myStudent.ID;
  cin >> myStudent.exams[0];
  cin >> myStudent.exams[1];
  cin >> myStudent.exams[2];
  cin >> myStudent.exams[3];
}

int main() {
  student cptr000[15];
  int index;
  
  for (index = 0; index < 15; index++){
    getStudentData(cptr000[index]);
  }
  cout << "The 5th student's second exam grade is " <<
    cptr000[4].exams[1] << endl;
  
  // NOW LET'S AVERAGE EVERYONE'S GRADES, SET THEIR didPass FLAGS
  //         AND PRINT OUT THE RESULTS -- SEE WRITE-UP FOR
  //         DETAILS ON THE LAYOUT!
  
  string boolMessage;		// Creates a string version of didPass
  
  for (int i = 0; i < 15; i ++)		// Loops through each student 
  {
	  int sum = 0;		// Initializes the sum of each students exams to 0
	  double average = 0;		// Initializes the average of each students exams to 0
	  
	  cout << cptr000[i].ID;		// Prints out the student ID number 
	  
	  for (int j = 0; j < 4; j ++)		// Loops through each exam 
	  {
		  sum = cptr000[i].exams[j] + sum;		// Finds the sum of the exams 
		  
		  cout << setw(4) << cptr000[i].exams[j];		// Prints out the exam scores in columns
	  }
	  average = sum / 4.0;		// Finds the average of the exams 
	  
	  cout << setw(7) << showpoint << setprecision(4) << average;		// Prints out the average
	  
	  if (average >= 60)		// If the average is passing 
	  {
		  cptr000[i].didPass = true;
		  boolMessage = "Yippee!";
	  }
	  else		// If the average is failing
	  {
		  cptr000[i].didPass = false;
		  boolMessage = "Bummer.";
	  }
	  
	  cout << setw(10) << boolMessage << endl;		// Prints out the message 
  }
  
  
  return 0;
}

