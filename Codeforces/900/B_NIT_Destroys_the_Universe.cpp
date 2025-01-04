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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (count(all(a), 0) == n) {
            cout << 0 << "\n";
            continue;
        }
        int cnt = 1;
        bool flag = false;
        bool flag2 = false;
        for (int i = 0; i < n; i++) {
            if (!flag && a[i] != 0) {
                flag = true;
            }
            if (flag && a[i] == 0) {
                flag2 = true;
            }
            if (flag2 && a[i] != 0) {
                cnt++;
                break;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}