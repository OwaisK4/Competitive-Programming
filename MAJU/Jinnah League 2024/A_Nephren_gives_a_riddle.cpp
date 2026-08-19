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

string f0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
string x = "What are you doing while sending \"";
string y = "\"? Are you busy? Will you send \"";
string z = "\"?";

vector<int> dp(1e5 + 1, -1);
int f(int n) {
    if (n == 0) {
        return f0.size();
    }
    if (dp[n] != -1) {
        return dp[n];
    }
    int total = x.size() + y.size() + z.size() + 2 * f(n - 1);
    return dp[n] = total;
}

char recur(int n, int k) {
    if (n == 0) {
        if (k < f0.size())
            return f0[k];
        else
            return '.';
    }
    if (n > 53) {
        if (k < x.size()) {
            return x[k];
        } else {
            return recur(n - 1, k - x.size());
        }
    } else {
        if (k < x.size()) {
            return x[k];

        } else if (k < x.size() + f(n - 1)) {
            return recur(n - 1, k - (x.size()));

        } else if (k < x.size() + f(n - 1) + y.size()) {
            return y[k - (x.size() + f(n - 1))];

        } else if (k < x.size() + f(n - 1) + y.size() + f(n - 1)) {
            return recur(n - 1, k - (x.size() + f(n - 1) + y.size()));

        } else if (k < x.size() + f(n - 1) + y.size() + f(n - 1) + z.size()) {
            return z[k - (x.size() + f(n - 1) + y.size() + f(n - 1))];
        } else {
            return '.';
        }
    }
}

void solve() {
    int n, k;
    cin >> n >> k;
    char answer = recur(n, k - 1);
    cout << answer;
    // for (int i = 0; i < 100; i++) {
    //     print(i, f(i));
    // }
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