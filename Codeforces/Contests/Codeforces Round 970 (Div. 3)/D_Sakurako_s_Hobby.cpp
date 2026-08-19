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

vector<int> a;
vector<vector<int>> components;
vector<bool> visited;

vector<int> dfs(int i) {
    vector<int> b = {i};
    visited[i] = true;
    while (!visited[a[i]]) {
        i = a[i];
        b.push_back(i);
        visited[i] = true;
    }
    return b;
}

void solve() {
    int n;
    cin >> n;
    a.assign(n, 0);
    components.assign(0, vector<int>());
    visited.assign(n, false);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        if (!visited[a[i]]) {
            vector<int> b = dfs(a[i]);
            components.push_back(b);
        }
    }
    for (auto it : components) {
        int cnt = 0;
        for (auto jt : it) {
            if (s[jt] == '0') {
                cnt++;
            }
        }
        for (auto jt : it) {
            a[jt] = cnt;
        }
        // print(it);
    }
    for (auto it : a) {
        cout << it << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}