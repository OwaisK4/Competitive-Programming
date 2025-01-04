#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
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
    // vector<vector<char>> s;
    // s.assign(3, vector<char>(n, ' '));
    vector<char> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == s[i - 1]) {
            if (s[i + 1] == s[i]) {
                if (s[i - 1] == 'R')
                    s[i] = 'G';
                if (s[i - 1] == 'R')
                    s[i] = 'G';
                else
                    s[i] = 'G';
            }
        }
    }
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