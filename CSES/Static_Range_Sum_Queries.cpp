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
    int n, q;
    cin >> n >> q;

    vector<int> array(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
    }
    partial_sum(all(array), array.begin());
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        int answer = array[b] - array[a - 1];
        cout << answer << "\n";
    }
    // print(a);

    return 0;
}