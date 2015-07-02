// BEGIN CUT HERE
// PROBLEM STATEMENT
// Alice and Bob play the following game. 
// The game board consists of some cells in a row. 
// Each cell is marked either 'A' or 'B'. 
// At the beginning, there are no coins placed on the board – all the cells are 
// empty. 
// Alice and Bob take alternating turns. 
// Alice plays first. 
// In each turn, the current player chooses some contiguous empty cells and 
// places a coin onto each of the chosen cells. 
// The player must always choose at least one cell. 
// The player must never choose all empty cells. 
// In other words, after each turn there must be at least one empty cell. 
// 
// The following picture shows two examples of placing coins: 
// 
// 
// 
// The game ends when there is only one cell left without a coin. 
// If that cell is marked 'A', Alice wins. 
// Otherwise, Bob wins. 
// You are given a string cells representing the row of cells. 
// Assuming that both players aim to win and play optimally, return a string 
// containing the name of the winner. 
// 
// 
// DEFINITION
// Class:RowAndCoins
// Method:getWinner
// Parameters:string
// Returns:string
// Method signature:string getWinner(string cells)
// 
// 
// CONSTRAINTS
// -cells will contain between 2 and 14 characters, inclusive. 
// -Each character in cells will be either 'A' or 'B'. 
// 
// 
// EXAMPLES
// 
// 0)
// "ABBB"
// 
// Returns: "Alice"
// 
// Alice can win by placing coins on three cells marked 'B' in her first turn. 
// 
// 
// 1)
// "BBBB"
// 
// Returns: "Bob"
// 
// 2)
// "BA"
// 
// Returns: "Alice"
// 
// 
// 
// 3)
// "BABBABBB"
// 
// Returns: "Bob"
// 
// 4)
// "ABABBBABAABBAA"
// 
// Returns: "Alice"
// 
// 
// 
// 5)
// "BBBAAABBAAABBB"
// 
// Returns: "Bob"
// 
// 
// 
// END CUT HERE
//#line 84 "RowAndCoins.cpp"
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

class RowAndCoins {
	public:
	string getWinner(string cells) 
	{
		int N = cells.length(); 
		bool marked[N]; 
		for (int i = 0; i < N; i++) {
			marked[i] = false; 
		}

		while (N > 1) {
			N -= removeChar(cells, 'B', marked, N);
			if (N == 1) break; 

			N -= removeChar(cells, 'A', marked, N);
			if (N == 1) break;
		}

		int i; 
		for (i = 0; i < cells.size(); i++) {
			if (marked[i] == false) break;  
		}

		if (cells[i] == 'A') return "Alice";
		else return "Bob";
	}

	private: 
	int removeChar(string cells, char c, bool marked[], int N) 
	{
		int longest = 0; 
		int start = 0; 

		for (int i = 0; i < cells.length(); i++) {
			if (marked[i] == false && cells[i] == c) {
				int l = 1; 
				for (int j = i + 1; j < cells.length(); j++) {
					if (cells[j] != c) break; 
					l++;
				}

				if (l > longest) {
					longest = l; 
					start = i;
				} 
			}
		}

		for (int i = start; i < start + longest; i++) {
			marked[i] = true; 
		}

		if (longest == N) {
			marked[start] = false; 
			return longest - 1; 
		}

		return longest; 
	}
};
