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
#define MOD 10000000007
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    int start;
    cin >> start;
    start;
    int prev = start;
    for (int i = 0; i < n - 2; i++) {
        int v;
        cin >> v;
        adj[prev].push_back(v);
        prev = v;
    }
    int end;
    cin >> end;
    adj[prev].push_back(end);

    queue<int> q;
    q.push(start);
    vector<int> vstd(n + 1, 0);
    vector<int> parent(n + 1, 0);
    while (!q.empty()) {
        auto u = q.front();
        q.pop();
        vstd[u] = 1;
        for (auto &v : adj[u]) {
            if (vstd[v])
                continue;
            q.push(v);
            parent[v] = u;
        }
    }
    int curr = end;
    vector<int> ans;
    while (curr != 0) {
        ans.push_back(curr);
        curr = parent[curr];
    }
    reverse(all(ans));
    for (auto &a : ans)
        cout << a << ' ';
}

signed main() {
    fastio;
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}