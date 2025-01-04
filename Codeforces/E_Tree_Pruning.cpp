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

vector<vector<int>> adj;
vector<int> leaf;
// map<int, vector<int>> lengths;

void dfs(int u, int p, int cnt) {
    if (u != 0 && adj[u].size() == 1) {
        leaf[u] = cnt;
        return;
    }
    for (auto v : adj[u]) {
        if (v == p)
            continue;
        dfs(v, u, cnt + 1);
    }
}

void solve() {
    int n;
    cin >> n;
    // vector<int> a(n);
    leaf.assign(n, 0);
    adj.assign(n, vector<int>());
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0, 0);
    sort(all(leaf));
    erase_if(leaf, [](int x) { return x == 0; });
    print(leaf);
    int m = leaf.size();
    vector<int> prefix(m + 1);
    partial_sum(all(leaf), prefix.begin() + 1);
    int answer = INT_MAX;
    for (int i = 0; i < m; i++) {
        int ops = -prefix[i];
    }
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