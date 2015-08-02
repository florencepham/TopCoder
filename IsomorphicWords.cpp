// BEGIN CUT HERE
// PROBLEM STATEMENT
// Two words are called isomorphic if the letters in one word can be remapped to 
// get the second word.  Remapping a letter means replacing all occurrences of it 
// with another letter. The ordering of the letters remains unchanged. No two 
// letters may map to the same letter, but a letter may map to itself.
// 
// For example, the words "abca" and "zbxz" are isomorphic because we can map 'a' 
// to 'z', 'b' to 'b' and 'c' to 'x'.
// 
// Given a vector <string> words, return how many (unordered) pairs of words are 
// isomorphic.
// 
// 
// DEFINITION
// Class:IsomorphicWords
// Method:countPairs
// Parameters:vector <string>
// Returns:int
// Method signature:int countPairs(vector <string> words)
// 
// 
// CONSTRAINTS
// -words will contain between 2 and 50 elements, inclusive.
// -Each element of words will contain between 1 and 50 lowercase letters 
// ('a'-'z'), inclusive.
// -All elements of words will have the same length.
// -There will be no duplicates in words.
// 
// 
// EXAMPLES
// 
// 0)
// {"abca", "zbxz", "opqr"}
// 
// Returns: 1
// 
// "abca" and "zbxz" are isomorphic, but none of the two is isomorphic with "opqr".
// 
// 1)
// {"aa", "ab", "bb", "cc", "cd"}
// 
// Returns: 4
// 
// The four isomorphic pairs are {"aa", "bb"}, {"aa", "cc"}, {"bb", "cc"} and 
// {"ab", "cd"}.
// 
// 2)
// { "cacccdaabc", "cdcccaddbc", "dcdddbccad", "bdbbbaddcb",
//   "bdbcadbbdc", "abaadcbbda", "babcdabbac", "cacdbaccad",
//   "dcddabccad", "cacccbaadb", "bbcdcbcbdd", "bcbadcbbca" }
// 
// Returns: 13
// 
// 
// 
// END CUT HERE
#line 59 "IsomorphicWords.cpp"
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

class IsomorphicWords {
	public:
	int countPairs(vector <string> words) {
		int pairs = 0; 
		int N = words.size();
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				pairs += min(isPairs(words[i], words[j]), isPairs(words[j], words[i]));
			}
		}
		return pairs; 
	}

	private: 
	int isPairs(string A, string B) {
		if (A.length() != B.length()) return 0; 
		map<char, char> Map; 

		for (int i = 0; i < A.length(); i++) {
			char a = A[i]; 
			char b = B[i]; 
			if (Map.count(a) == 0) Map[a] = b; 
			else if (Map[a] != b) return 0; 
		}
		return 1; 
	}
};
