#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
using namespace std;

int main(){
	vector<vector<int>> compatible{
		{1, 2},
		{3 ,4, 5},
		{6 ,7, 8, 9}
	};
	compatible[0].push_back(5);
	compatible.push_back(vector<int>());
	compatible[0].push_back(5);
	for (auto it = compatible.begin(); it != compatible.end(); it++){
		for(auto jt = it->begin() ; jt<it->end() ; jt++){
			cout << *jt << " ";
		}
	}
	return 0;
}
