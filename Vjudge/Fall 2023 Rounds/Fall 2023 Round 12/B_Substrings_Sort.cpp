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
        cout << array[i] << "\n";
    }
    // cout << "\n";
}
template <typename T>
void print(T X) {
    cout << X << "\n";
}

signed main() {
    fastio;
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a), [](string s1, string s2) {if (s1.size() <= s2.size()) return true; });
    bool valid = true;
    for (int i = 0; i < n - 1; i++) {
        string substring = a[i];
        string main_string = a[i + 1];
        if (main_string.find(substring, 0) == main_string.npos) {
            cout << "NO";
            valid = false;
            break;
        }
    }
    if (valid) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << a[i] << "\n";
        }
    }

    return 0;
}