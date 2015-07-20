// BEGIN CUT HERE
// PROBLEM STATEMENT
// Magical Girl Illy uses "magical strings" to cast spells.
// For her, a string X is magical if and only if there exists a non-negative 
// integer k such that X is composed of k consecutive '>' characters followed by 
// k consecutive '<' characters.
// Note that the empty string is also magical (for k=0).
// 
// Once Illy picked up a string S.
// Each character of S was either '<' or '>'.
// Illy can change S by removing some of its characters.
// (The characters she does not remove will remain in their original order.)
// Illy wants to change S into a magical string by removing as few of its 
// characters as possible.
// 
// You are given the string S.
// Compute and return the length of the magical string Illy will obtain from S.
// 
// DEFINITION
// Class:MagicalStringDiv1
// Method:getLongest
// Parameters:string
// Returns:int
// Method signature:int getLongest(string S)
// 
// 
// CONSTRAINTS
// -S will contain between 1 and 50 characters, inclusive.
// -Each character of S will be '<' or '>'.
// 
// 
// EXAMPLES
// 
// 0)
// "<><><<>"
// 
// Returns: 4
// 
// The longest magical string Illy can produce is ">><<".
// Its length is 4.
// To change S into ">><<", Illy must remove the characters at 0-based indices 0, 
// 2, and 6.
// 
// 1)
// ">>><<<"
// 
// Returns: 6
// 
// S is already a magical string. Therefore Illy doesn't have to remove any 
// character.
// 
// 
// 2)
// "<<<>>>"
// 
// Returns: 0
// 
// Illy has to remove all characters of S.
// 
// 3)
// "<<<<><>>><>>><>><>><>>><<<<>><>>>>><<>>>>><><<<<>>"
// 
// Returns: 24
// 
// 
// 
// END CUT HERE
//#line 69 "MagicalStringDiv1.cpp"
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

class MagicalStringDiv1 {
	public:
	int getLongest(string S)
    {
        int l = 0;                  // >
        int sumL = 0;
        
        int r = S.length() - 1;      // <
        int sumR = 0;
        
        while (l <= r) {
            if (S[l] == '<') {
                S[l] = '.';
            } else if (S[l] == '>') {
                sumL++;
                while (S[r] != '<' && l <= r) {
                    S[r] = '.';
                    r--;
                }
                if (S[r] == '<') {
                    S[r] = '.';
                    sumR++;
                }
            }
            l++;
        }
        
        if (sumL > sumR) {
            sumL--;
        } else if (sumR > sumL) {
            sumR--;
        }
        
        return sumL + sumR;
    }
};
