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

vector<int> x;

pii f(int player, int left, int right) {
    if (left == right) {
        return pii(x[left], x[right]);
    }
    pii left_removed = f((player + 1) % 2, left + 1, right);
    pii right_removed = f((player + 1) % 2, left, right - 1);

    return pii(max(left_removed.first, right_removed.first), max(left_removed.second, right_removed.second));
}

void solve() {
    int n;
    cin >> n;
    x.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    pii answer = f(0, 0, n - 1);
    cout << answer.first;
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