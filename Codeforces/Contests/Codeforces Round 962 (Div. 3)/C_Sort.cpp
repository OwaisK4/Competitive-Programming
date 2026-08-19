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
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;

    vector<vector<int>> state_a(n + 1, vector<int>(26, 0));
    vector<vector<int>> state_b(n + 1, vector<int>(26, 0));

    for (int i = 0; i < n; i++) {
        int letter = a[i] - 'a';
        state_a[i + 1][letter]++;
        for (int j = 0; j < 26; j++) {
            state_a[i + 1][j] += state_a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        int letter = b[i] - 'a';
        state_b[i + 1][letter]++;
        for (int j = 0; j < 26; j++) {
            state_b[i + 1][j] += state_b[i][j];
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        int diff = 0;
        for (int j = 0; j < 26; j++) {
            int letter_a = state_a[r][j] - state_a[l - 1][j];
            int letter_b = state_b[r][j] - state_b[l - 1][j];
            diff += abs(letter_a - letter_b);
        }
        diff /= 2;
        cout << diff << "\n";
    }
}

signed main() {
    fastio;
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}