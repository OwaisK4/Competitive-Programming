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

vector<vector<int>> tree;
vector<bool> visited;
vector<int> dist;

void dfs(int source, int previous, int cnt) {
    dist[source] = cnt;
    for (auto &it : tree[source]) {
        if (it != previous) {
            dfs(it, source, cnt + 1);
        }
    }
}

signed main() {
    fastio;
    int n;
    cin >> n;
    tree.assign(n, vector<int>());
    visited.assign(n, false);
    dist.assign(n, LONG_LONG_MAX);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    int source = (rand() % n);
    dfs(source, -1, 0);
    // cout << "Source: " << source << "\n";
    // print(dist);
    auto index = max_element(all(dist)) - dist.begin();
    // cout << "Index: " << index << "\n";
    // print(dist);
    // cout << "\n";

    fill(all(dist), LONG_LONG_MAX);
    dfs(index, -1, 0);
    // index = max_element(all(dist)) - dist.begin();
    // cout << "Index: " << index << "\n";
    // print(dist);
    cout << *max_element(all(dist));

    return 0;
}