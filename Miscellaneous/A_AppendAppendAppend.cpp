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

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    map<char, vector<int>> positions;
    for (int i = 0; i < n; i++) {
        positions[s[i]].push_back(i);
    }
    int index = -1;
    int inversions = 1;
    for (int i = 0; i < m; i++) {
        char current = t[i];
        auto it = upper_bound(all(positions[current]), index);
        if (it == positions[current].end()) {
            index = positions[current].front();
            inversions++;
        } else {
            index = *it;
        }
    }
    cout << inversions;
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