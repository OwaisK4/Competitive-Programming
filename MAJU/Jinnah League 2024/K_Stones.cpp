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

int n, k;
vector<int> a, dp;

int f(int remaining) {
    if (dp[remaining] != -1) {
        return dp[remaining];
    }
    int answer = 1;
    for (int i = 0; i < n; i++) {
        if (remaining >= a[i]) {
            answer = answer & f(remaining - a[i]);
        }
    }
    if (answer == 1) {
        return dp[remaining] = 0;
    }
    return dp[remaining] = 1;
}

void solve() {
    cin >> n >> k;
    a.assign(n, 0);
    dp.assign(k + 1, -1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int answer = f(k);
    print((answer == 1) ? "First" : "Second");
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