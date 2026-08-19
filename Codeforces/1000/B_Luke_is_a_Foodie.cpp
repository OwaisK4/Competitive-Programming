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
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int l = a[0] - x;
        int r = a[0] + x;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            l = max(l, a[i] - x);
            r = min(r, a[i] + x);
            if (l > r) {
                cnt++;
                l = a[i] - x;
                r = a[i] + x;
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}