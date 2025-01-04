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
#define MOD 10000000007
using namespace std;
using ll = long long;
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

vector<ll> x;

bool is_valid(int max_sum, int k) {
    int subarrays = 0;
    int sum = 0;
    for (const auto &i : x) {
        if (i > max_sum) {
            return false;
        }
        if (sum + i > max_sum) {
            sum = 0;
            subarrays++;
        }
        sum += i;
    }
    if (sum > 0) {
        subarrays++;
    }
    if (subarrays <= k)
        return true;
    return false;
}

int first_true(int low, int high, int k) {
    while (low < high) {
        int mid = (low + high) / 2;
        if (is_valid(mid, k)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

void solve() {
    int n, k;
    cin >> n >> k;
    x.assign(n, 0);
    for (int &i : x) {
        cin >> i;
    }
    int low = *max_element(all(x));
    int high = accumulate(all(x), 0LL);

    int answer = first_true(low, high, k);
    cout << answer;
}

signed main() {
    fastio;
    // file_read("/home/owaisk4/Win_backup/Speed Programming/CSES/input.txt");
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}