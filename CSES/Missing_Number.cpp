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

vector<int> freq(3e5, 0);

signed main() {
    fastio;
    int n, x;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> x;
        freq[x]++;
    }
    for (int i = 1; i <= n; i++) {
        if (freq[i] == 0) {
            cout << i;
            break;
        }
    }

    return 0;
}