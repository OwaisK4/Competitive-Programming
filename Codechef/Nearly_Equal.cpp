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

int hamming(string &A, string &B, int M) {
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        if (A[i] != B[i]) {
            cnt++;
        }
    }
    return cnt;
    // vector<vector<int>> dp(M + 1, vector<int>(M + 1, 0));
    // for (int i = 0; i <= M; i++) {
    //     dp[i][0] = i;
    // }
    // for (int i = 0; i <= M; i++) {
    //     dp[0][i] = i;
    // }
    // for (int i = 1; i <= M; i++) {
    //     for (int j = 1; j <= M; j++) {
    //         if (A[i - 1] == B[j - 1]) {
    //             dp[i][j] = dp[i - 1][j - 1] + 1;
    //         } else {
    //             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    //         }
    //     }
    // }
    // return dp[M][M];
}

void solve() {
    int N, M;
    cin >> N >> M;
    string A, B;
    cin >> A >> B;
    int minimum = INT_MAX;
    for (int i = 0; i < N - M + 1; i++) {
        string rolling(A.begin() + i, A.begin() + M + i);
        minimum = min(minimum, hamming(rolling, B, M));
        // print(rolling);
    }
    cout << minimum << "\n";
}

signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}