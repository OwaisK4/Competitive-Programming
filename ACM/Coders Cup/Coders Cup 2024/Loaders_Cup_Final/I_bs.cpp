#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define MOD 1000000007
using namespace std;
using pii = pair<int, int>;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;

void solve() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    if (count(all(s), 'X') == 0) {
        cout << min(n, k);
        return;
    }
    int low = -1, high = n;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        int cnt = 0;
        bool valid = false;
        for (int i = 0; i < mid; i++) {
            if (s[i] == 'X') {
                cnt++;
            }
        }
        if (mid <= k + cnt) {
            valid = true;
        }
        for (int i = mid; i < n; i++) {
            if (s[i - mid] == 'X')
                cnt--;
            if (s[i] == 'X')
                cnt++;
            if (mid <= k + cnt) {
                valid = true;
            }
        }
        if (valid) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    cout << low;
}

signed main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}