#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF INT_MAX
#define LINF LONG_LONG_MAX
#define int long long
#define all(a) a.begin(), a.end()
#define f first
#define s second
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vii vector<pair<int, int>>
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
template <typename T, typename... Ts>
void print(T X, Ts... Y) {
    cout << X << " ";
    print(Y...);
}

int n, m;
vi a, b, c;

int first_true(int low, int high, int ai, int ai1) {
    high++;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (b[mid] - ai >= ai1) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

int last_true(int low, int high, int ai, int ai1) {
    low--;
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (b[mid] - ai <= ai1) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

void solve() {
    cin >> n >> m;
    a.assign(n, 0);
    c.assign(n, 0);
    b.assign(m, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        c[i] = a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(all(b));

    bool valid = true;
    if (a[0] > (b[0] - a[0])) {
        a[0] = b[0] - a[0];
    }
    for (int i = 1; i < n; i++) {
        int index = first_true(0, m - 1, a[i], a[i - 1]);
        if (index >= 0 && index < m && (a[i] < a[i - 1] || a[i] > (b[index] - a[i])))
            a[i] = b[index] - a[i];

        if (a[i] < a[i - 1]) {
            valid = false;
            break;
        }
    }
    if (valid) {
        print("YES");
        return;
    }
    valid = true;
    for (int i = 0; i < n; i++) {
        a[i] = c[i];
    }

    if (a[n - 1] < (b[m - 1] - a[n - 1])) {
        a[n - 1] = (b[m - 1] - a[n - 1]);
    }
    for (int i = n - 2; i >= 0; i--) {
        int index = last_true(0, m - 1, a[i], a[i + 1]);
        if (index >= 0 && index < m && (a[i] > a[i + 1] || a[i] < (b[index] - a[i])))
            a[i] = b[index] - a[i];
        if (a[i] > a[i + 1]) {
            valid = false;
            break;
        }
    }
    if (valid) {
        // print(a);
        print("YES");
        return;
    }
    print("NO");
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