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
const int N = 2e5;
int cost, n;
vi v[N + 2];
int dp[(int)1e3 + 10][(int)1e5 + 10];
int f(int i, int x)
{
    if (i == n)
    {
        return x;
    }
    if (dp[i][x] != -1)
    {
        return dp[i][x];
    }
    int ans = 0;
    for (int j = 0; j < (int)v[i].size(); j++)
    {
        if (x + v[i][j] <= cost)
        {
            ans = max(ans, f(i + 1, x + v[i][j]));
        }
    }

    return dp[i][x] = ans;
}
void solve()
{
    cin >> cost >> n;
    forn(0, n)
    {
        v[i].clear();
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            v[i].pb(x);
        }
    }
    memset(dp, -1, sizeof(dp));
    int ans = f(0, 0);
    if (ans <= 0)
    {
        cout << -1;
    }
    else
    {
        cout << ans;
    }
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
        nl;
    }
    return 0;
}