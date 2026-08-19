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
    string s;
    cin >> s;

    char last = s[0];
    int n = s.size();

    int cnt = 1;
    int max_cnt = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == last) {
            cnt++;
        } else {
            cnt = 1;
        }
        max_cnt = max(max_cnt, cnt);
        last = s[i];
    }
    cout << max_cnt;

    return 0;
}