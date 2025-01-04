#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> &array, int size = numeric_limits<int>::max()) {
    for (int i = 0; i < min<int>(size, array.size()); i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}
template <typename T>
void print(T X) {
    cout << X << "\n";
}
vector<vector<int>> dp;

signed main() {
    fastio;
    string s1, s2;
    cin >> s1 >> s2;

    int m = s1.size();
    int n = s2.size();
    dp.assign(m + 1, vector<int>(n + 1, 0));
    for (int a = 1; a <= m; a++) {
        for (int b = 1; b <= n; b++) {
            if (a == 1) {
                dp[a][b] = b;
                continue;
            }
            if (b == 1) {
                dp[a][b] = a;
                continue;
            }
            int cost = (s1[a - 1] == s2[b - 1]) ? 0 : 1;
            dp[a][b] = min({dp[a - 1][b] + 1, dp[a][b - 1] + 1, dp[a - 1][b - 1] + cost});
        }
    }
    // cout << dp[m][n];
    for (auto &it : dp) {
        print(it);
    }

    return 0;
}