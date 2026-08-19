#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF LONG_LONG_MAX
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vii vector<pair<int, int>>
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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

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
template <typename T, typename... Ts>
void print(T X, Ts... Y) {
    cout << X << " ";
    print(Y...);
}

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vvi dp(1e6 + 1, vi(2, 0));
    for (int i = 0; i < n; i++) {
        dp[a[i]][0] = max(dp[a[i]][0], dp[a[i] - 1][0] + 1);
        dp[a[i]][1] = max(dp[a[i]][1], dp[a[i] - 1][1] + 1);
        if (a[i] >= 2) {
            dp[a[i]][1] = max(dp[a[i]][1], dp[a[i] - 2][0] + 2);
        }
    }
    int maximum = -INF;
    for (int i = 0; i < n; i++) {
        maximum = max({maximum, dp[a[i]][0] + 1, dp[a[i]][1]});
    }
    print(maximum);
    // for (int i = 0; i < n; i++) {
    //     cin >> a[i];
    //     auto it = lower_bound(all(dp), a[i]);
    //     if (it == dp.end()) {
    //         dp.push_back(a[i]);
    //     } else {
    //         *it = a[i];
    //     }
    // }
    // print(dp.size() + 1);
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