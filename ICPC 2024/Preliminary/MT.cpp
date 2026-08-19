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
vector<int> degree;
vector<int> dist;

void dfs(int source, int previous, int cnt) {
    dist[source] = cnt;
    for (auto &it : tree[source]) {
        if (it != previous) {
            dfs(it, source, cnt + 1);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    tree.assign(n, vector<int>());
    degree.assign(n, 0);
    dist.assign(n, INT_MAX);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    int source = 0;
    dfs(source, -1, 0);
    auto index = max_element(all(dist)) - dist.begin();

    fill(all(dist), LONG_LONG_MAX);
    dfs(index, -1, 0);
    int longest = *max_element(all(dist));
    sort(all(degree));
    reverse(all(degree));
    int first = degree[0];
    int second = degree[1];
    cout << longest << " " << first << " " << second << "\n";
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}