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
    vector<int> parent, size;

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
        if (v == parent[v]) {
            return v;
        }
        return parent[v] = find_set(parent[v]);
    }

    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int total_sets() {
        int total = 0;
        for (int i = 1; i < parent.size(); i++) {
            if (i == parent[i])
                total++;
        }
        return total;
    }
};

int n, m;
// vvi adj;

void solve() {
    cin >> n >> m;
    // adj.assign(n, vi());
    int components = n;
    DSU dsu(n);
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        s.insert(dsu.size[i]);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (dsu.find_set(u) == dsu.find_set(v)) {
            print(components, *prev(s.end()));
        } else {
            int combined = dsu.size[dsu.find_set(u)] + dsu.size[dsu.find_set(v)];
            s.erase(s.find(dsu.size[dsu.find_set(u)]));
            s.erase(s.find(dsu.size[dsu.find_set(v)]));
            s.insert(combined);
            dsu.union_set(u, v);
            components--;
            print(components, *prev(s.end()));
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