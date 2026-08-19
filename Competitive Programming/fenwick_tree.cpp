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
    vector<int> tree;
    int n; // size
    FenwickTree(int n) {
        this->n = n;
        tree.assign(n + 1, 0);
    }
    int sum(int k) {
        int answer = 0;
        while (k >= 1) {
            answer += tree[k];
            k -= (k & -k);
        }
        return answer;
    }
    void add(int k, int x) {
        while (k <= n) {
            tree[k] += x;
            k += (k & -k);
        }
    }
    void print() {
        for (int i = 1; i <= n; i++) {
            cout << tree[i] << " ";
        }
        cout << "\n";
    }
};

signed main() {
    fastio;
    vector<int> array = {1, 3, 4, 8, 6, 1, 4, 2};
    int n = array.size();
    FenwickTree f_tree(n);
    for (int i = 0; i < n; i++) {
        f_tree.add(i + 1, array[i]);
    }
    print(array);
    f_tree.print();

    int a = 1, b = 3;
    int answer = f_tree.sum(b) - f_tree.sum(a - 1);
    cout << answer << "\n";

    return 0;
}