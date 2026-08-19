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

class Edge {
public:
    int x;
    int y;
    int score;
    Edge(int x, int y, int score) {
        this->x = x;
        this->y = y;
        this->score = score;
    }
};

vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<bool> marked;
vector<bool> reachable;
vector<int> dist;
vector<Edge> edgeList;

void dfs(int source) {
    reachable[source] = true;
    for (auto it : adj[source]) {
        if (!reachable[it.first]) {
            dfs(it.first);
        }
    }
}

bool dfs2(int source) {
    visited[source] = true;
    if (marked[source]) {
        return true;
    }
    for (auto it : adj[source]) {
        if (!visited[it.first]) {
            if (dfs2(it.first)) {
                return true;
            }
        }
    }
    return false;
}

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    dist.assign(n, LONG_LONG_MIN);
    adj.assign(n, vector<pair<int, int>>());
    visited.assign(n, false);
    reachable.assign(n, false);
    marked.assign(n, false);
    int a, b, x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> x;
        a--;
        b--;
        edgeList.push_back(Edge(a, b, x));
    }

    dist[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (auto &e : edgeList) {
            if (dist[e.x] != LONG_LONG_MIN && dist[e.y] < dist[e.x] + e.score) {
                dist[e.y] = dist[e.x] + e.score;
            }
        }
    }

    bool positiveCycle = false;
    for (auto &e : edgeList) {
        if (dist[e.y] < dist[e.x] + e.score) {
            positiveCycle = true;
            marked[e.y] = true;
            // break;
        }
    }

    if (positiveCycle) {
        for (auto &e : edgeList) {
            adj[e.x].push_back({e.y, e.score});
        }
        dfs(0);
        adj.clear();
        adj.assign(n, vector<pair<int, int>>());
        for (auto &e : edgeList) {
            if (reachable[e.x] && reachable[e.y])
                adj[e.y].push_back({e.x, e.score});
        }
        bool path_has_cycle = dfs2(n - 1);
        if (path_has_cycle) {
            cout << -1;
        } else {
            cout << dist[n - 1];
        }
        // cout << -1;
    } else {
        cout << dist[n - 1];
    }

    return 0;
}