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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    vector<pair<int, int>> times(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        times[i] = {a[i], b[i]};
    }
    sort(all(times), [](pair<int, int> &p1, pair<int, int> &p2) { return p1.second < p2.second; });

    int curr = 0;
    int maximum = 0;
    for (int i = 0; i < n; i++) {
        if (curr <= times[i].first) {
            curr = times[i].second;
            maximum++;
        }
        // cout << times[i].first << " " << times[i].second << "\n";
    }
    cout << maximum;

    return 0;
}