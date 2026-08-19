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

vector<int> a;
vector<vector<int>> dp;

// int f(int index) {}

void solve() {
    int n;
    cin >> n;
    a.assign(n, 0);
    dp.assign(n + 1, vector<int>(2, INT_MAX));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    dp[0][0] = 0;
    dp[0][1] = a[0];
    for (int i = 0; i < n; i++) {
        if (i + 1 <= n) {
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + a[i]);
        }
        if (i + 2 <= n) {
            dp[i + 2][0] = min(dp[i + 2][0], dp[i][1]);
            dp[i + 2][1] = min(dp[i + 2][1], dp[i][0] + a[i] + a[i + 1]);
        }
    }
    print(min(dp[n][0], dp[n][1]));
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