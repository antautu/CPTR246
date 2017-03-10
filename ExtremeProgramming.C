/**********************************************
* Program:  ExtremeProgramming.C              *
* Author:   Eileen Peluso                     *
* Date:     01/04/02                          *
*                                             *
* Abstract: Driver program for Team.h class   *
*           DO NOT MODIFY THIS PROGRAM        *
**********************************************/
#include <iostream>			// needed for cin and cout
#include "Team.h"			// pulls in our class definition
#include <cstdlib>			// needed for the "system" command

using namespace std;

int main() {

   Team myTeam("Extreme Programming");		// define an object of the Team class
   string playerName;				// needed to get input from user

   // Get the names of the team members
   system("clear");				// this is how we clear the screen
   cout << "Enter the name of a player to be added to the team (ctrl-d to end): ";
   getline(cin, playerName);	// primal extraction
   					// this is how we get a whole line from the keyboard
   					//   when it contains spaces and we want to put it
            				//   into a string object
   while (!cin.eof()){			// while the user has not hit ctrl-d when asked for input
	myTeam.AddAPlayer(playerName);		// add that player to the team
	cout << "Enter the name of a player to be added to the team (ctrl-d to end): ";
	getline(cin, playerName);		// bottom extraction
   }

	// Get the win/loss record
   int numberOfGames = 0;		// counter for the for loop that gets the win/loss record
   char WorL;				// character object to get user input
   cout << endl << endl << "Enter the number of games played: ";
   cin.clear();				// Why do we need this?  We'll learn in a couple ofweeks.
   cin >> numberOfGames;		// Get the number of games played
   for (int i = 1; i <= numberOfGames; i++){		// for each game, find out if
      							//    it was a win or a loss
      cout << endl << "Did you win (W) or lose (L) game " << i << "? ";
      cin >> WorL;
      WorL = toupper(WorL);	// convert to uppercase to save yourself some coding
      while (!(WorL == 'W' || WorL == 'L')){		// force the user to enter a W or L
         cout << "You must enter a W or L.  Try again: ";
         cout << endl << "Did you win (W) or lose (L) game " << i << "? ";
         cin >> WorL;
         WorL = toupper(WorL);
      }
      if (WorL == 'W')			// register the game as a win or loss
         myTeam.GamePlayed(1);
      else
         myTeam.GamePlayed(0);
   }

   // Display the team information
   cout << endl << endl;
   myTeam.DisplayRoster();		// display the team roster
   					// display the win/loss percentage
   cout << "You won " << myTeam.PercentageWon() * 100.0 << "% of your games." << endl;

   // Test out the OnTeam function
   cout << endl << "Enter a name of someone on the team just as it appears: ";
   cin.ignore(80, '\n');		// Why do we need this?  We'll learn in a couple of weeks
   getline(cin, playerName);
   if (myTeam.OnTeam(playerName))	// Notice how the Boolean function is used
      cout << "OK ... that's working!" << endl;
   else
      cout << "Oops ... that's not working!" << endl;

   cout << endl << "Enter a name of someone NOT on the team: ";
   getline(cin, playerName);
   if (!myTeam.OnTeam(playerName))
      cout << "OK ... that's working!" << endl;
   else
      cout << "Oops ... that's not working!" << endl;


   return 0;
}


