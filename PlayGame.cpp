// BEGIN CUT HERE
// PROBLEM STATEMENT
// You are playing a computer game and a big fight is planned between two armies. 
// You and your computer opponent will line up your respective units in two rows, 
// with each of your units facing exactly one of your opponent's units and vice 
// versa. Then, each pair of units, who face each other will fight and the 
// stronger one will be victorious, while the weaker one will be captured. If two 
// opposing units are equally strong, your unit will lose and be captured. You 
// know how the computer will arrange its units, and must decide how to line up 
// yours. You want to maximize the sum of the strengths of your units that are 
// not captured during the battle.
// 
// You will be given a vector <int> you and a vector <int> computer that specify 
// the strengths of the units that you and the computer have, respectively. The 
// return value should be an int, the maximum total strength of your units that 
// are not captured.
// 
// DEFINITION
// Class:PlayGame
// Method:saveCreatures
// Parameters:vector <int>, vector <int>
// Returns:int
// Method signature:int saveCreatures(vector <int> you, vector <int> computer)
// 
// 
// CONSTRAINTS
// -you and computer will have the same number of elements.
// -you and computer will contain between 1 and 50 elements, inclusive.
// -Each element of you and computer will be between 1 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {5, 15, 100, 1, 5}
// {5, 15, 100, 1, 5}
// 
// Returns: 120
// 
// Your units with strengths of 100 and 15, along with one of your strength 5 
// units, can avoid capture.
// 
// 1)
// {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 
//  1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
//  1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
//  1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
//  1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}
// {1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 
//  1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
//  1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
//  1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000,
//  1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000}
// 
// Returns: 0
// 
// All units are equally strong, so all your units are captured.
// 
// 2)
// {1, 3, 5, 7, 9, 11, 13, 15, 17, 19}
// {2, 4, 6, 8, 10, 12, 14, 16, 18, 20}
// 
// Returns: 99
// 
// You assign your weakest unit to the computer's strongest unit. Then you assign 
// all your other units in such a way that each of your units has a strength one 
// higher than the opposing unit. So all your units except the weakest one avoid 
// capture.
// 
// 3)
// {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}
// {10, 9, 8, 7, 6, 5, 4, 3, 2, 1}
// 
// Returns: 65
// 
// All your units can win.
// 
// 4)
// {651, 321, 106, 503, 227, 290, 915, 549, 660, 115,
//  491, 378, 495, 789, 507, 381, 685, 530, 603, 394,
//  7, 704, 101, 620, 859, 490, 744, 495, 379, 781,
//  550, 356, 950, 628, 177, 373, 132, 740, 946, 609,
//  29, 329, 57, 636, 132, 843, 860, 594, 718, 849}
// {16, 127, 704, 614, 218, 67, 169, 621, 340, 319,
//  366, 658, 798, 803, 524, 608, 794, 896, 145, 627,
//  401, 253, 137, 851, 67, 426, 571, 302, 546, 225,
//  311, 111, 804, 135, 284, 784, 890, 786, 740, 612,
//  360, 852, 228, 859, 229, 249, 540, 979, 55, 82}
// 
// Returns: 25084
// 
// END CUT HERE
//#line 94 "PlayGame.cpp"
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


bool descending(int i, int j) { return (i > j); }
class PlayGame {
	public:
	int saveCreatures(vector <int> you, vector <int> computer)
    {
        int totalSaved = 0;
        sort(you.begin(), you.begin() + you.size(), descending);
        sort(computer.begin(), computer.begin() + computer.size(), descending); 

        int c = 0; 
        for (int y = 0; y < you.size(); y++) {
        	int myUnit = you[y];
        	while (c < computer.size()) {
        		int cUnit = computer[c];
        		if (myUnit > cUnit) {
        			totalSaved += myUnit;
        			c++;
        			break; 
        		}
        		c++;
        	}
        }
        return totalSaved; 
	}
};
