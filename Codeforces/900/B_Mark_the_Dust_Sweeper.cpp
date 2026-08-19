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
        int cnt = 0;
        bool flag = false;
        for (int i = 0; i < n - 1; i++) {
            if (!flag && a[i] != 0)
                flag = true;
            if (a[i] != 0)
                cnt += a[i];
            if (a[i] == 0 && flag)
                cnt++;
        }
        cout << cnt << "\n";
    }

    return 0;
}