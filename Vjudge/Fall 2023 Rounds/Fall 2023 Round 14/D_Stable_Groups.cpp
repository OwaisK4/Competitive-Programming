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
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n - 1; i++) {
        int diff = a[i + 1] - a[i];
        if (diff > x) {
            pq.push(diff);
        }
    }
    while (!pq.empty() && k > 0) {
        int t = pq.top();
        int req = (t % x == 0) ? (t / x - 1) : (t / x);
        if (k >= req) {
            k -= req;
            pq.pop();
        } else {
            break;
        }
    }

    cout << 1 + pq.size();
    return 0;
}