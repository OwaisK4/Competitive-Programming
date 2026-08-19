#include <bits/stdc++.h>
#define int int
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

int n, t, x;
vector<vector<int>> adj;
vector<int> dp, answer;

/*
int f(int u, int p) {
    if (adj[u].size() == 1 && adj[u][0] == p) {
        return dp[u] = 0;
    }
    if (dp[u] != -1)
        return dp[u];
    int answer = 1;
    for (auto v : adj[u]) {
        if (v != p) {
            answer = answer & f(v, u);
        }
    }
    if (answer == 0) {
        return dp[u] = 1;
    }
    return dp[u] = 0;
}
*/

int f(int u, int p) {
    // dp[u] = 0;
    for (auto v : adj[u]) {
        if (v != p) {
            f(v, u);
            dp[u] += (dp[v] == 0);
        }
    }
    return dp[u];
}

void dfs(int v, int p) {
    answer[v] = (dp[v] > 0);
    for (auto u : adj[v]) {
        if (u == p)
            continue;
        int x = dp[v], y = dp[u];
        dp[v] -= (dp[u] == 0);
        dp[u] += (dp[v] == 0);
        dfs(u, v);
        dp[v] = x;
        dp[u] = y;
    }
}

void solve() {
    cin >> n >> t;
    adj.assign(n, vector<int>());
    dp.assign(n, 0);
    answer.assign(n, -1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    f(0, 0);
    // print(dp);
    dfs(0, 0);
    // print(answer);
    for (int i = 0; i < t; i++) {
        cin >> x;
        x--;
        print((answer[x] == 1) ? "Ron" : "Hermione");
    }
}

signed main() {
    fastio;
    solve();

    return 0;
}