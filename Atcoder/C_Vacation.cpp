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

int N;
vector<int> a, b, c;
vector<vector<vector<vector<int>>>> dp;

int f(int index, int as, int bs, int cs) {
    if (index == N) {
        return 0;
    }
    if (dp[index][as][bs][cs] != -1) {
        return dp[index][as][bs][cs];
    }
    int answer = 0;
    answer = (as < 1) ? max(answer, f(index + 1, as + 1, 0, 0) + a[index]) : answer;
    answer = (bs < 1) ? max(answer, f(index + 1, 0, bs + 1, 0) + b[index]) : answer;
    answer = (cs < 1) ? max(answer, f(index + 1, 0, 0, cs + 1) + c[index]) : answer;
    return dp[index][as][bs][cs] = answer;
}

void solve() {
    cin >> N;
    a.assign(N, 0);
    b.assign(N, 0);
    c.assign(N, 0);
    dp.assign(N, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(2, -1))));
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }
    int answer = f(0, 0, 0, 0);
    cout << answer;
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