#include <bits/stdc++.h>
using namespace std;
#define int long long

int mod = 1e9 + 7;
int dp[1000001];
int coin[100];

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

signed main() {
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    sort(coin, coin + 100);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= x; j++) {
            if (j - coin[i] >= 0) {
                dp[j] += dp[j - coin[i]];
                dp[j] %= mod;
            }
        }
    }
    // for (int i = 0; i < x; i++) {
    //     if (dp[i] > mod) {
    //         cout << dp[i] << " ";
    //     }
    // }
    // cout << "\n";
    cout << dp[x];
}