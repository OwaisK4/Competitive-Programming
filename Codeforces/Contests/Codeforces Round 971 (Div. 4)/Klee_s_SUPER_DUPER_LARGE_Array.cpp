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

int best = -1, best2 = -1;

bool pred(int i, int k, int n) {
    int left = (i * (2 * k + (i - 1))) / 2;
    int right = ((n * (2 * k + (n - 1))) / 2) - left;
    int answer = left - right;
    if (answer <= 0) {
        best = abs(left - right);
        return true;
    }
    return false;
}

int last_true(int low, int high, int k, int n) {
    low--;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (pred(mid, k, n)) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

bool pred2(int i, int k, int n) {
    int left = (i * (2 * k + (i - 1))) / 2;
    int right = ((n * (2 * k + (n - 1))) / 2) - left;
    int answer = left - right;
    if (answer >= 0) {
        best2 = abs(left - right);
        return true;
    }
    return false;
}

int first_true(int low, int high, int k, int n) {
    high++;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (pred2(mid, k, n)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

void solve() {
    int n, k;
    cin >> n >> k;
    int answer = last_true(1, n, k, n);
    int answer2 = first_true(1, n, k, n);
    // cout << answer << "\n";
    cout << min(best, best2) << "\n";
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