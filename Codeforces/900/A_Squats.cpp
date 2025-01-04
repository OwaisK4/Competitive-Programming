#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define seed chrono::high_resolution_clock::now().time_since_epoch().count()
#define file_read(filepath) freopen(filepath, "r", stdin);
#define file_write(filepath) freopen(filepath, "w", stdout);
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
#define MOD 1000000007
using namespace std;
using pii = pair<int, int>;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int sit = 0, stand = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'x') {
            sit++;
        } else {
            stand++;
        }
    }
    int k = 0;
    if (stand > sit) {
        k = (n / 2) - sit;
        int j = k;
        for (int i = 0; i < n && j > 0; i++) {
            if (s[i] == 'X') {
                s[i] = 'x';
                j--;
            }
        }
    } else if (stand < sit) {
        k = (n / 2) - stand;
        int j = k;
        for (int i = 0; i < n && j > 0; i++) {
            if (s[i] == 'x') {
                s[i] = 'X';
                j--;
            }
        }
    }
    cout << k << "\n";
    cout << s;
}

signed main() {
    fastio;
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}