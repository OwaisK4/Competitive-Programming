#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
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

void solve() {
    int N, T;
    cin >> N >> T;
    vector<int> rows(N, 0), columns(N, 0), diagonals(N, 0);
    vector<vector<int>> grid(N, vector<int>(N, 0));
    vector<int> A(T);
    for (int i = 0; i < T; i++) {
        cin >> A[i];
    }
    for (int k = 0; k < T; k++) {
        int i = (A[k] - 1) / N;
        int j = (A[k] - 1) % N;
        grid[i][j] = 1;
        rows[i]++;
        columns[j]++;
        if (i == j) {
            diagonals[0]++;
        }
        if (j == (N - i - 1)) {
            diagonals[1]++;
        }
        if (rows[i] == N || columns[j] == N || diagonals[0] == N || diagonals[1] == N) {
            cout << k + 1;
            return;
        }
    }
    // for (auto &it : grid) {
    //     print(it);
    // }
    cout << -1;
    return;
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