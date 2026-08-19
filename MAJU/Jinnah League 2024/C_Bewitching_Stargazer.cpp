#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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

int n, k;
void f(int l, int r) {
    if (r - l + 1 < k) {
        return;
    }
    int m = (l + r) / 2;
    if ((r - l + 1) % 2 == 0) {
        f(l, m);
        f(m + 1, r);
    } else {
        f(l, m - 1);
        cout << m << " ";
        f(m + 1, r);
    }
}

int binpow(int x, int n) {
    int a = 1;
    while (n > 0) {
        if (n & 1) {
            a *= x;
        }
        x *= x;
        n >>= 1;
    }
    return a;
}

pii f1(int l, int r, int cnt, int last, int total = 0) {
    if (r - l + 1 < k) {
        // return last;
        return {last, total};
    }
    int m = (l + r) / 2;
    if ((r - l + 1) % 2 == 0) {
        return f1(l, m, cnt, last, total);
    } else {
        return f1(l, m - 1, cnt + 1, m, r - l + 1);
    }
}

pii f2(int l, int r, int cnt, int last, int total = 0) {
    if (r - l + 1 < k) {
        // return last;
        return {last, total};
    }
    int m = (l + r) / 2;
    if ((r - l + 1) % 2 == 0) {
        return f2(m + 1, r, cnt, last, total);
    } else {
        return f2(m + 1, r, cnt + 1, m, r - l + 1);
    }
}

void solve() {
    cin >> n >> k;
    // f(1, n);
    print<pii>(f1(1, n, 0, -1));
    print<pii>(f2(1, n, 0, -1));
    auto [a, cnt1] = f1(1, n, 0, -1);
    auto [b, cnt2] = f2(1, n, 0, -1);
    int n = (b + 1) / a;
    // int d = (b - a + 1) / cnt1;
    // print(d);
    int answer = (n * (2 * a + (n - 1) * a)) / 2;
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