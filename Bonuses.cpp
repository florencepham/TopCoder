// replace each element in the vector with percentage 
// find the left over percentage 
// after that write a function that sort the percentage, and organize them as their indices
// increament n element s 

#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

class Bonuses {
	public: 
	vector<int> getDivision(vector <int> points) 
	{
		int sumPoints = 0; 
		for (int i = 0; i < points.size(); i++) {
			sumPoints += points.at(i); 
		}
		
		cout << sumPoints << endl;
		int sumPercent = 0; 
		for (int i = 0; i < points.size();i++) {
			int point = points.at(i);
			points.at(i) = point * 100 / sumPoints;
			sumPercent += points.at(i);
		}
		
		if (sumPercent < 100) {
			int buffer[points.size()]; 

			buffer[0] = 0;
			int sizeBuffer = 1; 
			for (int i = 1; i < points.size(); i++) {
				cout << i << endl;
				int value = points.at(i);
				int j = i; 
				while (points.at(buffer[j]) < value && j >= 0) {
					buffer[j + 1] = buffer[i];
					j--; 
				} 
				buffer[j] = i; 
				sizeBuffer++;

				for (int k = 0; k < sizeBuffer; k++) {
					cout << sizeBuffer << " " << k << " " << buffer[k] << " " << points.at(buffer[k]) << endl;
				}
				cout << "here " << endl;
			}
		
			for (int k = 0; k < 100 - sumPercent; k++) {
				points.at(buffer[k])++;
			}
		}
		
		return points;
	}	
};
