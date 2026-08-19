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
// vvi adj, adj2, components;
map<string, vector<string>> adj, adj2;
vector<vector<string>> components;
vector<string> nodes;
map<string, bool> visited;
// vector<bool> visited;

void dfs(string v) {
    visited[v] = true;
    for (auto u : adj[v]) {
        if (!visited.count(u)) {
            dfs(u);
        }
    }
    nodes.push_back(v);
}

void dfs2(string v) {
    visited[v] = true;
    components.back().push_back(v);
    for (auto u : adj2[v]) {
        if (!visited.count(u)) {
            dfs2(u);
        }
    }
}

void solve() {
    int cnt = 1;
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        adj = map<string, vector<string>>();
        adj2 = map<string, vector<string>>();
        components = vector<vector<string>>();
        nodes = vector<string>();
        visited = map<string, bool>();
        cout << "Calling circles for data set " << cnt << ":\n";
        cnt++;
        for (int i = 0; i < m; i++) {
            string u, v;
            cin >> u >> v;
            // u--;
            // v--;
            adj[u].push_back(v);
            adj2[v].push_back(u);
        }
        for (auto [it, value] : adj) {
            if (!visited.count(it)) {
                dfs(it);
            }
        }
        reverse(all(nodes));
        visited = map<string, bool>();
        // print(nodes);

        for (int i = 0; i < n; i++) {
            if (!visited.count(nodes[i])) {
                components.push_back(vector<string>());
                dfs2(nodes[i]);
            }
        }
        // print(root);
        // print(components.size());
        for (auto it : components) {
            for (int i = 0; i < it.size(); i++) {
                cout << it[i];
                if (i < it.size() - 1) {
                    cout << ", ";
                }
            }
            cout << endl;
        }
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