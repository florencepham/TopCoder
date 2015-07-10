//#line 91 "UnderscoreJustification.cpp"
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

class UnderscoreJustification {
	public:
	string justifyLine(vector <string> words, int width) {
		int gapL; 
		int extraS; 
		int numS = width; 
		int numG = words.size() - 1; 

		for (int i = 0; i < words.size(); i++) {
			numS -= words[i].length(); 
		}
		extraS = numS % numG;
		gapL = numS / numG;

		string smallest = words[0]; 

		for (int i = 1; i < words.size(); i++) {
			cout << extraS << " " << numG << endl; 
			if (words[i][0] <= 'Z') {
				smallest += addSpaces(gapL) + words[i]; 
			} else if (extraS <= 0 || extraS < numG) {
				smallest += addSpaces(gapL) + words[i]; 
			} else {
				smallest += addSpaces(gapL + 1) + words[i]; 
				extraS--; 
			}
			numG--; 
		}

		cout << smallest << endl;
		for (int i = 0; i < smallest.size(); i++) {
			if (smallest[i] == ' ') {
				smallest[i] = '_';
			}
		}
		return smallest; 
	}

	private: 
	string addSpaces(int num) {
		string result = ""; 

		for (int i = 0; i < num; i++) {
			result += " ";
		}

		return result; 
	}
};


// Powered by FileEdit
