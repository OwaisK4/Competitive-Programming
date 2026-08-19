#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int r = 1; r <= n; r++) {
            int total = r;
            int moves = r;
            int x = 0;
            while (moves + 3 <= n) {
                if (x == 0) {
                    x = r;
                } else {
                    x *= 2;
                }
                total += x;
                moves += 3;
            }
            total += (max(0ll, n - moves) * x);
            ans = max(ans, total);
        }
        cout << ans << "\n";
    }

    return 0;
}