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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    set<int> s, indices;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (!s.count(a[j])) {
                s.insert(a[j]);
                indices.insert(j + 1);
                break;
            }
        }
    }
    if (s.size() >= k) {
        cout << "YES\n";
        for (auto it : indices) {
            cout << it << " ";
        }
    } else {
        cout << "NO\n";
    }

    return 0;
}

// map<int, int> mp;
// map<int, int> index;
// for (int i = 0; i < n; i++) {
//     cin >> a[i];
//     mp[a[i]] = i + 1;
// }
// if (mp.size() < k) {
//     cout << "NO";
// } else {
//     cout << "YES\n";
//     for (auto it : mp) {
//         cout << it.second << " ";
//     }
// }