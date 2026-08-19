#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define vvi vector<vector<int>>
#define vi vector<int>
#define INF INT_MAX
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

vector<vector<pii>> adj;
vvi adm;

// vector<vector<pair<int, int>>> adj;
vector<bool> visited;
vector<int> dist;
map<int, int> target;

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

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    adj.assign(n, vector<pii>());
    adm.assign(n, vi(n, INF));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // u--;
        // v--;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        adm[u][v] = w;
        adm[v][u] = w;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                adm[i][j] = 0;
            for (int k = 0; k < n; k++) {
                if (adm[i][k] == INF || adm[k][j] == INF)
                    continue;
                adm[i][j] = min(adm[i][j], adm[i][k] + adm[k][j]);
            }
        }
    }
    vector<pii> indexes;
    int ind = 0;
    for (auto it : adm) {
        // print(it);
        int sum = accumulate(all(it), 0LL);
        indexes.push_back({sum, ind});
        ind++;
    }
    sort(indexes.begin(), indexes.end());
    // for (auto it : indexes) {
    //     cout << it.first << " " << it.second << "\n";
    // }
    for (int i = 0; i < k; i++) {
        target[indexes[i].second] = 69;
    }
    int maximum = -INF;
    for (int i = 0; i < n; i++) {
        dist.assign(n, INF);
        visited.assign(n, false);
        dijkstra(i);
        int minimum = INF;
        for (auto [k, v] : target) {
            // print(dist[k]);
            minimum = min(minimum, dist[k]);
        }
        maximum = max(maximum, minimum);
    }
    print(maximum);
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