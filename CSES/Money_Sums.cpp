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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<bool>> dp(n + 1, vector<bool>(100001, false));
    dp[0][0] = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // sort(all(a));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = true;
        for (int j = 1; j <= 100000; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - a[i - 1] >= 0) {
                dp[i][j] = dp[i][j] || dp[i - 1][j - a[i - 1]];
            }
        }
    }
    cout << (int)count(all(dp[n]), true) - 1 << "\n";
    for (int j = 1; j <= 100000; j++) {
        if (dp[n][j]) {
            cout << j << " ";
        }
    }
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