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
        int n, s;
        cin >> n >> s;
        vector<int> a(n), prefix(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        partial_sum(all(a), prefix.begin() + 1);
        int max_length = -1;
        for (int i = 1; i <= n; i++) {
            int value = s + prefix[i - 1];
            auto it = upper_bound(prefix.begin() + i, prefix.end(), value);
            if (it == prefix.end() && *(it - 1) < value) {
                continue;
            }
            int length = it - prefix.begin() - i;
            max_length = max(max_length, length);
        }
        if (max_length == -1) {
            cout << max_length << "\n";
        } else {
            cout << (n - max_length) << "\n";
        }
    }

    return 0;
}