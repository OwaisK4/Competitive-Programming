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

int n, m;
vvi dp;

void getMasks(int i, int mask, int nextMask, vi &nextMasks) {
    if (i == n) {
        nextMasks.push_back(nextMask);
        return;
    }
    if (i + 1 < n && ((1 << i) & mask) == 0 && ((1 << (i + 1)) & mask) == 0) {
        getMasks(i + 2, mask, nextMask, nextMasks);
    }
    if (((1 << i) & mask) == 0) {
        getMasks(i + 1, mask, nextMask + (1 << i), nextMasks);
    }
    if ((((1 << i) & (mask)) != 0)) {
        getMasks(i + 1, mask, nextMask, nextMasks);
    }
    return;
}

int f(int i, int mask) {
    if (i == m) {
        if (mask) {
            return 0;
        }
        return 1;
    }
    if (dp[i][mask] != -1) {
        return dp[i][mask];
    }
    int answer = 0;
    vi nextMasks;
    getMasks(0, mask, 0, nextMasks);
    for (auto x : nextMasks) {
        answer += f(i + 1, x);
        answer %= MOD;
    }
    return dp[i][mask] = answer;
}

void solve() {
    cin >> n >> m;
    dp.assign(m, vi(1 << n, -1));
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