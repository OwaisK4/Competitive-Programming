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

vector<int> answer;
vector<vector<int>> dp;

int f(int remaining, int k, int a, int b) {
    if (k == 0) {
        if (remaining == 0) {
            return dp[remaining][k] = true;
        }
        return dp[remaining][k] = false;
    }
    if (dp[remaining][k] != -1) {
        return dp[remaining][k];
    }
    for (int i = a; i <= b; i++) {
        answer.push_back(i);
        if (remaining - i >= 0 && f(remaining - i, k - 1, a, b)) {
            return dp[remaining][k] = true;
        }
        answer.pop_back();
    }
    return dp[remaining][k] = false;
}

void solve() {
    int k, a, b;
    cin >> k >> a >> b;
    string s;
    cin >> s;
    int n = s.size();
    dp.assign(n + 1, vector<int>(k + 1, -1));
    bool valid = f(n, k, a, b);
    if (valid) {
        int last = 0;
        for (auto it : answer) {
            print(s.substr(last, it));
            last += it;
        }
    } else {
        print("No solution");
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