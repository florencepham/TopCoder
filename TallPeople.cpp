// BEGIN CUT HERE
// PROBLEM STATEMENT
// A group of people stand before you arranged in rows and columns.  Looking from 
// above, they form an R by C rectangle of people.  You will be given a vector 
// <string> people containing the height of each person.  Elements of people 
// correspond to rows in the rectangle.  Each element contains a space-delimited 
// list of integers representing the heights of the people in that row.  Your job 
// is to return 2 specific heights in a vector <int>.  The first is computed by 
// finding the shortest person in each row, and then finding the tallest person 
// among them (the "tallestOfTheShortest").  The second is computed by finding 
// the tallest person in each column, and then finding the shortest person among 
// them (the "shortestOfTheTallest").
// 
// DEFINITION
// Class:TallPeople
// Method:getPeople
// Parameters:vector <string>
// Returns:vector <int>
// Method signature:vector <int> getPeople(vector <string> people)
// 
// 
// CONSTRAINTS
// -people will contain between 2 and 50 elements inclusive.
// -Each element of people will contain between 3 and 50 characters inclusive.
// -Each element of people will be a single space-delimited list of positive 
// integers such that: 1) Each positive integer is between 1 and 1000 inclusive 
// with no extra leading zeros.2) Each element contains the same number of 
// integers.3) Each element contains at least 2 positive integers.4) Each element 
// does not contain leading or trailing whitespace.
// 
// 
// EXAMPLES
// 
// 0)
// {"9 2 3",
//  "4 8 7"}
// 
// Returns: { 4,  7 }
// 
// The heights 2 and 4 are the shortest from the rows, so 4 is the taller of the 
// two.  The heights 9, 8, and 7 are the tallest from the columns, so 7 is the 
// shortest of the 3.
// 
// 1)
// {"1 2",
//  "4 5",
//  "3 6"}
// 
// Returns: { 4,  4 }
// 
// 2)
// {"1 1",
//  "1 1"}
// 
// Returns: { 1,  1 }
// 
// END CUT HERE
#line 59 "TallPeople.cpp"
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

typedef vector<int> VI;

class TallPeople {
	public:
	vector <int> getPeople(vector <string> people) {
		vector<VI> peopleList = parse(people); 

		vector<int> rowShortest = findRowShortest(peopleList); 
		vector<int> columnTallest = findColumnTallest(peopleList); 

		int shortestOfTheTallest = columnTallest[0];
		for (int i = 0; i < columnTallest.size(); i++) {
			if (shortestOfTheTallest > columnTallest[i]) {
				shortestOfTheTallest = columnTallest[i]; 
			}
		}

		int tallestOfTheShortest = rowShortest[0]; 
		for (int i = 0; i < rowShortest.size(); i++) {
			if (tallestOfTheShortest < rowShortest[i]) {
				tallestOfTheShortest = rowShortest[i]; 
			}
		}

		cout << tallestOfTheShortest << " " << shortestOfTheTallest << endl;
		return {tallestOfTheShortest, shortestOfTheTallest}; 
	}

	private: 
	vector<int> findRowShortest(vector<VI> people) {
		vector<int> rowShortest; 
		for (int r = 0; r < people.size(); r++) {
			int shortest = people[r][0]; 
			for (int c = 0; c < people[0].size(); c++) {
				if (shortest > people[r][c]) {
					shortest = people[r][c]; 
				}
			}
			rowShortest.push_back(shortest); 
		}
		return rowShortest;
	}

	vector<int> findColumnTallest(vector<VI> people) {
		vector<int> columnTallest; 
		for (int c = 0; c < people[0].size(); c++) {
			int tallest = 0;
			for (int r = 0; r < people.size(); r++) {
				if (tallest < people[r][c]) {
					tallest = people[r][c]; 
				}
			}
			columnTallest.push_back(tallest); 
		}
		return columnTallest;
	}

	vector<VI> parse(vector<string> people) {
		vector<VI> Library; 
		for (int i = 0; i < people.size(); i++) {
			vector<int> result; 
			string row = people[i]; 
			string curNum = ""; 
			for (int j = 0; j < row.length(); j++) {
				if (row[j] == ' ') {
					result.push_back(stoi(curNum));
					curNum = "";
				} else {
					curNum += row[j]; 
				}
			}
			result.push_back(stoi(curNum)); 
			Library.push_back(result); 
		}
		return Library; 
	}
};
