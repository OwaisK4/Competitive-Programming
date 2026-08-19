#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> vis;
vector<int> pre;

signed main() {
    int n, m;
    cin >> n >> m;
    adj.assign(n, vector<int>());
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vis.assign(n, 0);
    pre.assign(n, -1);
    int curr = 0;
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    while (!q.empty()) {
        curr = q.front();
        // cout << curr << " ";
        q.pop();
        for (auto it : adj[curr]) {
            if (!vis[it]) {
                q.push(it);
                vis[it] = 1;
                pre[it] = curr;
            }
        }
    }
    vector<int> path;
    int en = n - 1;
    if (vis[n - 1]) {
        while (en != 0) {
            int p = pre[en];
            path.push_back(p);
            en = p;
        }
        reverse(path.begin(), path.end());
        cout << path.size() + 1 << endl;
        for (auto it : path) {
            cout << it + 1 << " ";
        }
        cout << n;
        cout << endl;
    } else
        cout << "IMPOSSIBLE";
}