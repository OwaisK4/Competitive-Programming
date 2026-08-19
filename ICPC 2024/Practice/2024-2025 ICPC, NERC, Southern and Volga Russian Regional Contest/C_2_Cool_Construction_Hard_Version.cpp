#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define int long long int
#define nl cout << endl;
#define PB push_back
#define MP make_pair
#define f(a, b) for (int i = a; i < b; i++)

void solve() {
    int n;
    cin >> n;

    vector<vi> a(n, vi(n, 0));
    if (n % 2) {
        a[0][0] = 4;
        a[0][2] = 6;
    }
    // asdasdasdasdasd
    int val, pos = 0, div;
    f(0, n) {
        for (int j = 0; j < n; j++) {
            if ((i + j) % 2) {
                val = i + j + 2;
                pos = 0;
                div = 3;
                while (div <= val) {
                    if (val % div == 0) {
                        break;
                    }
                    div++;
                }
                a[i][j] = div;
            } else if (!a[i][j])
                a[i][j] = 2;
        }
    }

    f(0, n) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        nl
    }

    // nl
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}