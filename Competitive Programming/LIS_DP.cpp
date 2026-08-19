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
    vector<int> array = {8, 3, 4, 6, 5, 2, 0, 7, 9, 1};
    vector<int> length(array.size(), 1);

    for (int k = 0; k < array.size(); k++) {
        for (int i = 0; i < k; i++) {
            if (array[i] < array[k]) {
                length[k] = max(length[k], length[i] + 1);
            }
        }
    }
    print(array);
    print(length);
    cout << "LIS length = " << *max_element(all(length)) << "\n\n";

    vector<int> d(array.size(), LONG_LONG_MAX);
    d[0] = array[0];
    for (int i = 0; i < array.size(); i++) {
        auto it = lower_bound(all(d), array[i]);
        *it = array[i];
    }
    for_each(all(d), [](int x) {if (x == LONG_LONG_MAX)cout << "inf" << " "; else cout << x << " "; });
    int answer = d.size() - count(all(d), LONG_LONG_MAX);
    cout << "\nLIS length = " << answer << "\n";

    return 0;
}
