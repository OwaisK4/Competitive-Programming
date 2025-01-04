#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define pi pair<int, int>
#define int long long
#define nl cout << endl;
#define PB push_back
#define MP make_pair
#define f(a, b) for (int i = a; i < b; i++)

class SegmentTree {
public:
    int identity = 0;
    int n;
    vi tree;
    SegmentTree(vi &array) {
        n = array.size();
        tree.assign(4 * n, 0);
        build(array, 1, 0, n - 1);
    }
    int fo(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    void build(vi &array, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = array[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(array, 2 * v, tl, tm);
            build(array, 2 * v + 1, tm + 1, tr);
            tree[v] = fo(tree[2 * v], tree[2 * v + 1]);
        }
    }
    void update(int v, int tl, int tr, int pos, int value) {
        if (tl == tr) {
            tree[v] = value;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm) {
                update(2 * v, tl, tm, pos, value);
            } else {
                update(2 * v + 1, tm + 1, tr, pos, value);
            }
            tree[v] = fo(tree[2 * v], tree[2 * v + 1]);
        }
    }
    int query(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return identity;
        }
        if (tl == l && tr == r) {
            return tree[v];
        }
        int tm = (tl + tr) / 2;
        return fo(query(2 * v, tl, tm, l, min(tm, r)), query(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
    }
};

void solve() {
    int n, q;
    cin >> n >> q;

    vi a(n), diff(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0)
            diff[i - 1] = a[i] - a[i - 1];
    }

    SegmentTree segtree(diff);
    int l, r;
    f(0, q) {
        cin >> l >> r;
        if (r == 1)
            cout << 0;
        else
            cout << segtree.query(1, 0, n - 1, l - 1, r - 1) << " ";
    }
    // for (int i = 1; i < n; i++) {
    //     cout << "GCD(" << i - 1 << ", " << i << ") = " << segtree.query(1, 0, n - 1, i - 1, i) << "\n";
    // }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;
    cin >> t;

    while (t--)
        solve();

    return 0;
}