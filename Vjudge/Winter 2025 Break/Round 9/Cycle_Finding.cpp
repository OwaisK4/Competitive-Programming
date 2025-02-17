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

class Edge {
public:
    int u, v, w;
    Edge() {};
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

int n, m;
// vvi adj;
vi dist, parent;
vector<Edge> edgeList;
// int cycle_start = -1, cycle_end = -1;

void solve() {
    cin >> n >> m;
    // adj.assign(n, vi());
    dist.assign(n, 0);
    parent.assign(n, -1);
    edgeList.assign(m, Edge());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        edgeList[i] = Edge(u, v, w);
        // adj[u].push_back(v);
    }
    // dist[0] = 0;
    int c = -1;
    for (int j = 0; j < n; j++) {
        c = -1;
        for (int i = 0; i < m; i++) {
            int u = edgeList[i].u;
            int v = edgeList[i].v;
            int w = edgeList[i].w;
            if (dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                c = u;
            }
        }
    }
    if (c != -1) {
        print("YES");
        // print(c + 1);
        vector<int> cycle;
        for (int v = c;; v = parent[v]) {
            cycle.push_back(v + 1);
            if (v == c && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        print(cycle);

    } else {
        print("NO");
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