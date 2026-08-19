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

vector<int> degree;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> dist;

void dijkstra(int source, bool V = false) {
    queue<pii> pq;
    dist[source] = 0;
    pq.push({source, 0});
    while (!pq.empty()) {
        int source = pq.front().first;
        pq.pop();
        if (visited[source]) {
            continue;
        }
        if (!V)
            visited[source] = true;
        for (auto it : adj[source]) {
            if (dist[it] > dist[source] + 1) {
                dist[it] = dist[source] + 1;
                pq.push({dist[it], it});
            }
        }
    }
    int maxi = *max_element(all(dist));
}

void solve() {
    int n;
    cin >> n;
    adj.assign(n, vector<int>());
    degree.assign(n, 0);
    visited.assign(n, false);
    dist.assign(n, INT_MAX);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }
    dijkstra(0);
    int maximum = *max_element(all(dist));
    int source;
    for (int i = 0; i < n; i++) {
        if (dist[i] == maximum) {
            source = i;
            break;
        }
    }
    fill(all(visited), false);
    fill(all(dist), INT_MAX);

    dijkstra(source, true);
    int answer = *max_element(all(dist));
    sort(all(degree));
    reverse(all(degree));
    int first = degree[0];
    int second = degree[1];
    cout << answer << " " << first << " " << second << "\n";
}

signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}