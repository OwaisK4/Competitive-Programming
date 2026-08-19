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
vi color;
int white = 0, grey = 1, black = 2;
bool cyclic = false;
vi component;

void dfs(int v, int par) {
    if (color[v] == grey) {
        cyclic = true;
        return;
    } else if (color[v] == black) {
        return;
    }
    color[v] = grey;
    for (auto u : adj[v]) {
        if (u == par)
            continue;
        dfs(u, v);
    }
    color[v] = black;
    component.push_back(v);
}

void solve() {
    cin >> n >> m;
    adj.assign(n, vi());
    color.assign(n, white);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (color[i] == white) {
            dfs(i, i);
            if (cyclic) {
                for (auto it : component) {
                    if (adj[it].size() != 2) {
                        cyclic = false;
                        break;
                    }
                }
                if (cyclic) {
                    cnt++;
                }
            }
            cyclic = false;
            component.resize(0);
        }
    }
    print(cnt);
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