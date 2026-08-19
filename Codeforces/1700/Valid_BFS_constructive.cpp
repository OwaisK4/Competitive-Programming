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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n, vector<int>());
    vector<vector<int>> levels(n, vector<int>());
    vector<int> dist(n, LONG_LONG_MAX);
    vector<int> parent(n, -1);
    // vector<bool> visited(n, false);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int> seq(n);
    for_each(all(seq), [](int &a) { cin >> a; a--; });
    vector<int> checker(seq);

    queue<pii> q;
    int src = 0;
    int cnt = 0;
    q.push({src, cnt});
    dist[src] = 0;
    parent[0] = 0;
    // visited[src] = true;
    int popped = 0;
    while (!q.empty()) {
        auto it = q.front();
        q.pop();
        src = it.first;
        cnt = it.second;
        levels[cnt].push_back(src);
        dist[src] = cnt;
        for (auto u : adj[src]) {
            // if (!visited[u]) {
            //     visited[u] = true;
            if (parent[u] == -1) {
                parent[u] = src;
                q.push({u, cnt + 1});
            }
        }
    }
    int covered = 0;
    bool valid = true;
    int index = 0;
    while (covered < n) {
        sort(all(levels[index]));
        sort(checker.begin() + covered, checker.begin() + covered + levels[index].size());
        for (int i = 0; i < levels[index].size(); i++) {
            if (levels[index][i] != checker[covered + i]) {
                valid = false;
                break;
            }
        }
        covered += levels[index].size();
        index++;
        if (!valid) {
            break;
        }
    }
    if (valid) {
        // print("Here");
        vector<int> indexes(n, -1);
        for (int i = 0; i < n; i++) {
            indexes[seq[i]] = i;
        }
        int pos = n - 1;
        for (int i = n - 1; i >= 0; i--) {
            int parent_pos = indexes[parent[seq[i]]];
            if (parent_pos > pos) {
                cout << "No";
                return;
            }
            pos = parent_pos;
        }
        cout << "Yes";
    } else {
        cout << "No";
    }
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