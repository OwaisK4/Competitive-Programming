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

int niggaMod(int x, int m) {
    return ((x % m) + m) % m;
}

int n;
vector<int> a;
vector<vector<int>> dp;

bool f(int index, int last) {
    if (index == n) {
        if ((((last % 360) + 360) % 360) == 0)
            return true;
        return false;
    }
    if (dp[index][last] != -1)
        return dp[index][last];
    for (auto it : {-1, 1}) {
        if (f(index + 1, (((last + (it * a[index]) % 360) + 360) % 360)))
            return dp[index][last] = true;
    }
    return dp[index][last] = false;
}

void solve() {
    cin >> n;
    a.assign(n, 0);
    dp.assign(n, vector<int>(360, -1));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    bool answer = f(0, 0);
    print((answer == true) ? "YES" : "NO");
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