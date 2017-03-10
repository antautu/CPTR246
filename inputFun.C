/**********************************************
* Program:  inputFun.C                        *
* Author:   Autumn Anthony                    *
* Date:     02/15/2017                        *
*                                             *
* Abstract: Program to determine what a string*
*           (null-terminated character array) *
*            contains.                        *
**********************************************/
#include <iostream>
#include <iomanip>
#include <cstdlib>		 
#include <cctype>
#include <cstring>
#include <fstream>

using namespace std;

bool isInt(char inputString[]){
	// pre:  inputString has been initialized to some string
	// post: if inputString is the proper format for
	//          an integer then the function will return TRUE (1).
	//          Otherwise it will return FALSE (0)
  
	int index(0);		// index for character array (string)
  
	if (inputString[0] == '-' && strlen(inputString) == 1){	// DEMONSTRATES HOW TO CHECK THE LENGTH OF A NULL-TERMINATED CHARACTER ARRAY
		return 0;		// its only a "-"
	}

	index = 0;			// set index
	if (inputString[0] == '-'){
		index++;
	}

	for (; inputString[index]; index++){	// LOOP ENDS WHEN TERMINATING NULL IS REACHED
		if (!isdigit(inputString[index])){
			return 0;	// return false since we found a non-digit
		}
	}
	return 1;			// this was indeed an integer
}

bool isReal(char inputString[]){
	// pre:  inputString has been initialized to some string
	// post: if inputString is the proper format for
	//          a real number then the function will return TRUE (1).
	//          Otherwise it will return FALSE (0)
	//			NOTE: Integers are also real numbers.
	
	int index(0);
	int numDecimals = 0;		// Sets the number of decimals 
	index = 0;
	if (inputString[0] == '-')		// If the first character is a negative move on to the next 
		index ++;
	for (; inputString[index]; index++)
	{
		if (inputString[index] == '.' && numDecimals == 0)		// If there were no previous decimal points 
		{
			index ++;		// Move on to the next character 
			numDecimals ++;		// Increments the number of decimals so that we can only have 1 to be a real number
		}
		if (!isdigit(inputString[index]))
			return 0;		// Returns false since we found a non-digit
	}
	if (inputString[0] == '-' && strlen(inputString) == 1)		// If we only have a negative sign it returns false
		return 0;
	return 1;		// This was a real number 
}

bool isPhoneNumber(char inputString[]){
	// pre:  inputString has been initialized to some string
	// post: if inputString (ignoring any non-digits)is a valid 
	//          phone number (see lab handout for the rules)
	//			then the function will return TRUE (1).
	//          Otherwise it will return FALSE (0)
	
	int index = 0;
	char array[10];		// Sets up a character array to hold the 10 digits of the phone number 
	for (int i = 0; inputString[i]; i ++)
	{
		if (isdigit(inputString[i]))		// If it is a digit 	
		{
			array[index] = inputString[i];		// Add it to the array 
			index ++;		// Go to the next 
		}
	}
	if (index != 10)		// If there are not 10 digits in the array, return false 
		return 0;
	
	
	if (array[0] < '2' || array[3] < '2' || (array[4] == '1' && array[5] =='1'))		// Returns false if the digits don't follow the correct format
		return 0;
	else
		return 1;		// It is a real phone number 
}

void displayPhoneNumber(char inputString[]){
	// pre:	inputString contains a phone number
	// post:the phone number is displayed on cout in the 
	//      form (xxx)xxx-xxxx
	int index = 0;
	char array[10];		// Sets up the character array to hold the 10 digits of the phone number 
	for (int i = 0; inputString[i]; i ++)
	{
		if (isdigit(inputString[i]))		// If it is a digit 	
		{
			array[index] = inputString[i];		// Add it to the array 
			index ++;		// Go to the next 
		}
	}
	cout << "(" << array[0] << array[1] << array[2] << ")" <<		
		array[3] << array[4] << array[5] << "-" <<
		array[6] << array[7] << array[8] << array[9] << endl;		// Prints out the phone number in the correct format
}


int main() {
	char userInput[80];
  
	system("clear");	
	//cout << "Enter some lines of input: (ctrl-d to end)" << endl;
	
	string fileName;
	ifstream inFile;		// Now we can input a file
	int next;
	
	cout << "Enter the name of the input file: ";		// Asks the user for the name of the input file 
	cin >> fileName;

	inFile.open(fileName.c_str());
	if (!inFile)
	{
		cout << "The file was not found." << endl;		// Gives an error if the file cannot be opened 
		return 1;
	}
	inFile.getline(userInput, 80);
	//cin.getline(userInput,80);	// get a line of input
	while (!inFile.eof()){			// as long as user didn't ^D
		bool recognized = false;
		if (isInt(userInput))
		{
			cout << userInput << " is an integer." << endl;
			recognized = true;
		}
		if (isReal(userInput))
		{
			cout << userInput << " is a real number." << endl;
			recognized = true;
		}
		if (isPhoneNumber(userInput))
		{
			cout << userInput << " is the phone number ";
			displayPhoneNumber(userInput);
			cout << endl;
			recognized = true;
		}
		if (!recognized)
			cout << userInput << " is not recognized." << endl;
		cout << "--------------------------------" << endl << endl;	
		inFile.getline(userInput, 80);
		//cin.getline(userInput,80);	// get another line
	}
	return 0;
}

