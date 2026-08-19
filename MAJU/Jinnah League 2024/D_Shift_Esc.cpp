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

int n, m, K;
vector<vector<int>> grid;
vector<vector<vector<int>>> dp;
// vector<vector<int>> dp;

int f(int i, int j, int k) {
    if (i == 0 && j == 0) {
        return 0;
    }
    // if (dp[i][j] != -1) {
    //     return dp[i][j];
    // }
    if (dp[i][j][k] != -1) {
        return dp[i][j][k];
    }
    int answer = LONG_LONG_MAX;
    if (i > 0) {
        for (int l = 0; l < m; l++) {
            answer = min(answer, (K * l) + grid[i - 1][(j + l) % m] + f(i - 1, j, (j + l) % m));
        }
    }
    if (j > 0) {
        answer = min(answer, grid[i][(k - 1 + m) % m] + f(i, j - 1, (k - 1 + m) % m));
    }
    // return answer;
    return dp[i][j][k] = answer;
}

void solve() {
    cin >> n >> m >> K;
    grid.assign(n, vector<int>(m, 0));
    // dp.assign(n, vector<int>(m, -1));
    dp.assign(n, vector<vector<int>>(m, vector<int>(m, -1)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int answer = LONG_LONG_MAX;
    for (int i = 0; i < m; i++) {
        answer = min(answer, (K * i) + grid[n - 1][(m - 1 + i) % m] + f(n - 1, m - 1, (m - 1 + i) % m));
    }
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