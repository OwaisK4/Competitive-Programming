#include <bits/stdc++.h>
#define int long long int
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
using namespace std;

signed main(){
    string s;
    cin >> s;

    for (int i=0; i<s.size()-1; i+=2){
        swap(s[i], s[i+1]);
    }
    cout << s;
    return 0;
}