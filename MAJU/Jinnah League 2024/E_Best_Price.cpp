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
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    ordered_set<int> s_a, s_b;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s_a.insert(a[i]);
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        s_b.insert(b[i]);
    }
    int earnings = LONG_LONG_MIN;
    for (int i = 0; i < n; i++) {
        int price = a[i];
        int total = price * n;
        int lesser = s_b.order_of_key(price);
        total -= (price * lesser);
        int reviews = s_a.order_of_key(price) - lesser;
        if (reviews > k)
            continue;
        earnings = max(earnings, total);
    }
    for (int i = 0; i < n; i++) {
        int price = b[i];
        int total = price * n;
        int lesser = s_b.order_of_key(price);
        total -= (price * lesser);
        int reviews = s_a.order_of_key(price) - lesser;
        if (reviews > k)
            continue;
        earnings = max(earnings, total);
    }
    print(earnings);
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