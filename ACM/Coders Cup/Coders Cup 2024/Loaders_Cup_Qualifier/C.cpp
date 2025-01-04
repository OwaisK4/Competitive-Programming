#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

vector<vector<int>> adj;
vector<int> parent;
vector<int> answer;

bool dfs(int src, int p) {
    parent[src] = p;
    for (auto it : adj[src]) {
        if (parent[it] != -1) {
            answer.push_back(it);
            int index = src;
            while (index != it && index != -1) {
                answer.push_back(index);
                index = parent[index];
            }
            return true;
        }
        if (dfs(it, src)) {
            return true;
        }
    }
    return false;
}

void solve() {
    int N;
    cin >> N;
    adj.assign(N, vector<int>());
    parent.assign(N, -1);

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        x--;
        adj[i].push_back(x);
    }
    for (int i = 0; i < N; i++) {
        if (dfs(i, -1)) {
            cout << answer.size() << "\n";
            for (auto it : answer) {
                cout << it + 1 << " ";
            }
            break;
        }
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