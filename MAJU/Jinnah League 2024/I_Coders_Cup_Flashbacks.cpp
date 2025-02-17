#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
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

// vvi dp(901, vi(8101, INT_MAX));
// vvi parent(901, vi(8101, -1));
// vector<vector<short>> dp(901, vector<short>(8101, SHRT_MAX));
// vector<vector<short>> parent(901, vector<short>(8101, -1));
short dp[901][8101];
short parent[901][8101];

void solve() {
    int s1, s2;
    cin >> s1 >> s2;
    if (s1 > 900 || s2 > 8100 || dp[s1][s2] == SHRT_MAX || dp[s1][s2] > 100) {
        print("No solution");
        return;
    }
    // print("Digits = ", dp[s1][s2]);
    vector<short> answer;
    short p = parent[s1][s2];
    while (p != -1) {
        answer.push_back(p);
        s1 -= p;
        s2 -= p * p;
        p = parent[s1][s2];
    }
    sort(all(answer));
    for (auto it : answer) {
        cout << it;
    }
    print("");
}

signed main() {
    fastio;
    for (int i = 0; i <= 900; i++) {
        for (int j = 0; j <= 8100; j++) {
            dp[i][j] = SHRT_MAX;
            parent[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for (short i = 0; i <= 900; i++) {
        for (short j = 0; j <= 8100; j++) {
            for (short k = 1; k <= 9; k++) {
                if (i < k || j < k * k || dp[i - k][j - k * k] == SHRT_MAX)
                    continue;
                if (dp[i][j] > dp[i - k][j - k * k] + 1) {
                    dp[i][j] = dp[i - k][j - k * k] + 1;
                    parent[i][j] = k;
                }
            }
        }
    }

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}