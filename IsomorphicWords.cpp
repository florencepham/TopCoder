#line 59 "IsomorphicWords.cpp"
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

class IsomorphicWords {
	public:
	int countPairs(vector <string> words) {
		int pairs = 0; 
		int N = words.size();
		for (int i = 0; i < N - 1; i++) {
			for (int j = i + 1; j < N; j++) {
				pairs += min(isPairs(words[i], words[j]), isPairs(words[j], words[i]));
			}
		}
		return pairs; 
	}

	private: 
	int isPairs(string A, string B) {
		if (A.length() != B.length()) return 0; 
		map<char, char> Map; 

		for (int i = 0; i < A.length(); i++) {
			char a = A[i]; 
			char b = B[i]; 
			if (Map.count(a) == 0) Map[a] = b; 
			else if (Map[a] != b) return 0; 
		}
		return 1; 
	}
};


// Powered by FileEdit
