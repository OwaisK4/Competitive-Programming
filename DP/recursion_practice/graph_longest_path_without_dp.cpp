#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

int dfs(auto& adj, int source){
    int max_dist = 0;
    for (auto it : adj[source]){
        max_dist = max(max_dist, dfs(adj, it, dist) + 1);
    }
    return max_dist;
}

signed main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N);
    vector<int> dist(N, -1);
    int x, y;
    for (int i=0; i<M; i++){
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
    }
    int max_dist = 0;
    for (int i=0; i<N; i++){
        max_dist = max(max_dist, dfs(adj, i));
    }
    cout << max_dist;

    return 0;
}