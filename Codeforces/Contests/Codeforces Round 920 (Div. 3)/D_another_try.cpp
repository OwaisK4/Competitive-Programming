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
        multiset<int> s1, s2;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s1.insert(a[i]);
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
            s2.insert(b[i]);
        }

        int D = 0;
        for (int i = 0; i < n; i++) {
            int a1 = *s1.begin();
            int a2 = *(prev(s1.end()));
            int c1 = *s2.begin();
            int c2 = *(prev(s2.end()));
            int diff1 = abs(a1 - c2);
            int diff2 = abs(a2 - c1);
            if (diff1 >= diff2) {
                D += diff1;
                s1.erase(s1.begin());
                s2.erase(prev(s2.end()));
            } else {
                D += diff2;
                s1.erase(prev(s1.end()));
                s2.erase(s2.begin());
            }
        }
        cout << D << "\n";
    }

    return 0;
}