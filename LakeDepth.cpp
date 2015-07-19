
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

class LakeDepth {
	public:
	int depth(vector <string> plot) {
		// find the min value that is not on the edge. 0: r, 1: c; 
		VI min = findMin(plot);
		if (min.size() == 0) {
			return 0; 
		}

		// find the highest possible height, -1: can go to infinity
		char h = findMax(plot, 127);

		// check to make sure that there's no path < h that leads to edge
		while (validate(plot, min, h) == false) {
			h = findMax(plot, h);
		}

		return h - plot[min[0]][min[1]];
	}

	private: 
	VI findMin(vector <string> plot) {

		VI result = {};
		int W = plot[0].length();
		int H = plot.size(); 

		// find a min that's not on the edge
		char curMin = plot[0][0];

		for (int i = 1; i < H - 1; i++) {
			for (int j = 1; j < W - 1; j++) {
				if((plot[i][j] < curMin)) {
					result = {i, j};
				}
			}
		}

		return result; 
	}

	char findMax(vector <string> plot, char curHeight) 
	{
		int W = plot[0].length();
		int H = plot.size(); 
		char max = 0;

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (plot[i][j] > max && plot[i][j] < curHeight) {
					max = plot[i][j];
				}
			}
		}
		return max; 
	}

	bool validate(vector <string> plot, VI min, char curHeight) 
	{
		map<VI, bool> visited; 
		queue<VI> Q; 
		Q.push(min);

		int W = plot[0].length();
		int H = plot.size(); 

		while (!Q.empty()) {
			VI pos = Q.front(); Q.pop(); 
			int r = pos[0];
			int c = pos[1];

			if (((r == 0) || (r == H - 1) || (c == 0) || (c == W - 1)) &&
				(plot[r][c] < curHeight)) {
				return false; 
			}
			visited[pos] = true; 

			if(valid(r, c - 1, plot, visited, curHeight)) Q.push({r, c - 1});
			if(valid(r, c + 1, plot, visited, curHeight)) Q.push({r, c + 1});
			if(valid(r - 1, c, plot, visited, curHeight)) Q.push({r - 1, c});
			if(valid(r + 1, c, plot, visited, curHeight)) Q.push({r + 1, c});
		}

		return true; 
	}

	bool valid(int r, int c, vector <string> plot, map <VI, bool> visited, char curHeight) 				
	{
		int W = plot[0].length();
		int H = plot.size(); 

		if ((r >= 0) && (r < H) && (c >= 0) && (c < W) &&
			(visited.count({r, c}) == 0) && 
			(plot[r][c] < curHeight) ) {
			return true; 
		} else {
			return false;
		}
	}
};
