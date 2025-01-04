#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, a, b;
        cin >> n >> k >> a >> b;
        k--;
        a--;
        b--;
        vector<pair<int, int>> g(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            g[i] = {x, y};
        }
        if (a <= k && b <= k) {
            cout << 0 << endl;
        } else if (a <= k) {
            int mincost = LLONG_MAX;
            for (int i = 0; i <= k; i++) {
                int cost;
                cost = abs(g[i].first - g[b].first) + abs(g[i].second - g[b].second);
                mincost = min(cost, mincost);
            }
            cout << mincost << endl;
        } else {
            int mincost = abs(g[a].first - g[b].first) + abs(g[a].second - g[b].second);
            int f = 1e16, s = 1e16;
            for (int i = 0; i <= k; i++) {
                int x1 = abs(g[i].first - g[a].first) + abs(g[i].second - g[a].second);
                int x2 = abs(g[i].first - g[b].first) + abs(g[i].second - g[b].second);
                f = min(f, x1);
                s = min(s, x2);
            }

            cout << min(mincost, f + s) << endl;
        }
    }
}