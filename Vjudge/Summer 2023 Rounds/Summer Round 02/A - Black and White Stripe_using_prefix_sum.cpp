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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> prefix(n+1, 0);

    prefix[0] = 0;
    for (int i=0; i<n; i++){
        if (s[i] == 'W'){
            prefix[i+1] = 1;
        }
    }
    partial_sum(all(prefix), prefix.begin());

    int l = 1;
    int r = k;

    int count = prefix[k] - prefix[l - 1];
    int min_count = count;

    while (r <= n){
        count = prefix[r] - prefix[l - 1];
        min_count = min(min_count, count);
        l++;
        r++;
    }
    cout << min_count << "\n";
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