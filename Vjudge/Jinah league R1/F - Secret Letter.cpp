#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
//LLONG_MAX,LLONG_MIN

using namespace std;

signed main(){
    map<char, int> chars;
    string s1, s2;

    getline(cin, s1);
    getline(cin, s2);

    for (int i=0; i<s1.size(); i++){
        chars[s1[i]]++;
    }

    // for (auto it : chars){
    //     cout << it.first << " = " << it.second << "\n";
    // }

    
    for (int i=0; i<s2.size(); i++){
        if (s2[i] == ' ')
            continue;
        if (chars[s2[i]] > 0){
            chars[s2[i]]--;
        }
        else{
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";

    return 0;
}