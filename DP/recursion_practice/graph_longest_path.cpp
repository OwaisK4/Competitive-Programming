#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

int dfs(auto& adj, int source, auto& dist){
    if (dist[source] != -1){
        return dist[source];
    }
    int max_dist = 0;
    for (auto it : adj[source]){
        max_dist = max(max_dist, dfs(adj, it, dist) + 1);
    }
    dist[source] = max_dist;
    return dist[source];
}

void dfs2(auto& adj, int source, auto& visited, auto& dist){
    visited[source] = true;
    
    for (auto it : adj[source]){
        if (!visited[it]){
            dfs2(adj, it, visited, dist);
        }
        dist[source] = max(dist[source], dist[it] + 1);
    }
}

signed main(){
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N);
    vector<bool> visited(N, false);
    vector<int> dist(N, -1);
    vector<int> dist2(N, 0);
    int x, y;
    for (int i=0; i<M; i++){
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
    }
    int max_dist = 0;
    for (int i=0; i<N; i++){
        if (!visited[i]){
            dfs2(adj, i, visited, dist2);
        }
        // max_dist = max(max_dist, dfs(adj, i, dist));
    }
    // cout << max_dist;
    cout << *max_element(all(dist2));

    return 0;
}