// BEGIN CUT HERE
// PROBLEM STATEMENT
// John and Brus are studying string theory at the university.  According to 
// Brus, a string is called lucky if no two consecutive characters are equal.  
// John is analyzing a string s, and he wants to know how many distinct lucky 
// strings can be generated by reordering the letters in s.  If s is a lucky 
// string in its original ordering, it should also be considered in the count.
// 
// DEFINITION
// Class:TheLuckyString
// Method:count
// Parameters:string
// Returns:int
// Method signature:int count(string s)
// 
// 
// CONSTRAINTS
// -s will contain between 1 and 10 characters, inclusive.
// -Each character of s will be a lowercase letter ('a' - 'z').
// 
// 
// EXAMPLES
// 
// 0)
// "ab"
// 
// Returns: 2
// 
// Two lucky strings - "ab" and "ba".
// 
// 1)
// "aaab"
// 
// Returns: 0
// 
// It's impossible to construct a lucky string.
// 
// 2)
// "aabbbaa"
// 
// Returns: 1
// 
// "abababa" is the only lucky string that can be generated.
// 
// 3)
// "abcdefghij"
// 
// Returns: 3628800
// 
// END CUT HERE
// 
#line 52 "TheLuckyString.cpp"
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

class TheLuckyString {
	public:
	int count(string s) {
		if (s.size() == 1) return 1; 
		vector<string> result; 
		result = findPermutations(result, "", s);
		return result.size(); 
	}

	private: 
	vector<string> findPermutations(vector<string> list, string word, string remain) {
		if (remain.length() == 0) {
			int L = word.length(); 
			if (word[L - 1] != word[L]) {
				//cout << word << endl; 
				list.push_back(word);
			}
		}

		cout << word << " " << remain << endl; 
		for (int i = 0; i < remain.length(); i++) {
			int L = word.length(); 
			cout << remain[i] << endl; 
			if ((L > 1) && (word[L - 1] != word[L])) {
				cout << word << endl; 
				word += remain[i]; 
				remain = remain.substr(0, i + 1) + remain.substr(i + 1, remain.length() - i - 1);
				list = findPermutations(list, word, remain); 
			}
		}

		return list;
	}
};
