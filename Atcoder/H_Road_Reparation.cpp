#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
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
};

class DSU {
public:
    int n;
    vector<int> parent, size;
    DSU(int n) {
        this->n = n;
        parent.assign(n, -1);
        size.assign(n, 0);
    }
    void make_set(int v) {
        parent[v] = v;
        size[v] = 1;
    }
    int find_set(int v) {
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b]) {
                swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> edgeList(m);
    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        cin >> edgeList[i].u >> edgeList[i].v >> edgeList[i].w;
        edgeList[i].u--;
        edgeList[i].v--;
    }
    for (int i = 0; i < n; i++) {
        dsu.make_set(i);
    }

    sort(all(edgeList), [](Edge &a, Edge &b) { return a.w < b.w; });
    int cost = 0;
    for (Edge e : edgeList) {
        if (dsu.find_set(e.u) != dsu.find_set(e.v)) {
            cost += e.w;
            dsu.union_set(e.u, e.v);
        }
    }
    bool valid = true;
    int parent = dsu.find_set(0);
    for (int i = 1; i < n; i++) {
        if (parent != dsu.find_set(i)) {
            valid = false;
            break;
        }
    }
    if (valid)
        print(cost);
    else
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