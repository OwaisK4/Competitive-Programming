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
        int x1, p1;
        int x2, p2;
        cin >> x1 >> p1;
        cin >> x2 >> p2;

        double diff = (log10(x1) + (double)p1) - (log10(x2) + (double)p2);
        // cout << "diff = " << diff << " ";
        if (abs(diff) <= 2 * DBL_EPSILON) {
            cout << "=\n";
        } else if (diff > 0) {
            cout << ">\n";
        } else {
            cout << "<\n";
        }
    }

    return 0;
}