#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
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
void print(T X) {
    cout << X << "\n";
}
template <typename T, typename... Ts>
void print(T X, Ts... Y) {
    cout << X << " ";
    print(Y...);
}

void solve() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    vector<int> prefix(n + 1, 0);
    vector<int> suffix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        if (i == 0 || a[i + 1] - a[i] < a[i] - a[i - 1]) {
            prefix[i + 1] = (a[i + 1] - a[i] - 1);
        }
    }
    for (int i = n - 1; i > 0; i--) {
        if (i == n - 1 || a[i + 1] - a[i] > a[i] - a[i - 1]) {
            suffix[i] = (a[i] - a[i - 1] - 1);
        }
    }
    partial_sum(all(prefix), prefix.begin());
    partial_sum(rall(suffix), suffix.rbegin());
    // print(prefix);
    // print(suffix);
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, answer;
        cin >> l >> r;
        l--;
        r--;
        if (l < r) {
            answer = a[r] - a[l] - (prefix[r] - prefix[l]);
        } else {
            answer = a[l] - a[r] - (suffix[r + 1] - suffix[l + 1]);
        }
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