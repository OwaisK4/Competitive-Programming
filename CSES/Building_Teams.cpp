#include <bits/stdc++.h>
#define int long long
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
vector<int> color;

bool matching(int source) {
    if (visited[source]) {
        return true;
    }
    visited[source] = true;
    color[source] = 1;
    queue<int> pq;
    pq.push(source);
    while (!pq.empty()) {
        source = pq.front();
        pq.pop();
        for (auto it : adj[source]) {
            if (visited[it] && color[it] == color[source]) {
                return false; // Exit condition. Bipartite matching impossible.
            }
            if (!visited[it]) {
                visited[it] = true;
                color[it] = (color[source] % 2) + 1;
                pq.push(it);
            }
        }
    }
    return true;
}

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    adj.assign(n, vector<int>());
    visited.assign(n, false);
    color.assign(n, 0);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // for (auto it : adj) {
    //     print(it);
    // }
    for (int i = 0; i < n; i++) {
        if (!matching(i)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    print(color);
    return 0;
}