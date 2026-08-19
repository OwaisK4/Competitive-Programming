#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
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

int dp[1000][1000][2];
bool visited[1000][1000][2];

void solve() {
    int n, m;
    cin >> n >> m;
    int sx, sy, ex, ey;
    vector<vector<char>> a(n, vector<char>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'S') {
                sx = i;
                sy = j;
            }
            if (a[i][j] == 'G') {
                ex = i;
                ey = j;
            }
        }
    }
    queue<array<int, 3>> q;
    q.push({sx, sy, 0});
    q.push({sx, sy, 1});
    visited[sx][sy][0] = true;
    visited[sx][sy][1] = true;
    dp[sx][sy][0] = 0;
    dp[sx][sy][1] = 0;
    while (!q.empty()) {
        auto [x, y, flag] = q.front();
        q.pop();
        if (flag) {
            if (x - 1 >= 0 && !visited[x - 1][y][1 - flag] && a[x - 1][y] != '#') {
                q.push({x - 1, y, 1 - flag});
                dp[x - 1][y][1 - flag] = min(dp[x - 1][y][1 - flag], dp[x][y][flag] + 1);
                visited[x - 1][y][1 - flag] = true;
            }
            if (x + 1 < n && !visited[x + 1][y][1 - flag] && a[x + 1][y] != '#') {
                q.push({x + 1, y, 1 - flag});
                dp[x + 1][y][1 - flag] = min(dp[x + 1][y][1 - flag], dp[x][y][flag] + 1);
                visited[x + 1][y][1 - flag] = true;
            }
        } else {
            if (y - 1 >= 0 && !visited[x][y - 1][1 - flag] && a[x][y - 1] != '#') {
                q.push({x, y - 1, 1 - flag});
                dp[x][y - 1][1 - flag] = min(dp[x][y - 1][1 - flag], dp[x][y][flag] + 1);
                visited[x][y - 1][1 - flag] = true;
            }
            if (y + 1 < m && !visited[x][y + 1][1 - flag] && a[x][y + 1] != '#') {
                q.push({x, y + 1, 1 - flag});
                dp[x][y + 1][1 - flag] = min(dp[x][y + 1][1 - flag], dp[x][y][flag] + 1);
                visited[x][y + 1][1 - flag] = true;
            }
        }
    }
    int answer = min(dp[ex][ey][0], dp[ex][ey][1]);
    if (answer == INF) {
        print(-1);
    } else {
        print(answer);
    }
}

signed main() {
    fastio;
    // memset(dp, LINF, sizeof(int) * 1000 * 1000 * 2);
    // memset(visited, false, sizeof(bool) * 1000 * 1000 * 2);
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < 1000; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = INF;
                visited[i][j][k] = false;
            }
        }
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}