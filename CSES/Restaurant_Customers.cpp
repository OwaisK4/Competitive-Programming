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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<pair<int, int>> times;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        times.push_back({a[i], 1LL});
        times.push_back({b[i], -1LL});
    }
    sort(all(times));
    int maximum = 0, current = 0;
    for (auto &[time, option] : times) {
        current += option;
        maximum = max(maximum, current);
    }
    cout << maximum;

    return 0;
}