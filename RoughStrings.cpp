// BEGIN CUT HERE
// PROBLEM STATEMENT
// Given a string s, its roughness is calculated as follows:  Let c1 be the 
// letter that appears most frequently in s, and let c2 be the letter that 
// appears least frequently (c2 must appear at least once).  The roughness of s 
// is the number of occurrences of c1 minus the number of occurrences of c2.
// 
// You are allowed to modify s by erasing between 0 and n characters, inclusive 
// (see example 1 for clarification).  Return the minimum possible roughness that 
// can be achieved by such a modification.
// 
// DEFINITION
// Class:RoughStrings
// Method:minRoughness
// Parameters:string, int
// Returns:int
// Method signature:int minRoughness(string s, int n)
// 
// 
// CONSTRAINTS
// -s will contain between 1 and 50 characters, inclusive.
// -s will contain only lowercase letters ('a'-'z').
// -n will be between 0 and m-1, inclusive, where m is the number of characters 
// in s.
// 
// 
// EXAMPLES
// 
// 0)
// "aaaaabbc"
// 1
// 
// Returns: 3
// 
// We may remove one 'a' or one 'c' to obtain the minimal roughness of 3.
// 
// 1)
// "aaaabbbbc"
// 5
// 
// Returns: 0
// 
// One of the ways is to remove 'c' and all occurrences of 'a'.
// 
// 2)
// "veryeviltestcase"
// 1
// 
// Returns: 2
// 
// 
// 
// 3)
// "gggggggooooooodddddddllllllluuuuuuuccckkk"
// 5
// 
// Returns: 3
// 
// 
// 
// 4)
// "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz"
// 17
// 
// Returns: 0
// 
// 
// 
// 5)
// "bbbccca"
// 2
// 
// Returns: 0
// 
// Sometimes you may want to remove less than n characters.
// 
// END CUT HERE
#line 79 "RoughStrings.cpp"
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

class RoughStrings {
	public:
	int minRoughness(string s, int n) {
		
	}
};
