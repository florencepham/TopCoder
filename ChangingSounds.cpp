#line 68 "ChangingSounds.cpp"
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

class ChangingSounds {
	public:
	int maxFinal(vector <int> changeIntervals, int beginLevel, int maxLevel) 
	{
		int ILen = changeIntervals.size() + 1;
		int LLen = maxLevel + 1;
		cout << ILen << " " << LLen << endl; 

		bool chart[ILen][LLen]; 
		for (int s = 0; s < ILen; s++) {
			for (int l = 0; l < LLen; l++) {
				chart[s][l] = false; 
			}
		}

		// init the begin level to be true
		chart[0][beginLevel] = true; 
		for (int s = 0; s < ILen - 1; s++) {
			for (int l = 0; l < LLen; l++) {
				if (chart[s][l]) {
					int change = changeIntervals[s]; 
					if (l - change >= 0) 		chart[s + 1][l - change] = true; 
					if (l + change <= maxLevel) chart[s + 1][l + change] = true; 
				}
			}
		}

		while (maxLevel >= 0) {
			if (chart[ILen - 1][maxLevel] == true) {
				break;  
			}
			maxLevel--; 
		}
		return maxLevel; 
	}
};


// Powered by FileEdit
