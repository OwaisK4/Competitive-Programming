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
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    int min_diff = LONG_LONG_MAX;

    int limit = 1 << n;
    for (int i = 0; i <= limit; i++) {
        int sum1 = 0;
        int sum2 = 0;
        for (int j = 0; j < n; j++) {
            if ((1 << j) & i) {
                sum1 += p[j];
            } else {
                sum2 += p[j];
            }
        }
        // cout << "Sum = " << sum1 << "\n";
        int diff = abs(sum1 - sum2);
        min_diff = min(min_diff, diff);
    }
    cout << min_diff;

    return 0;
}