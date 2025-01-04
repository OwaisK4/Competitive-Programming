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
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;
    int cnt = 0;
    int suneel = 0, slavic = 0;

    suneel += (a1 > b1) ? 1 : 0;
    suneel += (a1 > b2) ? 1 : 0;
    suneel += (a2 > b1) ? 1 : 0;
    suneel += (a2 > b2) ? 1 : 0;

    slavic += (a1 < b1) ? 1 : 0;
    slavic += (a1 < b2) ? 1 : 0;
    slavic += (a2 < b1) ? 1 : 0;
    slavic += (a2 < b2) ? 1 : 0;

    cout << max(0LL, suneel - slavic) << "\n";
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