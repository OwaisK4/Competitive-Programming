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

int n;
vvi adj;
vi f, h, g;

void dfs1(int v, int p) {
    f[v] = 0;
    h[v] = 1;
    for (auto u : adj[v]) {
        if (u == p)
            continue;
        dfs1(u, v);
        h[v] += h[u];
        f[v] += f[u] + h[u];
    }
}

void dfs2(int v, int p) {
    for (auto u : adj[v]) {
        if (u == p)
            continue;
        // g[u] = max(g[v], f[v] + h[v] - 2 * h[u]);
        // g[u] = g[v] + (f[v] + h[v] - 2 * h[u]);
        g[u] = g[v] + n - 2 * h[u];
        dfs2(u, v);
    }
}

void solve() {
    cin >> n;
    adj.assign(n, vi());
    f.assign(n, 0);
    g.assign(n, 0);
    h.assign(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(0, 0);
    // print(h);
    // print(f);
    g[0] = f[0];
    dfs2(0, 0);
    print(g);
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