#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define int long long
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
int n, m, k;
vector<int> a;
int dp[101][101][101];

int f(int index, int flyers, int gifts) {
    if (flyers < 0 || gifts < 0) {
        return -1;
    }
    if (index == n) {
        return 0;
    }
    if (dp[index][flyers][gifts] != -1) {
        return dp[index][flyers][gifts];
    }
    int answer = 0;
    answer = max(1 + f(index + 1, flyers - a[index], gifts), 1 + f(index + 1, flyers, gifts - 1));
    return dp[index][flyers][gifts] = answer;
}

void solve() {
    cin >> n >> m >> k;
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int answer = f(0, m, k);
    print(answer);
}

signed main() {
    fastio;
    memset(dp, -1, sizeof(int) * 101 * 101 * 101);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}