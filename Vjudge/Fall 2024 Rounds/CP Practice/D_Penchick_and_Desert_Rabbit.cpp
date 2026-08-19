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
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> maximum(n + 1, 0);
    vector<int> minimum(n + 1, INT_MAX);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        maximum[i + 1] = max(maximum[i], a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        minimum[i] = min(minimum[i + 1], a[i]);
    }
    vector<int> dp(n + 1, 0);
    dp[n] = maximum[n];
    function<int(int)> f = [&](int i) -> int {
        if (dp[i] != 0) {
            return dp[i];
        }
        int j = upper_bound(all(minimum), maximum[i] - 1) - minimum.begin();
        j--;
        if (j <= i) {
            return dp[i] = maximum[i];
        } else {
            return dp[i] = f(j);
        }
    };

    for (int i = 1; i <= n; i++) {
        cout << f(i) << " ";
    }
    print("");
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