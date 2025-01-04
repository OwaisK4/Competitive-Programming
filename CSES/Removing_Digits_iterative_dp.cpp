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
using namespace std;

template <typename T>
void print(vector<T> &array, int size = numeric_limits<int>::max()) {
    for (int i = 0; i < min<int>(size, array.size()); i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

vector<int> digitize(int n) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    return digits;
}

vector<int> dp(1e6 + 1, LONG_LONG_MAX - 1);

void fill_dp(int n) {
    for (int i = n; i > 0; i--) {
        if (dp[i] == LONG_LONG_MAX - 1) {
            continue;
        }
        vector<int> digits = digitize(i);
        for (auto d : digits) {
            dp[i - d] = min(dp[i - d], dp[i] + 1);
        }
    }
}

signed main() {
    fastio;
    int n;
    cin >> n;
    dp[n] = 0;
    fill_dp(n);
    print(dp, n + 1);

    cout << dp[0];

    return 0;
}