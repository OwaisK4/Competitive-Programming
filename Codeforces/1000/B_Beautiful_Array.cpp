#include <bits/stdc++.h>
#include <ext/numeric>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
using namespace __gnu_cxx;

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
        int n, k, b, s;
        cin >> n >> k >> b >> s;
        if (s == 0) {
            if (b == 0) {
                for (int i = 0; i < n; i++) {
                    cout << 0 << " ";
                }
                cout << "\n";
                continue;
            } else {
                cout << -1 << "\n";
                continue;
            }
        }
        if ((s / k) < b) {
            cout << -1 << "\n";
            continue;
        }
        int c = (k * b);
        c = min(s, c + k - 1);
        s -= c;
        if (n == 1 && s != 0) {
            cout << -1 << "\n";
            continue;
        }
        int sum = (n - 1) * (k - 1);
        if (sum < s) {
            cout << -1 << "\n";
            continue;
        }
        cout << c << " ";
        for (int i = 0; i < n - 1; i++) {
            int value = min(k - 1, s);
            s -= value;
            cout << max(value, 0LL) << " ";
        }
        cout << "\n";
    }

    return 0;
}