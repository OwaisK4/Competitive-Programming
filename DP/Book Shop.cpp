#include <bits/stdc++.h>
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

int dp[1001][(int)1e5 + 1] = {};
int keep[1001][(int)1e5 + 1] = {};

signed main() {
    fastio;
    int n, x;
    cin >> n >> x;

    vector<int> price(n), pages(n);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            if (j - price[i - 1] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
                if (dp[i][j] != dp[i - 1][j])
                    keep[i][j] = 1;
                else
                    keep[i][j] = 0;
            } else {
                dp[i][j] = dp[i - 1][j];
                keep[i][j] = 0;
            }
        }
    }
    cout << dp[n][x] << "\n";

    int K = x;
    for (int i = n; i > 0; i--) {
        if (keep[i][K]) {
            cout << price[i - 1] << " " << pages[i - 1] << "\n";
            K -= price[i - 1];
        }
    }

    return 0;
}