#include <bits/stdc++.h>
#include <ext/numeric>
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
        map<int, int> mp;
        set<int> s;
        if (s.contains(1)) {
        }
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]] = 1;
        }
        int i = 1;
        while (x > 0) {
            if (mp.count(i) == 0) {
                mp[i] == 1;
                x--;
            }
            i++;
        }
        while (mp.count(i)) {
            i++;
        }
        cout << i - 1 << "\n";
    }

    return 0;
}