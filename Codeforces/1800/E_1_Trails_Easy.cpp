#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define MOD 1000000007
using namespace std;
using pii = pair<int, int>;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

void solve() {
    int m, n;
    cin >> m >> n;
    vector<int> s(m), l(m);
    // vector<vector<int>> dp(m, vector<int>(2, 0));
    vector<int> dp(m, 0);
    dp[0] = 1;

    for (int i = 0; i < m; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> l[i];
    }

    for (int i = 0; i < n; i++) {
        int short_lake = 0, long_lake = 0;
        for (int j = 0; j < m; j++) {
            short_lake += (dp[j] * s[j]) % MOD;
            long_lake += (dp[j] * l[j]) % MOD;
        }
        fill(all(dp), 0LL);
        for (int j = 0; j < m; j++) {
            dp[j] += (long_lake * s[j]) % MOD;
            dp[j] += (short_lake * l[j]) % MOD;
            dp[j] += (short_lake * s[j]) % MOD;
        }
    }
    int answer = 0;
    for (int i = 0; i < m; i++) {
        answer += dp[i];
        answer %= MOD;
    }
    cout << answer;
    // print(dp);
}

signed main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}