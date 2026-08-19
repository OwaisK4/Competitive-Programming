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
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int sum = accumulate(all(a), 0LL);
    ordered_set<int> s;
    s.insert(a[0]);
    int answer = 0;
    for (int i = 1; i < n; i++) {
        int target = sum - a[i];
        int left = target - y;
        int right = target - x;
        // auto l = s.lower_bound(left);
        // auto r = s.upper_bound(right);
        // if (l == s.end()) {
        //     s.insert(a[i]);
        //     continue;
        // }
        // print("Iteration", i);
        // print("Order of left: ", s.order_of_key(*l));
        // print("Order of right: ", s.order_of_key(*r));
        // int cnt = s.order_of_key(*r) - s.order_of_key(*l) + 1;
        int cnt = s.order_of_key(right + 1) - s.order_of_key(left);
        answer += cnt;
        s.insert(a[i]);
    }
    print(answer);
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