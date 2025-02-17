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
    vi tree;
    SegmentTree(vi &array) {
        n = array.size();
        tree.assign(4 * n, 0);
        build(array, 1, 0, n - 1);
    }
    int combine(int a, int b) {
        return a + b;
    }
    void build(vi &array, int v, int tl, int tr) {
        if (tl == tr) {
            tree[v] = array[tl];
        } else {
            int tm = midpoint(tl, tr);
            build(array, 2 * v, tl, tm);
            build(array, 2 * v + 1, tm + 1, tr);
            tree[v] = combine(tree[2 * v], tree[2 * v + 1]);
        }
    }
    int conquer(int v, int tl, int tr, int l, int r) {
        if (l > r) {
            return 0;
        }
        if (l == tl && r == tr) {
            return tree[v];
        }
        int tm = midpoint(tl, tr);
        int answer = combine(conquer(2 * v, tl, tm, l, min(r, tm)), conquer(2 * v + 1, tm + 1, tr, max(tm + 1, l), r));
        return answer;
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    SegmentTree segtree(a);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        print(segtree.conquer(1, 0, n - 1, a, b));
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