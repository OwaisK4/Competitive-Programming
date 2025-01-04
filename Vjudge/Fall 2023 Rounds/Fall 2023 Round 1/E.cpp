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

        int i = 0, j = n - 1;
        while (i < n && (a[i] == i + 1 || a[i] == n - 1 - i)) {
            i++;
        }
        while (j >= 0 && (a[j] == j + 1 || a[j] == n - j)) {
            j--;
        }
        if (i >= j) {
            cout << -1 << "\n";
            continue;
        }

        int maximum = a[i];
        int max_index = i;
        int minimum = a[i];
        int min_index = i;

        for (int k = i; k <= j; k++) {
            if (maximum < a[k]) {
                maximum = a[k];
                max_index = k;
            }
            if (minimum > a[k]) {
                minimum = a[k];
                min_index = k;
            }
        }

        int left = min(min_index, max_index);
        int right = max(min_index, max_index);

        if ((i < left) && (right < j)) {
            cout << (left - 1) + 1 << " " << (right + 1) + 1 << "\n";
        } else {
            cout << -1 << "\n";
        }

        // if ((i < min_index) && (max_index < j)) {
        //     cout << (min_index - 1) + 1 << " " << (max_index + 1) + 1 << "\n";
        // } else {
        //     cout << -1 << "\n";
        // }
    }

    return 0;
}