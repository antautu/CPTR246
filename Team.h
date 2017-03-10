/*************************************************
*    Team.h                                      *
*                                                *
*    Author:  Autumn Anthony                     *
*    Date:    01/18/2017                         *
*    Abstract:  Team class for CPTR 246 Lab 1    *
*************************************************/
#include <string>

using namespace std;

#ifndef _TEAM_H
#define _TEAM_H

class Team{
  public:
    Team(string whichSport);
         // .... see below
    void AddAPlayer(string newName);
         // .... see below
    void GamePlayed(bool won);
         // .... see below
    double PercentageWon();
         // .... see below
    bool OnTeam(string person);
         // .... see below
    void DisplayRoster();
         // .... see below
private:
    string sport;           	// which sport, e.g. football, soccer, etc.
    int wins;            	 	// total number of wins so far
    int losses;		 			// total number of losses so far
    int numberOfPlayers;		// the number of players on the team
    string names[60];      	// names of the team members
};


Team::Team (string nameOfSport){
// Intent:  Constructor
// Pre:   "which sport" is provided as parameter
// Post:  data members initialized properly

	sport = nameOfSport;
	wins = 0;
	losses = 0;
	numberOfPlayers = 0;

}

void Team::AddAPlayer(string newPlayer){
// Intent: To add a new player to the team.
// Pre: newPlayer is the player's name.
// Post: data members updated properly

	names[numberOfPlayers] = newPlayer; // Adds a new player to the array
	numberOfPlayers ++; 			    // Increments the number of players

}

void Team::GamePlayed(bool won){
// Intent: to update the number of wins or number of losses
// pre: "won" is either true (1) or false (0)
// post: increments the number of wins if "won" is true (1)
//			otherwise increments the number of losses

	if (won == 1) 		// Use 1 as value for true
		wins ++;  		// Increments number of wins
	else
		losses ++; 		// Increments number of losses

}

double Team::PercentageWon(){
// Intent: To determine the percentage of games won
// pre: none
// post: returns the ratio of games won to games played (assume that there
//			is no such thing as a tie!)

	double ratio = wins/(double)(wins + losses); // Casts as a double to allow percentage to be calculated
	return ratio;	

}

bool Team::OnTeam (string person){
// Intent: To determine if a particular person is on the team
// pre: none
// post: returns true (1) if "person" is on the team, false (0) otherwise

bool person_tf = false;				// Creates a person as false
	for (int i = 0; i <= numberOfPlayers; i++)
	{
		if(names[i] == person)
			return person_tf = true;	// If the person is on the team the new person_tf is returned true
	}
	return person_tf;
}

void Team::DisplayRoster (){
// Intent: To display the names of the team member on the screen
// pre: none
// post: displays the team roster on the screen

	for(int i = 0; i <= numberOfPlayers; i++)
	{
		cout << names[i] << endl;	// Prints the team roster to the screen
	}

}
   

#endif


