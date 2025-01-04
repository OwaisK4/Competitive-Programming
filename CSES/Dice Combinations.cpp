#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define MOD 1e9 + 7
using namespace std;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

vector<int> dp;
vector<int> dice = {1, 2, 3, 4, 5, 6};

void fill_dp(int n) {
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (auto it : dice) {
            if (i - it >= 0) {
                dp[i] += dp[i - it];
                if (dp[i])
                    dp[i] %= (int)MOD;
            }
        }
    }
}

signed main() {
    fastio;
    dp.assign((int)1e6, 0LL);
    int n;
    cin >> n;
    fill_dp(n);
    cout << dp[n];

    return 0;
}