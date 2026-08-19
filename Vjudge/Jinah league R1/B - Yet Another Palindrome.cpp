#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
//LLONG_MAX,LLONG_MIN

using namespace std;

signed main(){
    int t;
    cin >> t;
    while (t--){
        string s;
        map<char, int> characters;
        cin >> s;
        int n = s.size();
        for (int i=0; i<n; i++){
            characters[s[i]]++;
        }

        int doubles = 0;
        for (auto it : characters){
            if (it.second > 1){
                doubles++;
            }
        }
        if (doubles > 1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}