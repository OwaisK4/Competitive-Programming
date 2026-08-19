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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.rbegin(), a.rend());
        int j = 0;
        for (int i = 1; i < n; i++) {
            int diff = max(a[j].first, a[j].first - a[i].first);
            if (diff < 0) {
                diff = a[j].first;
                a[i].first -= diff;
                j = i;
            }
            for (int k = 0; k < diff; k++) {
                cout << j + 1 << " " << i + 1 << "\n";
            }
            a[j].first = diff;
            if (diff == 0) {
                j = i + 1;
                i = i + 1;
            }
        }
        cout << "\n";
    }

    return 0;
}