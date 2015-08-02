//#line 84 "RowAndCoins.cpp"
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

class RowAndCoins {
	public:
	string getWinner(string cells) 
	{
		int N = cells.length(); 
		bool marked[N]; 
		for (int i = 0; i < N; i++) {
			marked[i] = false; 
		}

		while (N > 1) {
			N -= removeChar(cells, 'B', marked, N);
			if (N == 1) break; 

			N -= removeChar(cells, 'A', marked, N);
			if (N == 1) break;
		}

		int i; 
		for (i = 0; i < cells.size(); i++) {
			if (marked[i] == false) break;  
		}

		if (cells[i] == 'A') return "Alice";
		else return "Bob";
	}

	private: 
	int removeChar(string cells, char c, bool marked[], int N) 
	{
		int longest = 0; 
		int start = 0; 

		for (int i = 0; i < cells.length(); i++) {
			if (marked[i] == false && cells[i] == c) {
				int l = 1; 
				for (int j = i + 1; j < cells.length(); j++) {
					if (cells[j] != c) break; 
					l++;
				}

				if (l > longest) {
					longest = l; 
					start = i;
				} 
			}
		}

		for (int i = start; i < start + longest; i++) {
			marked[i] = true; 
		}

		if (longest == N) {
			marked[start] = false; 
			return longest - 1; 
		}

		return longest; 
	}
};


// Powered by FileEdit
