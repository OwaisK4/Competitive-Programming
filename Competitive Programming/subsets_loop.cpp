#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void subsets(vector<int>& set, vector<vector<int>>& total, vector<int>& subset, int index){
    total.push_back(subset);
    for (int i=index; i<set.size(); i++){
        subset.push_back(set[i]);
        subsets(set, total, subset, i+1);
        subset.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    vector<int> set{1,2,3,4};
    vector<vector<int>> total;
    vector<int> subset;
    subsets(set, total, subset, 0);
    for (auto& it : total){
        for (auto& jt : it){
            cout << jt << " ";
        }
        cout << "\n";
    }
    return 0;
}