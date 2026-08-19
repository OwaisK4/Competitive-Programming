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

bool f(string &s, vector<string> wordDict, int n, vector<int> &dp) {
    if (n > s.size()) {
        return false;
    } else if (n == s.size()) {
        return true;
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    bool answer = false;
    for (auto word : wordDict) {
        bool possible = true;
        for (int i = 0; i < word.size() && i + n < s.size() && possible; i++) {
            if (word[i] != s[i + n])
                possible = false;
        }
        if (possible) {
            answer = answer || f(s, wordDict, n + word.size(), dp);
        }
    }
    dp[n] = (answer) ? 1 : 0;
    return answer;
}

void solve() {
    string s = "catsandog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    vector<int> dp(s.size(), -1);
    bool answer = f(s, wordDict, 0, dp);
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