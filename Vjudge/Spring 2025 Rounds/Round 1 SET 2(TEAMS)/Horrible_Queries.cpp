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

class SegmentTree {
public:
    int n;
    vi tree, lazy;
    SegmentTree(vi &array) {
        n = array.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(array, 1, 0, n - 1);
    }
    int f(int a, int b) {
        return a + b;
    }
    void build(vi &array, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = array[tl];
        } else {
            // int tm = midpoint(tl, tr);
            int tm = (tl + tr) / 2;
            build(array, v * 2, tl, tm);
            build(array, v * 2 + 1, tm + 1, tr);
            tree[v] = f(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    void updateRange(int v, int tl, int tr, int l, int r, int value) {
        if (lazy[v] != 0) {
            tree[v] += (tr - tl + 1) * lazy[v];
            if (tl != tr) {
                lazy[v * 2] += lazy[v];
                lazy[v * 2 + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
        if (l > r) {
            return;
        }
        if (l == tl && r == tr) {
            tree[v] += (tr - tl + 1) * value;
            if (tl != tr) {
                lazy[v * 2] += value;
                lazy[v * 2 + 1] += value;
            }
            return;
        }
        // int tm = midpoint(tl, tr);
        int tm = (tl + tr) / 2;
        updateRange(v * 2, tl, tm, l, min(tm, r), value);
        updateRange(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, value);
        tree[v] = f(tree[v * 2], tree[v * 2 + 1]);
    }
    int query(int v, int tl, int tr, int l, int r) {
        if (lazy[v] != 0) {
            tree[v] += (tr - tl + 1) * lazy[v];
            if (tl != tr) {
                lazy[v * 2] += lazy[v];
                lazy[v * 2 + 1] += lazy[v];
            }
            lazy[v] = 0;
        }
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        // int tm = midpoint(tl, tr);
        int tm = (tl + tr) / 2;
        return f(query(v * 2, tl, tm, l, min(tm, r)), query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n, 0);
    SegmentTree segtree(a);
    for (int i = 0; i < q; i++) {
        int c, p, q, v;
        cin >> c;
        if (c == 0) {
            cin >> p >> q >> v;
            p--;
            q--;
            segtree.updateRange(1, 0, n - 1, p, q, v);
        } else {
            cin >> p >> q;
            p--;
            q--;
            int answer = segtree.query(1, 0, n - 1, p, q);
            print(answer);
        }
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