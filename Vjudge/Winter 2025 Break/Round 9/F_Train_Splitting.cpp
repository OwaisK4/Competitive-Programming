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
int n, m;
vvi adj;
map<pii, int> routes;
vii edges;
vi answer;

void solve() {
    cin >> n >> m;
    adj.assign(n, vi());
    edges.assign(m, pii());
    answer.assign(m, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        routes[{min(u, v), max(u, v)}] = i;
        edges[i] = {min(u, v), max(u, v)};
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool complete = true;
    int v = -1;
    for (int i = 0; i < n; i++) {
        if (adj[i].size() < n - 1) {
            complete = false;
            v = i;
            break;
        }
    }
    if (!complete) {
        fill(all(answer), 2);
        for (auto it : adj[v]) {
            answer[routes[{min(it, v), max(it, v)}]] = 1;
        }
        print(2);
        print(answer);
    } else {
        v = 0;
        fill(all(answer), 2);
        for (auto it : adj[v]) {
            answer[routes[{min(it, v), max(it, v)}]] = 1;
        }
        answer[routes[{min(v, adj[v].back()), max(v, adj[v].back())}]] = 3;
        print(3);
        print(answer);
    }
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