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
        int a, b;
        cin >> a >> b;
        if (a == b) {
            cout << 0 << " " << 0 << "\n";
            continue;
        }
        int maximum = max(a, b);
        int minimum = min(a, b);
        int diff = maximum - minimum;
        int left = maximum - (maximum % diff);
        int right = maximum - (maximum % diff) + diff;
        // cout << diff << " " << left << " " << right << "\n";
        cout << diff << " " << min(abs(maximum - left), abs(maximum - right)) << "\n";
    }

    return 0;
}