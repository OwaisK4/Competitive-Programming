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
    int n;
    cin >> n;
    vector<int> y_up, y_down;
    map<int, int> mp_up, mp_down;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (y == 0) {
            y_down.push_back(x);
            mp_down[x] = 1;
        } else {
            y_up.push_back(x);
            mp_up[x] = 1;
        }
    }
    sort(all(y_down));
    sort(all(y_up));

    int triangles = 0;

    int i = 0, j = 0;
    while (i < y_down.size() && j < y_up.size()) {
        if (y_down[i] == y_up[j]) {
            triangles += (n - 2);
            i++;
            j++;
        } else if (y_down[i] < y_up[j]) {
            i++;
        } else {
            j++;
        }
    }

    for (int i = 0; i < y_down.size(); i++) {
        int x = y_down[i];
        if (mp_up.count(x - 1) && mp_up.count(x + 1)) {
            triangles++;
        }
    }
    for (int i = 0; i < y_up.size(); i++) {
        int x = y_up[i];
        if (mp_down.count(x - 1) && mp_down.count(x + 1)) {
            triangles++;
        }
    }
    cout << triangles << "\n";
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