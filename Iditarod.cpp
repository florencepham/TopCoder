// BEGIN CUT HERE
// PROBLEM STATEMENT
// The Iditarod is a dogsled race from Anchorage to Nome that takes many days. 
// We want to take a list of the times when the competitors crossed the
// finish line and convert that into the average number of minutes to complete 
// the race.
// 
// The race starts on day 1 at 8:00 AM. We are given a list of finish times as
// a vector <string>, where each finish time is formatted as 
//                  hh:mm xM, DAY n  
// 
// where hh is exactly 2 digits giving the hour, mm is exactly 2 digits giving
// the minute, x is either 'A' or 'P', and n is a positive integer less than 100
// with no leading zeros.
// So each string has exactly 15 or 16 characters (depending on whether n is
// less than 10).
// 
// Create a class Iditarod containing method avgMinutes that is given a 
// vector <string>, times, and that returns the average number of minutes taken 
// by the
// competitors to complete the race.  Round the returned value to the nearest
// minute, with .5 rounding up.
// 
// 
// 
// DEFINITION
// Class:Iditarod
// Method:avgMinutes
// Parameters:vector <string>
// Returns:int
// Method signature:int avgMinutes(vector <string> times)
// 
// 
// NOTES
// -"12:00 AM, DAY d" refers to midnight between DAY d-1 and DAY d
// -"12:00 PM, DAY d" refers to noon on DAY d
// 
// 
// CONSTRAINTS
// -times contains between 1 and 50 elements inclusive
// -each element of times is formatted as specified above, with hh between 01 and 
// 12 inclusive, mm between 00 and 59 inclusive, and d between 1 and 99 inclusive
// -each element of times represents a time later than the start of the race
// 
// 
// EXAMPLES
// 
// 0)
// {"12:00 PM, DAY 1","12:01 PM, DAY 1"}
// 
// Returns: 241
// 
// From 8:00 AM to noon is 4 hours, so we have 4 hours for one competitor,
// and 4 hours, 1 minute for the other. These two values average to 240.5 minutes 
// which is rounded up.
// 
// 1)
// {"12:00 AM, DAY 2"}
// 
// Returns: 960
// 
// The one competitor finished in 16 hours, just at the start of DAY 2.
// 
// 2)
// {"02:00 PM, DAY 19","02:00 PM, DAY 20", "01:58 PM, DAY 20"}
// 
// Returns: 27239
// 
// 26280 minutes, 27720 minutes, 27718 minutes average to 27239.333 which rounds 
// down. 
// 
// END CUT HERE
#line 74 "Iditarod.cpp"
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

class Iditarod {
	public:
	int avgMinutes(vector <string> times) {
		
	}
};
