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
    int a, K;
    cin >> a >> K;

    int next = a;
    for (int i=1; i<K; i++){
        string digits = to_string(next);
        int min_digit = *(min_element(all(digits))) - 48;
        int max_digit = *(max_element(all(digits))) - 48;

        if (min_digit == 0 || max_digit == 0)
            break;
        // cout << min_digit << " " << max_digit << "\n";
        next = next + (min_digit * max_digit);
    }
    cout << next << "\n";
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