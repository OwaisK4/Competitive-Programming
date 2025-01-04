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
    cout << X;
}
template <typename T, typename... Ts>
void print(T X, Ts... Y) {
    cout << X << " ";
    print(Y...);
}

void multiply(vector<vector<int>> &A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> X(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            X[i][j] = 0;
            for (int k = 0; k < n; k++) {
                X[i][j] += (A[i][k] * B[k][j]);
                X[i][j] %= MOD;
            }
        }
    }
    A = X;
}

void solve() {
    int n;
    cin >> n;
    n--;
    int limit = 10;
    vector<int> dp(limit, 0);
    for (int i = 0; i < 6; i++) {
        dp[i] = 1;
    }
    for (int i = 0; i < limit; i++) {
        for (int j = 1; j <= 6; j++) {
            if (i + j < limit) {
                dp[i + j] += dp[i];
            }
        }
    }
    if (n < 6) {
        print(dp[n]);
        return;
    }
    vector<vector<int>> F = {
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
        {1, 1, 1, 1, 1, 1},
    };
    vector<vector<int>> A = {
        {1, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 1},
    };
    vector<vector<int>> initial = {
        {dp[0], 0, 0, 0, 0, 0},
        {dp[1], 0, 0, 0, 0, 0},
        {dp[2], 0, 0, 0, 0, 0},
        {dp[3], 0, 0, 0, 0, 0},
        {dp[4], 0, 0, 0, 0, 0},
        {dp[5], 0, 0, 0, 0, 0},
    };
    while (n > 0) {
        if (n & 1) {
            multiply(A, F);
        }
        multiply(F, F);
        n >>= 1;
    }
    multiply(A, initial);
    print(A[0][0]);
    // print(dp);
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