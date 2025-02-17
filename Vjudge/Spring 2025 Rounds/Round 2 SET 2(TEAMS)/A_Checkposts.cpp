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

int white = -1, grey = 0, black = 1;
int n, m;
vvi adj, adj2, components;
vi cost, nodes, root;
vector<bool> visited;

void dfs(int v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u]) {
            dfs(u);
        }
    }
    nodes.push_back(v);
}

void dfs2(int v) {
    visited[v] = true;
    components.back().push_back(v);
    root[v] = components.size() - 1;
    for (auto u : adj2[v]) {
        if (!visited[u]) {
            dfs2(u);
        }
    }
}

void solve() {
    cin >> n;
    adj.assign(n, vi());
    adj2.assign(n, vi());
    visited.assign(n, false);
    cost.assign(n, 0);
    root.assign(n, 0);
    // color.assign(n, white);
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj2[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(all(nodes));
    // print(nodes);

    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[nodes[i]]) {
            components.push_back(vi());
            dfs2(nodes[i]);
        }
    }
    // print(root);
    // print(components.size());
    vi component_money(components.size(), 0);
    vi component_count(components.size(), 0);
    for (int i = 0; i < components.size(); i++) {
        int minimum = INT_MAX;
        for (auto it : components[i]) {
            minimum = min(minimum, cost[it]);
        }
        int cnt = 0;
        for (auto it : components[i]) {
            if (cost[it] == minimum) {
                cnt++;
            }
        }
        component_money[i] = minimum;
        component_count[i] = cnt;
    }
    int total = 0;
    for (auto it : component_money) {
        total += it;
    }
    int cnt = 1;
    for (auto it : component_count) {
        cnt *= (it % MOD);
        cnt %= MOD;
    }
    print(total, cnt);
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