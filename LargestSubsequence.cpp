//#line 65 "LargestSubsequence.cpp"
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

class LargestSubsequence {
	public:
	string getLargest(string s)
    {
        int i = 0;
        string result = "";
        while (i < s.size()) {
            int j = findLargest(s, i);
            result += s[j];
            i = j + 1;
        }
        
        return result;
	}
    
    private:
    int findLargest(string s, int start)
    {
        int largest = start;
        
        for (int i = start + 1; i < s.size(); i++) {
            if (s[i] > s[largest]) {
                largest = i;
            }
        }
        return largest;
    }
};


// Powered by FileEdit
