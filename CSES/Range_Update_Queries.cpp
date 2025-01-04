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

class FenwickTree {
public:
    int n;
    vector<int> tree;
    FenwickTree(vector<int> &a) {
        this->n = a.size();
        this->tree.assign(n + 1, 0);
        for (int i = 0; i < n; i++) {
            this->point_update(i + 1, a[i]);
        }
    }
    void point_update(int index, int value) {
        // print("Here");
        while (index <= this->n) {
            this->tree[index] += value;
            index += (index & (-index));
        }
    }
    void range_update(int l, int r, int value) {
        this->point_update(l, value);
        this->point_update(r + 1, -value);
    }
    int query(int index) {
        int sum = 0;
        while (index > 0) {
            sum += this->tree[index];
            index -= (index & (-index));
        }
        return sum;
    }
    int range_query(int l, int r) {
        return this->query(r) - this->query(l - 1);
    }
    int point_query(int index) {
        return this->range_query(index, index);
    }
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n), prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    partial_sum(all(a), prefix.begin() + 1);
    FenwickTree f_tree(a);
    for (int i = 0; i < q; i++) {
        int operation;
        cin >> operation;
        if (operation == 1) {
            int l, r, value;
            cin >> l >> r >> value;
            f_tree.range_update(l, r, value);
        } else {
            int index;
            cin >> index;
            // int answer = f_tree.point_query(index);
            int answer = f_tree.query(index) - prefix[index - 1];
            cout << answer << "\n";
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