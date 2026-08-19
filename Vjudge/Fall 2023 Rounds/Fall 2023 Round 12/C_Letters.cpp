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
    int n, m;
    cin >> n >> m;
    vector<int> a(n), prefix(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    partial_sum(all(a), prefix.begin() + 1);
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < m; i++) {
        int room = b[i];
        auto it = lower_bound(all(prefix), room);
        int f = it - prefix.begin();
        int k = room - *(it - 1);
        cout << f << " " << k << "\n";
    }

    return 0;
}