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

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<vector<vector<vector<int>>>> dist;
vector<vector<vector<vector<bool>>>> visited;
vector<vector<char>> grid;

bool isSafe(int x, int y, int n, int m) {
    if (x >= 0 && y >= 0 && x < n && y < m && grid[x][y] != '#') {
        return true;
    }
    return false;
}

void solve() {
    int n, m;
    cin >> n >> m;
    grid.assign(n, vector<char>(m, '0'));
    dist.assign(n, vector<vector<vector<int>>>(m, vector<vector<int>>(4, vector<int>(4, INT_MAX))));
    visited.assign(n, vector<vector<vector<bool>>>(m, vector<vector<bool>>(4, vector<bool>(4, false))));
    int s_x, s_y, e_x, e_y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                s_x = i;
                s_y = j;
            } else if (grid[i][j] == 'T') {
                e_x = i;
                e_y = j;
            }
        }
    }

    visited[s_x][s_y][0][0] = true;
    dist[s_x][s_y][0][0] = 0;
    queue<array<int, 4>> q;
    q.push({s_x, s_y, 0, 0});
    while (!q.empty()) {
        auto [x, y, dir, c] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xs = x + dx[i];
            int ys = y + dy[i];
            if (isSafe(xs, ys, n, m)) {
                int cs = (i == dir) ? c + 1 : 1;
                if (cs > 3 || visited[xs][ys][i][cs]) {
                    continue;
                }
                dist[xs][ys][i][cs] = dist[x][y][dir][c] + 1;
                visited[xs][ys][i][cs] = true;
                q.push({xs, ys, i, cs});
            }
        }
    }

    int answer = INT_MAX;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            answer = min(answer, dist[e_x][e_y][i][j]);
        }
    }
    if (answer == INT_MAX) {
        print(-1);
    } else {
        print(answer);
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