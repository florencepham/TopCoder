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

bool descending(int i, int j) { return (i > j); }

class StandInLine {
	public:
	vector <int> reconstruct(vector <int> left)
    {
        map <int, int> HtoL;
        vector<int> P;
        int maxHeight = left.size() - 1; 

        for (int i = 0; i <= maxHeight; i++) {
            HtoL[i] = left[i];
            P.push_back(maxHeight - i);
        }
                
        int i = 1;
        while (i < P.size()) { 
            int h = P[i];
            int rightPos = findRightPos(HtoL, P, i);
            P.erase(P.begin() + i);
            P.insert(P.begin() + rightPos, h);
            i++;
        }

        for (int i = 0; i < P.size(); i++) {
            P[i]++;
        }

        return P;
	}
    
    private:
    int findRightPos(map <int, int> HtoL, vector <int> P, int i) 
    {
        int h = P[i];
        int l = HtoL[h];

        if (l >= i) { return i; }
        
        int j = 0; 
        int numL = 0;
        for (j = 0; j < P.size(); j++) {
            if (numL == l) { return j; }
            if (P[j] > h) { numL++; }
        }

        return j;
    }
};
