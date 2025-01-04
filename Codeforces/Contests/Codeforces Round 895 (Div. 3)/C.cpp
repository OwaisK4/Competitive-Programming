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

template <typename T>
void print(T array) {
    for (auto it = begin(array); it != end(array); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int l, r;
        cin >> l >> r;
        bool flag = false;
        if (l == r) {
            int a = 1;
            int b = r - 1;
            while (a <= b) {
                if (gcd(a, b) != 1) {
                    flag = true;
                    break;
                }
                a++;
                b--;
            }
            cout << a << " " << b << "\n";
        } else {
            int i;
            for (i = l; i <= r; i++) {
                if (i % 2 == 0) {
                    if ((i / 2) % 2 == 0) {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                cout << (i / 2) << " " << (i / 2) << "\n";
            }
        }
        if (!flag) {
            cout << -1 << "\n";
        }
    }

    return 0;
}