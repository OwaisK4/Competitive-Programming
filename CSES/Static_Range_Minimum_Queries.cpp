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

signed main() {
    fastio;
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maximum = *max_element(all(a));
    int K = __lg(maximum) + 1;
    vector<vector<int>> sparse(K + 1, vector<int>(n + 1, 0));
    copy(all(a), sparse[0].begin());
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j + (1 << i) <= n; j++) {
            sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][j + (1 << (i - 1))]);
        }
    }
    // for (auto &it : sparse) {
    //     print(it);
    // }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        int r = b - a + 1;
        int j = __lg(r);
        int minimum = min(sparse[j][a], sparse[j][b - (1 << j) + 1]);
        cout << minimum << "\n";
    }

    return 0;
}