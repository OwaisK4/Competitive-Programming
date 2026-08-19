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

vector<vector<int>> adj;
vector<bool> visited;

int cnt = -1;
vector<int> roads;

void dfs(int source) {
    visited[source] = true;
    for (auto it : adj[source]) {
        if (!visited[it]) {
            dfs(it);
        }
    }
}

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    adj.assign(n, vector<int>());
    visited.assign(n, false);
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
            cnt++;
            roads.push_back(i + 1);
        }
    }

    if (cnt > 0) {
        cout << cnt << "\n";
        for (int i = 0; i < roads.size() - 1; i++) {
            cout << roads[i] << " " << roads[i + 1] << "\n";
        }
    } else {
        cout << 0;
    }

    return 0;
}