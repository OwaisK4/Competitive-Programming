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
    int n, d, k;
    cin >> n >> d >> k;
    vector<int> starting(n + 1, 0), ending(n + 1, 0);
    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        starting[l]++;
        ending[r]++;
    }
    partial_sum(all(starting), starting.begin());
    partial_sum(all(ending), ending.begin());
    int maximum = LONG_LONG_MIN;
    int minimum = LONG_LONG_MAX;
    int r_day = -1, m_day = -1;

    for (int i = 0; i <= n; i++) {
        if (i + d <= n) {
            int p = starting[i + d] - ending[i];
            if (maximum < p) {
                maximum = p;
                r_day = i + 1;
            }
            if (minimum > p) {
                minimum = p;
                m_day = i + 1;
            }
        }
    }
    cout << r_day << " " << m_day << "\n";
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