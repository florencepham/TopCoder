// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// An accurate scale is one of the most important tools of the apothecary (an old-
// time pharmacist).  
// To measure the weight of an object, the apothecary places the object on one
// pan of the scale, along with some weights of known size, and adds more weights
// of known size to the other pan until the scales balance.  For example, if an 
// object
// weighs 17 grains, the apothecary could balance the scales by placing a 1-grain 
// weight
// and a 9-grain weight in the pan with the object, and a 27-grain weight in the 
// other
// pan.
// 
// 
// 
// The apothecary owns weights in a range of sizes starting at 1 grain.  In 
// particular, he owns one weight for each
// power of 3: 1 grain, 3 grains, 9 grains, 27 grains, etc.  Determine, for an 
// object weighing W grains, how to distribute the weights among the
// pans to balance the object.  This distribution will be unique.  Return a 
// vector <int> of the weights used.  The sign of each weight should be
// negative if the weight goes in the same pan as the object, and positive if it 
// goes in the other pan.  The vector <int> should be arranged in increasing order.
// 
// 
// 
// DEFINITION
// Class:Apothecary
// Method:balance
// Parameters:int
// Returns:vector <int>
// Method signature:vector <int> balance(int W)
// 
// 
// CONSTRAINTS
// -W is between 1 and 1000000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 17
// 
// Returns: { -9,  -1,  27 }
// 
// The example above.
// 
// 1)
// 1
// 
// Returns: { 1 }
// 
// A 1-grain weight is placed in the pan opposite the object being measured.
// 
// 2)
// 2016
// 
// Returns: { -243,  -9,  81,  2187 }
// 
// A 9-grain weight and a 243-grain weight are placed in the pan with the object,
// and an 81-grain weight and a 2187-grain weight are placed in the opposite pan.
// 
// 3)
// 1000000
// 
// Returns: { -531441,  -59049,  -6561,  -243,  -27,  1,  81,  729,  2187,  
// 1594323 }
// 
// END CUT HERE
#line 73 "Apothecary.cpp"
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

bool ascending (int i,int j) { return (i<j); }

class Apothecary {
	public:
	vector <int> balance(int W) 
	{
		int r = findNextPowerThree(W); 
		int R = pow(3, r); 
		int L = W; 
		vector<int> possible, weights; 
		for (int i = 0; i < r; i++) {
			possible.push_back(pow(3, i)); 
		}

		while (L <= R) {

			cout << "L: " << L << " R: " << R << endl; 
			for (int i = 0; i < possible.size(); i++) {
				if (possible[i] + L > R) {
					continue; 
				} else {
						L += possible[i]; 
						weights.push_back(0 - possible[i]); 
						possible.erase(possible.begin() + i); 
				}
			}

			cout << "L: " << L << " R: " << R << endl; 

			if (L == R) {
				cout << "here" << endl; 
				sort(weights.begin(), weights.end(), ascending); 
				weights.push_back(R); 
				return weights; 
			}
			// add to R
			possible.push_back(R); 
			R = pow(3, ++r); 

		}
		return weights; 
	}

	private: 
		int findNextPowerThree(int W) {
		int i = 0; 
		while (pow(3, i) < W) {
			i++;
		}
		return i; 
	}
};
