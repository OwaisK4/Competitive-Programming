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

vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<int> dist;

void dijkstra(int source) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[source] = 0;
    pq.push({0, source});
    while (!pq.empty()) {
        int source = pq.top().second;
        pq.pop();
        if (visited[source]) {
            continue;
        }
        visited[source] = true;
        for (auto it : adj[source]) {
            if (dist[it.first] > dist[source] + it.second) {
                dist[it.first] = dist[source] + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }
}

signed main() {
    fastio;
    int n, m;
    int a, b, c;
    cin >> n >> m;
    adj.assign(n, vector<pair<int, int>>());
    dist.assign(n, LONG_LONG_MAX);
    visited.assign(n, false);
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
    }
    dijkstra(0);
    print(dist);

    return 0;
}