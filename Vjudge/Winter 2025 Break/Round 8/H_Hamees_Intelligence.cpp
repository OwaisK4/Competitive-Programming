#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vii vector<pair<int, int>>
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
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int k = 0; k < q; k++) {
        int l, r;
        cin >> l >> r;
        if (r - l + 1 > 1000) {
            print(0);
            continue;
        }
        vector<int> subarray(a.begin() + l, a.begin() + r + 1);
        sort(all(subarray));
        int minimum = INF;
        for (int i = 1; i < subarray.size(); i++) {
            minimum = min(minimum, abs(subarray[i] - subarray[i - 1]));
        }
        // for (int i = l; i <= r; i++) {
        //     for (int j = i + 1; j <= r; j++) {
        //         minimum = min(minimum, abs(a[i] - a[j]));
        //     }
        // }
        print(minimum);
    }
}

signed main() {
    fastio;
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << "Case " << i + 1 << ":\n";
        solve();
    }

    return 0;
}