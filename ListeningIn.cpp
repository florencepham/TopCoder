// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are creating an online multiplayer cooperative game. Players on a team may 
// chat with each other during the game, and you intend to take advantage of this 
// when building the AI to handle opponents. Part of the AI includes determining 
// whether a given phrase is part of a player's chat. Of course, many variations 
// of a given phrase are possible, and you want to detect as many as you can. 
// Shorthand is the most common example: instead of typing 'capture', a player 
// might type 'cptr', or 'port to me' instead of 'teleport to me'. You will be 
// provided with a string typed typed by a player and a phrase that you wish to 
// check against. Return the characters removed from phrase to obtain typed in 
// the order they appear in phrase or "UNMATCHED" if there is no way to obtain 
// typed from phrase by simply removing characters. The constraints ensure that 
// the return is unique (there is only one option for which string is returned).
// 
// DEFINITION
// Class:ListeningIn
// Method:probableMatch
// Parameters:string, string
// Returns:string
// Method signature:string probableMatch(string typed, string phrase)
// 
// 
// CONSTRAINTS
// -typed and phrase will contain only lowercase letters ('a'-'z') and spaces
// -typed and phrase will be between 1 and 50 characters long, inclusive.
// -All valid groups of characters that could be removed to turn phrase into 
// typed will give the same output.
// 
// 
// EXAMPLES
// 
// 0)
// "cptr"
// "capture"
// 
// Returns: "aue"
// 
// The example given in the problem statement.
// 
// 1)
// "port to me"
// "teleport to me"
// 
// Returns: "tele"
// 
// The other example from the statement.
// 
// 2)
// "back  to base"
// "back to base"
// 
// Returns: "UNMATCHED"
// 
// An extra space has been added; we do not account for additions, only deletions.
// 
// END CUT HERE
#line 59 "ListeningIn.cpp"
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

class ListeningIn {
	public:
	string probableMatch(string typed, string phrase) 
	{
		string removed = ""; 
		return findString(typed, phrase, removed); 
	}

	private: 
	string findString(string typed, string phrase, string removed) {
		if (typed == "") {
			return removed + phrase; 
		} else if (phrase == "") {
			return "UNMATCHED"; 
		}

		if (typed[0] != phrase[0]) {
			removed += phrase[0]; 
			return findString(typed, phrase.substr(1), removed); 
		} else {
			return findString(typed.substr(1), phrase.substr(1), removed); 
		} 
	}
};
