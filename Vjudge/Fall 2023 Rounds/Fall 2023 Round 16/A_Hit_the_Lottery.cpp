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
    vector<int> denom = {1, 5, 10, 20, 100};
    int n;
    cin >> n;
    int i = denom.size() - 1;
    int cnt = 0;
    while (n > 0 && i >= 0) {
        if (denom[i] <= n) {
            int div = n / denom[i];
            n -= (denom[i] * div);
            cnt += div;
        }
        i--;
    }
    cout << cnt;

    return 0;
}