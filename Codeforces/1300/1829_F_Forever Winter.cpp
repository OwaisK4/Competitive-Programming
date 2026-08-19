#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;
vector<vector<int>> adj;

signed main(){
    fastio;
    int t;
    int n, m;
    int u, v;
    cin >> t;
    while (t--){
        cin >> n >> m;
        adj.assign(n, vector<int>());
        for (int i=0; i<m; i++){
            cin >> u >> v;
            u--;
            v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        map<int, int> mp;
        for (auto& it : adj){
            cout << it.size() << "\n";
            mp[it.size()]++;
        }
        int x = (prev(mp.end()))->second;
        if (x == 1){
            x = (prev(prev(mp.end())))->second;
        }
        int y = mp[1] / x;
        cout << x << " " << y;
        cout << "\n";
    }
    return 0;
}