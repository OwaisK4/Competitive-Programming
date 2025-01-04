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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m, 0));
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '1') {
                mp[j]++;
            }
        }
    }
    // for (auto it : mp) {
    //     cout << it.first << " " << it.second << "\n";
    // }
    bool valid;
    for (int i = 0; i < n; i++) {
        valid = true;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1') {
                if (mp[j] == 1) {
                    valid = false;
                    break;
                }
            }
        }
        if (valid) {
            break;
        }
    }
    if (valid && mp.size() == m) {
        cout << "YES";
    } else {
        cout << "NO";
    }
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