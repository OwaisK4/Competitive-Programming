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
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> count;
    int temp;
    for (int i=0; i<n; i++){
        cin >> a[i];
        count[a[i]]++;
    }

    map<int, int, greater<int>> freq_count;
    for (auto & [key, value] : count){
        freq_count[value]++;                        
    }
    
    int max_count = freq_count.begin()->first;
    int minimum = freq_count.begin()->second;
    freq_count.erase(freq_count.begin());

    for (auto & [key, value] : freq_count){
        minimum -= value;
    }
    cout << minimum << "\n";
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