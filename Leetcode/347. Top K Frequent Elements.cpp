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

void solve() {
    vector<int> nums;
    int k;
    vector<int> occurences(1e8 + 1, 0);
    for (auto it : nums) {
        int index = it + 1e4;
        occurences[index]++;
    }
    vector<int> prefix_frequencies(nums.size() + 1, 0);
    for (auto it : nums) {
        int index = it + 1e4;
        int f = occurences[index];
        prefix_frequencies[f]++;
    }
    partial_sum(prefix_frequencies.begin(), prefix_frequencies.end(), prefix_frequencies.begin());
    int min_frequency = -1;
    for (int i = prefix_frequencies.size() - 1; i > 0; i--) {
        if (prefix_frequencies[i - 1] < k) {
            min_frequency = i;
            break;
        }
    }
    vector<int> result;
    for (auto it : nums) {
        int index = it + 1e4;
        occurences[index]++;
    }
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