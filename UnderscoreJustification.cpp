// BEGIN CUT HERE
// PROBLEM STATEMENT
// Most word processors available today allow several standard ways to format 
// lines in a paragraph.  One of those ways is to 'justify' each line to a given 
// width.  The precise definition for that operation is as follows:
// Assume that a line of text consists of several words separated by spaces (for 
// simplicity, there will be no punctuation).  Define a gap as the sequence of 
// spaces between a pair of adjacent words.  When reformatting a line, each gap 
// can be replaced with a gap of a different non-zero length.  The line is said 
// to be justified to width w if it is exactly w characters long, has no leading 
// or trailing spaces, and all gaps are as evenly distributed as possible.  This 
// means that the gaps should all be of equal length, or, if that is not 
// possible, the difference in length between the longest and smallest gaps must 
// be 1.
// To better illustrate the results of the justification operation, we will use 
// underscores ('_') in place of spaces.
// Obviously, the above rules don't uniquely define the result of a 
// justification.  If there are multiple ways to justify a line of text, the one 
// that comes earliest lexicographically is used.  Note that an underscore comes 
// after uppercase letters but before lowercase letters in the ASCII ordering.
// You are given a vector <string> words containing all the words in a line of 
// text.  The words are given in the order that they appear in the line.  Return 
// the line of text justified to the given width, using underscores as spaces.
// 
// 
// DEFINITION
// Class:UnderscoreJustification
// Method:justifyLine
// Parameters:vector <string>, int
// Returns:string
// Method signature:string justifyLine(vector <string> words, int width)
// 
// 
// NOTES
// -Note that you must make all the gaps have equal length if possible.  Only if 
// that is impossible, the longest gap will be one longer than the shortest.
// -Remember that 'A' < 'B' < 'C' < ... < 'Z' < '_' < 'a' < 'b' < 'c' < ... < 'z'.
// -A string is lexicographically smaller than another string if it contains a 
// smaller character in the first position where they differ.
// 
// 
// CONSTRAINTS
// -words will contain between 2 and 10 elements, inclusive.
// -Each element of words will contain between 1 and 10 characters, inclusive.
// -Each element of words will contain only letters ('A'-'Z', 'a'-'z').
// -width will be between 3 and 200, inclusive.
// -width will be greater than or equal to len+n-1, where n is the number of 
// elements in words, and len is the total number of characters in words, to 
// allow at least one space between adjacent words.
// 
// 
// EXAMPLES
// 
// 0)
// {"A", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"}
// 50
// 
// Returns: "A___quick__brown__fox__jumps__over__the__lazy__dog"
// 
// We have 7 groups of 2 underscores and 1 group of 3 underscores to put between 
// our words. If the first gap contains 2 underscores, then the string would 
// start with "A__q", which is lexicographically larger than "A___", so it's 
// advantageous to put 3 underscores in the first gap.
// 
// 1)
// {"Alpha", "Beta", "Gamma", "Delta", "Epsilon"}
// 32
// 
// Returns: "Alpha_Beta_Gamma__Delta__Epsilon"
// 
// There are six possible variants:
// Alpha_Beta_Gamma__Delta__Epsilon
// Alpha_Beta__Gamma_Delta__Epsilon
// Alpha_Beta__Gamma__Delta_Epsilon
// Alpha__Beta_Gamma_Delta__Epsilon
// Alpha__Beta_Gamma__Delta_Epsilon
// Alpha__Beta__Gamma_Delta_Epsilon
// The former is the lexicographically smallest one.
// 
// 
// 2)
// {"Hello", "world", "John", "said"}
// 29
// 
// Returns: "Hello____world___John____said"
// 
// Sometimes it's better to mix large and small groups of underscores.
// 
// END CUT HERE
//#line 91 "UnderscoreJustification.cpp"
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

class UnderscoreJustification {
	public:
	string justifyLine(vector <string> words, int width) {
		int gapL; 
		int extraS; 
		int numS = width; 
		int numG = words.size() - 1; 

		for (int i = 0; i < words.size(); i++) {
			numS -= words[i].length(); 
		}
		extraS = numS % numG;
		gapL = numS / numG;

		string smallest = words[0]; 

		for (int i = 1; i < words.size(); i++) {
			cout << extraS << " " << numG << endl; 
			if (((extraS <= 0) || (extraS == numG)) && (words[i][0] <= 'Z')) {
				cout << "less " << endl; 
				string lessSpace = smallest + addSpaces(gapL) + words[i]; 
				smallest = lessSpace;
			} else {
								cout << "more " << endl; 

				string moreSpace = smallest + addSpaces(gapL + 1) + words[i]; 
				extraS--; 
				smallest = moreSpace; 
			}
			numG--; 
		}

		cout << smallest << endl;
		for (int i = 0; i < smallest.size(); i++) {
			if (smallest[i] == ' ') {
				smallest[i] = '_';
			}
		}
		return smallest; 
	}

	private: 
	string addSpaces(int num) {
		string result = ""; 

		for (int i = 0; i < num; i++) {
			result += " ";
		}

		return result; 
	}
};
