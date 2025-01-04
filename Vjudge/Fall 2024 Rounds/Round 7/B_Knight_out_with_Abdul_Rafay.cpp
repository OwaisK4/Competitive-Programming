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
template <typename T, typename... Ts>
void print(T X, Ts... Y) {
    cout << X << " ";
    print(Y...);
}

vector<int> dx = {-2, -2, 1, -1};
vector<int> dy = {1, -1, -2, -2};
vector<vector<int>> dp(15, vector<int>(15, -1));

bool isSafe(int x, int y) {
    if (x >= 0 && y >= 0 && x < 15 && y < 15) {
        return true;
    }
    return false;
}

int f(int x, int y) {
    // if (!isSafe(x, y)) {
    //     return 1LL;
    // }
    if (dp[x][y] != -1) {
        return dp[x][y];
    }
    int answer = 1LL;
    for (int i = 0; i < 4; i++) {
        if (isSafe(x + dx[i], y + dy[i])) {
            answer = answer & (f(x + dx[i], y + dy[i]));
        }
    }
    if (answer == 0LL) {
        return dp[x][y] = 1LL;
    }
    return dp[x][y] = 0LL;
}

void solve() {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    int answer = f(x, y);
    if (answer) {
        print("First");
    } else {
        print("Second");
    }
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