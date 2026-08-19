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
void print(T X, bool newline = true) {
    cout << X;
    if (newline) {
        cout << "\n";
    }
}

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> prices(n, 0), pages(n, 0), copies(n, 0), dp(x + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> copies[i];
    }

    vector<int> extended_prices, extended_pages;

    for (int i = 0; i < n; i++) {
        int k = 1;
        while (k <= copies[i]) {
            extended_prices.push_back(prices[i] * k);
            extended_pages.push_back(pages[i] * k);
            copies[i] -= k;
            k *= 2;
        }
        if (copies[i] > 0) {
            extended_prices.push_back(prices[i] * copies[i]);
            extended_pages.push_back(pages[i] * copies[i]);
        }
        // break;
    }

    n = extended_prices.size();
    for (int i = 0; i < n; i++) {
        for (int j = x; j >= extended_prices[i]; j--) {
            // if (j >= prices[i])
            dp[j] = max(dp[j], dp[j - extended_prices[i]] + extended_pages[i]);
        }
    }
    // print(extended_prices);
    // print(extended_pages);
    // print(dp);
    cout << dp[x];
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