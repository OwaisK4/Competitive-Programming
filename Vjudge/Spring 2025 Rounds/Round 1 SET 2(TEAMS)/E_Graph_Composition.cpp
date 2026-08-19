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

class DSU {
public:
    int n;
    vi parent, size;
    DSU() {};
    DSU(int n) {
        this->n = n;
        parent.assign(n, -1);
        size.assign(n, 0);
        for (int i = 0; i < n; i++) {
            make_set(i);
        }
    }
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set(int v) {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int u, int v) {
        u = find_set(u);
        v = find_set(v);
        if (u != v) {
            if (size[u] < size[v])
                swap(u, v);
            parent[v] = u;
            size[u] += size[v];
        }
    }
};

int n, m1, m2, u, v;
vvi F, G;
// vi visited;
int removed = 0, added = 0;
DSU dsu_f, dsu_g;

// void dfs(int v) {
//     visited[v] = 1;
//     for (auto u : F[v]) {
//         if (visited[u])
//             continue;
//         if (dsu_g.find_set(u) != dsu_g.find_set(v)) {
//             print("Here", v + 1, u + 1);
//             removed++;
//         } else {
//             dsu_f.union_set(u, v);
//         }
//         dfs(u);
//     }
// }
// void bfs() {
//     for (int i = 0; i < G.size(); i++) {
//         for (auto j : G[i]) {
//             if (dsu_g.find_set(i) != dsu_g.find_set(j)) {
//                 print("Here");
//                 removed++;
//             } else {
//                 dsu_f.union_set(i, j);
//             }
//         }
//     }
// }

void solve() {
    removed = 0, added = 0;
    cin >> n >> m1 >> m2;
    F.assign(n, vi());
    // visited.assign(n, 0);
    G.assign(n, vi());
    dsu_f = DSU(n);
    dsu_g = DSU(n);
    map<pii, int> edges;
    for (int i = 0; i < m1; i++) {
        cin >> u >> v;
        u--;
        v--;
        F[u].push_back(v);
        F[v].push_back(u);
        edges[{min(u, v), max(u, v)}] = i;
    }
    for (int i = 0; i < m2; i++) {
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
        dsu_g.union_set(u, v);
    }
    for (auto [edge, i] : edges) {
        auto [u, v] = edge;
        if (dsu_g.find_set(u) != dsu_g.find_set(v)) {
            removed++;
        } else {
            dsu_f.union_set(u, v);
        }
    }
    // print(dsu_g.parent);
    map<int, vi> mp;
    for (int i = 0; i < n; i++) {
        mp[dsu_g.find_set(i)].push_back(i);
    }
    for (auto [key, it] : mp) {
        u = it[0];
        for (int i = 1; i < it.size(); i++) {
            if (dsu_f.find_set(u) != dsu_f.find_set(it[i])) {
                dsu_f.union_set(u, it[i]);
                added++;
            }
        }
    }
    int answer = removed + added;
    print(answer);
}

signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}