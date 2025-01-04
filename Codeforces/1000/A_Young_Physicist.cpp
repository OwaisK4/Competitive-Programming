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
    int n;
    cin >> n;
    int x_total = 0, y_total = 0, z_total = 0;
    int x, y, z;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        x_total += x;
        y_total += y;
        z_total += z;
    }
    if (x_total == y_total && y_total == z_total && z_total == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}