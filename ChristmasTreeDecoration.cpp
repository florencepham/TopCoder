// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// Christmas is just around the corner, and Alice just decorated her Christmas 
// tree.
// There are N stars on the tree.
// The stars are numbered 1 through N.
// Additionally, each star has some color.
// You are given the colors of stars as a vector <int> col with N elements.
// For each i, col[i] is the color of star i+1.
// (Different integers represent different colors.)
// 
// 
// 
// Alice has prepared N-1 ribbons and she is now going to attach them to the tree.
// Each ribbon will connect two of the stars.
// The ribbons have to be placed in such a way that all stars and ribbons will 
// hold together.
// (In other words, in the resulting arrangement the stars and ribbons will 
// correspond to vertices and edges of a tree.)
// 
// 
// 
// Only some pairs of stars can be connected by a ribbon.
// You are given a list of all such pairs of stars in two vector <int>s: x and y.
// For each valid i, it is possible to add a ribbon that connects the stars with 
// numbers x[i] and y[i].
// 
// 
// 
// According to Alice, a ribbon that connects two stars that share the same color 
// is less beautiful than a ribbon that connects two stars with different colors.
// Therefore, she would like to minimize the number of ribbons that connect two 
// same-colored stars.
// Compute and return the smallest possible number of such ribbons.
// 
// 
// DEFINITION
// Class:ChristmasTreeDecoration
// Method:solve
// Parameters:vector <int>, vector <int>, vector <int>
// Returns:int
// Method signature:int solve(vector <int> col, vector <int> x, vector <int> y)
// 
// 
// CONSTRAINTS
// -N will be between 2 and 50, inclusive.
// -The number of elements in col will be N exactly.
// -The number of elements in x will be between 1 and 200, inclusive.
// -The number of elements in y will be the same as the number of elements in x.
// -All elements of x and y will be between 1 and N, inclusive.
// -For each i, the numbers x[i] and y[i] will be different.
// -All unordered pairs (x[i], y[i]) will be distinct.
// -There will be at least one way to choose N-1 ribbons that form a connected 
// graph.
// 
// 
// EXAMPLES
// 
// 0)
// {1,1,2,2}
// {1,2,3,4}
// {2,3,4,1}
// 
// Returns: 1
// 
// We have four stars. Stars 1 and 2 have the same color, and stars 3 a 4 have 
// the same color.
// There are four pairs of stars we may connect: 1-2, 2-3, 3-4, and 4-1.
// One optimal solution is to use the following ribbons: 2-3, 3-4, and 4-1.
// Two of these are beautiful (2-3 and 4-1) and only one (3-4) is not beautiful.
// 
// 1)
// {1,1,2,2}
// {1,2,3,4,1,2}
// {2,3,4,1,3,4}
// 
// Returns: 0
// 
// Now we can have three beautiful ribbons.
// 
// 2)
// {50,50,50,50}
// {1,2,3,1,1,2}
// {2,3,4,4,3,4}
// 
// Returns: 3
// 
// All stars have the same color. Regardless of how we attach the ribbons, none 
// of them will be beautiful.
// 
// 3)
// {1,4,2,3}
// {1,2,3}
// {2,3,4}
// 
// Returns: 0
// 
// 
// 
// 4)
// {1,1,1,2,2,2,3,3,3,4,4,4}
// {1,2,3,4,5,6,7,8,9,10,11,12,1,1,1,1,1,1}
// {2,3,1,5,6,4,8,9,7,11,12,10,5,7,12,11,6,4}
// 
// Returns: 5
// 
// 
// 
// END CUT HERE
#line 112 "ChristmasTreeDecoration.cpp"
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

class ChristmasTreeDecoration {
	public:
	int solve(vector <int> col, vector <int> x, vector <int> y) {
		
	}
};
