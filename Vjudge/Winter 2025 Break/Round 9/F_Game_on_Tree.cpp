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
int n, u, v;
vvi adj;
vi dp;

int dfs(int u, int p) {
    int answer = 1;
    for (auto v : adj[u]) {
        if (v == p)
            continue;
        answer += dfs(v, u);
    }
    return dp[u] = answer;
}

void solve() {
    cin >> n;
    adj.assign(n, vi());
    dp.assign(n, -1);
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    // for (int i = 0; i < n; i++) {
    //     dp[i]--;
    // }
    print(dp);
    int gihun = adj[0].size();
    if (gihun % 2 == 0) {
        bool odd = false;
        int x = 0;
        for (int i = 1; i < n; i++) {
            // if (dp[i] % 2 != 0) {
            //     odd = true;
            //     break;
            // }
            x ^= dp[i];
        }
        // if (odd) {
        if (x) {
            print("Alice");
        } else {
            print("Bob");
        }
    } else {
        bool even = false;
        int x = 0;
        for (int i = 1; i < n; i++) {
            // if (dp[i] % 2 == 0) {
            //     even = true;
            //     break;
            // }
            x ^= dp[i];
        }
        // if (even) {
        if (x) {
            print("Alice");
        } else {
            print("Bob");
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