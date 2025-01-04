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

int first_true(int low, int high, int K, int l2, int r2) {
    low--;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        int y = K * mid;
        if (l2 <= y && y <= r2) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

int last_true(int low, int high, int K, int l2, int r2) {
    high++;
    while (low < high) {
        int mid = low + (high - low) / 2;
        int y = K * mid;
        if (l2 <= y && y <= r2) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

void solve() {
    int k, l1, r1, l2, r2;
    cin >> k >> l1 >> r1 >> l2 >> r2;
    int cnt = 0;
    for (int i = 1; i <= 32; i++) {
        int K = pow(k, i);
        int low = l1, high = r1;

        int left = first_true(low, high, K, l2, r2);
        int right = last_true(low, high, K, l2, r2);
        if (left == low - 1 || right == high + 1)
            continue;
        if (left > right)
            continue;
        cnt += (right - left + 1);
    }
    print(cnt);
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