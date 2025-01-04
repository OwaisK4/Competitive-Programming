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

// index i iterates over input s, while index j iterates over pattern p
// dp[i][j] = -1    ->  uninitialized
// dp[i][j] =  0    ->  false
// dp[i][j] =  1    ->  true
bool match(string &s, string &p, int i, int j, vector<vector<int>> &dp) {
    if (i == s.size() && j == p.size()) {
        return true;
    }
    if (i == s.size()) {
        while (j < p.size() && p[j] == '*')
            j++;
        if (j == p.size()) {
            dp[i][j] = true;
        } else {
            dp[i][j] = false;
        }
        return dp[i][j];
    }
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    char pattern = p[j];
    bool answer = false;
    if (pattern == '?') {
        answer = match(s, p, i + 1, j + 1, dp);
    } else if (pattern == '*') {
        answer = match(s, p, i + 1, j, dp) | match(s, p, i, j + 1, dp) | match(s, p, i + 1, j + 1, dp);
    } else {
        if (s[i] == p[j]) {
            answer = match(s, p, i + 1, j + 1, dp);
        } else {
            answer = false;
        }
    }
    return dp[i][j] = answer;
}

void solve() {
    string s, p;
    cin >> s >> p;
    vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1, -1));
    bool answer = match(s, p, 0, 0, dp);
    if (answer) {
        cout << "true";
    } else {
        cout << "false";
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