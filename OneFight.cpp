// BEGIN CUT HERE
// PROBLEM STATEMENT
// In some computer game, you are surrounded by monsters, and you are to kill 
// them all. Each monster has some number of life points and damage points, and 
// you also have some number of damage points. Life points represent the amount 
// of life left in a monster. As long as a monster has one or more life points, 
// it remains alive. Damage points represent the number of life points that are 
// taken away from an enemy by a single attack. At every turn, you are attacked 
// by each of the living monsters, and then you attack exactly one of them (at 
// the same turn).
// 
// You are given a vector <int> life, the number of life points that each monster 
// starts out with, a vector <int> damage, the number of damage points each 
// monster has, and an int yourDamage, the number of damage points you have. The 
// ith elements of life and damage represent the life points and damage points 
// for the ith monster. Return the minimal number of life points you must start 
// out with in order to kill all the monsters. At the end of the fight, you must 
// have one or more life points remaining.
// 
// DEFINITION
// Class:OneFight
// Method:monsterKilling
// Parameters:vector <int>, vector <int>, int
// Returns:int
// Method signature:int monsterKilling(vector <int> life, vector <int> damage, 
// int yourDamage)
// 
// 
// CONSTRAINTS
// -life will have between 1 and 10 elements, inclusive.
// -life and damage will have the same number of elements.
// -All elements of life will be between 1 and 100, inclusive.
// -All elements of damage will be between 0 and 100, inclusive.
// -yourDamage will be between 1 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {3}
// {10}
// 2
// 
// Returns: 21
// 
// You must hit the monster twice. You lose 20 life points in the fight. Since 
// you must have at least 1 life point remaining, the answer is 21.
// 
// 1)
// {5,1}
// {5,3}
// 3
// 
// Returns: 19
// 
// If you kill the first monster and then the second one, you will lose (3+5) + 
// (3+5) + 3 = 19 life points. If you kill the second monster and then first one, 
// you will lose (3+5) + 5 + 5 = 18 life points. You choose the latter option.
// 
// 2)
// {5,5,5,5,5,5,5,5,5,5}
// {10,20,30,40,50,60,70,80,90,100}
// 100
// 
// Returns: 2201
// 
// Kill all the monsters in reverse order from last to first.
// 
// 3)
// {6,34,21,79,31,5,8,23,9,100}
// {1,65,95,32,48,9,3,13,100,4}
// 4
// 
// Returns: 6554
// 
// END CUT HERE
#line 78 "OneFight.cpp"
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

class OneFight {
	public:
	int monsterKilling(vector <int> life, vector <int> damage, int yourDamage) {
		
	}
};
