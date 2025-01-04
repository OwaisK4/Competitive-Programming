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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    int ops = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = 0, down = 0, left = 0, right = 0;
            up = (i > 0) ? a[i - 1][j] : 0;
            down = (i < n - 1) ? a[i + 1][j] : 0;
            left = (j > 0) ? a[i][j - 1] : 0;
            right = (j < m - 1) ? a[i][j + 1] : 0;

            if (a[i][j] > up && a[i][j] > down && a[i][j] > left && a[i][j] > right) {
                ops += a[i][j] - max({up, down, left, right});
                a[i][j] = max({up, down, left, right});
            }
        }
    }
    for_each(all(a), [](vector<int> &a) { print(a); });
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