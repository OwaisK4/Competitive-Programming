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
const int N = 1e3;
vi adj[N + 10];
int n;
map<int, int> mp;
vi visited(N + 10);
vi d(N + 10);

void dijkstra(int s)
{
    visited.assign(N, 0);
    d.assign(N, 1e9);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, s});
    d[s] = 0;

    while (!pq.empty())
    {
        pii node = pq.top();
        pq.pop();
        int distance = node.first;
        int index = node.second;
        if (visited[index])
        {
            continue;
        }
        visited[index] = 1;
        for (auto it : adj[index])
        {
            if (d[index] + 1 < d[it])
            {
                d[it] = d[index] + 1;
                pq.push({d[it], it});
            }
        }
    }

    map<int, int> temp;
    forn(0, n + 1)
    {
        temp[d[i]]++;
    }
    int maxi = -1;
    for (auto it : temp)
    {
        if (it.first < 1e9)
        {
            maxi = it.first;
        }
    }
    mp[maxi]++;
}
void solve()
{
    cin >> n;
    mp.clear();
    forn(0, n + 1)
    {
        adj[i].clear();
    }
    forn(1, n)
    {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    forn(0, n)
    {
        dijkstra(i);
    }

    for (auto it : mp)
    {
        cout << it.second;
        return;
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