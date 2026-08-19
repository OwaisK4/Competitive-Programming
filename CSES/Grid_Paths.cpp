#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

int MOD = 1e9 + 7;
vector<vector<char>> grid;
vector<vector<int>> dp;

signed main() {
    fastio;
    int n;
    cin >> n;
    grid.assign(n, vector<char>(n));
    dp.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    if (grid[0][0] == '*') {
        cout << 0;
        return 0;
    }

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + 1 < n && grid[i][j + 1] == '.') {
                dp[i][j + 1] += dp[i][j];
                dp[i][j + 1] %= MOD;
            }
            if (i + 1 < n && grid[i + 1][j] == '.') {
                dp[i + 1][j] += dp[i][j];
                dp[i + 1][j] %= MOD;
            }
        }
    }
    cout << dp[n - 1][n - 1];

    return 0;
}