#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF LONG_LONG_MAX
#define int long long
#define all(a) a.begin(), a.end()
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
    DSU(int n) {
        this->n = n;
        parent.assign(n, -1);
        size.assign(n, 0);
        for (int i = 0; i < n; i++) {
            make_set(i);
        }
    }
    void make_set(int i) {
        parent[i] = i;
        size[i] = 1;
    }
    int find_set(int i) {
        if (i == parent[i]) {
            return i;
        }
        return parent[i] = find_set(parent[i]);
    }
    void union_set(int i, int j) {
        i = find_set(i);
        j = find_set(j);
        if (i != j) {
            if (size[i] < size[j]) {
                swap(i, j);
            }
            parent[j] = i;
            size[i] += size[j];
        }
    }
};

class Edge {
public:
    int u, v, weight;
    bool operator<(Edge &a) { return this->weight < a.weight; }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<Edge> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].u >> a[i].v >> a[i].weight;
        a[i].u--;
        a[i].v--;
    }
    sort(all(a));
    DSU dsu(n);
    int cost = 0;
    for (int i = 0; i < m; i++) {
        if (dsu.find_set(a[i].u) != dsu.find_set(a[i].v)) {
            dsu.union_set(a[i].u, a[i].v);
            cost += a[i].weight;
        }
    }
    int p = dsu.find_set(0);
    for (int i = 1; i < n; i++) {
        if (p != dsu.find_set(i)) {
            print("IMPOSSIBLE");
            return;
        }
    }
    print(cost);
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