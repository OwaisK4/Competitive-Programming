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

int lcm(int a, int b) {
    int answer = (a / gcd(a, b)) * b;
    return answer;
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 2, 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        vector<int> b(n + 2, 1);
        for (int i = 1; i <= n + 1; i++) {
            b[i] = lcm(a[i], a[i - 1]);
        }
        bool valid = true;
        for (int i = 1; i <= n; i++) {
            if (gcd(b[i], b[i + 1]) != a[i]) {
                cout << "NO\n";
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << "YES\n";
        }
    }

    return 0;
}