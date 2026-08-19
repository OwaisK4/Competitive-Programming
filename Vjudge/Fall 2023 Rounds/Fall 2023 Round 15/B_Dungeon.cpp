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
        int a, b, c;
        int maximum;
        cin >> a >> b >> c;

        while (a != b && b != c && a > 0 && b > 0 && c > 0) {
            for (int i = 0; i < 6; i++) {
                maximum = max(max(a, b), c);
                if (maximum == a) {
                    a--;
                } else if (maximum == b) {
                    b--;
                } else {
                    c--;
                }
            }
            a--;
            b--;
            c--;
        }
        if (a == 0 && b == 0 && c == 0) {
            cout << "YES\n";
        } else if (a > 0 && b > 0 && c > 0 && ((a + b + c) % 9 == 0)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}