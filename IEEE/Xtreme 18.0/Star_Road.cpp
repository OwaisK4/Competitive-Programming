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
void print(T X, bool newline = true) {
    cout << X;
    if (newline) {
        cout << "\n";
    }
}

vector<vector<int>> adj;
vector<int> stars;
vector<bool> used_by_parent;
vector<pii> starting_points, dp;

void calculate(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p)
            continue;
        calculate(v, u);
        if (dp[v].second > dp[u].second) {
            if (dp[u].first < dp[v].first + 1) {
                dp[u].first = dp[v].first + 1;
                used_by_parent[v] = true;
            }
            // dp[u].first = max(dp[u].first, dp[v].first + 1);
        } else {
            dp[u].second = dp[v].second;
        }
    }
}

void dfs(int u, int p) {
    for (auto v : adj[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        if (!used_by_parent[v]) {
            if (dp[u].second > dp[v].second) {
                if (dp[v].first < dp[u].first + 1) {
                    dp[v].first = dp[u].first + 1;
                }
            } else {
                dp[v].second = dp[u].second;
            }
        }
    }
}

void solve() {
    int n;
    cin >> n;
    stars.assign(n, 0);
    used_by_parent.assign(n, false);
    dp.assign(n, {1, 0});
    starting_points.assign(n, pii());
    adj.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        cin >> stars[i];
        starting_points[i] = {stars[i], i};
        dp[i].second = stars[i];
    }
    sort(all(starting_points));
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    calculate(0, -1);
    // dfs(0, -1);
    // print(dp);
    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer = max(answer, dp[i].first);
    }
    cout << answer;
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