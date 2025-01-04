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

int n;
string s;
vector<vector<int>> dp;

int f(int l, int r) {
    int &res = dp[l][r];
    if (l > r) {
        return res = 0;
    } else if (l == r) {
        return res = 1;
    } else if (res != -1) {
        return res;
    }
    res = min(f(l + 1, r) + 1, f(l, r - 1) + 1);
    for (int i = l + 1; i <= r; i++) {
        if (s[l] == s[i]) {
            res = min(res, f(l, i - 1) + f(i + 1, r));
        }
    }
    return res;
}

void solve() {
    cin >> n;
    cin >> s;
    dp.assign(n + 1, vector<int>(n + 1, -1));
    int answer = f(0, n - 1);
    print(answer);
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