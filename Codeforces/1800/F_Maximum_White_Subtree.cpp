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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

vector<int> color;
vector<int> subtree;
vector<bool> used_by_parent;
vector<vector<int>> adj;

int calculate(int u, int e) {
    int value = 0;
    for (auto s : adj[u]) {
        if (s != e) {
            int child_value = calculate(s, u);
            if (child_value > 0) {
                value += child_value;
                used_by_parent[s] = true;
            }
        }
    }
    subtree[u] = (color[u] == 1) ? 1 : -1;
    subtree[u] += value;
    return subtree[u];
}

void dfs(int u, int e) {
    if (u != e) {
        int current = subtree[u];
        int previous = subtree[e];
        if (used_by_parent[u]) {
            subtree[u] = max(current, previous);
        } else {
            subtree[u] = max(current, current + previous);
        }
    }
    for (auto s : adj[u]) {
        if (s != e) {
            dfs(s, u);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    color.assign(n, 0);
    subtree.assign(n, 0);
    used_by_parent.assign(n, false);
    adj.assign(n, vector<int>());
    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    calculate(0, 0);
    dfs(0, 0);
    print(subtree);
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