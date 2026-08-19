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

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        print(3);
        print(a, a, a);
        return;
    }
    int n = 3;
    vector<int> answer(3, 0);
    if (a < b) {
        answer[1] = b;
        answer[2] = b + 1;
        int diff = answer[1] + answer[2];
        int req = n * a;
        answer[0] = req - diff;
    } else {
        answer[1] = b;
        answer[0] = b - 1;
        int diff = answer[0] + answer[1];
        int req = n * a;
        answer[2] = req - diff;
    }
    print(n);
    print(answer);
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