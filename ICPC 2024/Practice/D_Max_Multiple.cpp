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
void print(T X, bool newline = true) {
    cout << X;
    if (newline) {
        cout << "\n";
    }
}
int N, K, D;
vector<int> a(N);
vector<vector<vector<int>>> dp;
bool ansf = false;

int f(int index, int k, int m) {
    if (k == 0) {
        if (m == 0) {
            ansf = true;
            return 0;
        }
        return -1e12;
    }
    if (index == N) {
        return -1e12;
    }
    if (dp[index][k][m] != -1) {
        return dp[index][k][m];
    }
    int answer = max(a[index] + f(index + 1, k - 1, (m + a[index]) % D), f(index + 1, k, m));
    return dp[index][k][m] = answer;
}

void solve() {
    cin >> N >> K >> D;
    a.assign(N, 0);
    dp.assign(N + 1, vector<vector<int>>(K + 1, vector<int>(D + 1, -1)));
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int answer = f(0, K, 0);
    print((ansf) ? answer : -1);
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