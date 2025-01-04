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

int first_true(int low, int high, auto f) {
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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int index = max_element(all(a)) - a.begin();
    int low = 0, high = 2e18;

    auto f = [index, a, n](int mid) {
        int sum = accumulate(all(a), 0LL) + mid;
        double average = (double)sum / (double)n;
        double half_average = average / 2.0;
        double cnt = 0;
        for (int i = 0; i < n; i++) {
            if (i == index)
                continue;
            if (a[i] < half_average)
                cnt++;
        }
        double half = n / 2.0;
        if (cnt > half) {
            return true;
        }
        return false;
    };

    int x = first_true(low, high, f);
    if (x == high + 1) {
        print(-1);
    } else {
        print(x);
    }
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