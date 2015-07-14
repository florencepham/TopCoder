// BEGIN CUT HERE
// PROBLEM STATEMENT
// A sentence is called dancing if its first letter is uppercase and the case of 
// each subsequent letter is the opposite of the previous letter. Spaces should 
// be ignored when determining the case of a letter.  For example, "A b  Cd" is a 
// dancing sentence because the first letter ('A') is uppercase, the next letter 
// ('b') is lowercase, the next letter ('C') is uppercase, and the next letter 
// ('d') is lowercase.
// You will be given a string sentence. Turn the sentence into a dancing sentence 
// by changing the cases of the letters where necessary.  All spaces in the 
// original sentence must be preserved.
// 
// DEFINITION
// Class:DancingSentence
// Method:makeDancing
// Parameters:string
// Returns:string
// Method signature:string makeDancing(string sentence)
// 
// 
// CONSTRAINTS
// -sentence will contain between 1 and 50 characters, inclusive.
// -Each character in sentence will be a letter ('A'-'Z','a'-'z') or a space (' ').
// -sentence will contain at least one letter ('A'-'Z','a'-'z').
// 
// 
// EXAMPLES
// 
// 0)
// "This is a dancing sentence"
// 
// Returns: "ThIs Is A dAnCiNg SeNtEnCe"
// 
// 1)
// " This   is         a  dancing   sentence  "
// 
// Returns: " ThIs   Is         A  dAnCiNg   SeNtEnCe  "
// 
// Spaces should be ignored when determining the cases of the letters, but they 
// should be preserved in the return value.
// 
// 2)
// "aaaaaaaaaaa"
// 
// Returns: "AaAaAaAaAaA"
// 
// 3)
// "z"
// 
// Returns: "Z"
// 
// END CUT HERE
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

class DancingSentence {
	public:
	string makeDancing(string sentence) 
	{
		int i = 0; 
		bool Up = true; 

		while (sentence[i] == ' ' && i < sentence.length()) {
			i++; 
		}

		if (i >= sentence.length()) return sentence; 
		sentence[i] = toupper(sentence[i]); 

		for (i = i + 1; i < sentence.length(); i++) {
			if (sentence[i] == ' ') {
				continue; 
			}
			if (Up == true) {
				sentence[i] = tolower(sentence[i]);
				Up = false; 
			} else {
				sentence[i] = toupper(sentence[i]);
				Up = true; 
			}
		}

		return sentence; 
	}
};
