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

vector<int> dp(2000001, 0);

int binpow(int x, int n) {
    if (n == 0) {
        return 1;
    } else if (n == 1) {
        return x;
    }
    int answer = binpow(x, n / 2);
    answer *= answer;
    if (n & 1) {
        answer *= x;
    }
    return answer;
}

void solve() {
    int l, r;
    cin >> l >> r;
    int answer = dp[l] * 2;
    for (int i = l + 1; i <= r; i++) {
        answer += dp[i];
    }
    cout << answer << "\n";
}

signed main() {
    fastio;
    int j = 0;
    for (int i = 0; binpow(3, i) < 2000001LL; i++) {
        while (j < binpow(3, i)) {
            dp[j++] = i;
        }
    }
    // print(dp, 15);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}