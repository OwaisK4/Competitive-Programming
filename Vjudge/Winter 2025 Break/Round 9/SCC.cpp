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

int n, m, u, v;
vvi adj, adj2, condensed, components;
vector<bool> visited;
vi nodes, root;

void dfs(int v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    nodes.push_back(v);
}

void dfs2(int v) {
    visited[v] = true;
    components.back().push_back(v + 1);
    root[v] = components.size() - 1;
    for (auto u : adj2[v]) {
        if (!visited[u])
            dfs2(u);
    }
}

void dfs3(int v) {
    visited[v] = true;
    for (auto u : condensed[v]) {
        if (!visited[u])
            dfs3(u);
    }
    nodes.push_back(v);
}

void solve() {
    cin >> n >> m;
    adj.assign(n, vi());
    adj2.assign(n, vi());
    root.assign(n, -1);
    visited.assign(n, false);
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj2[v].push_back(u);
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i])
            dfs(i);
    }
    reverse(all(nodes));
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (!visited[nodes[i]]) {
            components.push_back(vi());
            dfs2(nodes[i]);
        }
    }
    if (components.size() == 1) {
        print("YES");
    } else {
        print("NO");
        condensed.assign(components.size(), vi());
        for (int i = 0; i < n; i++) {
            for (auto it : adj[i]) {
                if (root[i] != root[it]) {
                    condensed[root[i]].push_back(root[it]);
                }
            }
        }
        for (auto &it : condensed) {
            sort(all(it));
            it.erase(unique(all(it)), it.end());
        }

        nodes = vi();
        visited.assign(n, false);
        for (int i = 0; i < condensed.size(); i++) {
            if (!visited[i]) {
                dfs3(i);
            }
        }
        print(components[nodes.front()].front(), components[nodes.back()].back());
        // for (auto it : condensed) {
        //     print(it);
        // }
    }
    // print(components.size());
    // for (auto it : components) {
    //     print(it);
    // }
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