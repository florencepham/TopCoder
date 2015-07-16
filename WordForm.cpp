// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// In English, the letters A, E, I, O and U are the vowels. Y is also
// considered to be a vowel if it's not preceded by another vowel and is not the 
// first letter in a word (the fact that a vowel is defined to some extent in 
// terms of itself does not make it ambiguous). If a letter is not a vowel then 
// it is a consonant. So in "TOY" the consonants are T and Y, and in "SYZYGY" 
// they are S, Z and G. 
// 
// 
// 
// A sequence of vowels will be denoted by uppercase letter 'V' and a sequence of 
// consonants will be denoted by uppercase letter 'C'. A word can then be 
// described as an alternating sequence of 'C' and 'V'. For instance, the word 
// "WHEREABOUTS" has the sequence CVCVCVC, and the words "YORK" and "TOY" both 
// have the sequence CVC. It's not permissible to have two or more consecutive 
// 'V' or 'C' in the sequence.
// 
// 
// Create a class WordForm containing the method getSequence which takes a string 
// word and returns a string containing the word's sequence as described above. 
// The word may contain both uppercase and lowercase letters, but your method 
// should be case insensitive (see example 2).
// 
// 
// DEFINITION
// Class:WordForm
// Method:getSequence
// Parameters:string
// Returns:string
// Method signature:string getSequence(string word)
// 
// 
// NOTES
// -word may not be an English word, or a word in any language at all, but you 
// should still use the rules defined above. See example 3.
// 
// 
// CONSTRAINTS
// -word will contain between 1 and 50 characters, inclusive.
// -word will only contain the characters 'A'-'Z' and 'a'-'z', both inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// "WHEREABOUTS"
// 
// Returns: "CVCVCVC"
// 
// Here we have consonant-consonant-vowel-consonant-vowel-vowel-consonant-vowel-
// vowel-consonant-consonant. Putting together consecutive consonants and vowels 
// gives us CVCVCVC.
// 
// 
// 1)
// "yoghurt"
// 
// Returns: "CVCVC"
// 
// 2)
// "YipPy"
// 
// Returns: "CVCV"
// 
// Mixing lowercase and uppercase does not affect the result.
// 
// 
// 3)
// "AyYyEYye"
// 
// Returns: "VCVCVCV"
// 
// Even though this isn't an English word, we use the rules defined in the 
// statement to find the consonant-vowel pattern.
// 
// 
// 4)
// "yC"
// 
// Returns: "C"
// 
// END CUT HERE
//#line 86 "WordForm.cpp"
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

class WordForm {
	public:
	string getSequence(string word) 
	{
		string result = ""; 
		for (int i = 0; i < word.length(); i++) {
			switch(tolower(word[i])) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
					if (result[result.length() - 1] == 'C' || i == 0) {
						result.push_back('V');
					} 
					continue; 
				case 'y':
					if (result[result.length() - 1] == 'C' && i != 0) {
						result.push_back('V');
					} else {
						result.push_back('C');
					}
					continue; 
				default: 
					if (result[result.length() - 1] == 'V' || i == 0) {
						result.push_back('C');
					} 
					continue; 
				}
		}
		return result; 
	}
};
