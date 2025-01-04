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
    cin >> s;
    int cnt = 0;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            char rep = '0';
            if (s[i] == 'z') {
                rep = 'a';
            } else {
                rep = s[i] + 1;
            }
            if (i < n - 1 && s[i + 1] == rep) {
                rep = '0';
                if (s[i + 1] == 'z') {
                    rep = 'a';
                } else {
                    rep = s[i + 1] + 1;
                }
            }
            s[i] = rep;
        }
    }
    cout << s;
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