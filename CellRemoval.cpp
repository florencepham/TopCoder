#line 95 "CellRemoval.cpp"
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

class CellRemoval {
	public:
	int cellsLeft(vector <int> parent, int deletedCell) 
	{
		int N = parent.size(); 
		map<int, bool> isOK; 
		for (int i = 1; i < N; i++) isOK[i] = true; 
		isOK[deletedCell] = false; 

		// not OK if : having ancestor as a deletedCell
		// not OK if : being an ancestor
		for (int i = 0; i < N; i++) {
			for (int j = parent[i]; j != -1; j = parent[j]) {
				isOK[j] = false; 
				if (j == deletedCell) isOK[i] = false; 
			}
		}

		int num = 0; 
		for (int i = 0; i < parent.size(); i++) {
			if (isOK[i] == true) {
				num++; 
			}
		}
		return num; 
	}
};


// Powered by FileEdit
