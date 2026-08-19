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

class SegmentTree {
public:
    int n;
    vector<int> tree;
    SegmentTree(vector<int> array) {
        n = array.size();
        tree.assign(n * 4, 0);
        build(array, 1, 0, n - 1);
    }
    int f(int a, int b) {
        return a + b;
    }
    void build(vector<int> &array, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = array[tl];
        } else {
            int tm = midpoint(tl, tr); // Hotspot
            build(array, v * 2, tl, tm);
            build(array, v * 2 + 1, tm + 1, tr);
            tree[v] = f(tree[v * 2], tree[v * 2 + 1]);
        }
    }

    void set(int v, int tl, int tr, int pos, int value) {
        if (tl == tr) {
            tree[v] = value;
        } else {
            int tm = midpoint(tl, tr);
            if (pos <= tm) {
                set(v * 2, tl, tm, pos, value);
            } else {
                set(v * 2 + 1, tm + 1, tr, pos, value);
            }
            tree[v] = f(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    void add(int v, int tl, int tr, int pos, int value) {
        if (tl == tr) {
            tree[v] += value;
        } else {
            int tm = midpoint(tl, tr);
            if (pos <= tm) {
                add(v * 2, tl, tm, pos, value);
            } else {
                add(v * 2 + 1, tm + 1, tr, pos, value);
            }
            tree[v] = f(tree[v * 2], tree[v * 2 + 1]);
        }
    }
    int get(int v, int tl, int tr, int pos) {
        if (tl == tr) {
            return tree[v];
        } else {
            int tm = midpoint(tl, tr);
            if (pos <= tm) {
                return tree[v] + get(v * 2, tl, tm, pos);
            } else {
                return tree[v] + get(v * 2 + 1, tm + 1, tr, pos);
            }
        }
    }

    int conquer(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return LONG_LONG_MAX;
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = midpoint(tl, tr);
        int answer = f(conquer(v * 2, tl, tm, l, min(r, tm)), conquer(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
        return answer;
    }
};

void solve() {
    int N, Q;
    cin >> N >> Q;
    vector<int> array(N);
    for (int i = 0; i < N; i++) {
        cin >> array[i];
    }
    SegmentTree salary(array);
    vector<int> hp(N);
    SegmentTree happiness(hp);
    for (int i = 0; i < Q; i++) {
        int op;
        cin >> op;
        if (op == 0) {
            int l, r, c;
            cin >> l >> r >> c;
            l--;
            r--;
            vector<int> a;
            for (int i = l; i <= r; i++) {
                a.push_back(salary.get(1, 0, N - 1, i));
            }
            salary.set(1, 0, N - 1, l, r);
            for (int i = l; i <= r; i++) {
                if (a[i - l] < salary.get(1, 0, N - 1, i)) {
                    happiness.add(1, 0, N - 1, i, 1);
                }
            }
        } else if (op == 1) {
            int l, r, c;
            cin >> l >> r >> c;
            l--;
            r--;
            vector<int> a;
            for (int i = l; i <= r; i++) {
                a.push_back(salary.get(1, 0, N - 1, i));
            }
            salary.add(1, 0, N - 1, l, r);
            for (int i = l; i <= r; i++) {
                if (a[i - l] < salary.get(1, 0, N - 1, i)) {
                    happiness.add(1, 0, N - 1, i, 1);
                }
            }
        } else if (op == 2) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
        } else if (op == 3) {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            //     cout << segtree.conquer(1, 0, N - 1, b, c) << "\n";
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