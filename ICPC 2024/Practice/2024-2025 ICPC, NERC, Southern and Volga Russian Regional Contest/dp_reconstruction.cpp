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

int n;
string answer = "owais";
int length = 51 * 51 * 51 * 51 * 2;
bool dp[51][51][51][51][2] = {0};

void solve() {
    cin >> n;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    print(dp[a][b][c][d][0]);
    print(dp[a][b][c][d][1]);
    // a = 00, b = 01, c = 01, d = 10
}

signed main() {
    fastio;
    // fill(dp, dp + length, false);
    dp[0][0][0][0][0] = true;
    dp[0][0][0][0][1] = true;
    for (int a = 0; a <= 50; a++) {
        for (int b = 0; b <= 50; b++) {
            for (int c = 0; c <= 50; c++) {
                for (int d = 0; d <= 50; d++) {
                    if (dp[a][b][c][d][0]) {
                        if (a < 50)
                            dp[a + 1][b][c][d][0] = true;
                        if (b < 50)
                            dp[a][b + 1][c][d][1] = true;
                    }
                    if (dp[a][b][c][d][1]) {
                        if (c < 50)
                            dp[a][b][c + 1][d][1] = true;
                        if (d < 50)
                            dp[a][b][c][d + 1][0] = true;
                    }
                }
            }
        }
    }
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}