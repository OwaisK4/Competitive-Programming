#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define nl cout << "\n"
using namespace std;

void dfs(int v, vector<vector<int>>& adj, vector<int>& visited, vector<int>& stack){
    visited[v] = true;
    for (auto it : adj[v]){
        if (!visited[it]){
            dfs(it, adj, visited, stack);
        }
    }
    stack.push_back(v);
}

void topological_sort(int n, vector<vector<int>> adj){
    vector<int> visited(n+1, false);
    vector<int> stack;
    for (int i=1; i<=n; i++){
        if (!visited[i]){
            dfs(i, adj, visited, stack);
        }
    }
    reverse(all(stack));
    for (auto it : stack){
        cout << it << " ";
    }
}

int main()
{
    vector<vector<int>> adj;
    int n = 6;
    adj.resize(n+1);

    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(6);
    adj[4].push_back(1);
    adj[4].push_back(5);
    adj[5].push_back(2);
    adj[5].push_back(3);

    topological_sort(n, adj);

    return 0;
}