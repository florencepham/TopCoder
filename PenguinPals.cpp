#line 110 "PenguinPals.cpp"
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

class PenguinPals {
	public:
	int findMaximumMatching(string colors) {
		if (colors.length() < 2) {
			return 0; 
		}

		int l = 0; 
		int r = colors.length() - 1; 

		int P = 0; 
		while (l < r) {
			if (colors[l] == colors[r]) {
				colors[l] = '.'; 
				colors[r] = '.'; 
				l++; 
				P++; 
			}
			r--; 
		}

		l = colors.length() - 1; 
		r = l;  
		while (colors[l] != '.') {
			l--;
		} 
		P += (r - l) / 2; 

		return P; 	
	}
};


// Powered by FileEdit
