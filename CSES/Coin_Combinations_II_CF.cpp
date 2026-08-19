#include <bits/stdc++.h>
using namespace std;
// #define int long long

int mod = 1e9 + 7;
vector<vector<int>> dp;
vector<int> coin;

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
    dp.assign(n + 1, vector<int>(x + 1, 0));
    coin.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> coin[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - coin[i - 1] >= 0) {
                dp[i][j] += (dp[i][j - coin[i - 1]]);
                dp[i][j] %= mod;
            }
        }
    }
    // for (int i = 0; i < x; i++) {
    //     if (dp[i] > mod) {
    //         cout << dp[i] << " ";
    //     }
    // }
    // cout << "\n";
    cout << dp[n][x];
}