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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> min_cost(n + 1, 0), dp(n + 1, -1);
    iota(all(min_cost), 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        min_cost[b] = min_cost[a] + 1;
        dp[a] = max(dp[a], b);
    }
    for (int i = 1; i <= n; i++) {
        min_cost[i] = min(min_cost[i], min_cost[i - 1] + 1);
    }
    print(min_cost);
    print(dp);
    vector<int> answer(n - 1, 1);
    for (int i = 0; i < n - 1; i++) {
        if (dp[i + 1] != -1) {
            int j = i;
            while (j < n - 1 && j < min_cost[dp[i + 1]]) {
                answer[j] = 0;
                j++;
            }
            i = j;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        cout << answer[i];
    }
    cout << "\n";
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