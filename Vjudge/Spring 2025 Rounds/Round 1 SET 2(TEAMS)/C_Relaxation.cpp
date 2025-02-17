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
int n, h, l, r;
vi a;
vvi dp;

int f(int index, int sum) {
    if (index == n) {
        return 0;
    }
    if (dp[index][sum] != -1) {
        return dp[index][sum];
    }
    int answer = 0;
    answer = max(answer, f(index + 1, (sum + a[index]) % h) + (l <= ((sum + a[index]) % h) && ((sum + a[index]) % h) <= r));
    answer = max(answer, f(index + 1, (sum + a[index] - 1) % h) + (l <= ((sum + a[index] - 1) % h) && ((sum + a[index] - 1) % h) <= r));
    return dp[index][sum] = answer;
}

void solve() {
    cin >> n >> h >> l >> r;
    a.assign(n, 0);
    dp.assign(n + 1, vi(h + 1, -1));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
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