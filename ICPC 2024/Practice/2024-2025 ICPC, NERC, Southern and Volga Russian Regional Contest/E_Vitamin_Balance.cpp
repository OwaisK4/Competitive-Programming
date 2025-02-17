#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define int long long
#define all(a) a.begin(), a.end()
#define f first
#define s second
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

vvi dp(5001, vi(3, 0));

void solve() {
    int n, x;
    cin >> n >> x;
    vvi a(n, vi(3, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= a[i][2]; j--) {
            int upgrade = dp[j - a[i][2]][a[i][0] - 1] + a[i][1];
            if (dp[j][a[i][0] - 1] < upgrade) {
                // print("Here");
                dp[j][0] = dp[j - a[i][2]][0];
                dp[j][1] = dp[j - a[i][2]][1];
                dp[j][2] = dp[j - a[i][2]][2];
                dp[j][a[i][0] - 1] += a[i][1];
            }
        }
    }
    vi answer = {-INF, -INF, -INF};
    for (int i = 0; i <= x; i++) {
        print(dp[i]);
        // if (*min_element(all(answer)) < *min_element(all(dp[i]))) {
        //     answer = dp[i];
        // }
    }
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