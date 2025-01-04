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

int last_true(int low, int high, int i, int j, int n) {
    low--;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        int left = (i * j) + (i * mid) + (j * mid);
        if (left <= n) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

void solve() {
    int n, x;
    cin >> n >> x;
    int triplets = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * i <= n; j++) {
            int sum = i + j;
            // int k = max(0LL, x - sum);
            int k = x - sum;
            int limited_k = last_true(1, k, i, j, n);
            triplets += max(0LL, limited_k);
        }
    }
    cout << triplets << "\n";
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