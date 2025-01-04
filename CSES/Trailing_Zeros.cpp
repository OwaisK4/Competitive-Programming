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

int findTrailingZeros(int n) {
    if (n < 0) // Negative Number Edge Case
        return -1;

    // Initialize result
    int count = 0;

    // Keep dividing n by powers of
    // 5 and update count
    for (int i = 5; n / i >= 1; i *= 5)
        count += n / i;

    return count;
}

signed main() {
    fastio;
    int n;
    cin >> n;
    // for (int i = 0; i < n; i++) {
    //     cout << i << ": " << fact(i) << "\n";
    // }
    // for (int i = 0; i < n; i++) {
    //     cout << i << ": " << count(all(to_string(fact(i))), '0') << "\n";
    // }
    cout << findTrailingZeros(n);

    return 0;
}