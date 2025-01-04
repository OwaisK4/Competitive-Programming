#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
using namespace std;
using pii = pair<int, int>;

int dfs(vector<vector<pii>> graph, int source, vector<bool>& visited){
    visited[source] = true;
    int maximum = 0;
    for (auto it : graph[source]){
        if (!visited[it.first]){
            int newVal = it.second + dfs(graph, it.first, visited);
            maximum = max(maximum, newVal);
        }
    }
    return maximum;
}

int main(){
    int n;
    cin >> n;
    vector<bool> visited(n, false);
    vector<vector<pii>> graph(n);
    for (int i=0; i<n-1; i++){
        int u, v, c;
        cin >> u >> v >> c;
        graph[u].push_back({v, c});
        graph[v].push_back({u, c});
    }
    int answer = dfs(graph, 0, visited);
    cout << answer;

    return 0;
}