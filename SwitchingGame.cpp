// BEGIN CUT HERE
// PROBLEM STATEMENT
// You're playing a game with lamps.
// There are M lamps in a row.
// The lamps are numbered 0 through M-1.
// Initially, all lamps are turned off.
// 
// The game consists of N levels.
// The levels are numbered 0 through N-1.
// Each level is described by a string of M characters.
// For each i, character i of that string gives the required state of lamp i.
// Each of these characters will be either '+', '-', or '?'.
// Here, '+' means that the lamp must be on, '-' means that the lamp must be off, 
// and '?' means that the lamp may be in either state.
// 
// The game is played in turns.
// Each turn takes one second.
// In each turn, you may do one of three things:
// 
// You may choose any subset of lamps that are all turned off, and turn all of 
// them on.
// You may choose any subset of lamps that are all turned on, and turn all of 
// them off.
// You may press the big red button that says "Check!".
// 
// Whenever you press the button, the current states of all lamps are checked 
// against the requirements of the current level.
// If all lamps satisfy the requirements, you solved the current level.
// You win the game by solving all N levels.
// You must solve the levels in the given order, starting with level 0.
// Note that the lamps do not reset between levels: you continue playing the next 
// level from the state you had when you solved the previous level.
// 
// Return the smallest number of seconds it takes to win the game if you play 
// optimally.
// 
// 
// DEFINITION
// Class:SwitchingGame
// Method:timeToWin
// Parameters:vector <string>
// Returns:int
// Method signature:int timeToWin(vector <string> states)
// 
// 
// CONSTRAINTS
// -states will contain exactly N elements.
// -N will be between 1 and 50, inclusive.
// -Each element of states will contain exactly M characters.
// -M will be between 1 and 50, inclusive.
// -Each character of states will be '+', '-' or '?'.
// 
// 
// EXAMPLES
// 
// 0)
// {"++--",
//  "--++"}
// 
// Returns: 5
// 
// The following sequence of actions wins the game in five seconds:
// 
// Turn lamps 0 and 1 on.
// Press the button to win level 0.
// Turn lamps 0 and 1 off.
// Turn lamps 2 and 3 on.
// Press the button to win level 1 and thus win the game.
// 
// 
// 1)
// {"+-++",
//  "+-++"}
// 
// Returns: 3
// 
// Each time you press the button you can only win a single level.
// Even though levels 0 and 1 are identical, you have to press the button twice 
// in a row to win both of them.
// 
// 
// 2)
// {"++",
//  "+?",
//  "?+",
//  "++"}
// 
// Returns: 5
// 
// Here we can simply turn both lamps on, and then use that configuration to win 
// all four levels.
// 
// 3)
// {"+", 
//  "?",
//  "?",
//  "?",
//  "-"}
// 
// Returns: 7
// 
// At some point between winning level 0 and winning level 4 we have to turn the 
// lamp off.
// 
// 4)
// {"+??+++",
//  "++??+-",
//  "?++??+",
//  "?-+-??",
//  "??+?++",
//  "++-?+?",
//  "?++?-+",
//  "?--+++",
//  "-??-?+"}
// 
// 
// Returns: 20
// 
// 
// 
// END CUT HERE
#line 123 "SwitchingGame.cpp"
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

class SwitchingGame {
	public:
	int timeToWin(vector <string> states) 
	{
		int M = 0; 	// numMoves
		string curState(states[0].length(), '-'); 
		bool turnOn = false; 
		bool turnOff = false; 

		// iterate through all levels
		for (int l = 0; l < states.size(); l++) {
			for (int j = 0; j < curState.length(); j++) {
				// iterate through future level
				int i = l; 

				while(i < states.size() && states[i][j] == '?') {
					i++; 
				}
				if (i >= states.size()) i = l; 

				// record what has been turned 
				if (states[i][j] == '+' && curState[j] == '-') {
					turnOn = true; 
					curState[j] = states[i][j]; 
				} else if (states[i][j] == '-' && curState[j] == '+') {
					turnOff = true;  
					curState[j] = states[i][j]; 
				}
			}
			if (turnOn == true) M++; turnOn = false;
			if (turnOff == true) M++; turnOff = false;
			M++; 
		}
		return M; 
	}
};
