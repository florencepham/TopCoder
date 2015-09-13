// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// You have many people working for you, and you have an urgent job that needs to 
// be done immediately.  You know each worker's skill level at performing the 
// task, and you also know that groups often work better than individuals.  This 
// particular task requires everybody in a group to perform at the same pace.  
// Therefore, a group of talented people can easily be slowed down by having a 
// single less talented member.
// 
// You have established that the productivity of a group is K*X, where K is the 
// number of people in the group and X is the minimum skill level in the group.  
// You must assemble a group with the highest possible productivity.  You will be 
// given two vector <int>s p and s describing the people who work for you.  Each 
// element of p represents a set of workers who all have the same skill level.  
// The ith element of p is the number of people in the ith set, and the ith 
// element of s is the skill level of each worker in the ith set.  The input is 
// organized into sets only for convenience.  You are free to choose any number 
// of individuals from any number of sets when assembling your group. See 
// examples for further clarification. Return the highest achievable productivity.
// 
// 
// DEFINITION
// Class:GroupWork
// Method:bestGroup
// Parameters:vector <int>, vector <int>
// Returns:long long
// Method signature:long long bestGroup(vector <int> p, vector <int> s)
// 
// 
// CONSTRAINTS
// -p will contain between 1 and 50 elements, inclusive.
// -s and p will contain the same number of elements.
// -Each element of p will be between 1 and 1000000000 (109), inclusive.
// -Each element of s will be between 1 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {1,2,1}
// {3,5,9}
// 
// Returns: 15
// 
// The possible groups and their productivities are (each possible group using 
// only 1 of the workers with skill level 5 is only listed once):
// 
// Group | Productivity   Group | Productivity    Group | Productivity
// ------+-------------   ------+-------------  --------+-------------
//   3   | 3               3-9  |  6             3-5-9  | 9
//   5   | 5               5-5  | 10             5-5-9  | 15
//   9   | 9               5-9  | 10            3-5-5-9 | 12
//  3-5  | 6              3-5-5 |  9
// 
// 
// 1)
// {2,2,2,2}
// {5,1,1,5}
// 
// Returns: 20
// 
// Here there are 4 people of skill level 5, and 4 people of skill level 1. The 
// best choice is to assign the task to the 4 workers of skill level 5.
// 
// 2)
// {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// {31,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
// 
// Returns: 31
// 
// The skilled worker has higher productivity working alone than any other group 
// of workers.
// 
// 3)
// {1000000000,1000000000,1000000000}
// {1000,999,998}
// 
// Returns: 2994000000000
// 
// Recruit all of them.
// 
// END CUT HERE
#line 85 "GroupWork.cpp"
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

class GroupWork {
	public:
	long long bestGroup(vector <int> p, vector <int> s) {
		
	}
};
