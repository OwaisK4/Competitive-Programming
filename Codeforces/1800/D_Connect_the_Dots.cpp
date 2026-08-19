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
void print(T X, bool newline = true) {
    cout << X;
    if (newline) {
        cout << "\n";
    }
}

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

vector<vector<int>> dp;
int D = 10;

void solve() {
    int n, m;
    cin >> n >> m;
    dp.assign(n + 1, vector<int>(D + 1, 0));
    DSU dsu(n + 1);
    for (int i = 0; i <= n; i++) {
        dsu.make_set(i);
    }
    for (int i = 0; i < m; i++) {
        int a, d, k;
        cin >> a >> d >> k;
        dp[a][d] = max(dp[a][d], k);
    }
    for (int i = 1; i <= n; i++) {
        for (int d = 1; d <= D; d++) {
            if (dp[i][d] > 0 && i + d <= n) {
                dp[i + d][d] = max(dp[i][d] - 1, dp[i + d][d]);
                dsu.union_set(i, i + d);
            }
        }
    }
    int answer = dsu.total_sets();
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