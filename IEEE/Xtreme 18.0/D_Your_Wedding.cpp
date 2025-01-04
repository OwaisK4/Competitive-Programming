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

int n, k;
vector<vector<vector<int>>> dp;

int f(int index, int plates_left, int last) {
    if (index == k) {
        if (plates_left == 0) {
            return 1;
        }
        return 0;
    }
    if (plates_left <= 0) {
        return 0;
    }
    if (dp[index][plates_left][last] != -1) {
        return dp[index][plates_left][last];
    }
    int answer = 0;
    for (int i = last; i <= plates_left; i++) {
        answer += f(index + 1, plates_left - i, i);
    }
    return dp[index][plates_left][last] = answer;
}

void solve() {
    cin >> n >> k;
    dp.assign(k + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));

    int answer = f(0, n, 1);
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