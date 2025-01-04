#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #define int long long
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

vvi dp;
// int f(int a, int b) {
//     if (a == b) {
//         return 0;
//     }
//     if (dp[a][b] != -1) {
//         return dp[a][b];
//     }
//     int answer = INT_MAX;
//     if (a > b)
//         for (int i = 1; i < a; i++) {
//             answer = min(answer, f(i, b) + f(a - i, b) + 1);
//         }
//     else
//         for (int i = 1; i < b; i++) {
//             answer = min(answer, f(a, i) + f(a, b - i) + 1);
//         }
//     return dp[a][b] = answer;
// }

void solve() {
    int a, b;
    cin >> a >> b;
    dp.assign(a + 1, vi(b + 1));
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            if (i == j) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = INT_MAX;
            for (int k = 1; k < i; k++) {
                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }
            for (int k = 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
            }
        }
    }
    print(dp[a][b]);
    // int answer = f(a, b);
    // print(answer);
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