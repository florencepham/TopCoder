// BEGIN CUT HERE
// PROBLEM STATEMENT
// Three players are playing a game of word composition in which each player 
// writes down a list of words. After the time expires the scores are calculated 
// using the following rules. Each player gains 3 points for each unique word 
// that only he has, 2 points for each word that is shared with exactly one other 
// player, and 1 point for each word that is shared with both of the other players.
// You will be given vector <string>s listA, listB and listC - the word lists of 
// playerA, playerB and playerC respectively. Your method should return scores of 
// playerA, playerB and playerC in the form "scoreA/scoreB/scoreC" (quotes for 
// clarity).
// 
// 
// DEFINITION
// Class:WordCompositionGame
// Method:score
// Parameters:vector <string>, vector <string>, vector <string>
// Returns:string
// Method signature:string score(vector <string> listA, vector <string> listB, 
// vector <string> listC)
// 
// 
// CONSTRAINTS
// -listA, listB and listC will have between 1 and 50 elements each, inclusive.
// -Each element of listA, listB and listC will contain between 1 and 20 
// characters, inclusive.
// -Each element of listA, listB and listC will contain only lowercase letters 
// ('a'-'z').
// -All elements in listA will be distinct.
// -All elements in listB will be distinct.
// -All elements in listC will be distinct.
// 
// 
// EXAMPLES
// 
// 0)
// {"cat", "dog", "pig", "mouse"}
// {"cat", "pig"}
// {"dog", "cat"}
// 
// Returns: "8/3/3"
// 
// 1)
// {"mouse"}
// {"cat", "pig"}
// {"dog", "cat"}
// 
// Returns: "3/5/5"
// 
// 2)
// {"dog", "mouse"}
// {"dog", "pig"}
// {"dog", "cat"}
// 
// Returns: "4/4/4"
// 
// 3)
// {"bcdbb","aaccd","dacbc","bcbda","cdedc","bbaaa","aecae"}
// {"bcdbb","ddacb","aaccd","adcab","edbee","aecae","bcbda"}
// {"dcaab","aadbe","bbaaa","ebeec","eaecb","bcbba","aecae","adcab","bcbda"}
// 
// Returns: "14/14/21"
// 
// END CUT HERE
#line 66 "WordCompositionGame.cpp"
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

class WordCompositionGame {
	public:
	string score(vector <string> listA, vector <string> listB, vector <string> listC) {
		map<string, int> numWords; 
		numWords = hashWord(listA, numWords); 
		numWords = hashWord(listB, numWords); 
		numWords = hashWord(listC, numWords); 

		int A = score(listA, numWords); 
		int B = score(listB, numWords); 
		int C = score(listC, numWords); 

		return to_string(A) + "/" + to_string(B) + "/" + to_string(C); 
	}

	private: 
	map<string, int> hashWord(vector<string> list, map<string, int> numWords) {
		int L = list.size(); 
		for (int i = 0; i < L; i++) {
			string word = list[i]; 
			if (numWords.count(word) == 0) {
				numWords[word] = 1; 
			} else {
				numWords[word]++; 
			}
		}
		return numWords; 
	} 

	int score(vector<string> list, map<string, int> numWords) {
		int S = 0; 
		int L = list.size(); 
		for (int i = 0; i < L; i++) {
			int n = numWords[list[i]]; 
			switch(n){ 
				case 1: S+=3; break; 
				case 2: S+=2; break;
				case 3: S+=1; break;
			}
		}
		return S; 
	}
};
