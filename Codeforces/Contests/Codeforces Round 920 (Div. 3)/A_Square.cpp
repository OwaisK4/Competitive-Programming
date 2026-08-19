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

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n = 4;
        vector<int> x(n), y(n);
        for (int i = 0; i < 4; i++) {
            cin >> x[i] >> y[i];
        }
        int answer = 1;
        bool found = false;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (x[i] == x[j]) {
                    int maximum = max(y[i], y[j]);
                    int minimum = min(y[i], y[j]);
                    answer *= (maximum - minimum);
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        found = false;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (y[i] == y[j]) {
                    int maximum = max(x[i], x[j]);
                    int minimum = min(x[i], x[j]);
                    answer *= (maximum - minimum);
                    found = true;
                    break;
                }
            }
            if (found) {
                break;
            }
        }
        cout << answer << "\n";
    }

    return 0;
}