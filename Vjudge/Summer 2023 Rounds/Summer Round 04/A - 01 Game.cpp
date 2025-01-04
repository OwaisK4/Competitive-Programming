#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> array){
    for (auto it : array){
        cout << it << " ";
    }
    cout << "\n";
}

void solve(){
    string s;
    cin >> s;
    int counter = 0;
    int i = 0;
    while (i < (s.size()-1) && s.size() > 0){
        if (s[i] != s[i+1]){
            s.erase(i, 2);
            counter = ~(counter);
            i = 0;
            continue;
        }
        i++;
    }
    if (counter == -1){
        cout << "DA\n";
    }
    else{
        cout << "NET\n";
    }
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}