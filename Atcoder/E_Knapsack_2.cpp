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

vector<int> w, v;
vector<vector<int>> dp;

void solve() {
    int N, W;
    cin >> N >> W;
    w.assign(N, 0);
    v.assign(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    dp.assign(N + 1, vector<int>(1e3 + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 1e3; j++) {
            dp[i][j] = dp[i - 1][j];
            int left = j - v[i - 1];
            if (left >= 0 && dp[i - 1][left] != INT_MAX) {
                dp[i][j] = min(dp[i - 1][j], dp[i - 1][left] + w[i - 1]);
            }
        }
    }
    // print(dp[N], 10);
    for (int j = 1e3; j >= 0; j--) {
        if (dp[N][j] <= W) {
            // cout << dp[N][j];
            cout << j;
            break;
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