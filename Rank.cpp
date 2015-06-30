// BEGIN CUT HERE
// PROBLEM STATEMENT
// At a recent competition, each competitor received an integer score between 0 
// and 100, inclusive.  Now, you need to rank the competitors from first to 
// last.  First place (the highest score) is ranked 1, second is ranked 2, and so 
// on.  In the event of a tie, all of the tied competitors should receive the 
// average of the ranks they would have received if there were put in some order 
// (it doesn't matter what order, the average is always the same).  For example, 
// if there is a tie between two people for first place, then ordering them would 
// give one competitor rank 1, and the other rank 2.  The average of these is 
// 1.5, so both competitors receive a rank of 1.5.
// You should return a vector <double> containing the ranks of the competitors, 
// each of whose elements corresponds to the element of score with the same 
// index.  
// 
// DEFINITION
// Class:Rank
// Method:rank
// Parameters:vector <int>
// Returns:vector <double>
// Method signature:vector <double> rank(vector <int> scores)
// 
// 
// CONSTRAINTS
// -scores will contain between 1 and 50 elements, inclusive.
// -Each element of scores will be between 0 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {49,48,49}
// 
// Returns: { 1.5,  3.0,  1.5 }
// 
// There is a tie for first place between competitors 0 and 2.  Hence they each 
// get ranked 1.5, while competitor 1 gets ranked 3.
// 
// 1)
// {10}
// 
// Returns: { 1.0 }
// 
// 2)
// {3,4,2,0,9,8,6,7,1,2,3,5,4,1}
// 
// Returns: { 8.5,  6.5,  10.5,  14.0,  1.0,  2.0,  4.0,  3.0,  12.5,  10.5,  
// 8.5,  5.0,  6.5,  12.5 }
// 
// END CUT HERE
#line 52 "Rank.cpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <math> 
#include <map> 
#include <queue> 
#include <stack> 

class Rank {
	public:
	vector <double> rank(vector <int> scores) {
		
	}
};
