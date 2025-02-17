#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define int long long
#define all(a) a.begin(), a.end()
#define f first
#define s second
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
    int n, w;
    cin >> n >> w;
    vector<int> a(n), chai(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        int half = (a[i] + 1) / 2;
        chai[i] = half;
        w -= half;
    }
    if (w < 0) {
        print(-1);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            while (a[i] > a[j] && chai[i] < chai[j]) {
                chai[i]++;
            }
        }
    }
    if (w < 0) {
        print(-1);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (chai[i] > a[i]) {
            print(-1);
            return;
        }
    }
    for (int i = 0; i < n; i++) {
        int min_extra = min(w, a[i] - chai[i]);
        for (int j = 0; j < n; j++) {
            if (i == j)
                continue;
            if (a[i] < a[j]) {
                min_extra = min(min_extra, chai[j] - chai[i]);
            }
        }
        chai[i] += min_extra;
        w -= min_extra;
    }

    if (w > 0) {
        print(-1);
        return;
    }
    print(chai);
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