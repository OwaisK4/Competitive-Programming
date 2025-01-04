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
    int k;
    // cin >> k;
    print(10 | 4);
    print(2 & 4);

    // for (int a = 1; a <= 50; a++) {
    //     int n = a;
    //     vector<int> dp(n, 1);
    //     for (int i = 1; i <= n; i++) {
    //         bool valid = false;
    //         for (int j = 0; j < n; j++) {
    //             if ((j + 1) >= i && (j + 1) % i == 0) {
    //                 dp[j] = 1 - dp[j];
    //                 valid = true;
    //             }
    //         }
    //         // if (valid)
    //         //     print(dp);
    //     }
    //     // print("");
    //     int cnt = count(all(dp), 1);
    //     print(cnt);
    // }
}

signed main() {
    fastio;
    // int t = 1;
    // cin >> t;
    // while (t--) {
    solve();
    // }

    return 0;
}