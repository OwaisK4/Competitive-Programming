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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto possible1 = [a, n](int mid) {
        vector<int> temp = a;
        for (int i = 0; i < n - 1; i++) {
            if (temp[i] > mid) {
                int diff = temp[i] - mid;
                temp[i] -= diff;
                temp[i + 1] += diff;
            }
        }
        int maximum = *max_element(all(temp));
        if (maximum > mid) {
            return false;
        }
        return true;
    };

    auto possible2 = [a, n](int mid) {
        vector<int> temp = a;
        for (int i = n - 1; i > 0; i--) {
            if (temp[i] < mid) {
                int diff = mid - temp[i];
                temp[i] += diff;
                temp[i - 1] -= diff;
            }
        }
        int minimum = *min_element(all(temp));
        if (minimum < mid) {
            return false;
        }
        return true;
    };

    auto first_true = [&](int low, int high, auto f) {
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
    };
    auto last_true = [&](int low, int high, auto f) {
        low--;
        while (low < high) {
            int mid = low + (high - low + 1) / 2;
            if (f(mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        return low;
    };

    int answer = LONG_LONG_MAX;
    int maximum = first_true(*min_element(all(a)), *max_element(all(a)), possible1);
    int minimum = last_true(*min_element(all(a)), *max_element(all(a)), possible2);

    answer = min(answer, maximum - minimum);

    // print(temp);
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