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
        vector<int> cnt(n);
        int max_index = 0;
        int maximum = 0;
        for (int i = 0; i < n; i++) {
            cin >> cnt[i];
            if (maximum < cnt[i]) {
                maximum = cnt[i];
                max_index = i;
            }
        }
        cout << max_index + 1 << "\n";
    }

    return 0;
}