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
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n >= m) {
            cout << "NO\n";
            continue;
        }
        sort(all(a), greater<int>());
        bool flag = true;

        m -= a[0];
        if (m <= 0) {
            cout << "NO\n";
            continue;
        }
        for (int i = 0; i < n; i++) {
            if (i == n - 1) {
                m -= 1;
            } else {
                m -= 1;
                m -= a[i];
            }
            if (m < 0) {
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}