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

bool sortbydiff(const tuple<int, int> &a, const tuple<int, int> &b) {
    auto &[r1, d1] = a;
    auto &[r2, d2] = b;
    return (r1 - d1) > (r2 - d2);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<tuple<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        auto &[regular, discounted] = a[i];
        cin >> regular >> discounted;
    }
    sort(all(a), sortbydiff);
    int answer = 0;
    for (int i = 0; i < n; i++) {
        auto &[regular, discounted] = a[i];
        if (i < k) {
            answer += discounted;
        } else {
            answer += regular;
        }
    }
    print(answer);
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