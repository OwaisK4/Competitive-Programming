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
    int i, n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    deque<char> slider;
    int count = 0, min_count = 0;
    for (i=0; i<k; i++){
        if (s[i] == 'W'){
            count++;
        }
        slider.push_back(s[i]);
    }
    min_count = count;
    for (i=k; i<n; i++){
        if (s[i] == 'W'){
            count++;
        }
        if (slider.front() == 'W'){
            count--;
        }
        slider.push_back(s[i]);
        slider.pop_front();
        min_count = min(min_count, count);
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