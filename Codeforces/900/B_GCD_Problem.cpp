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
        int n;
        cin >> n;
        int a, b, c;
        if (n % 2 == 0) {
            a = n - 3;
            b = 2;
            c = 1;
        } else {
            a = n - 4;
            b = 3;
            c = 1;
            while (gcd(a, b) != 1) {
                a--;
                b++;
            }
        }
        cout << a << " " << b << " " << c << "\n";
    }

    return 0;
}