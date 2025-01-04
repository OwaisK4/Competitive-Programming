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
    cout << X;
}
template <typename T, typename... Ts>
void print(T X, Ts... Y) {
    cout << X << " ";
    print(Y...);
}

vector<vector<int>> matrix;

void multiply(vector<vector<int>> &A, vector<vector<int>> B) {
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n, LONG_LONG_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] != LONG_LONG_MAX && B[k][j] != LONG_LONG_MAX)
                    result[i][j] = min(result[i][j], A[i][k] + B[k][j]);
            }
        }
    }
    A = result;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    matrix.assign(n, vector<int>(n, LONG_LONG_MAX));
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        matrix[a][b] = min(matrix[a][b], c);
    }
    vector<vector<int>> I(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        I[i][i] = 1;
    }
    bool first_time = true;
    while (k > 0) {
        if (k & 1) {
            if (first_time) {
                I = matrix;
                first_time = false;
            } else {
                multiply(I, matrix);
            }
        }
        multiply(matrix, matrix);
        k >>= 1;
    }
    if (I[0][n - 1] == LONG_LONG_MAX) {
        print(-1);
    } else {
        print(I[0][n - 1]);
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