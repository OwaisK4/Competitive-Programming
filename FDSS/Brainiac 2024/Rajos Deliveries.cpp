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
using pii = pair<int, int>;

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

vector<vector<int>> graph;
vector<pii> items;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    graph.assign(n, vector<int>(n, -1));
    for (int i = 0; i < m; i++) {
        int u, v, l;
        cin >> u >> v >> l;
        u--;
        v--;
        graph[u][v] = l;
        graph[v][u] = l;
    }
    for (int i = 0; i < n; i++) {
        graph[i][i] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (graph[i][k] != -1 && graph[k][j] != -1) {
                    if (graph[i][j] != -1) {
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                        graph[j][i] = min(graph[i][j], graph[i][k] + graph[k][j]);
                    } else {
                        graph[i][j] = graph[i][k] + graph[k][j];
                        graph[j][i] = graph[i][k] + graph[k][j];
                    }
                }
            }
        }
    }
    // for (auto it : graph) {
    //     print(it);
    // }
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        items.push_back({a, b});
    }
    // vector<int> indexes;
    // for (int i = 0; i < k; i++) {
    //     indexes.push_back(i);
    // }
    int min_dist = LONG_LONG_MAX;
    do {
        int dist = 0;
        for (int i = 0; i < k - 1; i++) {
            dist += graph[items[i].first][items[i].second];
            dist += graph[items[i].second][items[i + 1].first];
        }
        dist += graph[items[k - 1].first][items[k - 1].second];
        min_dist = min(min_dist, dist);
    } while (next_permutation(all(items)));
    cout << min_dist;
}

signed main() {
    fastio;
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}