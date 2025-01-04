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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if (n < 3) {
            cout << "YES\n";
            continue;
        }
        bool flag1 = false, flag2 = false;
        int current = a[0];
        for (int i = 1; i < n; i++) {
            if (!flag1 && a[i] < current) {
                flag1 = true;
            } else if (flag1 && a[i] > current) {
                flag2 = true;
                break;
            }
            current = a[i];
        }
        if (flag2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }

    return 0;
}