#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define int long long
#define all(a) a.begin(), a.end()
#define f first
#define s second
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

vvi adj, ancestor;
vi depth, parent;
int maxbit = 21;

void dfs(int v, int p, int d) {
    depth[v] = d;
    parent[v] = p;
    ancestor[0][v] = p;
    for (auto u : adj[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
        }
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    adj.assign(n, vi());
    ancestor.assign(maxbit + 1, vi(n, -1));
    depth.assign(n, 0);
    parent.assign(n, -1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, 0);
    for (int i = 1; i <= maxbit; i++) {
        for (int j = 0; j < n; j++) {
            if (ancestor[i - 1][j] == -1)
                continue;
            ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
        }
    }
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        int x = u, y = v;
        if (depth[u] > depth[v]) {
            swap(u, v);
        }
        int diff = depth[v] - depth[u];
        for (int i = maxbit; i >= 0; i--) {
            if ((1 << i) <= diff) {
                diff -= (1 << i);
                v = ancestor[i][v];
            }
        }
        if (u == v) {
            int answer = depth[x] + depth[y] - 2 * depth[v];
            print(answer);
            continue;
        }

        for (int i = maxbit; i >= 0; i--) {
            if (ancestor[i][u] != -1 && ancestor[i][u] != ancestor[i][v]) {
                u = ancestor[i][u];
                v = ancestor[i][v];
            }
        }
        v = ancestor[0][v];
        int answer = depth[x] + depth[y] - 2 * depth[v];
        print(answer);
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