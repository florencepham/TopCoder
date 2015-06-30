// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are the coach of a high school cross country team.  You are hosting a 
// cross country meet at your school this weekend, and you need to be ready to 
// score the meet.  Since it is a bit of a pain to do by hand, especially for 
// large meets, you are going to write a program to do it for you.  Given the 
// number of teams and the order in which the runners finish, determine the order 
// in which each team places.
// Capital letters will represent the teams in finishOrder and in the return 
// value.  The first team is 'A', the second team is 'B', and so on.  The place 
// in which the five fastest runners on a team finish is added together (first 
// place=1, second place=2, etc...), and that is the team's score (a team must 
// have at least five runners finish to place).  Lower scores beat higher scores, 
// and in the event of a tie the sixth fastest runners of each team are compared, 
// and the team whose sixth fastest runner finished earlier wins the tie.  If two 
// teams tie and only one has a sixth runner, that team wins the tie.  If two 
// teams tie and neither has a sixth runner, the team who's letter comes first 
// alphabetically wins the tie.
// You will be given an int, numTeams, which is the number of teams competing, 
// and a string, finishOrder, which is the order in which the runners finish.  
// You are to return a string that lists the teams in the order they placed in 
// the meet.  If a team has fewer than 5 runners finish, do not include it in the 
// return value.
// For example, if finishOrder="AABBABBABBA", then team A's runners finish 1st, 
// 2nd, 5th, 8th, and 11th, for a team score of 27 points.  Team B's runners 
// finish 3rd, 4th, 6th, 7th, 9th, and 10th, for a team score of 29 points 
// (notice that only team B's first 5 runners are scored).  In this case the 
// return value would be "AB".
// 
// DEFINITION
// Class:CrossCountry
// Method:scoreMeet
// Parameters:int, string
// Returns:string
// Method signature:string scoreMeet(int numTeams, string finishOrder)
// 
// 
// NOTES
// -If a team has fewer than 5 runners finish, don't remove that team's runners 
// from finishOrder before calculating the score of the other teams.
// 
// 
// CONSTRAINTS
// -numTeams will be between 2 and 10, inclusive.
// -finishOrder will be between 10 and 50 characters, inclusive.
// -finishOrder will contain only the first numTeams capital letters ('A','B',...).
// -finishOrder will not contain more than seven occurrences of the same character.
// 
// 
// EXAMPLES
// 
// 0)
// 2
// "AABBABBABBA"
// 
// Returns: "AB"
// 
// The example from above.
// 
// 1)
// 3
// "CCCBBBBBAAACC"
// 
// Returns: "BC"
// 
// In this case team A does not qualify because only 3 of its runners finish.  
// Team B beats team C with a score of 30-31.  Remember not to remove team A's 
// runners, doing this would have team C win over team B with a score of 25-30.
// 
// 2)
// 4
// "ABDCBADBDCCDBCDBCAAAC"
// 
// Returns: "BDCA"
// 
// 3)
// 10
// "BDHCEAJBIDBCCHGCBDJEBAAHEGAGGADHGIECJEHAEBDADJCDHG"
// 
// Returns: "BCDAHEG"
// 
// 4)
// 3
// "BABCAABABAB"
// 
// Returns: "AB"
// 
// END CUT HERE
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath> 
#include <map> 
#include <queue> 
#include <stack> 

class CrossCountry {
	public:
	string scoreMeet(int numTeams, string finishOrder)
    	{
		map<char, int> numRunner; 
		map<char, int> points; 
		vector<char> teams; 

		for (int i = 0; i < stringOrder.length(); i++) {
			char team = finishOrder[i]; 
			int points = i + 1; 
			if (points[team] == 0) {
				teams.push_back(team);
			}

			numRunner[team]++; 
			points[team]++; 
		}

		string result = sortString(numTeams, teams, points, numRunner);

		return result; 
	}

	private: 
	string sortString(map<char, int> numRunner, vector<char> teams, map<char, int> points, map<char, int> numRunner) 
	{
		string result = static_cast<string>(teams[0]); 

		for (int i = 1; i < teams.size(); i++) {
			char newTeam = teams[i]; 
			char newPoint = points[newTeam];
			if (numRunner[newTeam] >= 5) {
				int pos = 0; 
				while (pos < result.length()) {
					char curTeam = result[pos];
					char curPoint = points[curTeam];
					if (newPoint < curPoint) {
						result.insert(pos, 1, newTeam);
						break;
					}
					pos++;
				}
			}
		}

		return result; 
	}

};
