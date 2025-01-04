#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

signed main() {
    fastio;

    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        if (r < 4) {
            cout << -1 << "\n";
            continue;
        }
        if (l == r) {
            bool flag = false;
            int i;
            for (i = 2; (i * i) <= r; i++) {
                if (r % i == 0) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                cout << i << " " << r - i << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else {
            cout << r / 2 << " " << r / 2 << "\n";
        }
    }

    return 0;
}