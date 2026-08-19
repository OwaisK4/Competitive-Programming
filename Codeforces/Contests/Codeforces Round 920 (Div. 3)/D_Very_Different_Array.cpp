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
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        multiset<int> s;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            s.insert(b[i]);
        }
        // sort(all(a));
        int D = 0;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            int c1 = *s.begin();
            int c2 = *(prev(s.end()));
            int diff1 = abs(x - c1);
            int diff2 = abs(x - c2);
            if (diff1 >= diff2) {
                D += diff1;
                s.erase(s.begin());
            } else {
                D += diff2;
                s.erase(prev(s.end()));
            }
        }
        cout << D << "\n";
    }

    return 0;
}