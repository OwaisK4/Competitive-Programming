#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
// #define int long long
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

vvi adj;
vi depth;

void dfs(int v, int p, int d) {
    depth[v] = d;
    for (auto u : adj[v]) {
        if (u != p) {
            dfs(u, v, d + 1);
        }
    }
}

void solve() {
    int n, q, u, a, b;
    cin >> n >> q;
    depth.assign(n, 0);
    adj.assign(n, vi());
    int maxbit = 21;
    vector<int> parent(n, -1);
    vvi ancestor(maxbit + 1, vi(n, -1));
    for (int i = 1; i < n; i++) {
        cin >> u;
        u--;
        parent[i] = u;
        ancestor[0][i] = u;
        adj[u].push_back(i);
        adj[i].push_back(u);
    }
    dfs(0, 0, 0);
    // print(depth);
    for (int i = 1; i <= maxbit; i++) {
        for (int j = 0; j < n; j++) {
            if (ancestor[i - 1][j] == -1)
                continue;
            ancestor[i][j] = ancestor[i - 1][ancestor[i - 1][j]];
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> a >> b;
        a--;
        b--;
        if (depth[a] > depth[b])
            swap(a, b);
        int diff = depth[b] - depth[a];
        for (int j = maxbit; j >= 0; j--) {
            if ((1 << j) <= diff) {
                b = ancestor[j][b];
                diff -= (1 << j);
            }
        }
        if (a == b) {
            print(a + 1);
            continue;
        }
        for (int j = maxbit; j >= 0; j--) {
            if (ancestor[j][a] != -1 && (ancestor[j][a] != ancestor[j][b])) {
                a = ancestor[j][a];
                b = ancestor[j][b];
            }
        }
        print(ancestor[0][a] + 1);
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