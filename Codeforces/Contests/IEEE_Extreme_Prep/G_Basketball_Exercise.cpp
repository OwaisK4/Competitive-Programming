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

int n;
vector<int> a, b;
vector<vector<int>> dp;

int f(int index, int last) {
    if (index >= n) {
        return 0;
    }
    if (dp[index][last] != -1) {
        return dp[index][last];
    }
    int answer = 0;
    if (last != 0) {
        answer = max(answer, f(index + 1, 0) + b[index]);
    }
    if (last != 1) {
        answer = max(answer, f(index + 1, 1) + a[index]);
    }
    answer = max(answer, f(index + 1, 2));
    return dp[index][last] = answer;
}

void solve() {
    cin >> n;
    a.assign(n, 0);
    b.assign(n, 0);
    dp.assign(n + 1, vector<int>(3, -1));
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int answer = f(0, 2);
    cout << answer;
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