/***********

  Cypher

***********/
#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define nl '\n'

#ifdef LOCAL
#include "debug.h"
#else
#define debug(...)
#endif

void solve() {
    int a, b;
    cin >> a >> b;
    if (b <= 3) {
        cout << "-1\n";
        return;
    }
    if (a == b) {
        if (b % 2 == 0) {
            cout << b / 2 << " " << b / 2 << "\n";
            return;
        } else {
            for (int i = 2; i * i <= b; ++i) {
                if (b % i == 0) {
                    int d1 = i;
                    int d2 = b / i;
                    cout << d1 << " " << b - d1 << "\n";
                    return;
                }
            }
        }
    } else {
        if (b & 1)
            --b;
        cout << b / 2 << " " << b / 2 << "\n";
        return;
    }
    cout << "-1\n";
}

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int i = 0; i < tt; i++) {
        solve();
    }
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}
