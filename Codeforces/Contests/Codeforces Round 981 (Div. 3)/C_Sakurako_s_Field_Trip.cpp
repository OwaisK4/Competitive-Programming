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

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // int flag = 1;
    // for (int i = n / 2; i >= 0; i--) {
    //     int left = i;
    //     int right = n - i - 1;
    //     if (left == right)
    //         continue;
    //     if (flag) {
    //         if (a[left] < a[right]) {
    //             swap(a[left], a[right]);
    //         }
    //         flag = 1 - flag;
    //     } else {
    //         if (a[left] > a[right]) {
    //             swap(a[left], a[right]);
    //         }
    //         flag = 1 - flag;
    //     }
    // }
    for (int i = 0; i < n / 2; i++) {
        if (i % 2 == 0) {
            if (a[i] > a[n - i - 1]) {
                swap(a[i], a[n - i - 1]);
            }
        } else {
            if (a[i] < a[n - i - 1]) {
                swap(a[i], a[n - i - 1]);
            }
        }
    }
    print(a);
    for (int i = 0; i < n / 2; i++) {
        if (i % 2 == 0) {
            if (a[i] < a[n - i - 1]) {
                swap(a[i], a[n - i - 1]);
            }
        } else {
            if (a[i] > a[n - i - 1]) {
                swap(a[i], a[n - i - 1]);
            }
        }
    }
    print(a);

    int answer = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i + 1] == a[i]) {
            answer++;
        }
    }
    print(answer);
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