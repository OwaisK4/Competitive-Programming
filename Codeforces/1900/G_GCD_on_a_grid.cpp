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
    cout << X << "\n";
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, 0));
    vector<vector<bool>> dp(n, vector<bool>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int answer = 1;
    int g = gcd(a[0][0], a[n - 1][m - 1]);
    for (int i = 1; i * i <= g; i++) {
        if (g % i > 0) {
            continue;
        }

        vector<int> divisors = {i};
        if (i * i < g) {
            divisors.push_back(g / i);
        }
        for (auto d : divisors) {
            dp.assign(n, vector<bool>(m, 0));
            dp[0][0] = 1;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (a[i][j] % d > 0) {
                        continue;
                    }
                    if (!dp[i][j] && i) {
                        dp[i][j] = dp[i][j] | dp[i - 1][j];
                    }
                    if (!dp[i][j] && j) {
                        dp[i][j] = dp[i][j] | dp[i][j - 1];
                    }
                }
            }
            answer = max(answer, (dp[n - 1][m - 1]) ? d : answer);
        }
    }
    cout << answer << "\n";
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