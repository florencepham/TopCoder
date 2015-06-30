//#line 106 "Boxing.cpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <map> 
#include <queue> 
#include <stack> 
#include <vector>

using namespace std; 

typedef vector <int> VI;

class Boxing {
	public:
	int maxCredit(vector <int> a, vector <int> b, vector <int> c, vector <int> d, vector <int> e) {
            // Let N denotes the number of button pressed
            // For each button pressed, sort the activities time and the judge number
            // Let G denotes the group of judges that have pressed the buttons in that time inteval
            // A denotes the start time and finish time of the intervals that will be selected
            // J Denotes the last activity selected
        
            // For I = 2 to N
            // If it is below 1000 from the previous finishTime
            //
            // We can group the activity time into the current group only if
            //      - it is below 1000 from the start time
            // selected has already been finished
            // If the next I is equal to the current finish, skip it
            // end
        
        vector<VI> list = {a, b, c, d, e};
        int N = totalTime(list);
        int numInterval = 0;

        while (N > 0) {
            int begin = smallestTime(list);
            int end = begin;

            VI nextThree = {}; 

            while (nextThree.size() != 3) {
                nextThree = findNextTime(list, begin);
                if (nextThree.size() < 3) {
                    list = removeUpTo(list, begin);
                    N = totalTime(list);
                    continue;
                }
            }

            cout << "begin " << begin << " end " << end << " " << numInterval << endl; 
            list = removeUpTo(list, end);
            N = totalTime(list);
            numInterval++;
        }
        
        return numInterval;
	}
    
    private:

    int smallestTime(vector<VI> list) 
    {
        int begin = 180000; 

        for (int i = 0; i < list.size(); i++) {
            if (list[i].size() > 0) {
                if (list[i][0] < begin) {
                begin = list[i][0]; 
                }
            }
        }
        return begin;
    }

    VI findNextTime(vector<VI> list, int begin) 
    {
        VI result; 
        bool judges[5] = {false, false, false, false, false};

        for (int i = 0; i < list.size(); i++) {
            VI curJudge = list[i];
            for (int j = 0; j < curJudge.size(); j++) {
                if (result.size() == 3) {
                    return result; 
                }
                if (curJudge[j] - begin <= 1000 && 
                    judges[i] == false) {
                    judges[i] = true;
                    result.push_back(curJudge[j]);
                }
            }
        }
        return result;
    }
    
    vector<VI> removeUpTo(vector<VI> list, int end) 
    {
        for (int i = 0; i < list.size(); i++) {
            while (list[i].size() > 0) {
                if (list[i][0] <= end) {
                    list[i].erase(list[i].begin());
                } else {
                    break;
                }
            }
        }
        return list;
    }
    
    int totalTime(vector<VI> list) 
    {
        int sum = 0;
        for (int i = 0; i < list.size(); i++) {
            sum += list[i].size();
        }
        return sum;
    }
    
};


// Powered by FileEdit


// Powered by FileEdit
