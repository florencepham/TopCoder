#include <iostream> 
#include <vector> 
#include <string> 
#include <sstream> 

using namespace std; 

class LostParentheses {
	public: 
	int minResult(string e) 
	{
		vector <int> list = parseString(e); 
		
		// sum non-negatives
		int sum = 0; 
		int negSum = 0; 

		for (int i = 0; i < list.size(); i++) {
			if (list[i] < 0) {
				sum += negSum; 
				negSum = list[i]; 
			} else if (negSum != 0) {
				negSum -= list[i]; 
			} else {
				sum += list[i]; 
			}
		}

		return sum + negSum; 
	}
	
	private: 
	vector <int> parseString(string e) 
	{
		vector<int> result; 
		
		string temp = "";
		bool pos = true; 

		for (int i = 0; i < e.length(); i++) {
			char c = e[i];
			if (c != '+' && c != '-') {
				temp += c;
				continue; 
			}

			if (pos == true) result.push_back(stoi(temp)); 
			else result.push_back(0 - stoi(temp)); 

			if (c == '+') pos = true; 
			else pos = false; 
			temp = ""; 
		}

		if (pos == true) result.push_back(stoi(temp)); 
		else result.push_back(0 - stoi(temp)); 
		return result; 
	}
};
