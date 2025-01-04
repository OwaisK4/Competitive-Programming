#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
using namespace std;

vector<vector<int>> adj;
vector<int> counter;
vector<bool> visited;

int dfs(int source){
    visited[source] = true;
    for (auto it : adj[source]){
        if (!visited[it]){
            counter[source] += dfs(it);
        }
    }
    if (adj[source].size() == 1){
        return 1;
    }
    return counter[source];
}

void solve(){
    int n, q;
    cin >> n;
    adj.assign(n, vector<int>());
    visited.assign(n, false);
    counter.assign(n, 0);
    int x, y;
    for (int i=0; i<n-1; i++){
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(0);
    for (int i=0; i<n; i++){
		counter[i] = max(counter[i], 1LL);
	}

    cin >> q;
    for (int i=0; i<q; i++){
        cin >> x >> y;
        x--;
        y--;
        int x_verts = counter[x];
        int y_verts = counter[y];
        int answer = (x_verts * y_verts);
        cout << answer << "\n";
    }
    visited.clear();
    counter.clear();
}

signed main(){
    fastio;
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}