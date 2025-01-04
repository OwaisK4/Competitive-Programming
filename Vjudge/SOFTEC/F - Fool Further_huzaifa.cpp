#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pb push_back
#define vii vector<pair<int, int>>

int recur(vector<vii> &g, vi &visited, int n)
{
    visited[n] = 1;
    int maxi = 0;
    for (auto &t : g[n])
    {
        if (!visited[t.first])
            maxi = max(maxi, t.second + recur(g, visited, t.first));
    }
    return maxi;
}

int main(void)
{
    int n;
    cin >> n;
    vector<vii> g(n);
    vi visited(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].pb({v, c});
        g[v].pb({u, c});
    }
    cout << recur(g, visited, 0);

    return 0;
}