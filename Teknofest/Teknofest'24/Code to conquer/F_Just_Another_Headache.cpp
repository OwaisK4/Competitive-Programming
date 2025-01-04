#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    int t = 1;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), indexes(2 * n + 1, 0);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            indexes[a[i]] = i + 1;
        }
        int cnt = 0;
        for (int it = 0; it <= 2 * n; it++) {
            for (int ai = 1; ai * ai < it; ai++) {
                if (it % ai == 0) {
                    int aj = it / ai;
                    int i = indexes[ai];
                    int j = indexes[aj];
                    if (i + j == it && i != 0 && j != 0) {
                        cnt++;
                    }
                }
            }
        }
        cout << cnt << "\n";
    }
    return 0;
}