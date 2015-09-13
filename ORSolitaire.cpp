//#line 93 "ORSolitaire.cpp"
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

class ORSolitaire {
	public:
	int getMinimum(vector <int> numbers, int goal) 
	{
		int N = numbers.size(); 
		int L = ceil(sqrt(goal)) + 1; 
		map<int, int> freq;  

		for (int i = 0; i < N; i++) {
			int mask = 1; 
			int num = numbers[i]; 
			if ((goal | num) != goal) continue; 
			int j = 0; 
			while (j < L) {
				if ((mask & num) != 0) {
					if (freq.count(j) == 0) {
						freq[j] = 0; 
					}
					freq[j]++; 
				}
				mask = mask << 1; 
				j++;
			}
		}

 		int mask = 1; 
 		int i = 0; 
 		int min = 0; 
 		while (i < L) {
 			if (((mask & goal) != 0) && (min == 0 || min > freq[i])) min = freq[i]; 
 			i++;
 			mask = mask << 1; 
 		}
		return min; 
	}
};
