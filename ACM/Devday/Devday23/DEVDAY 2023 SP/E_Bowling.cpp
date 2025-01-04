#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long
using namespace std;

signed main(){
    string S;
    cin >> S;
    
    int N = 10;
    vector<vector<char>> pins(7, vector<char>());

    pins[0].push_back(S[6]);
    pins[1].push_back(S[3]);
    pins[2].push_back(S[7]);
    pins[2].push_back(S[1]);
    pins[3].push_back(S[4]);
    pins[3].push_back(S[0]);
    pins[4].push_back(S[8]);
    pins[4].push_back(S[2]);
    pins[5].push_back(S[5]);
    pins[6].push_back(S[9]);

    if (S[0] != '0'){
        cout << "No";
        return 0;
    }
    for (int i=0; i<7; i++){
        if (count(all(pins[i]), '1') == 0){
            bool left = false;
            bool right = false;
            for (int j=i-1; j>=0; j--){
                if (count(all(pins[j]), '1') != 0){
                    left = true;
                }
            }
            for (int j=i+1; j<7; j++){
                if (count(all(pins[j]), '1') != 0){
                    right = true;
                }
            }
            if (left && right){
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";

    return 0;
}