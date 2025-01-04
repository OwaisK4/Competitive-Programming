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
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int temp, odd = 0;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            if (temp & 1) {
                odd++;
            }
        }
        if (odd % 2 == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}