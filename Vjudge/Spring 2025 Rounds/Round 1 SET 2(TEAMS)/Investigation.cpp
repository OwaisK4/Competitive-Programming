#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define int long long
#define all(a) a.begin(), a.end()
#define f first
#define s second
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

vector<vii> adj;
vi dist, visited, routes, max_flights, min_flights;

void solve() {
    int n, m;
    cin >> n >> m;
    adj.assign(n, vii());
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
    }
    dist.assign(n, LINF);
    visited.assign(n, 0);
    routes.assign(n, 0);
    max_flights.assign(n, -LINF);
    min_flights.assign(n, LINF);

    // int v = 0;
    dist[0] = 0;
    routes[0] = 1;
    max_flights[0] = 0;
    min_flights[0] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [_, v] = pq.top();
        pq.pop();
        if (visited[v])
            continue;
        visited[v] = 1;
        for (auto [u, c] : adj[v]) {
            if (dist[u] == dist[v] + c) {
                dist[u] = dist[v] + c;
                routes[u] = (routes[u] + routes[v]) % MOD;
                max_flights[u] = max(max_flights[u], max_flights[v] + 1);
                min_flights[u] = min(min_flights[u], min_flights[v] + 1);
            } else if (dist[u] > dist[v] + c) {
                dist[u] = dist[v] + c;
                routes[u] = routes[v];
                max_flights[u] = max_flights[v] + 1;
                min_flights[u] = min_flights[v] + 1;
                pq.push({dist[u], u});
            }
        }
    }
    print(dist[n - 1], routes[n - 1], min_flights[n - 1], max_flights[n - 1]);
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