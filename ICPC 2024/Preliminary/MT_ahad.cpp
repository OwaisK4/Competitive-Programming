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
#define yesno(b) cout << ((b) ? "YES" : "NO");
#define pii pair<int, int>
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define hhh cout << "here" << endl;
#define mod1 1000000007
#define mod2 998244353
const int N = 2e5 + 10;
const int inf = 1e17;
void solve() {
    int n;
    cin >> n;
    vi adj[n];
    vi used(n, 0), d(n, 0);
    vi deg(n, 0);

    forn(1, n) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
        deg[u]++;
        deg[v]++;
    }

    forn(0, n) d[i] = inf;

    queue<pii> q;
    d[0] = 0;
    q.push({0, 0});
    while (!q.empty()) {
        int u = q.front().first;
        int x = q.front().second;
        q.pop();

        if (used[u])
            continue;

        for (auto v : adj[u]) {

            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push({v, d[v]});
            }
        }
    }

    int maxi = *max_element(all(d));
    int node;
    forn(0, n) {
        if (d[i] == maxi) {
            node = i;
            break;
        }
    }

    forn(0, n) {
        used[i] = 0;
        d[i] = inf;
    }

    d[node] = 0;
    q.push({node, 0});
    while (!q.empty()) {
        int u = q.front().first;
        int x = q.front().second;
        q.pop();

        if (used[u])
            continue;

        for (auto v : adj[u]) {
            if (d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push({v, d[v]});
            }
        }
    }

    int ans = *max_element(all(d));
    sort(all(deg));
    reverse(all(deg));
    cout << ans << " " << deg[0] << " " << deg[1];
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
        nl;
    }
    return 0;
}