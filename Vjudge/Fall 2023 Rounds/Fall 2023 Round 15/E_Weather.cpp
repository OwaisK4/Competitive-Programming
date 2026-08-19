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
using namespace std;

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

signed main() {
    fastio;
    file_read("input.txt");
    file_write("output.txt");

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> pre(n), suf(n);

    if (a[0] >= 0) {
        pre[0] = 1;
    }
    for (int i = 1; i < n - 1; i++) {
        if (a[i] >= 0) {
            pre[i] = pre[i - 1] + 1;
        } else {
            pre[i] = pre[i - 1];
        }
    }
    if (a[n - 1] <= 0) {
        suf[n - 2] = 1;
    }
    for (int i = n - 2; i > 0; i--) {
        if (a[i] <= 0) {
            suf[i - 1] = suf[i] + 1;
        } else {
            suf[i - 1] = suf[i];
        }
    }
    // print(pre);
    // print(suf);
    int min_diff = LONG_LONG_MAX;
    for (int i = 0; i < n - 1; i++) {
        if (min_diff > pre[i] + suf[i]) {
            min_diff = pre[i] + suf[i];
        }
    }
    cout << min_diff;

    return 0;
}