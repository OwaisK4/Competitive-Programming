#include <bits/stdc++.h>
// #define int long long
using namespace std;

int dp[1001][100001] = {0};
vector<int> price;
vector<int> pages;

signed main() {
    int n, x;
    cin >> n >> x;
    price.assign(n, 0);
    pages.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int cost = 1; cost <= x; cost++) {
            if (cost - price[i - 1] >= 0)
                dp[i][cost] = max(dp[i - 1][cost - price[i - 1]] + pages[i - 1], dp[i - 1][cost]);
            else
                dp[i][cost] = dp[i - 1][cost];
        }
    }
    cout << dp[n][x];
    return 0;
}