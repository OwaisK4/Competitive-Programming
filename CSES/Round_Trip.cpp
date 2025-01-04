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
vector<int> path;
int cyclic_node;

bool checkCycle(int s, int parent) {
    visited[s] = true;
    for (auto it : adj[s]) {
        if (!visited[it]) {
            if (checkCycle(it, s)) {
                return true;
            }
        } else if (it != parent) {
            cyclic_node = it;
            return true;
        }
    }
    return false;
}
bool findCycle(int s, int parent, int start) {
    visited[s] = true;
    path.push_back(s + 1);
    for (auto it : adj[s]) {
        if (!visited[it]) {
            if (findCycle(it, s, start)) {
                return true;
            }
        } else if (it != parent && it == start) {
            path.push_back(it + 1);
            return true;
        }
    }
    path.pop_back();
    return false;
}

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    adj.assign(n, vector<int>());
    visited.assign(n, false);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bool isCyclic = false;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (checkCycle(i, -1)) {
                isCyclic = true;
                break;
            }
        }
    }
    fill(all(visited), false);

    if (isCyclic) {
        findCycle(cyclic_node, -1, cyclic_node);
        print(path.size());
        print(path);
    } else {
        cout << "IMPOSSIBLE";
    }

    return 0;
}