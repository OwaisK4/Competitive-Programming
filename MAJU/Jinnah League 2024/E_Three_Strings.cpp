#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF LONG_LONG_MAX
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

string a, b, c;
int n, m;
vvi dp;

int f(int i, int j) {
    if (i == n && j == m) {
        return 0;
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    int answer = INT_MAX;
    if (i < n) {
        answer = min(answer, f(i + 1, j) + ((a[i] == c[i + j]) ? 0 : 1));
    }
    if (j < m) {
        answer = min(answer, f(i, j + 1) + ((b[j] == c[i + j]) ? 0 : 1));
    }
    return dp[i][j] = answer;
}

void solve() {
    cin >> a >> b >> c;
    n = a.size();
    m = b.size();
    dp.assign(n + 1, vi(m + 1, -1));
    int answer = f(0, 0);
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