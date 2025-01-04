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

int n, k;
vector<vector<int>> dp;
vector<int> a;

void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int MAX = LONG_LONG_MAX - (n * *max_element(all(a))) - 1;

    dp.assign(n + 1, vector<int>(k + 1, MAX));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            int minimum = MAX;
            for (int d = 0; j + d <= k && i + d + 1 <= n; d++) {
                minimum = min(minimum, a[i + d]);
                dp[i + d + 1][j + d] = min(dp[i + d + 1][j + d], dp[i][j] + (d + 1) * minimum);
            }
        }
    }

    print(*min_element(all(dp[n])));
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