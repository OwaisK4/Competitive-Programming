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

int n, m;
vector<int> a;
vector<vector<int>> dp;

int f(int index, int last) {
    if (index == n) {
        return dp[index][last] = 1LL;
    }
    if (dp[index][last] != -1) {
        return dp[index][last];
    }
    if (a[index] != 0) {
        if (last == 0 || abs(a[index] - last) <= 1)
            return dp[index][last] = f(index + 1, a[index]);
        else
            return dp[index][last] = 0;
    }
    int answer = 0;
    if (index == 0 && a[index] == 0) {
        for (int i = 1; i <= m; i++) {
            answer += f(index + 1, i);
            answer %= MOD;
        }
    } else {
        for (int i = max(1LL, last - 1); i <= min(m, last + 1); i++) {
            answer += f(index + 1, i);
            answer %= MOD;
        }
    }

    return dp[index][last] = answer % MOD;
}

void solve() {
    cin >> n >> m;
    a.assign(n, 0);
    dp.assign(n + 1, vector<int>(m + 1, -1));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int answer = f(0, 0);
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