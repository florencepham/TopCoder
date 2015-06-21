
#include <iostream> 
#include <string>
#include <vector>
#include <algorithm> 

using namespace std; 

class IPConverter {
	public:
	vector <string> possibleAddresses(string ambiguousIP) 
	{
		vector <string> result; 

		if (ambiguousIP.length() > 16) {
			return result; 
		}

		int numDot = 0; 

		for (int i = 1; i <= 3; i++) {
			result = findIP(result, ambiguousIP, 0, i, numDot);
		}

		int size = result.size(); 
		sort(result.begin(), result.begin() + size);
		return result; 
	}

	private: 
	vector <string> findIP(vector <string> result, string ambiguousIP, int prevDot, int length, int numDot) 
	{
		if (numDot > 3) {
			return result;
		}
		if (prevDot + length >= ambiguousIP.length()) {
			return result; 
		}
		
		ambiguousIP.insert(prevDot + length, 1, '.');
		numDot++; 
		prevDot += length; 

		if ((numDot == 3) && isValid(ambiguousIP)) {
			result.push_back(ambiguousIP);
		}
		
		for (int i = 1; i <= 3; i++) {
			result = findIP(result, ambiguousIP, prevDot + 1, i, numDot);
		}

		return result;
	}

	bool isValid(string ambiguousIP) 
	{
		int numDot = 1;
		int dotPos[5]; 
		dotPos[0] = -1; 
		dotPos[4] = ambiguousIP.length(); 

		for (int i = 0; i < ambiguousIP.length(); i++) {
			if (ambiguousIP[i] == '.') {
				dotPos[numDot] = i;
				numDot++;
			}
		}

		for (int i = 0; i < 4; i++) {
			int L = dotPos[i + 1] - dotPos[i] - 1;
			string substring = ambiguousIP.substr(dotPos[i] + 1, L);
			if (((L > 1) && (substring[0] == '0')) || (stoi(substring) > 255)) {
				return false;
			}
		}
		return true; 
	}
};

