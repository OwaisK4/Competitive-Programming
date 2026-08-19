#include <bits/stdc++.h>
#include <ext/numeric>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
void print(T array) {
    for (auto it = begin(array); it != end(array); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        string s;
        cin >> s;

        int X0 = 0, X1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                X0 ^= a[i];
            } else {
                X1 ^= a[i];
            }
        }
        // cout << X0 << " " << X1 << "\n";
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] ^ a[i - 1];
        }
        // print(prefix);
        cin >> q;
        for (int i = 0; i < q; i++) {
            int tp;
            cin >> tp;
            if (tp == 1) {
                int l, r;
                cin >> l >> r;
                int xor_array = prefix[r] ^ prefix[l - 1];
                X0 = X0 ^ xor_array;
                X1 = X1 ^ xor_array;
            } else {
                int g;
                cin >> g;
                if (g == 0) {
                    cout << X0 << " ";
                } else {
                    cout << X1 << " ";
                }
            }
        }
        cout << "\n";
    }

    return 0;
}