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
void print(T X, bool newline = true) {
    cout << X;
    if (newline) {
        cout << "\n";
    }
}

bool check(int mid, vector<int> &a) {
    int last = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] - last > mid) {
            return false;
        } else if (a[i] - last == mid) {
            mid--;
        }
        last = a[i];
    }
    return true;
}

int first_true(int low, int high, vector<int> &a) {
    high++;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (check(mid, a)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

void solve(int i) {
    int n;
    cin >> n;
    vector<int> a(n);
    int low = 1;
    int high = 0;
    int last = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        high = max(high, a[i] - last);
        last = a[i];
    }
    high++;
    int answer = first_true(low, high, a);
    cout << "Case " << i << ": " << answer << "\n";
}

signed main() {
    fastio;

    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve(i + 1);
    }

    return 0;
}