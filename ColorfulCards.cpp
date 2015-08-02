//#line 95 "ColorfulCards.cpp"
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

class ColorfulCards {
	public:
	vector <int> theCards(int N, string colors) 
	{
		// init VI
		VI result; 
		for (int i = 0; i < colors.size(); i++) {
			result.push_back(-2); 
		}

		for (int n = 1; n <= N - colors.size(); n++) {
			VI newList; 
			if ((colors[0] == 'R' && isPrime(n)) || 
				(colors[0] == 'B' && !isPrime(n)) ) {
				newList = findList(N, colors, n); 
			}
			
			if (newList.size() == 0) continue; 
			for (int i = 0; i < newList.size(); i++) {
				if (newList[i] == result[i] || result[i] == -2) {
					result[i] = newList[i]; 
				} else {
					result[i] = -1;
				}
			}
		}
		return result; 
	}

	private: 
	bool isPrime(int n) {
		if (n <= 1) return false;
		if (n == 2) return true; 
		for (int i = 2; i <= sqrt(n); i++) {
			if (n % i == 0) return false; 
		}
		return true; 
	}

	VI findList(int N, string colors, int n) {
		VI result; 
		int i = 0; 
		while (i < colors.length()) {
			if (n > N) break; 
			if ((colors[i] == 'R' && isPrime(n)) || (colors[i] == 'B' && !isPrime(n)) ) {
				result.push_back(n); 
				i++; 
			}
			n++; 
		}

		cout << n << endl; 
		if (i < colors.length()) return {}; 
		else return result; 
	}
};


// Powered by FileEdit
