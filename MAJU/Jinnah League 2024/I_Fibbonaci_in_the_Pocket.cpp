#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF LONG_LONG_MAX
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

int N = 400000007;
vector<int> dp(2), even, prefix;

void solve() {
    int M;
    cin >> M;
    auto it = lower_bound(all(even), M);
    if (it != even.end() && *it == M) {
        it++;
    }
    int jt = it - even.begin();
    print(prefix[jt]);
}

signed main() {
    fastio;
    dp[0] = 1;
    dp[1] = 2;
    int i = 2;
    while (true) {
        int current = dp[i - 1] + dp[i - 2];
        if (current > N) {
            break;
        }
        dp.push_back(current);
        i++;
    }
    for (auto it : dp) {
        if (it % 2 == 0) {
            even.push_back(it);
            i++;
        }
    }
    prefix.assign(even.size() + 1, 0);
    partial_sum(all(even), prefix.begin() + 1);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}