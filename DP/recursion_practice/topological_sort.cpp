#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define int long long int
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> nodes;

void dfs(int source){
    visited[source] = true;
    for (auto it : graph[source]){
        if (!visited[it]){
            dfs(it);
        }
    }
    nodes.push_back(source + 1);
}

signed main(){
    int N, M;
    cin >> N >> M;

    graph.resize(N);
    visited.assign(N, false);

    int x, y;
    for (int i=0; i<M; i++){
        cin >> x >> y;
        x--;
        y--;
        graph[x].push_back(y);
    }
    for (int i=0; i<N; i++){
        if (!visited[i]){
            dfs(i);
        }
    }
    reverse(all(nodes));

    for (auto it : nodes){
        cout << it << " ";
    }
    cout << "\n";

    return 0;
}