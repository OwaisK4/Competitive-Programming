// Ya to win hai ya learn hai
//  #ifndef ONLINE_JUDGE
//      #define DEBUG
//      #include "utilities.h"
//  #else
//      #define debug(var)
//      #define debugArr(...)
//  #endif

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl endl
#define double long double
#define pb push_back
#define forn(i, a, n) for (int i = a; i < n; ++i)
#define all(a) a.begin(), a.end()
#define getunique(v)                      \
    {                                     \
        sort(all(v));                     \
        v.erase(unique(all(v)), v.end()); \
    }
#define MOD(a, b) ((a % b) + b) % b
#define pii pair<int, int>
#define pis pair<int, string>
#define psi pair<string, int>
#define pss pair<string, string>
#define pdi pair<double, int>
#define pid pair<int, double>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vd vector<double>
#define vs vector<string>
#define vvs vector<vector<string>>
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vpss vector<pss>
#define vpsi vector<psi>
#define vpis vector<pis>
template <typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
#define fastnuces            \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);             \
    int t = 1;

const int N = 2e5 + 10;
vi adj[N];
map<int, int> mp;
vector<bool> vis(N, false);
bool cmp(int i, int j) {
    return mp[i] < mp[j];
}
void solve() {
    int n;
    cin >> n;
    forn(i, 1, n) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // if we permute the ordering given
    // it must be one of bfs we get
    // how to make the given input be valid
    // store the ordering
    vi a;
    forn(i, 0, n) {
        int x;
        cin >> x;
        mp[x] = i;
        a.pb(x);
    }
    forn(i, 1, n + 1) {
        sort(all(adj[i]), cmp); // now we got a valid ordering
    }
    // now bfs over this graph
    // it should equal given ordering
    queue<int> myq;
    vi temp;
    vis[1] = true;
    myq.push(1);
    while (myq.size()) {
        int par = myq.front();
        myq.pop();
        temp.pb(par);
        for (int i : adj[par]) {
            if (!vis[i]) {
                vis[i] = true;
                myq.push(i);
            }
        }
    }
    if (a == temp) {
        cout << "Yes" << nl;
    } else
        cout << "No" << nl;
}
int main() {
    fastnuces;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}