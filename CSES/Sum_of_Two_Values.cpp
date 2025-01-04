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

int first_true(vector<pair<int, int>> &array, int low, int high, int target) {
    high++;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (array[mid].first >= target) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

signed main() {
    fastio;
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(all(a));
    for (int i = 0; i < n; i++) {
        int value = x - a[i].first;
        int index = first_true(a, i + 1, n - 1, value);
        if (index != n && a[index].first == value) {
            int left = min(a[i].second, a[index].second);
            int right = max(a[i].second, a[index].second);
            cout << left << " " << right;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}