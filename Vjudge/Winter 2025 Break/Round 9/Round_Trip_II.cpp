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
int n, m;
vvi adj;
vi color, parent;
int white = -1, grey = 0, black = 1;
int cycle_start = -1, cycle_end = -1;

bool acyclic(int v) {
    color[v] = grey;
    for (auto u : adj[v]) {
        if (color[u] == grey) {
            cycle_start = u;
            cycle_end = v;
            return false;
        } else if (color[u] == black) {
            continue;
        }
        parent[u] = v;
        if (!acyclic(u))
            return false;
    }
    color[v] = black;
    return true;
}

void solve() {
    cin >> n >> m;
    adj.assign(n, vi());
    color.assign(n, white);
    parent.assign(n, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
    }

    for (int i = 0; i < n; i++) {
        if (!acyclic(i)) {
            vi path;
            path.push_back(cycle_start + 1);
            for (int p = cycle_end; p != cycle_start; p = parent[p]) {
                path.push_back(p + 1);
            }
            path.push_back(cycle_start + 1);
            reverse(all(path));
            print(path.size());
            print(path);
            return;
        }
    }
    print("IMPOSSIBLE");
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