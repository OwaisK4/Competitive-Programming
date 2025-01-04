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

vector<vector<int>> dp(101, vector<int>(100001, 0));

signed main() {
    fastio;
    int N, X;
    cin >> N >> X;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= N; i++) {
        if (i == 1) {
            dp[i][a[i - 1]] = 1;
            dp[i][b[i - 1]] = 1;
            continue;
        }
        for (int j = 1; j <= X; j++) {
            if (dp[i - 1][j] != 0) {
                if (j + a[i - 1] <= X)
                    dp[i][j + a[i - 1]] += 1;
                if (j + b[i - 1] <= X)
                    dp[i][j + b[i - 1]] += 1;
            }
        }
    }
    // for (int i = 1; i <= N; i++) {
    //     print(dp[i], X + 1);
    // }

    if (dp[N][X]) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}