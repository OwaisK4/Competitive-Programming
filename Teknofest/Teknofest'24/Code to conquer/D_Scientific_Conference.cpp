#include <bits/stdc++.h>
using namespace std;
signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first >> a[i].second;
        }
        sort(a.begin(), a.end(), [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });
        int cnt = 1;
        int ending = a[0].second;
        for (int i = 0; i < n; i++) {
            if (a[i].first > ending) {
                ending = a[i].second;
                cnt++;
            }
        }
        cout << cnt;
    }
    return 0;
}