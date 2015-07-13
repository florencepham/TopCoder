// BEGIN CUT HERE
// PROBLEM STATEMENT
// Many image editing programs have the ability to stitch two images
// together to form one larger image.  In this problem, you will be given
// two images, represented by vector <string>'s.  Each
// vector <string> represents a bitmap, where the ASCII value of
// character j of element i represents the color of the pixel in row i,
// column j of the image.  Your task is to stitch the two images
// together.  Specifically, image A goes to the left of image
// B and overlap pixels from the right of A and the
// left of B overlap.  To prevent any obvious artifacts from the
// stitching, you want to gradually blend the stitched region from
// image A to image B.  The ith pixel (indexed from 1) from the left in the
// overlapping region should have a value of
// 
// ((overlap+1-i)*a+(i*b))/(overlap+1) where a and b are
// the values of the pixels from A and B, respectively.  Hence, the leftmost 
// pixels in the overlapping
// region should have values of
// 
// (overlap*a+b)/(overlap+1).
// 
// In all cases, you should round the pixel values to the nearest
// integer, rounding 0.5 up.
// 
// 
// 
// DEFINITION
// Class:Stitch
// Method:stitch
// Parameters:vector <string>, vector <string>, int
// Returns:vector <string>
// Method signature:vector <string> stitch(vector <string> A, vector <string> B, 
// int overlap)
// 
// 
// CONSTRAINTS
// -A will contain between 1 and 50 elements, inclusive.
// -B will contain the same number of elements as A.
// -Each element of A will contain the same number of characters.
// -Each element of B will contain the same number of characters.
// -Each element of A and B will contain between overlap+1 and 50 characters, 
// inclusive.
// -overlap will be between 0 and 49, inclusive.
// -Each character in A and B will have ASCII value between 32 and 126, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"AAAAAA"}
// {"JJJJJ"}
// 4
// ((overlap+1-i)*a+(i*b))/(overlap+1)  -->   (4 * 3 + 4)/(5)   --> 16 / 5 
// Returns: { "AACEFHJ" }
// 
// First, line up the two images:
// 
//  AAAAAA
//    JJJJJ
// 
// Then, blend the overlapping region:
// 
//  AACEFHJ
// 
// 
// 1)
// {"14ABCD",
//  "25EFGH",
//  "36IJKL"}
// {"ABCD14",
//  "EFGH25",
//  "IJKL36"}
// 4
// 
// Returns: { "14ABCD14",  "25EFGH25",  "36IJKL36" }
// 
// 2)
// {" 32ygfd",
//  "3uh53G:",
//  ")O83gh3"}
// {"hsd$*(PH",
//  "3G:$)(*P",
//  "gh86$PBB"}
// 3
// 
// Returns: { " 32ygmd$*(PH",  "3uh53G:$)(*P",  ")O83gh76$PBB" }
// 
// 3)
// {"A"}
// {"A"}
// 0
// 
// Returns: { "AA" }
// 
// END CUT HERE
#line 98 "Stitch.cpp"
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

class Stitch {
	public:
	vector <string> stitch(vector <string> A, vector <string> B, int overlap) 
	{
		vector<string> result;

		for (int pos = 0; pos < A.size(); pos++) {
			string wordA = A[pos];
			string wordB = B[pos];
			int a = wordA.length() - overlap; 
			int b = 0; 

			string newWord = ""; 
			for (int i = 0; i < a; i++) {
				newWord += wordA[i];
			}

			for (int i = 1; i <= overlap; i++) {
				char cInA = wordA[a];
				char c = ceil((((overlap + 1.0 - i) * a + (i * b)) / (overlap + 1.0))) + cInA;
				cout << (((overlap + 1.0 - i) * a + (i * b)) / (overlap + 1.0)) << endl; 
				newWord += c; 
				a++; 
				b++;
			}

			for (int i = b; i < wordB.length(); i++) {
				newWord += wordB[i];
			}

			result.push_back(newWord);
		}

		return result;
	}
};
