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
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants(n), apartments(m);
    for (int i = 0; i < n; i++) {
        cin >> applicants[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> apartments[i];
    }
    sort(all(applicants));
    sort(all(apartments));

    int i = 0, j = 0;
    int accepted = 0;
    while (i < n && j < m) {
        if (applicants[i] - k <= apartments[j] && applicants[i] + k >= apartments[j]) {
            i++;
            j++;
            accepted++;
        } else if (applicants[i] - k > apartments[j]) {
            j++;
        } else {
            i++;
        }
    }
    cout << accepted;

    // print(applicants);
    // print(apartments);

    return 0;
}