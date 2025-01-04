#include <bits/stdc++.h>
// #define int long long
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

vector<vector<int>> adj;
vector<int> distances;

int dfs(int src, int last) {
    int children = 0;
    for (auto dest : adj[src]) {
        if (dest != last) {
            children = children + dfs(dest, src) + 1;
        }
    }
    return distances[src] = children;
}

signed main() {
    fastio;
    int n;
    cin >> n;
    vector<int> a(n + 2);
    adj.resize(n + 2);
    distances.resize(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        adj[i].push_back(a[i]);
        adj[a[i]].push_back(i);
    }
    // for_each(all(adj), [](auto it) { print(it); });
    // print(distances);
    dfs(1, 1);
    for (int i = 1; i < distances.size(); i++) {
        cout << distances[i] << " ";
    }

    return 0;
}