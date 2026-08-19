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

bool possible(int n, int m, int k, int target) {
    int left = min(k - 1, target - 1);
    int right = min(n - k, target - 1);

    int sum_left = (left * (2 * (target - 1) - (left - 1))) / 2;
    int sum_right = (right * (2 * (target - 1) - (right - 1))) / 2;

    if (left == target - 1) {
        sum_left += (k - target);
    }

    if (right == target - 1) {
        sum_right += (n - k - target + 1);
    }

    m -= (target + sum_left + sum_right);
    if (m >= 0) {
        return true;
    }
    return false;

    // vector<int> pillows(n, 0);
    // pillows[k - 1] = target;
    // m -= pillows[k - 1];
    // for (int i = k; i < n; i++) {
    //     pillows[i] = max(pillows[i - 1] - 1, 1LL);
    //     m -= pillows[i];
    // }
    // for (int i = k - 2; i >= 0; i--) {
    //     pillows[i] = max(pillows[i + 1] - 1, 1LL);
    //     m -= pillows[i];
    // }
    // if (m >= 0) {
    //     return true;
    // }
    // return false;
}

int last_true(int low, int high, int n, int m, int k) {
    low--;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (possible(n, m, k, mid)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

void solve() {
    int n, m, k;
    cin >> n >> m >> k;

    int low = 0;
    int high = m;
    int answer = last_true(low, high, n, m, k);
    cout << max(1LL, answer);
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