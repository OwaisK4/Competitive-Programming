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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int minimum = 1;
        int maximum = n;
        int i = 0, j = n - 1;

        bool flag1 = false, flag2 = false;
        while (i < j) {
            flag1 = false;
            flag2 = false;
            if (a[i] == maximum) {
                i++;
                maximum--;
            } else if (a[i] == minimum) {
                i++;
                minimum++;
            } else {
                flag1 = true;
            }

            if (a[j] == maximum) {
                j--;
                maximum--;
            } else if (a[j] == minimum) {
                j--;
                minimum++;
            } else {
                flag2 = true;
            }
            if (flag1 && flag2) {
                break;
            }
        }
        if (flag1 && flag2) {
            cout << i + 1 << " " << j + 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}