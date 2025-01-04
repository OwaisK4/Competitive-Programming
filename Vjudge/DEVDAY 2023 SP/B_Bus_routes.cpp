#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
#define vii vector<pair<int, int>>
#define MAX numeric_limits<int>::max()
using namespace std;

signed main(){
    int u, v, w;
    int n, m;
    cin >> n >> m;

    vector<vii> graph(n+1, vii());
    vector<int> dist(n+1, MAX);
    vector<bool> visited(n+1, false);
    // cout << MAX << "\n";
    for (int i=0; i<m; i++){
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        // graph[v].push_back({u, w});
    }

    int source = 1;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});
    dist[source] = 0;

    while (!pq.empty()){
        // int distance = pq.top().first;
        int source = pq.top().second;
        
        if(pq.top().first > dist[source]) {
            pq.pop();
            continue;
        }
        pq.pop();
        
        for (auto it : graph[source]){
            if (dist[it.first] > dist[source] + it.second){
                dist[it.first] = dist[source] + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }

    // cout << "owais";
    for (int i=1; i<=n; i++){
        cout << dist[i] << " ";
    }

    return 0;
}