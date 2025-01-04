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
    // file_read("/home/owaisk4/Win_backup/Speed Programming/CSES/test_input.txt");
    int n;
    cin >> n;
    vector<int> a(n), indexes(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        indexes[a[i]] = i;
    }

    int cnt = 1;
    int k = indexes[1];
    for (int i = 2; i <= n; i++) {
        if (indexes[i] < k) {
            cnt++;
        }
        k = indexes[i];
    }
    cout << cnt;

    return 0;
}