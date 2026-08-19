#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
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

vector<vector<int>> dp;

signed main() {
    fastio;
    vector<pair<int, int>> array = {{30, 35}, {35, 15}, {15, 5}, {5, 10}, {10, 20}, {20, 25}};

    int n = array.size();
    dp.assign(n + 1, vector<int>(n + 1, 0));

    for (int z = 1; z < n; z++) {
        for (int i = 1; i < n; i++) {
            // for (int j = i + 1; j <= n; j++) {
            int j = i + z;
            if (j > n) {
                continue;
            }
            dp[i][j] = LONG_LONG_MAX;
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + array[i - 1].first * array[k].first * array[j - 1].second);
            }
            // }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}