#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define MOD 1000000007
using namespace std;
using pii = pair<int, int>;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

// struct Edge {
// public:
//     int a, b, w;
// };

vector<vector<pii>> adj;
vector<bool> visited;
vector<int> dist;
vector<int> parent;

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
                parent[it.first] = source;
                pq.push({dist[it.first], it.first});
            }
        }
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    adj.assign(n, vector<pii>());
    visited.assign(n, false);
    dist.assign(n, LONG_LONG_MAX);
    parent.assign(n, -1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        a--;
        b--;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    dijkstra(0);
    if (parent[n - 1] == -1) {
        cout << -1;
    } else {
        int v = n - 1;
        stack<int> s;
        while (v != -1) {
            s.push(v + 1);
            v = parent[v];
        }
        while (!s.empty()) {
            cout << s.top() << " ";
            s.pop();
        }
    }
}

signed main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}