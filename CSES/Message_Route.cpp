#include <bits/stdc++.h>
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> &array, int size = numeric_limits<int>::max()) {
    for (int i = 0; i < min<int>(size, array.size()); i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}
template <typename T>
void print(T X) {
    cout << X << "\n";
}

vector<vector<int>> adj;
vector<bool> visited;
vector<int> previous;
bool found = false;

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    adj.assign(n, vector<int>());
    visited.assign(n, false);
    previous.assign(n, -1);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        visited[node] = true;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                q.push(it);
                previous[it] = node;
                // visited[it] = true;
            }
        }
    }

    if (visited[n - 1]) {
        vector<int> path;
        int node = n - 1;
        while (node != -1) {
            path.push_back(node);
            node = previous[node];
        }
        reverse(all(path));
        cout << path.size() << "\n";
        for (auto it : path) {
            cout << it + 1 << " ";
        }
        // cout << n << "\n";
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}