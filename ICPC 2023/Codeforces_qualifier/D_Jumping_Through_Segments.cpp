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

int n;
vector<int> l, r;

bool is_valid(int k) {
    int lowest = -k;
    int highest = k;
    for (int i = 0; i < n; i++) {
        if (highest < l[i] || lowest > r[i])
            return false;
        lowest = max(lowest, l[i]) - k;
        highest = min(highest, r[i]) + k;
    }
    if (highest < l[n - 1] || lowest > r[n - 1])
        return false;
    else
        return true;
}

int first_true(int low, int high) {
    high++;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (is_valid(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    return high;
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        l.assign(n, 0);
        r.assign(n, 0);

        for (int i = 0; i < n; i++) {
            cin >> l[i] >> r[i];
        }
        int answer = first_true(0, 2e9);
        cout << answer << "\n";
    }

    return 0;
}