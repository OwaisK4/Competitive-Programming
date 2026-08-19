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

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
    return os << '(' << p.first << ", " << p.second << ')';
}

template <typename T>
void print(vector<T> &array, int size = numeric_limits<int>::max()) {
    for (int i = 0; i < min<int>(size, array.size()); i++) {
        cout << array[i] << " ";
    }
    cout << "\n";
}
template <typename T>
void print(T X, bool newline = true) {
    cout << X;
    if (newline) {
        cout << "\n";
    }
}

void solve() {
    int n, q;
    cin >> n >> q;
    unordered_map<string, int> mapping = {{"BG", 0}, {"BR", 1}, {"BY", 2}, {"GR", 3}, {"GY", 4}, {"RY", 5}};
    vector<vector<int>> indexes(mapping.size(), vector<int>());
    vector<string> colors = {"BG", "BR", "BY", "GR", "GY", "RY"};
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        string c;
        cin >> c;
        a[i] = c;
        indexes[mapping[c]].push_back(i);
    }
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        string src = a[x], dest = a[y];
        if (src[0] == dest[0] || src[0] == dest[1] || src[1] == dest[0] || src[1] == dest[1]) {
            print(abs(x - y));
            continue;
        }
        int s_index = find(all(colors), src) - colors.begin();
        int d_index = find(all(colors), dest) - colors.begin();
        int answer = LONG_LONG_MAX;
        for (int index = 0; index < colors.size(); index++) {
            if (index == s_index || index == d_index) {
                continue;
            }
            if (indexes[index].size() == 0)
                continue;
            auto it = lower_bound(all(indexes[index]), x);

            int nearest;
            int current;
            if (it != indexes[index].begin()) {
                nearest = *(it - 1);
                current = abs(nearest - x) + abs(nearest - y);
                answer = min(answer, current);
            }

            if (it != indexes[index].end()) {
                nearest = *it;
                current = abs(nearest - x) + abs(nearest - y);
                answer = min(answer, current);
            }
        }
        if (answer == LONG_LONG_MAX)
            print(-1);
        else
            print(answer);
    }
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