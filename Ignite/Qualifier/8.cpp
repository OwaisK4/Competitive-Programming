#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define int long long int
#define nl cout << endl;
#define PB push_back
#define MP make_pair
#define f(a, b) for (int i = a; i < b; i++)

void solve(int n, int d) {
    // int n, d;
    // cin >> n >> d;
    int ans, expected;
    if (d == 1) {
        ans = n + (n / 2);
    } else {
        expected = (2 * n) / 3;
        while (n > expected + (expected / 2))
            expected++;
        if (n == expected + (expected / 2))
            ans = expected;
        else if (n < expected + (expected / 2))
            ans = -1;
    }
    cout << ans;

    nl
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    // cin>>t;
    f(1, 101) {
        solve(i, -1);
    }

    while (t--)
        // solve();

        return 0;
}