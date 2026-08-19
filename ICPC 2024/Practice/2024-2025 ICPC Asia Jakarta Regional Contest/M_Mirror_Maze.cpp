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

int n, m;
bool isSafe(int x, int y) {
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;
    return true;
}

void solve() {
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m, 0));
    int mirrors = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] != '.')
                mirrors++;
        }
    }
    int answer = 0;
    queue<array<int, 5>> q; // {x, y, dx, dy, cnt}
    for (int i = 0; i < m; i++) {
        q.push({0, i, -1, 0, 0});
    }
    for (int i = 0; i < m; i++) {
        q.push({n - 1, i, 1, 0, 0});
    }
    for (int i = 0; i < n; i++) {
        q.push({i, 0, 0, 1, 0});
    }
    for (int i = 0; i < n; i++) {
        q.push({i, m - 1, 0, -1, 0});
    }
    while (!q.empty()) {
        auto [x, y, dx, dy, cnt] = q.front();
        q.pop();
        if (a[x][y] == '.') {
            q.push({x + dx, y + dx, dx, dy, cnt});
            continue;
        }
        if (a[x][y] == '/') {
            if (dx == 0 && dy == -1) {
                dx = 1;
                dy = 0;
                cnt++;
            }
            if (dx == 0 && dy == 1) {
                dx = -1;
                dy = 0;
            }
            if (dx == -1 && dy == 0) {
                dx = 0;
                dy = 1;
            }
            if (dx == 1 && dy == 0) {
                dx = 0;
                dy = -1;
            }
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