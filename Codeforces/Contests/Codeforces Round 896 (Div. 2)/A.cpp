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

void solve() {
    int n;
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x = 0;
    for (int i = 0; i < n; i++) {
        x ^= a[i];
    }
    if (x == 0) {
        cout << 1 << "\n";
        cout << 1 << " " << n << "\n";
        return;
    }

    if (n & 1) {
        cout << 4 << "\n";
        cout << 1 << " " << n << "\n";
        cout << 1 << " " << n - 1 << "\n";
        cout << n - 1 << " " << n << "\n";
        cout << n - 1 << " " << n << "\n";
    } else {
        cout << 2 << "\n";
        cout << 1 << " " << n << "\n";
        cout << 1 << " " << n << "\n";
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}