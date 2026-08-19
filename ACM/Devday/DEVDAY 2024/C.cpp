#include <bits/stdc++.h>
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
    int a, b, n;
    cin >> a >> b >> n;
    int m = a;
    int t = b;
    int t1, t2;
    int x = n / t;
    int y = (n - x * t) / m;
    t1 = a * x + b * y;
    m = b;
    t = a;
    int x1 = n / t;
    int y1 = (n - x1 * t) / m;
    t2 = a * x1 + b * y1;

    if (t1 > t2) {
        cout << x << ' ' << y;
    } else
        cout << x1 << ' ' << y1;
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