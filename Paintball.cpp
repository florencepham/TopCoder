// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// For his birthday, Bart received the brand new video game "Paintball!".  In 
// this game, a person plays on teams over the Internet against various 
// competitors, attempting to hit their opponents with paint balls.  Each player 
// earns a point each time that they "splatter" an opponent with a paintball, and 
// lose a point for each time they get "splattered".  Due to the way that the 
// game is played, it is also possible to accidentally splatter yourself or a 
// teammate.  In that case, the shooter loses a point, and the person who was 
// splattered (if not the shooter) does not lose any points.  A team's score is 
// simply the sum of the scores of its players.
// 
// Although Bart loves the game, he is disappointed that the game does not 
// provide a leaderboard during gameplay.  However, it does provide the list of 
// players, formatted as "NAME TEAM" (where NAME is the player's name, and TEAM 
// is his team), and a series of messages, each formatted as "NAME1 SPLATTERED 
// NAME2" (all quotes for clarity), where NAME1 indicates the name of the person 
// who shot the paintball, and NAME2 indicates the name of the person who got 
// splattered.  Bart would like to have an updated scoreboard, and that is where 
// you come in.
// 
// All teams will receive a rank number from 1 to M (the total number of teams), 
// based on the team scores (with 1 corresponding to the highest score).  If 
// multiple teams have the same score, then the team with the name that comes 
// first alphabetically will receive a lower rank number.  For each team (in 
// order from 1 to M), its leaderboard entry will be formatted as follows:
// 
// The first line will be "TEAM SCORE" (quotes for clarity), where TEAM is the 
// team name, and SCORE is the team score (with no extra leading zeroes).
// Let N be the number of players on the team.  Assign rank numbers to the N 
// players from 1 to N, giving a lower rank number to a higher score.  If 
// multiple players have the same score, assign the player whose name comes first 
// alphabetically to the lower rank number.
// From the player with rank 1 to rank N, output a line with 2 spaces, the 
// player's name, a single space, and then the player's score (with no extra 
// leading zeroes).  
// 
// Thus, if player A from team RED splatters player B from team BLUE (and they 
// are the only players in the game), the leaderboard will be:
// 
// RED 1
//   A 1
// BLUE -1
//   B -1
// 
// You are to generate the leaderboard and return it.
// 
// 
// DEFINITION
// Class:Paintball
// Method:getLeaderboard
// Parameters:vector <string>, vector <string>
// Returns:vector <string>
// Method signature:vector <string> getLeaderboard(vector <string> players, 
// vector <string> messages)
// 
// 
// NOTES
// -A SCORE of 0 should be output as 0, not as -0.
// 
// 
// CONSTRAINTS
// -players will contain between 1 and 50 elements, inclusive.
// -Each element of players will contain between 3 and 50 characters, inclusive.
// -Each element of players will be formatted as "NAME TEAM" (quotes for clarity).
// -In each element of players, NAME will consist of uppercase characters 
// ('A'-'Z') and will contain at least 1 character.
// -There will be no duplicate NAMEs in players.
// -In each element of players, TEAM will consist of uppercase characters 
// ('A'-'Z') and will contain at least 1 character.
// -messages will contain between 1 and 50 elements, inclusive.
// -Each element of messages will contain between 14 and 50 characters, inclusive.
// -Each element of messages will be formatted as described in the problem 
// statement.
// -In each element of messages, NAME1 and NAME2 will be NAMEs found in players.
// 
// 
// EXAMPLES
// 
// 0)
// {"A RED", "B BLUE"}
// {"A SPLATTERED B"}
// 
// Returns: {"RED 1", "  A 1", "BLUE -1", "  B -1" }
// 
// The example from the statement.
// 
// 1)
// {"LISA RED", "BART RED", "HOMER BLUE", "MARGE BLUE", "MAGGIE GREEN"}
// {"MAGGIE SPLATTERED HOMER", "MAGGIE SPLATTERED MARGE"}
// 
// Returns: {"GREEN 2", "  MAGGIE 2", "RED 0", "  BART 0", "  LISA 0", "BLUE -2", 
// "  HOMER -1", "  MARGE -1" }
// 
// 
// 
// 2)
// {"TODD STRIKEFORCE",
//  "BART OMEGA",
//  "DATA STRIKEFORCE",
//  "MILHOUSE OMEGA",
//  "NELSON DISCOVERYCHANNEL",
//  "MARTIN DISCOVERYCHANNEL"}
// {"BART SPLATTERED MARTIN","TODD SPLATTERED MARTIN"}
// 
// Returns: {"OMEGA 1", "  BART 1", "  MILHOUSE 0", "STRIKEFORCE 1", "  TODD 1", 
// "  DATA 0", "DISCOVERYCHANNEL -2", "  NELSON 0", "  MARTIN -2" }
// 
// 
// 
// 3)
// {"DR COHO", "ST COHO", "PE COHO"}
// {"DR SPLATTERED ST",
//  "ST SPLATTERED PE"}
// 
// Returns: {"COHO -2", "  PE 0", "  DR -1", "  ST -1" }
// 
// Don't shoot your teammates!
// 
// 4)
// {"A B", "AA AA", "AAA AAA"}
// {"A SPLATTERED AAA", "A SPLATTERED AAA", "A SPLATTERED AAA", 
// "AA SPLATTERED AAA", "AA SPLATTERED AAA"}
// 
// Returns: {"B 3", "  A 3", "AA 2", "  AA 2", "AAA -5", "  AAA -5" }
// 
// 
// 
// END CUT HERE
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> 
#include <map> 
#include <queue> 
#include <stack> 

using namespace std; 

typedef vector<string> VS 

class Paintball {
	public:
	vector <string> getLeaderboard(vector <string> players, vector <string> messages) 
	{
		map <string, string> playerToTeam = parsePlayer(players); 
		map <string, int> playerScore; 
		map <string, VS> teams = parseTeam(players); 

		for (int i = 0; i < messages.size(); i++) {
			string mesg = messages[i]; 
			int pos = 0; 
			string attacker = ""; 
			while (mesg[pos] != ' ') {
				attack += mesg[pos];
			}

			pos += 12; 
			string attackee = mesg.substr(pos, mesg.length() - pos); 

			string teamAttacker = playerToTeam[attacker];
			string teamAttackee = playerToTeam[attackee]; 

			if (teamAttacker == teamAttackee) {
				playerScore[attacker]--; 
				playerScore[attackee]++; 
			} else {
				playerScore[attacker]++; 
				playerScore[attackee]--; 
			}
		}

		for (int i = 0; i < )



	}
};
