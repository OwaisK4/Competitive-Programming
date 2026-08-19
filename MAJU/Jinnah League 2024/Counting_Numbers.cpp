#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vii vector<pair<int, int>>
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

int a, b, length;
vector<vvvi> dp;

int f(string &c, int index, int previous, int leading_zero, int is_lesser) {
    if (index == c.size()) {
        return 1;
    }
    if (dp[index][previous][leading_zero][is_lesser] != -1) {
        return dp[index][previous][leading_zero][is_lesser];
    }
    int answer = 0;
    int limit = 9;
    if (!is_lesser) {
        limit = c[index] - '0';
    }
    for (int i = 0; i <= limit; i++) {
        if (leading_zero == 0 && (i == previous)) {
            continue;
        }
        int new_leading_zero = (leading_zero == 1 && i == 0) ? 1 : 0;
        if (is_lesser) {
            answer += f(c, index + 1, i, new_leading_zero, is_lesser);
        } else {
            answer += f(c, index + 1, i, new_leading_zero, i < limit);
        }
    }
    return dp[index][previous][leading_zero][is_lesser] = answer;
    // return answer;
}

void solve() {
    cin >> a >> b;
    string r = to_string(b);
    string l = to_string(a - 1);
    dp.assign(r.size(), vvvi(10, vvi(2, vi(2, -1))));
    int answer = f(r, 0, 0, 1, 0);
    dp.assign(l.size(), vvvi(10, vvi(2, vi(2, -1))));
    if (a != 0)
        answer -= f(l, 0, 0, 1, 0);
    print(answer);
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