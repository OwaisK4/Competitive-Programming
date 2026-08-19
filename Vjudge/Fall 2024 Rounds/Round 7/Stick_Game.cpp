#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #define int long long
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

int f(int index) {
    if (index == 0LL) {
        return dp[index] = 0LL;
    }
    if (dp[index] != -1) {
        return dp[index];
    }
    int answer = 1LL;
    for (int i = 0; i < k; i++) {
        if (index - a[i] >= 0LL) {
            answer = answer & f(index - a[i]);
        }
    }
    if (answer == 0LL) {
        return dp[index] = 1LL;
    }
    return dp[index] = 0LL;
}

void solve() {
    cin >> n >> k;
    a.assign(k, 0);
    dp.assign(n + 1, -1);
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        if (f(i)) {
            cout << "W";
        } else {
            cout << "L";
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