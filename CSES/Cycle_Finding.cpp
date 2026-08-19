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
vector<int> dist;
vector<int> parent;
vector<Edge> edgeList;

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    dist.assign(n, LONG_LONG_MAX);
    parent.assign(n, -1);
    visited.assign(n, false);
    adj.assign(n, vector<pair<int, int>>());
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        a--;
        b--;
        edgeList.push_back(Edge(a, b, c));
        adj[a].push_back({b, c});
    }
    int min_degree = LONG_LONG_MAX;
    int source = -1;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() < min_degree) {
            min_degree = adj[i].size();
            source = i;
        }
    }
    dist[source] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto &e : edgeList) {
            if (dist[e.x] != LONG_LONG_MAX && dist[e.y] > dist[e.x] + e.score) {
                dist[e.y] = dist[e.x] + e.score;
                parent[e.y] = e.x;
            }
        }
    }

    bool positiveCycle = false;
    for (auto &e : edgeList) {
        if (dist[e.y] > dist[e.x] + e.score) {
            positiveCycle = true;
            break;
        }
    }

    return 0;
}