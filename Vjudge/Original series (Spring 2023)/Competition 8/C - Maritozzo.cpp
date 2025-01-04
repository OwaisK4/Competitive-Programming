#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(){
    vector<string> S(4);
    string T;
    string answer;
    for (int i=1; i<=3; i++){
        cin >> S[i];
    }
    cin >> T;
    for (auto it : T){
        string temp = string(1, it);
        answer += S[stoi(temp)];
    }
    cout << answer;
    return 0;
}