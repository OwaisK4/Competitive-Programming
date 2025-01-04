#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF LONG_LONG_MAX
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vii vector<pair<int, int>>
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
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

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
template <typename T, typename... Ts>
void print(T X, Ts... Y) {
    cout << X << " ";
    print(Y...);
}

int n, m;
vector<vii> adj;
vvi dist;
vvi visited;

void dijkstra() {
    int src = 0, discount = -1;
    for (int i = 0; i < 2; i++) {
        dist[0][i] = 0;
    }
    priority_queue<pair<pii, int>, vector<pair<pii, int>>, greater<pair<pii, int>>> pq;
    pq.push({{0, src}, 0});
    pq.push({{0, src}, 1});
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        src = it.first.second;
        discount = it.second;
        if (visited[src][discount]) {
            continue;
        }
        visited[src][discount] = true;
        for (auto [dest, cost] : adj[src]) {
            if (discount == 1 && dist[dest][discount] > dist[src][discount] + cost) {
                dist[dest][discount] = dist[src][discount] + cost;
                pq.push({{dist[dest][discount], dest}, discount});
            }
            if (discount == 0 && dist[dest][discount] > dist[src][discount] + cost) {
                dist[dest][discount] = dist[src][discount] + cost;
                pq.push({{dist[dest][discount], dest}, discount});
            }
            if (discount == 0 && dist[dest][1] > dist[src][discount] + (cost / 2)) {
                dist[dest][1] = dist[src][discount] + (cost / 2);
                pq.push({{dist[dest][1], dest}, 1});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    adj.assign(n, vii());
    dist.assign(n, vi(2, INF));
    visited.assign(n, vi(2, 0));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
    }
    dijkstra();
    print(*min_element(all(dist[n - 1])));
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