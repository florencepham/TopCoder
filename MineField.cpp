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

#define INCREMENT(r, c, board) {(board)[(r)][(c)] = '0' + (((board)[(r)][(c)] - '0') + 1); }

class MineField {
	public:
	vector <string> getMineField(string mineLocations) 
	{
		vector <string> Coords = parseStrings(mineLocations); 

		vector <string> board;

		for (int i = 0; i < 9; i++) {
			board.push_back("000000000"); 
		}

		for (int i = 0; i < Coords.size(); i++) {
			string word = Coords[i];
			int r = word[1] - '0'; 
			int c = word[3] - '0'; 
			board[r][c] = 'M'; 

			if (withinBound(r - 1, c, board)) { INCREMENT(r - 1, c, board); }
			if (withinBound(r + 1, c, board)) { INCREMENT(r + 1, c, board); }
			if (withinBound(r, c - 1, board)) { INCREMENT(r, c - 1, board); }
			if (withinBound(r, c + 1, board)) { INCREMENT(r, c + 1, board); }
			if (withinBound(r - 1, c - 1, board)) { INCREMENT(r - 1, c - 1, board); }
			if (withinBound(r - 1, c + 1, board)) { INCREMENT(r - 1, c + 1, board); }
			if (withinBound(r + 1, c - 1, board)) { INCREMENT(r + 1, c - 1, board); }
			if (withinBound(r + 1, c + 1, board)) { INCREMENT(r + 1, c + 1, board); }
		}

		return board; 
	}

	private: 
	bool withinBound(int r, int c, vector<string> board) {
		if (r >= 0 && r < 9 && c >= 0 && r < 9 && board[r][c] != 'M') {
			return true; 
		} else {
			return false; 
		}
	}

	vector <string> parseStrings(string location) 
	{
		vector <string> locations; 
		int l = 5;
		for (int i = 0; i < location.length(); i += l) {
			string word = location.substr(i, l); 
			locations.push_back(word);
		}
		return locations;
	}

};
