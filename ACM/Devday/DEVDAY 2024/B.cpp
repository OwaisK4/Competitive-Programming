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
#define MOD 10000000007
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

int sum_digits(int x) {
    int sum = 0;
    while (x > 0) {
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << -1;
        return;
    }

    vector<int> result;
    int i;
    for (i = (int)1e5 - 1; i >= 0; i--) {
        if (n == 0) {
            break;
        }
        int sum = sum_digits(i);
        if (n >= sum) {
            n -= sum;
            result.push_back(i);
        }
    }
    if (n > 0) {
        cout << -1;
        return;
    }

    cout << result.size() << "\n";
    for (auto it : result) {
        cout << it << " ";
    }
}

signed main() {
    fastio;
    int t = 1;
    //    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}