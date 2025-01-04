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

void multiply(vector<vector<int>> &A, vector<vector<int>> &B, int n) {
    vector<vector<int>> temp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                temp[i][j] += (A[i][k] * B[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = temp[i][j];
        }
    }
}

void matrixExponentiation(vector<vector<int>> &T, vector<vector<int>> &initial, int n) {
    vector<vector<int>> result(T.size(), vector<int>(T.size(), 0));
    for (int i = 0; i < T.size(); i++) {
        result[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) {
            multiply(result, T, result.size());
        }
        multiply(T, T, T.size());
        n >>= 1;
    }
    multiply(result, initial, result.size());
    cout << "Nth fibonacci number: " << result[0][0] << "\n";
    cout << "N-1th fibonacci number: " << result[1][0] << "\n\n";
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> T = {{1, 1}, {1, 0}};
    vector<vector<int>> initial = {{1, 0}, {0, 0}};
    for (int i = 1; i < n; i++) {
        matrixExponentiation(T, initial, i - 1);
        T = {{1, 1}, {1, 0}};
        initial = {{1, 0}, {0, 0}};
    }
    // matrixExponentiation(T, initial, n - 1);
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