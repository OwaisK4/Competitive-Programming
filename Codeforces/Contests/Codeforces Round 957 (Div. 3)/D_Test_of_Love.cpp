#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
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
    int n, m, k;
    cin >> n >> m >> k;
    string s;
    cin >> s;
    vector<bool> dp(n + 2, false);
    for (int j = 0; j <= m; j++) {
        if (j < n + 2)
            dp[j] = true;
    }
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == 'L') {
            for (int j = 0; j <= m; j++) {
                if (i + j < n + 2)
                    dp[i + j] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dp[i]) {
            if (s[i - 1] == 'W') {
                k--;
            } else if (s[i - 1] == 'C') {
                cout << "NO\n";
                return;
            }
        }
    }
    if (k < 0 || !dp[n + 1]) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }

    // for (int i = 0; i <= m; i++) {
    //     if (i < n + 2) {
    //         dp[i] = true;
    //     }
    // }
    // for (int i = 1; i <= n; i++) {
    //     if (s[i - 1] == 'C')
    //         continue;
    //     else if (s[i - 1] == 'L') {
    //         for (int j = 0; j <= m; j++) {
    //             if (i + j < n + 2) {
    //                 dp[i + j] = dp[i] || dp[i + j];
    //             }
    //         }
    //     } else {
    //         if (i + 1 < n + 2) {
    //             dp[i + 1] = dp[i] || dp[i + 1];
    //         }
    //     }
    // }
    // if (dp[n + 1]) {
    //     cout << "YES\n";
    // } else {
    //     cout << "NO\n";
    // }
}

signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}