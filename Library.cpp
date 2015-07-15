//#line 90 "Library.cpp"
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

class Library {
	public:
	int documentAccess(vector <string> records, vector <string> userGroups, vector <string> roomRights) 
	{
		map<string, bool> userAccess;
		map<string, bool> roomAccess;
		map<string, bool> libRecords; 

		for (int i = 0; i < userGroups.size(); i++) {
			userAccess[userGroups[i]] = true;
		}

		for (int i = 0; i < roomRights.size(); i++) {
			roomAccess[roomRights[i]] = true; 
		}

		int num = 0; 
		for (int i = 0; i < records.size(); i++) {
			vector<string> info = parseInfo(records[i]);

			string name = info[0];
			string room = info[1];
			string user = info[2]; 

			if (libRecords.count(name) == 0) {
				if (roomAccess[room] == true && 
					userAccess[user] == true) {
					libRecords[name] = true; 
					num++; 
				} 
				
			} 

		}

		return num;
	}

	private: 
	vector <string> parseInfo(string record) {
		vector <string> info; 
		string curWord = "";
		for (int i = 0; i < record.length(); i++) {
			if (record[i] == ' ') {
				info.push_back(curWord);
				curWord = ""; 
			} else {
				curWord += record[i];
			}
		} 
		info.push_back(curWord);
		return info;
	}
};


// Powered by FileEdit
