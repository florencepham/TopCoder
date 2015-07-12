// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are given a string code and vector <int>s position and length.  code 
// contains an encoded string which you must decode using the following method.  
// Step through the elements of position in order, and for each element i, take 
// the substring of length length[i] at position position[i].  Insert the reverse 
// of that substring before position position[i]+length[i], thereby creating a 
// palindromic substring.  All positions are 0-based.  Return the decoded string.
// 
// DEFINITION
// Class:PalindromeDecoding
// Method:decode
// Parameters:string, vector <int>, vector <int>
// Returns:string
// Method signature:string decode(string code, vector <int> position, vector 
// <int> length)
// 
// 
// CONSTRAINTS
// -code will contain between 1 and 10 characters, inclusive.
// -code will contain only digits ('0'-'9') and letters ('a'-'z', 'A'-'Z').
// -position will contain between 0 and 10 elements, inclusive.
// -length will contain the same number of elements as position.
// -position and length will always refer to a valid substring in the (partially 
// decoded) string code.
// -Each element of length will be positive.
// -The return value will have at most 1000 characters.
// 
// 
// EXAMPLES
// 
// 0)
// "ab"
// {0}
// {2}
// 
// Returns: "abba"
// 
// The decoding step selects the whole string and appends it in reversed form.
// 
// 1)
// "Misip"
// {2,3,1,7}
// {1,1,2,2}
// 
// Returns: "Mississippi"
// 
// The decoding steps are: "Misip" -> "Missip" -> "Misssip" -> "Mississip" -> 
// "Mississippi"
// 
// 2)
// "XY"
// {0, 0, 0, 0}
// {2, 4, 8, 16}
// 
// Returns: "XYYXXYYXXYYXXYYXXYYXXYYXXYYXXYYX"
// 
// In this example the length of the string doubles in each decoding step.
// 
// 3)
// "TC206"
// {1,2,5}
// {1,1,1}
// 
// Returns: "TCCC2006"
// 
// 
// 
// 4)
// "nodecoding"
// {}
// {}
// 
// Returns: "nodecoding"
// 
// 
// 
// END CUT HERE
//#line 80 "PalindromeDecoding.cpp"
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

class PalindromeDecoding {
	public:
	string decode(string code, vector <int> position, vector <int> length)
    {
        int N = position.size();
        for (int i = 0; i < N; i++) {
            int pos = position[i];
            int len = length[i];
            int newPos = pos + len;
            string substring = code.substr(pos, len);
            reverse(substring.begin(), substring.end());
            code.insert(newPos, substring);
        }
        
        return code;
	}
};
