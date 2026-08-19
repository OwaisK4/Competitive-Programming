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
            // cout << it.size() << "\n";
            mp[it.size()]++;
        }
        int xy = mp[1];
        int x = -1;
        int y;
        for (auto it : mp){
            if (it.second == 1){
                x = it.first;
                y = xy / x;
            }
        }
        if (x == -1){
            y = prev(mp.end())->first - 1;
            x = xy / y;
        }

        cout << x << " " << y;
        cout << "\n";
    }
    return 0;
}