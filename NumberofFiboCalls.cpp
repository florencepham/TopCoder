#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <map> 
#include <queue> 
#include <stack> 
#include <vector>

using namespace std; 

typedef vector<int> VI; 

class NumberofFiboCalls {
	public: 
	vector <int> fiboCallsMade(int n) 
	{
		if (n < 0) return {0, 0}; 

		map<int, VI> fibCalls; 
		fibCalls[0] = {1, 0}; 
		fibCalls[1] = {0, 1}; 

		for (int i = 2; i <= n; i++) {
			int numZero = fibCalls[i - 1][0] + fibCalls[i - 2][0]; 
			int numOne = fibCalls[i - 1][1] + fibCalls[i - 2][1]; 
			fibCalls[i] = {numZero, numOne}; 
		}

		return fibCalls[n];
	}
};
