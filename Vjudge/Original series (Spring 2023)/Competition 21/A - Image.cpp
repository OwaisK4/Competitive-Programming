#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        map<char, int> mp;
        char temp;
        for (int i=0; i<4; i++){
            cin >> temp;
            mp[temp]++;
        }
        cout << mp.size() - 1 << "\n";
    }
    return 0;
}