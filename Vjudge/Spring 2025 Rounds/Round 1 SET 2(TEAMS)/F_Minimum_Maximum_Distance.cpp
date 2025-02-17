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

vector<bool> marked;
vi f, g, h;
vvi adj;

void dfs(int v, int p) {
    for (auto u : adj[v]) {
        if (u == p)
            continue;
        dfs(u, v);
        if (f[v] <= f[u] + 1) {
            h[v] = f[v];
            f[v] = f[u] + 1;
        } else if (h[v] <= f[u] + 1) {
            h[v] = f[u] + 1;
        }
    }
}

void dfs2(int v, int p) {
    for (auto u : adj[v]) {
        if (u == p)
            continue;
        if (f[v] == f[u] + 1) {
            g[u] = max(g[v] + 1, h[v] + 1);
        } else {
            g[u] = max(g[v] + 1, f[v] + 1);
        }
        dfs2(u, v);
    }
}

void solve() {
    int n, k, u, v;
    cin >> n >> k;
    adj.assign(n, vi());
    marked.assign(n, false);
    f.assign(n, -INF);
    h.assign(n, -INF);
    g.assign(n, 0);
    for (int i = 0; i < k; i++) {
        cin >> u;
        u--;
        marked[u] = true;
        f[u] = 0;
        // h[u] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    // print(h);
    // print(f);
    dfs2(0, 0);
    g[0] = f[0];
    // print(g);
    int answer = LINF;
    for (int i = 0; i < n; i++) {
        answer = min(answer, max(f[i], g[i]));
    }
    print((k == 1) ? 0 : answer);
}

signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        // break;
    }

    return 0;
}