#include <iostream>
#include <vector> 
#include <string> 

using namespace std; 

class BusinessTasks 
{
	public: 
	string getTask(vector <string> list, int n) {
		int curr = 0;
		while (list.size() > 1) {
			curr = (curr + (n - 1)) % list.size();
			list.erase(list.begin() + curr);
			curr = curr % list.size();
		}
		return list.at(curr);
	}
};
