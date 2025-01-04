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
#define MOD 10000000007
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

void solve() {
    int A, B, N;
    cin >> A >> B >> N;

    bool swapped = false;
    if (A < B) {
        swapped = true;
        swap(A, B);
    }

    int x = -1, y = -1;
    int min_diff = LONG_LONG_MAX;

    for (int i = 0; i * A <= N; i++) {
        int remaining = N - (i * A);
        int diff = remaining % B;
        if (diff < min_diff) {
            min_diff = diff;
            x = i;
            // y = remaining / B;
        }
    }
    y = (N - (A * x)) / B;
    if (swapped) {
        swap(x, y);
    }
    cout << x << " " << y;
}

signed main() {
    fastio;
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}