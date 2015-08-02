// BEGIN CUT HERE
// PROBLEM STATEMENT
// Given a sequence of uppercase letters, we want to remove all but one 
// occurrence of each
// letter, doing it in such a way that the
// remaining letters are in alphabetical order.  Of course, there may be no way to 
// do this, but if there is, we want to know which letters to remove.
// 
// Create a class MakeUnique that contains a method eliminated that is given a
// string original, and returns original with the
// eliminated letters replaced with periods ('.'). The remaining letters must 
// be in alphabetical order.
// 
// If there is no way to do this, return a string with length 0.
// 
// If there are several ways to do this, choose the one with the shortest length
// between the first and last remaining letters. If there are still several ways,
// return the string among these that comes earliest lexicographically ('.' comes 
// earlier than any letter in the ASCII sequence).
// 
// 
// 
// 
// DEFINITION
// Class:MakeUnique
// Method:eliminated
// Parameters:string
// Returns:string
// Method signature:string eliminated(string original)
// 
// 
// CONSTRAINTS
// -original will contain between 1 and 50 characters inclusive
// -each character in original will be an uppercase letter 'A'-'Z'
// 
// 
// EXAMPLES
// 
// 0)
// "ABBBXCXABCX"
// 
// Returns: ".......ABCX"
// 
// 
// 
//     The 4 letters ABCX must remain, and in that order. "AB...CX...." would 
// also leave these letters in the
// appropriate order,
// but the length between the first and last remaining letters
//     would be longer than in the given answer.
// 
// 
// 1)
// "ABBBXCXABCB"
// 
// Returns: "A..B.CX...."
// 
// 
//     "AB...CX...." and "A.B..CX...." are also possible and have the same
//     length between first and last remaining letters, but they come later
//     lexicographically than the given answer.
// 
// 
// 2)
// "ABBBXCABCB"
// 
// Returns: ""
// 
// 
// 
//     There is no way to eliminate letters and end up with C before X.
// 
// 3)
// "AABACBXABX"
// 
// Returns: ".AB.C.X..."
// 
//        
// 
// 4)
// "CABDEAFDEGSDABCDEADFGSEFBGS"
// 
// Returns: "............ABCDE..FGS....."
// 
// 5)
// "AAAAAA"
// 
// Returns: ".....A"
// 
// END CUT HERE
//#line 92 "MakeUnique.cpp"
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

class MakeUnique {
	public:
	string eliminated(string original) 
	{
		vector <char> C = putChar(original); 
		string smallest = original; 
		int L = original.size(); 

		// iterate through the original to find the ocurrence of lastChar; 
		for (int i = original.size() - 1; i >= 0; i--) {
			if (original[i] != C.end()) {
				continue; 
			}
			string temp = original; 
			int c = C.size() - 2; 
			int pos = i; 
			int l; 
			while (pos >= 0) {
				if (temp[pos] == C[c]) {
					c--; 
				} else if (temp[pos] == C[0]) {
					l = i - pos; 
					if (l < L) {
						for (int j = i)
					}
				} else {
					temp[pos] = '.';
				}
				pos--; 
			}
		}
	}
};
