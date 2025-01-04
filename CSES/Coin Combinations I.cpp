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
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i - coin[j] >= 0) {
                dp[i] += dp[i - coin[j]];
            }
        }
        dp[i] %= mod;
    }
    cout << dp[x];
}