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
    int n, q;
    cin >> n >> q;
    vector<int> a(n), k(q);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    map<int, int> dp;
    for (int i = 0; i < n; i++) {
        int temp = a[i];
        int left = i + 1;
        int right = n - i;
        int value;
        if (i > 0 && i < n - 1) {
            value = (left * right) - 1;
            dp[value]++;
        } else {
            if (i == 0) {
                right--;
                value = (left * right);
                dp[value]++;
            } else {
                left--;
                value = (left * right);
                dp[value]++;
            }
        }
        temp++;
        if (i < n - 1) {
            left = i + 1;
            right = n - i - 1;
            value = (left * right);
            dp[value] += (a[i + 1] - temp);
        }
    }

    for (int i = 0; i < q; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < q; i++) {
        cout << dp[k[i]] << " ";
    }
    cout << "\n";
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