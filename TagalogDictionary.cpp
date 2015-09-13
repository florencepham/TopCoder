// BEGIN CUT HERE
// PROBLEM STATEMENT
// 
// In the first half of the 20th century, around the time that Tagalog became the 
// national language of the Philippines, a standardized alphabet was introduced 
// to be used in Tagalog school books (since then, the national language has 
// changed to a hybrid "Pilipino" language, as Tagalog is only one of several 
// major languages spoken in the Philippines).
// 
// 
// Tagalog's 20-letter alphabet is as follows:
// 
// a b k d e g h i l m n ng o p r s t u w y
// 
// Note that not all letters used in English are present, 'k' is the third 
// letter, and 'ng' is a single letter that comes between 'n' and 'o'.
// 
// 
// You are compiling a Tagalog dictionary, and for people to be able to find 
// words in it, the words need to be sorted in alphabetical order with reference 
// to the Tagalog alphabet.  Given a list of Tagalog words as a vector <string>, 
// return the same list in Tagalog alphabetical order.
// 
// 
// DEFINITION
// Class:TagalogDictionary
// Method:sortWords
// Parameters:vector <string>
// Returns:vector <string>
// Method signature:vector <string> sortWords(vector <string> words)
// 
// 
// NOTES
// -Any 'n' followed followed by a 'g' should be considered a single 'ng' letter 
// (the one that comes between 'n' and 'o').
// 
// 
// CONSTRAINTS
// -words will contain between 1 and 50 elements, inclusive.
// -Each element of words will contain between 1 and 50 characters, inclusive.
// -Each character of each element of words will be a valid lowercase letter that 
// appears in the Tagalog alphabet.
// -Each element of words will be distinct.
// 
// 
// EXAMPLES
// 
// 0)
// {"abakada","alpabet","tagalog","ako"}
// 
// Returns: {"abakada", "ako", "alpabet", "tagalog" }
// 
// The tagalog word for "alphabet", a Tagalogization of the English word 
// "alphabet", the name of the language, and the word for "I".
// 
// 1)
// {"ang","ano","anim","alak","alam","alab"}
// 
// Returns: {"alab", "alak", "alam", "anim", "ano", "ang" }
// 
// A few "A" words that are alphabetically close together.
// 
// 2)
// {"siya","niya","kaniya","ikaw","ito","iyon"}
// 
// Returns: {"kaniya", "ikaw", "ito", "iyon", "niya", "siya" }
// 
// Common Tagalog pronouns.
// 
// 3)
// {"kaba","baka","naba","ngipin","nipin"}
// 
// Returns: {"baka", "kaba", "naba", "nipin", "ngipin" }
// 
// 4)
// {"knilngiggnngginggn","ingkigningg","kingkong","dingdong","dindong","
// dingdont","ingkblot"}
// 
// Returns: {"kingkong", "knilngiggnngginggn", "dindong", "dingdont", "dingdong", 
// "ingkblot", "ingkigningg" }
// 
// 5)
// {"silangang", "baka", "bada", "silang"}
// 
// Returns: {"baka", "bada", "silang", "silangang" }
// 
// 
// 
// END CUT HERE
#line 91 "TagalogDictionary.cpp"
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

class TagalogDictionary {
	public:
	vector <string> sortWords(vector <string> words) {
		
	}
};
