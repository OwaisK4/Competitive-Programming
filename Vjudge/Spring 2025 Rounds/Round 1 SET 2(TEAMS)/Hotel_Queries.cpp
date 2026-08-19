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
    vii tree;
    SegmentTree(vi &array) {
        n = array.size();
        tree.assign(4 * n, pii());
        build(array, 1, 0, n - 1);
    }
    pii f(pii a, pii b) {
        if (a.f > b.f) {
            return a;
        } else if (a.f < b.f) {
            return b;
        } else {
            return pii(a.f, a.s + b.s);
        }
    }
    void build(vi &array, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = {array[tl], 1};
        } else {
            int tm = midpoint(tl, tr);
            build(array, 2 * v, tl, tm);
            build(array, 2 * v + 1, tm + 1, tr);
            tree[v] = f(tree[2 * v], tree[2 * v + 1]);
        }
    }
    void update(int v, int tl, int tr, int pos, int val) {
        if (tl == tr) {
            tree[v].f -= val;
        } else {
            int tm = midpoint(tl, tr);
            if (pos <= tm) {
                update(2 * v, tl, tm, pos, val);
            } else {
                update(2 * v + 1, tm + 1, tr, pos, val);
            }
            tree[v] = f(tree[2 * v], tree[2 * v + 1]);
        }
    }
    pii conquer(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return {-INF, -INF};
        } else if (l == tl && r == tr) {
            return tree[v];
        } else {
            int tm = midpoint(tl, tr);
            pii answer = f(conquer(2 * v, tl, tm, l, min(tm, r)), conquer(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
            return answer;
        }
    }
    int walk(int v, int tl, int tr, int needed) {
        if (needed > tree[v].first) {
            return -1;
        }
        if (tl == tr) {
            return tl;
        }
        int tm = midpoint(tl, tr);
        if (needed <= tree[2 * v].f) {
            return walk(2 * v, tl, tm, needed);
        } else {
            return walk(2 * v + 1, tm + 1, tr, needed);
        }
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> h(n), r(m);
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> r[i];
    }
    SegmentTree segtree(h);
    for (int i = 0; i < m; i++) {
        int v = segtree.walk(1, 0, n - 1, r[i]);
        cout << (v + 1) << " ";
        if (v != -1) {
            segtree.update(1, 0, n - 1, v, r[i]);
        }
    }
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