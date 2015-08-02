// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// 
// In the grafix file format, a bitmap is encoded as a
// sequence of lowercase alphabetic words. All of these words are drawn from
// a dictionary that has been built specially for the bitmap by a compression
// algorithm. Each word in the dictionary has the same length.
// 
// 
// 
// 
// 
// It can occur that words in a grafix file are corrupted by poor
// transmission or storage media. In such cases, grafix attempts to
// reconstruct the original file by matching each corrupted word to a
// dictionary word that contains one or more of the same characters at the same
// positions.
// 
// 
// 
// 
// You are given a vector <string>, dictionary, containing
// every word in a grafix file's dictionary, and a string,
// candidate, which is a possibly corrupted word in that file. If
// there is no dictionary word that has at least one character in the
// same position as candidate, then return the int
// value -1. Otherwise, return the zero-based index of the dictionary word
// that has the greatest number of characters at the same positions as
// candidate. In the event of a tie, favor the lowest index.
// 
// 
// 
// 
// DEFINITION
// Class:grafixCorrupt
// Method:selectWord
// Parameters:vector <string>, string
// Returns:int
// Method signature:int selectWord(vector <string> dictionary, string candidate)
// 
// 
// CONSTRAINTS
// -dictionary contains between 1 and 50 elements, inclusive
// -candidate is between 1 and 20 characters long, inclusive
// -each element of dictionary has the same length as candidate
// -only the characters 'a' to 'z' are permitted in candidate and dictionary
// 
// 
// EXAMPLES
// 
// 0)
// {"cat", "cab", "lab"}
// "dab"
// 
// Returns: 1
// 
// The word "dab" has two letters in the same position as both "cab" and "lab", 
// but "cab" comes first.
// 
// 1)
// {"cat", "cab", "lab"}
// "lag"
// 
// Returns: 2
// 
// Here, "lab" is the best fit.
// 
// 2)
// {"cat", "cab", "lab"}
// "bic"
// 
// Returns: -1
// 
// The word "bic" contains a 'c' and a 'b', but neither character is at the same 
// position in any dictionary word.
// 
// 3)
// {"zkv", "izs", "fed", "waa", "ttx", "bgt", "quy", "dtq", "dgo", "yrs",
//  "cid", "nln", "pvz", "txt", "zun", "erd", "jen", "klh", "kxy", "emf",
//  "mqt", "lza", "dzb", "ndx", "vfr", "jhs", "dkm", "elb"}
// "cwd"
// 
// Returns: 10
// 
// 4)
// {"zhadjsg", "vzptftx", "fbaslxs", "ejejncm", "xpxkeae", "ixrrtzw",
//  "ovctbzx", "sfzekhh", "lxzixjk", "jixdpik", "bkianck", "laclyin",
//  "uqmdkfx", "dimswqo", "fojhetr", "grntrce", "obdtqwx", "bhojwcy",
//  "zuuuvst", "mvqtoly", "aftmupx", "govuidx", "qklpret", "yptccki",
//  "uxdnslh", "wudrusz", "uwxbvou", "ouytqun", "pjdexqe", "xraaqdw",
//  "lxmoncl", "sjnjfgb", "qrlqgvc", "fgvoadm", "yohsrxw", "udpvrsr",
//  "mklucgt"}
// "vklikgf"
// 
// Returns: 36
// 
// END CUT HERE
// iterate and keep the max number of the same index
//#line 100 "grafixCorrupt.cpp"
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

class grafixCorrupt {
	public:
	int selectWord(vector <string> dictionary, string candidate) 
	{
		int bestMatch = 0; 
		string bestWord = ""; 
		int bestLength = 0; 

		int N = dictionary.size();
		for (int i = 0; i < N; i++) {
			string word = dictionary[i]; 
			int L = 0; 
			for (int j = 0; j < candidate.length(); j++) {
				if (candidate[j] == word[j]) {
					L++; 
				}
			}

			if ((L > bestLength) || 
				(bestWord == "") || 
				(L == bestLength && word < bestWord)) {
					bestMatch = i; 
					bestWord = word; 
					bestLength = L; 
			}
		}

		if (bestWord == "") return -1; 
		return bestMatch; 
	}
};
