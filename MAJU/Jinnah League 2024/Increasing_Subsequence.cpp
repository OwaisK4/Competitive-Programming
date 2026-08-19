#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF LONG_LONG_MAX
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

class SegmentTree {
public:
    int identity = 0;
    static int n;
    vi tree;
    SegmentTree(vi &array) {
        n = array.size();
        tree.assign(4 * n, 0);
        build(array, 1, 0, n - 1);
    }
    int f(int a, int b) {
        return max(a, b);
    }
    void build(vi &array, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = array[tl];
        } else {
            int tm = midpoint(tl, tr);
            build(array, 2 * v, tl, tm);
            build(array, 2 * v + 1, tm + 1, tr);
            tree[v] = f(tree[2 * v], tree[2 * v + 1]);
        }
    }
    void update(int pos, int value, int v = 1, int tl = 0, int tr = n - 1) {
        if (tl == tr) {
            tree[v] = value;
        } else {
            int tm = midpoint(tl, tr);
            if (pos <= tm) {
                update(2 * v, tl, tm, pos, value);
            } else {
                update(2 * v + 1, tm + 1, tr, pos, value);
            }
            tree[v] = f(tree[2 * v], tree[2 * v + 1]);
        }
    }
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return identity;
        }
        if (tl == l && tr == r) {
            return tree[v];
        }
        int tm = midpoint(tl, tr);
        return f(query(2 * v, tl, tm, l, min(tm, r)), query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b = a;
    sort(b.begin(), b.end());
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[b[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        a[i] = m[a[i]];
    }
    // print(a);
    // print(b);
    // for (int i = 0; i < n; i++) {
    //     cout << b[a[i]] << " ";
    // }
    vector<int> dp(n, 0);
    SegmentTree segtree(dp);
    for (int i = 0; i < n; i++) {
        int previous = segtree.query(1, 0, n - 1, 0, a[i] - 1);
        dp[i] = previous + 1;
        segtree.update(1, 0, n - 1, a[i], dp[i]);
    }
    // print(dp);
    print(*max_element(all(dp)));
    // **************************
    // vector<int> dp;
    // for (int i = 0; i < n; i++) {
    //     auto it = lower_bound(all(dp), a[i]);
    //     if (it == dp.end()) {
    //         dp.push_back(a[i]);
    //     } else {
    //         *it = a[i];
    //     }
    // }
    // print(dp.size());
    // **************************
    // vector<int> dp(n + 1, INF);
    // dp[0] = -INF;
    // for (int i = 0; i < n; i++) {
    //     auto it = lower_bound(all(dp), a[i]) - dp.begin();
    //     if (dp[it - 1] < a[i] && a[i] < dp[it]) {
    //         dp[it] = a[i];
    //     }
    // }
    // int answer = 0;
    // for (int i = 1; i <= n; i++) {
    //     if (dp[i] != INF) {
    //         answer = i;
    //     }
    // }
    // print(answer);
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