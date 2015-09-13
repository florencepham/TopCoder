// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// I give my true love presents every day.  On day 1, I give her one Type 1 
// present.  On day 2, I give her two Type 2 presents, followed
// by one Type 1 present.  On day 3, I give her three Type 3 presents, followed 
// by two Type 2 presents, followed by one Type 1 present.
// This pattern continues day after day.  Soon I begin to wonder, what type of 
// present will be the 100th present that I give my
// true love?  The 1000th?  The 1000000th?
// 
// 
// 
// For example, the 10th present that I give my true love is the Type 1 present 
// on day 3.
// 
// 
// 
// Write a method that takes an int n and returns the type of the nth present 
// that I give my true love.  Note that n is one-based, so n=1 refers to the very 
// first present I give her (the Type 1 present on day 1).
// 
// 
// 
// DEFINITION
// Class:TwoTurtledoves
// Method:presentType
// Parameters:int
// Returns:int
// Method signature:int presentType(int n)
// 
// 
// NOTES
// -Unlike the poseur in the popular Christmas song, I do not stop giving my true 
// love presents after the 12th day.
// 
// 
// CONSTRAINTS
// -n is between 1 and 1000000000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 10
// 
// Returns: 1
// 
// The example above.
// 
// 1)
// 12
// 
// Returns: 4
// 
// The second of four Type 4 presents on Day 4.
// 
// 2)
// 399
// 
// Returns: 11
// 
// 3)
// 123456
// 
// Returns: 65
// 
// 4)
// 1000000000
// 
// Returns: 1704
// 
// END CUT HERE
#line 75 "TwoTurtledoves.cpp"
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

class TwoTurtledoves {
	public:
	int presentType(int n) {
		int d = 0; 
		int latestSum = 0; 

		while (n > latestSum + d) {
			d++; 
			latestSum += d; 
			n -= latestSum; 
		}	
 
		if (n == 0) return 1; 

		int type = d + 1; 
		do {
			n-= type; 
			type--; 
		} while (n >= 0); 

		return type + 1; 
	}
};
