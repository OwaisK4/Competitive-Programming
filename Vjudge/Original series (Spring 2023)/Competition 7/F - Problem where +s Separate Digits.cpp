#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void subsets(string set, string subset, int index){
    cout << subset << "\n";
    for (int i=index; i<set.size(); i++){
        // subset.push_back(set[i]);
        subset += set[i];
        subsets(set, subset, i+1);
        subset.erase(subset.end() - 1);
        // subset.pop_back();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string S;
    getline(cin, S);
    subsets(S, "", 0);
    return 0;
}