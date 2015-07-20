// BEGIN CUT HERE
// PROBLEM STATEMENT
// There are N students standing in a single row, one next to the other, numbered 
// 0 to N-1 from left to right.  Your goal is to minimize the number of adjacent 
// pairs where one student is a boy and the other is a girl.  More precisely, you 
// want to minimize the number of values i, 0 <= i < N-1, where student i and 
// student i+1 are of different genders.
// 
// You are given the current arrangement as a string row, where the i-th 
// character is 'G' if student i is a girl, and 'B' if student i is a boy. In a 
// single move, you can choose two adjacent students and swap their positions. 
// Return the minimum number of moves required to achieve your goal.
// 
// DEFINITION
// Class:GirlsAndBoys
// Method:sortThem
// Parameters:string
// Returns:int
// Method signature:int sortThem(string row)
// 
// 
// CONSTRAINTS
// -row will contain between 1 and 50 characters, inclusive.
// -Each character in row will be 'G' or 'B'.
// 
// 
// EXAMPLES
// 
// 0)
// "GGBBG"
// 
// Returns: 2
// 
// You can swap the rightmost girl with the two boys (one after the other) to get 
// "GGGBB", with a minimum of only 1 pair of adjacent students of different gender.
// 
// 1)
// "BBBBGGGG"
// 
// Returns: 0
// 
// There is already a single pair of adjacent students of different gender, and 
// there is no arrangement without such pairs at all, so the best solution is to 
// swap nothing.
// 
// 2)
// "BGBGBGBGGGBBGBGBGG"
// 
// Returns: 33
// 
// 
// 
// 3)
// "B"
// 
// Returns: 0
// 
// With only one student, there is not much swapping to do.
// 
// END CUT HERE
//#line 62 "GirlsAndBoys.cpp"
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

class GirlsAndBoys {
	public:
	int sortThem(string row)
    {
        int GFirst = count(row, 'G');
        int BFirst = count(row, 'B');
        
        return min(GFirst, BFirst);
    }
    
    private:
    
    // find the left characters, and count how many moves must be made
    // to put it in its correct slot
    int count(string row, char left)
    {
        int M = 0;
        int pos = 0;
        for (int i = 0; i < row.length(); i++) {
            if (row[i] == left) {
                M += i - pos;
                pos++;
            }
        }
        
        return M;
    }
};
