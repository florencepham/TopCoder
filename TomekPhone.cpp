//#line 115 "TomekPhone.cpp"
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

bool descending(int i, int j) { return i > j; }

class TomekPhone {
	public:
	int minKeystrokes(vector <int> frequencies, vector <int> keySizes) 
	{
		int sum = 0; 
		int maxKeys = 0; 
		int nButtons = keySizes.size(); 
		int nChar = frequencies.size(); 

		for (int i = 0; i < nButtons; i++) {
			maxKeys += keySizes[i];
		}
		if (maxKeys < nChar) return -1; 

		sort(frequencies.begin(), frequencies.begin() + nChar, descending); 

		vector <int> numKeys; 
		for (int i = 0; i < nButtons; i++) {
			numKeys.push_back(0);
		}

		int keyPos = 0; 
		for (int i = 0; i < nChar; i++) {
			int freq = frequencies[i];
			while (numKeys[keyPos] >= keySizes[keyPos]) {
				keyPos = (keyPos + 1) % nButtons; 
			}
			numKeys[keyPos]++; 
			sum = sum + freq * numKeys[keyPos];
			keyPos = (keyPos + 1) % nButtons; 
		}
		return sum; 
	}
};


// Powered by FileEdit
