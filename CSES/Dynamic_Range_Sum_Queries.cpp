#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
using pii = pair<int, int>;

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
    FenwickTree(int n) {
        this->n = n;
        tree.assign(n + 1, 0);
    }
    int sum(int k) {
        int answer = 0;
        while (k > 0) {
            answer += tree[k];
            k -= (k & -k);
        }
        return answer;
    }
    int sum(int a, int b) {
        int answer = sum(b) - sum(a - 1);
        return answer;
    }
    void add(int k, int x) {
        int original = sum(k, k);
        x -= original;
        while (k <= n) {
            tree[k] += x;
            k += (k & -k);
        }
    }
};

signed main() {
    fastio;
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    FenwickTree f_tree(n);
    for (int i = 0; i < n; i++) {
        f_tree.add(i + 1, a[i]);
    }

    for (int i = 0; i < q; i++) {
        int c, k, u, a, b;
        cin >> c;
        if (c == 1) {
            cin >> k >> u;
            f_tree.add(k, u);
        } else {
            cin >> a >> b;
            int answer = f_tree.sum(a, b);
            cout << answer << "\n";
        }
    }

    return 0;
}