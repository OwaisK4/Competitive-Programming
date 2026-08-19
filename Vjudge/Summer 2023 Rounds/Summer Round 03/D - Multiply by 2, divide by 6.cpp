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
    if (n == 1){
        cout << "0" << "\n";
        return;
    }
    int moves = 0;
    while (n > 1){
        if (n % 6 == 0){
            n /= 6;
            moves++;
        }
        else if ((n * 2) % 6 == 0){
            n *= 2;
            n /= 6;
            moves += 2;
        }
        else{
            cout << "-1" << "\n";
            break;
        }
    }
    if (n == 1){
        cout << moves << "\n";
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