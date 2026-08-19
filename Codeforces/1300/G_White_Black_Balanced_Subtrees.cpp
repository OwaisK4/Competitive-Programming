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

vector<vector<int>> adj;
vector<int> dp;
int cnt = 0;
string colors;

int dfs(int v, int p) {
    if (dp[v] != -1)
        return dp[v];
    int answer = 0;
    for (auto u : adj[v]) {
        if (u != p) {
            answer += dfs(u, v);
        }
    }
    answer += (colors[v] == 'W') ? 1 : -1;
    if (answer == 0)
        cnt++;
    return dp[v] = answer;
}

void solve() {
    int n;
    cin >> n;
    cnt = 0;
    adj.assign(n, vector<int>());
    dp.assign(n, -1);
    for (int i = 1; i < n; i++) {
        int parent;
        cin >> parent;
        parent--;
        adj[parent].push_back(i);
    }
    cin >> colors;
    dfs(0, 0);
    cout << cnt << "\n";
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