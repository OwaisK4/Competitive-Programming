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
vector<int> lengths, endpoints;
vector<double> probabilities;

void dfs(int src, int parent, double probability, int length) {
    if (adj[src].size() == 1 && src != 0) {
        probabilities[src] = probability;
        lengths[src] = length;
        endpoints.push_back(src);
        return;
    }
    for (auto child : adj[src]) {
        if (child != parent) {
            dfs(child, src, probability / ((double)adj[src].size() - 1), length + 1);
        }
    }
}

void solve() {
    int n;
    cin >> n;
    adj.assign(n, vector<int>());
    probabilities.assign(n, -1);
    lengths.assign(n, -1);
    endpoints.resize(0);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(0, -1, 1, 0);
    double answer = 0;
    // print(endpoints);
    for (auto it : endpoints) {
        // cout << "Length: " << lengths[it] << ", Probability: " << probabilities[it] << "\n";
        answer += (lengths[it] * probabilities[it]);
    }
    answer /= (double)endpoints.size();
    cout << fixed << setprecision(15) << answer;
    // cout << answer;
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