#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
int MOD = (int)1e9 + 7;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

int total_ways = 1;
vector<vector<int>> dp;

signed main(signed argc, char **argv) {
    fastio;
    // file_write("/home/owaisk4/Win_backup/Speed Programming/CSES/output_array_description");
    int n, m;
    cin >> n >> m;
    vector<int> x(n);

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    if (n == 1 && x[0] == 0) {
        cout << m;
        return 0;
    }

    dp.assign(n + 1, vector<int>(m, 0));
    bool valid = true;

    for (int i = 1; i <= n; i++) {
        int ways = 0;
        // Edge case #01: If start of array is 0.
        if (i == 1 && x[i - 1] == 0) {
            dp[i].assign(m, 1);
            continue;
        }
        // Edge case #02: If end of array is 0.
        if (i == n && x[i - 1] == 0) {
            ways += dp[i - 1][0];
            if (m >= 2)
                ways += dp[i - 1][1];
            for (int j = 1; j < m - 1; j++) {
                ways += dp[i - 1][j - 1];
                ways += dp[i - 1][j];
                ways += dp[i - 1][j + 1];
            }
            ways += dp[i - 1][m - 1];
            if (m >= 2)
                ways += dp[i - 1][m - 2];
            if (ways > 0) {
                ways %= MOD;
                total_ways *= ways;
            }
            total_ways %= MOD;
            continue;
        }
        if (i == 1 && x[i - 1] > 0 || i > 1 && x[i - 1] > 0 && x[i - 2] == 0) {
            if (x[i - 1] + 1 <= m) {
                ways += dp[i - 1][x[i - 1]];
            }
            if (x[i - 1] - 2 >= 0) {
                ways += dp[i - 1][x[i - 1] - 2];
            }
            ways += dp[i - 1][x[i - 1] - 1];
            dp[i][x[i - 1] - 1] = 1;

            if (ways > 0) {
                ways %= MOD;
                total_ways *= ways;
            }
            if (i > 1 && ways == 0) {
                valid = false;
                break;
            }
            total_ways %= MOD;
            continue;
        }

        if (i > 1 && x[i - 1] > 0 && x[i - 2] > 0) {
            if (abs(x[i - 1] - x[i - 2]) > 1) {
                valid = false;
                break;
            }
            dp[i][x[i - 1] - 1] = 1;
            continue;
        }

        dp[i][0] += dp[i - 1][0];
        if (m >= 2)
            dp[i][0] += dp[i - 1][1];
        dp[i][0] %= MOD;

        for (int j = 1; j < m - 1; j++) {
            dp[i][j] += dp[i - 1][j - 1];
            dp[i][j] += dp[i - 1][j];
            dp[i][j] += dp[i - 1][j + 1];
            dp[i][j] %= MOD;
        }
        dp[i][m - 1] += dp[i - 1][m - 1];
        if (m >= 2)
            dp[i][m - 1] += dp[i - 1][m - 2];
        dp[i][m - 1] %= MOD;
    }

    // for (int i = 1; i <= n; i++) {
    //     print(dp[i]);
    // }

    if (!valid) {
        cout << 0;
    } else {
        total_ways %= MOD;
        cout << total_ways;
    }

    return 0;
}