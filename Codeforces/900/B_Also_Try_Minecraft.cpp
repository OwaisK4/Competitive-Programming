#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define r_all(a) a.rbegin(), a.rend()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(T array) {
    for (auto it = begin(array); it != end(array); it++) {
        cout << *it << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), diff(n), prefix(n + 1), suffix(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n - 1; i++) {
        diff[i + 1] = max(0LL, a[i] - a[i + 1]);
    }
    partial_sum(all(diff), prefix.begin() + 1);
    diff.assign(n, 0);
    for (int i = n - 1; i > 0; i--) {
        diff[i - 1] = max(0LL, a[i] - a[i - 1]);
    }
    partial_sum(r_all(diff), suffix.rbegin());
    // print(diff);
    // print(prefix);
    // print(suffix);
    int s, j;
    for (int i = 0; i < m; i++) {
        cin >> s >> j;
        int fall_damage;
        if (s < j) {
            fall_damage = prefix[j] - prefix[s];
        } else {
            fall_damage = suffix[j] - suffix[s];
        }
        cout << fall_damage << "\n";
    }

    return 0;
}