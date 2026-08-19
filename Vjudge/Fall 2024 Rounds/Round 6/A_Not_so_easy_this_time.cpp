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
template <typename T, typename... Ts>
void print(T X, Ts... Y) {
    cout << X << " ";
    print(Y...);
}

void solve() {
    int n;
    cin >> n;
    int zeroes = 0;
    zeroes += (n / 6);
    n %= 6;

    if (n == 0) {
        for (int i = 0; i < zeroes; i++) {
            cout << "0";
        }
        cout << "\n";
    } else if (n == 1) {
        zeroes--;
        for (int i = 0; i < zeroes; i++) {
            cout << "0";
        }
        cout << "8\n";
    } else if (n == 2) {
        for (int i = 0; i < zeroes; i++) {
            cout << "0";
        }
        cout << "1\n";
    } else if (n == 3) {
        for (int i = 0; i < zeroes; i++) {
            cout << "0";
        }
        cout << "7\n";
    } else if (n == 4) {
        for (int i = 0; i < zeroes; i++) {
            cout << "0";
        }
        cout << "4\n";
    } else if (n == 5) {
        for (int i = 0; i < zeroes; i++) {
            cout << "0";
        }
        cout << "2\n";
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