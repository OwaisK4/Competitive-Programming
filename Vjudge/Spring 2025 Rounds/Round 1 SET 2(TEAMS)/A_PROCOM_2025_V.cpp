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

vector<vector<char>> a;
vvi grid;
// char a[60][60];
// int grid[60][60];

void solve() {
    int n, m, total = 0;
    cin >> n >> m;
    a.assign(n, vector<char>(m, 0));
    grid.assign(n + 1, vi(m + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '1') {
                grid[i + 1][j + 1] = 1;
                total++;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            grid[i][j] += grid[i][j - 1];
            grid[i][j] += grid[i - 1][j];
            grid[i][j] -= grid[i - 1][j - 1];
        }
    }

    vii factors;
    for (int i = 1; i * i <= total; i++) {
        if (total % i == 0) {
            factors.push_back({i, total / i});
            // factors.push_back({i, total / i});
        }
    }
    // print(factors);

    int answer = INF;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (auto [k, l] : factors) {
                if (i + k <= n && j + l <= m) {
                    int sum = grid[i + k][j + l] - grid[i + k][j] - grid[i][j + l] + grid[i][j];
                    answer = min(answer, total - sum);
                }
                if (i + l <= n && j + k <= m) {
                    int sum = grid[i + l][j + k] - grid[i + l][j] - grid[i][j + k] + grid[i][j];
                    answer = min(answer, total - sum);
                }
            }
        }
    }
    print((answer == INF) ? -1 : answer);
}

signed main() {
    fastio;
    // for (int i = 0; i < 51; i++) {
    //     for (int j = 0; j < 51; j++) {
    //         grid[i][j] = 0;
    //     }
    // }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}