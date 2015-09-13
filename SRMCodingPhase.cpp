// BEGIN CUT HERE
// PROBLEM STATEMENT
// Mr. Dengklek introduced you to an online programming contest called SRM 
// (Special Round Match)!
// 
// You are now in the coding phase of the contest. There are 3 problems in the 
// contest. You have practiced a lot before in practice rooms, so you are sure 
// that you can solve the first problem in skills[0] minutes, the second problem 
// in skills[1] minutes and the third problem is skills[2] minutes.
// 
// You have exactly 75 minutes to solve the problems. Before submitting a 
// solution to a problem, you must first open the problem. If you submit a 
// solution to a problem t minutes after you open the problem, you will receive:
// 
// (points[0] - 2t) points for the first problem, or
// (points[1] - 4t) points for the second problem, or
// (points[2] - 8t) points for the third problem.
// 
// 
// In your strategy, you only submit a solution to a problem after you solve the 
// problem. If you don't submit a solution to a problem, you will receive zero 
// points for the problem.
// 
// It is well-known that luck plays an important role in a contest. A fortune-
// teller told you that you have luck points of luck. You may use these points to 
// decrease the amount of time you need to solve the problems, in minutes. Of 
// course, you don't have to use all the points. Each point is worth one minute 
// per problem. So, if you initially can solve a problem in t minutes, by using x 
// points of luck (where x is a positive integer and 0 < x < t), you can solve 
// the problem in (t - x) minutes (it is impossible to use t or more points of 
// luck on the problem).
// 
// Arrange your strategy in this coding phase. Return the maximum total score you 
// can achieve in this coding phase.
// 
// DEFINITION
// Class:SRMCodingPhase
// Method:countScore
// Parameters:vector <int>, vector <int>, int
// Returns:int
// Method signature:int countScore(vector <int> points, vector <int> skills, int 
// luck)
// 
// 
// CONSTRAINTS
// -points will contain exactly 3 elements.
// -points[0] will be between 250 and 300, inclusive.
// -points[1] will be between 450 and 600, inclusive.
// -points[2] will be between 900 and 1100, inclusive.
// -skills will contain exactly 3 elements.
// -Each element of skills will be between 1 and 100, inclusive.
// -luck will be between 0 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {250, 500, 1000}
// {10, 25, 40}
// 0
// 
// Returns: 1310
// 
// You don't have any luck points. However, you can solve all the problems in 
// exactly 75 minutes.
// 
// 1)
// {300, 600, 900}
// {30, 65, 90}
// 25
// 
// Returns: 680
// 
// Use 25 luck points on the 600-point problem, and then solve the 300- and 600-
// point problems.
// 
// 2)
// {250, 550, 950}
// {10, 25, 40}
// 75
// 
// Returns: 1736
// 
// Using the large amount of luck points, solve each problem in only 1 minute.
// 
// 3)
// {256, 512, 1024}
// {35, 30, 25}
// 0
// 
// Returns: 1216
// 
// 
// 
// 4)
// {300, 600, 1100}
// {80, 90, 100}
// 4
// 
// Returns: 0
// 
// 
// 
// END CUT HERE
#line 106 "SRMCodingPhase.cpp"
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

class SRMCodingPhase {
	public:
	int countScore(vector <int> points, vector <int> skills, int luck) 
	{
		int maxScore = 0; 
		for (int i = 0; i < skills.size(); i++) {
			int newScore = findScore(points, skills, luck, i); 
			if (newScore > maxScore) {
				maxScore = newScore;
			}
		}
		return maxScore; 
	}

	private:
	int findScore(vector <int> points, vector <int> skills, int luck, int start) 
	{
		cout << start << endl; ; 
		int i = 0; 
		int score = 0; 
		int totalTime = 0; 
		while (i < 3) {
			int Point = points[start]; 
			int Time = max(skills[start] - luck, 1); 
			cout << "Time " << skills[start] << " " << totalTime << endl; 
			if (Time + totalTime <= 75) {
				cout << "ehre " << endl; 
				cout << score << endl; 
				totalTime += Time; 
				luck -= max(skills[start] - luck, 1); 
				score += (Point - pow(2, start + 1) * Time); 
				cout << "score " << score << endl; 
			}
			start = start - 1 % 3; 
			i++;
			cout << "Start " << start << endl;   
		}
		cout << score << endl; 
		return score; 
	}
};
