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
    int n, s;
    cin >> n >> s;
    vector<int> array(n), prefix(n+1, 0);
    int total = 0;
    for (int i=0; i<n; i++){
        cin >> array[i];
        total += array[i];
    }
    if (total < s){
        cout << -1 << "\n";
        return;
    }
    partial_sum(all(array), prefix.begin() + 1);
    // print(prefix);
    
    int max_elements = 0;
    int l = 0;
    int r = 0;
    while (r <= n){
        if ((prefix[r] - prefix[l]) == s){
            max_elements = max(max_elements, r - l);
            r++;
        }
        else if ((prefix[r] - prefix[l]) < s){
            r++;
        }
        else{
            l++;
        }
    }
    int operations = n - max_elements;
    cout << operations << "\n";
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