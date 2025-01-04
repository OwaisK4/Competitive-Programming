#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
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
using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void solve() {
    int n;
    cin >> n;
    adj.assign(n, vector<int>());
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        int v;
        while (true) {
            cin >> v;
            if (v == 0) {
                break;
            }
            v--;
            adj[i].push_back(v);
            // adj[v].push_back(i);
        }
    }
    // for (auto it : adj) {
    //     for (auto jt : it) {
    //         cout << jt + 1 << " ";
    //     }
    //     cout << endl;
    // }
    set<int> s;
    queue<int> q;
    q.push(0);
    visited[0] = true;
    vector<int> answer;
    while (!q.empty()) {
        int src = q.front();
        q.pop();
        if (s.count(src)) {
            continue;
        }
        // cout << "Current = " << src + 1 << "\n";
        answer.push_back(src + 1);
        for (auto it : adj[src]) {
            s.insert(it);
        }
        for (int i = 0; i < n; i++) {
            if (visited[i] || s.count(i)) {
                continue;
            } else {
                visited[i] = true;
                q.push(i);
            }
        }
    }
    // for (int i = 0; i < n; i++) {
    //     if (visited[i]) {
    //         answer.push_back(i + 1);
    //     }
    // }
    cout << answer.size() << "\n";
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
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