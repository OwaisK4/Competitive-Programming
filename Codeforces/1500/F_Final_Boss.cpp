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

int h, n;
vector<int> a, c;

bool f(int turns) {
    vector<int> times(n, 0);
    for (int i = 0; i < n; i++) {
        times[i] = 1;
        times[i] += ((turns - 1) / (c[i]));
    }
    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer += (times[i] * a[i]);
        if (answer >= h) {
            break;
        }
    }
    if (answer >= h) {
        return true;
    }
    return false;
}

int first_true(int low, int high) {
    high++;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (f(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

void solve() {
    cin >> h >> n;
    a.assign(n, 0);
    c.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    int low = 1;
    int index = max_element(all(c)) - c.begin();
    int high = (h / a[index]) * c[index];
    int answer = first_true(low, high);
    cout << answer << "\n";
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