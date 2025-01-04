#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define MOD 10000000007
using namespace std;
using pii = pair<int, int>;

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

void solve() {
    int T, A, B;
    cin >> T >> A >> B;
    vector<int> dp(T + 1, 0);
    dp[0] = 1;

    for (int i = 0; i <= T; i++) {
        if (i + A <= T) {
            dp[i + A] |= dp[i];
        }
        if (i + B <= T) {
            dp[i + B] |= dp[i];
        }
        dp[i / 2] |= dp[i];
    }
    for (int i = 0; i <= T; i++) {
        if (i + A <= T) {
            dp[i + A] |= dp[i];
        }
        if (i + B <= T) {
            dp[i + B] |= dp[i];
        }
    }
    int max_fullness = 0;
    for (int i = T; i >= 0; i--) {
        if (dp[i]) {
            max_fullness = i;
            break;
        }
    }
    cout << max_fullness;
}

signed main() {
    fastio;
    file_read("feast.in");
    file_write("feast.out");

    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}