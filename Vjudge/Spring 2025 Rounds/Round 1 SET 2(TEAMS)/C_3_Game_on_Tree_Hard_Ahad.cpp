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
#define yesno(b) cout << ((b) ? "Ron" : "Hermione");
#define pii pair<int, int>
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define hhh cout << "here" << endl;
#define mod1 1000000007
#define mod2 998244353
const int inf = 1e17 + 1;

template <typename T>
void print(vector<T> &array, int size = numeric_limits<int>::max()) {
    for (int i = 0; i < min<int>(size, array.size()); i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}

void solve() {
    int n, q;
    cin >> n >> q;
    vi adj[n];
    forn(1, n) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    vi dp(n, 0), dp1(n, 0);
    function<void(int, int)> dfs = [&](int u, int p) {
        for (int v : adj[u]) {
            if (v == p)
                continue;
            dfs(v, u);
            dp[u] += (dp[v] == 0);
        }
    };

    function<void(int, int)> dfs1 = [&](int u, int p) {
        if (dp[u] > 0)
            dp1[u] = 1;
        for (int v : adj[u]) {
            if (v == p)
                continue;

            int lu = dp[u], lv = dp[v];

            dp[u] -= (dp[v] == 0);
            dp[v] += (dp[u] == 0);

            dfs1(v, u);
            dp[u] = lu;
            dp[v] = lv;
        }
    };

    dfs(0, -1);
    print(dp);
    dfs1(0, -1);

    while (q--) {
        int x;
        cin >> x;
        yesno(dp1[x - 1]);
        nl;
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
        // nl;
    }
    return 0;
}