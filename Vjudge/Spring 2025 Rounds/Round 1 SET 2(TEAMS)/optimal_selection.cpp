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

vvi price, dp;
int k, n;

int f(int index, int bitmask) {
    if (index == n) {
        return (bitmask == (1 << k) - 1) ? 0 : INF;
    }
    if (dp[index][bitmask] != -1) {
        return dp[index][bitmask];
    }
    int answer = INF;
    for (int i = 0; i < k; i++) {
        if ((1 << i) & bitmask)
            continue;
        answer = min(answer, f(index + 1, bitmask | (1 << i)) + price[i][index]);
    }
    answer = min(answer, f(index + 1, bitmask));
    return dp[index][bitmask] = answer;
}

void solve() {
    price = {
        {6, 9, 5, 2, 8, 9, 1, 6},
        {8, 2, 6, 2, 7, 5, 7, 2},
        {5, 3, 9, 7, 3, 5, 1, 4},
    };
    k = price.size();
    n = price.back().size();
    dp.assign(n, vi(1 << k, -1));
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