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

void solve() {
    vector<vector<int>> grid(3, vector<int>(3, 0));
    map<int, vector<pii>> indexes;
    int n = 3;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            indexes[grid[i][j]].push_back({i, j});
        }
    }
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> n;
        for (auto [x, y] : indexes[n]) {
            grid[x][y] = -69;
        }
    }
    bool valid = false;
    n = 3;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == -69) {
                cnt++;
            }
        }
        if (cnt == 3) {
            valid = true;
        }
    }
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (grid[j][i] == -69) {
                cnt++;
            }
        }
        if (cnt == 3) {
            valid = true;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (grid[i][i] == -69) {
            cnt++;
        }
    }
    if (cnt == 3) {
        valid = true;
    }
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (grid[i][n - 1 - i] == -69) {
            cnt++;
        }
    }
    if (cnt == 3) {
        valid = true;
    }
    if (valid) {
        print("Yes");
    } else {
        print("No");
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