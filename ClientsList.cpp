// BEGIN CUT HERE
// PROBLEM STATEMENT
// Your company has just undergone some software upgrades, and you will now be 
// storing all of the names of your clients in a new database.  Unfortunately, 
// your existing data is inconsistent, and cannot be imported as it is.  You have 
// been tasked with writing a program to cleanse the data.
// 
// You are given a vector <string>, names, which is a list of the names of all of 
// your existing clients.  Some of the names are in "First Last" format, while 
// the rest are in "Last, First" format.  You are to return a vector <string> 
// with all of the names in "First Last" format, sorted by last name, then by 
// first name.
// 
// 
// DEFINITION
// Class:ClientsList
// Method:dataCleanup
// Parameters:vector <string>
// Returns:vector <string>
// Method signature:vector <string> dataCleanup(vector <string> names)
// 
// 
// CONSTRAINTS
// -names will contain between 1 and 50 elements, inclusive.
// -Each element of names will be of the form "First Last" or "Last, First" 
// (quotes added for clarity).
// -Each first and last name will begin with a single capital letter 'A'-'Z', and 
// the remaining letters will be lower case 'a'-'z'.
// -Each element of names will contain between 3 and 50 characters, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {"Joe Smith", "Brown, Sam", "Miller, Judi"}
// 
// Returns: { "Sam Brown",  "Judi Miller",  "Joe Smith" }
// 
// The last names, in order, are Brown, Miller, Smith.  We rearrange each name to 
// be in the proper format also.
// 
// 1)
// {"Campbell, Phil", "John Campbell", "Young, Warren"}
// 
// Returns: { "John Campbell",  "Phil Campbell",  "Warren Young" }
// 
// Notice here how we sort by first name when the last names are the same.
// 
// 2)
// {"Kelly, Anthony", "Kelly Anthony", "Thompson, Jack"}
// 
// Returns: { "Kelly Anthony",  "Anthony Kelly",  "Jack Thompson" }
// 
// Be careful to properly identify first name versus last name!
// 
// 3)
// {"Trevor Alvarez", "Jackson, Walter", "Mandi Stuart",
//  "Martin, Michael", "Peters, Tammy", "Richard Belmont",
//  "Carl Thomas", "Ashton, Roger", "Jamie Martin"}
// 
// Returns: { "Trevor Alvarez",  "Roger Ashton",  "Richard Belmont",  "Walter 
// Jackson",  "Jamie Martin",  "Michael Martin",  "Tammy Peters",  "Mandi 
// Stuart",  "Carl Thomas" }
// 
// 4)
// {"Banks, Cody", "Cody Banks", "Tod Wilson"}
// 
// Returns: { "Cody Banks",  "Cody Banks",  "Tod Wilson" }
// 
// Notice that two identical names can appear in the list.
// 
// 5)
// {"Mill, Steve", "Miller, Jane"}
// 
// Returns: { "Steve Mill",  "Jane Miller" }
// 
// Notice that when shorter names precede longer names alphabetically, when the 
// shorter name is a substring of the longer.
// 
// END CUT HERE
#line 82 "ClientsList.cpp"
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

struct Name {
	string first = "no"; 
	string last = " no" ; 
}; 

bool sortName(Name A, Name B) {
	if (A.last == B.last) {
		return (A.first < B.first); 
	} else {
		return (A.last < B.last); 
	}
}

class ClientsList {
	public:
	vector <string> dataCleanup(vector<string> names) {
		vector<Name> list = parseName(names); 
		sort(list.begin(), list.end(), sortName); 
		vector<string> result = toString(list); 
		return result; 
	}

	private: 
	vector<Name> parseName(vector<string> names) {
		vector<Name> list; 
		Name newName;

		int L = names.size(); 
		for (int i = 0; i < L; i++) {
			string name = names[i]; 
			int f, l; 
			for (int j = 0; j < name.length(); j++) {
				if (name[j] == ',') {
					l = j - 1;  
					f = j + 2; 
					newName.last = name.substr(0, l + 1);
					newName.first = name.substr(f);
					break; 
				} else if (name[j] == ' ') {
					f = j - 1;  
					l = j + 1; 
					newName.last = name.substr(l);
					newName.first = name.substr(0, f + 1);
					break; 
				}
			}
			list.push_back(newName);
		}

		return list; 
	}

	vector<string> toString(vector<Name> names) {
		vector<string> list; 
		int L = names.size();
		for (int i = 0; i < L; i++) {
			list.push_back(names[i].first + " " + names[i].last); 
		}
		return list; 
	}
};
