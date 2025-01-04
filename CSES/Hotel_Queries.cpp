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
    int n, m;
    cin >> n >> m;
    set<pii> h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert({x, i + 1});
    }
    vector<int> r(m);
    for (int i = 0; i < m; i++) {
        cin >> r[i];
    }
    bool compare = [](const pii &a, int value) {
        return a.first < value;
    };
    for (int i = 0; i < m; i++) {
        // auto it = lower_bound(all(h), r[i], compare);
        auto it = h.lower_bound({r[i], numeric_limits<int>::min()});
        if (it == h.end()) {
            cout << 0 << " ";
            continue;
        } else if (r[i] == it->first) {
            cout << it->second << " ";
            h.erase(it);
        } else {
            cout << it->second << " ";
            int remaining = it->first - r[i];
            h.insert({remaining, it->second});
            h.erase(it);
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