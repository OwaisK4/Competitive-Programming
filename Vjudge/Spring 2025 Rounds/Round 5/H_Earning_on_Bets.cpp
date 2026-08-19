#include <iostream>
#include <numeric>
#include <utility>
#include <vector>
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

int n = 3;
vector<double> a;

void solve() {
    a.assign(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // int low = 0, high = (1000 * 1000 * 1000);
    double low = 0, high = (1000 * 1000 * 1000);
    while (low < high) {
        int mid = low + (high - low + 1) / 2;
        double remaining = 1000;
        for (int i = 0; i < n; i++) {
            double needed = (mid / a[i]);
            // print(needed);
            remaining -= needed;
        }
        if (remaining >= 0) {
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    double increase = low + 0.5;
    double remaining = 1000;
    for (int i = 0; i < n; i++) {
        double needed = (increase / a[i]);
        remaining -= needed;
    }
    if (remaining >= 0) {
        print(low + 1);
    } else {
        print(low);
    }
    // print(low);
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