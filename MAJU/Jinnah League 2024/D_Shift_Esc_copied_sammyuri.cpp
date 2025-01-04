#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define vecin(name, len)   \
    vector<int> name(len); \
    for (auto &_ : name)   \
        cin >> _;
#define vecout(v)         \
    for (auto _ : v)      \
        cout << _ << " "; \
    cout << endl;

void solve() {
    int n, m;
    ll kk;
    cin >> n >> m >> kk;
    /*
    let dp[i] = min cost to be at position i
    */
    vector<ll> dp(m, 1e18);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        vecin(aa, m);
        vector<vector<ll>> dp2(m, vector<ll>(m, 1e18));
        // for each position, get min cost
        // suppose we want min cost to go from j to k
        // there are n possible shifts...
        // let dp2[i][j] = min cost to be at position i using shift j?
        for (int j = 0; j < m; j++)
            for (int k = 0; k < m; k++) {
                dp2[j][k] = min(dp2[j][k], kk * k + aa[(j + k) % m] + dp[j]);
                if (j > 0)
                    dp2[j][k] = min(dp2[j][k], aa[(j + k) % m] + dp2[j - 1][k]);
            }
        for (int j = 0; j < m; j++) {
            dp[j] = 1e18;
            for (int k = 0; k < m; k++)
                dp[j] = min(dp[j], dp2[j][k]);
        }
    }
    cout << dp[m - 1] << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt = 1;

    cin >> tt;

    while (tt--)
        solve();
    return 0;
}