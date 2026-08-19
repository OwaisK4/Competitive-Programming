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
    string narek = "narek";
    vector<string> strings;
    vector<int> dp, ndp;
    cin >> n >> m;
    strings.assign(n, "");
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }
    dp.assign(5, INT_MIN);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        ndp = dp;
        for (int j = 0; j < 5; j++) {
            if (dp[j] == INT_MIN) {
                continue;
            }
            int score = 0;
            int x = j;
            for (auto c : strings[i]) {
                if (narek.find(c) == narek.npos) {
                    continue;
                } else if (c == narek[x]) {
                    x = (x + 1) % 5;
                    score++;
                } else {
                    score--;
                }
            }
            ndp[x] = max(ndp[x], dp[j] + score);
        }
        dp = ndp;
    }
    int answer = 0;
    for (int i = 0; i < 5; i++) {
        answer = max(answer, dp[i] - 2 * i);
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