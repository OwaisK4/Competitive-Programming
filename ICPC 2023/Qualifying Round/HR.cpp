#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long int
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define ld long double
#define nl cout << "\n";
#define getunique(v)                                  \
    {                                                 \
        sort(v.begin(), v.end());                     \
        v.erase(unique(v.begin(), v.end()), v.end()); \
    }
#define forn(a, b) for (int i = a; i < b; i++)
#define __builtin_popcountll __builtin_popcountll
#define __builtin_clzll __builtin_clzll
#define __builtin_ctzll __builtin_ctzll
#define pii pair<int, int>
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define hhh cout << "here" << endl;
#define mod1 1000000007
#define mod2 998244353
int n;
vi v[101];
int dp[101];
int f(int i, set<int> &s) {
    if (i >= n) {
        return 1;
    }

    // if (dp[i] != -1)
    // {
    //     return dp[i];
    // }

    int ans = 0;
    for (int j = 0; j < (int)v[i].size(); j++) {
        if (!s.count(v[i][j])) {
            s.insert(v[i][j]);
            ans += f(i + 1, s);
            s.erase(v[i][j]);
        }
    }

    // return dp[i] = ans;
    return ans;
}
void solve() {
    // memset(dp, -1, sizeof(dp));
    cin >> n;
    forn(0, n) {
        v[i].clear();
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            v[i].pb(x);
        }
    }
    set<int> s;
    cout << f(0, s);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        nl;
    }
    return 0;
}