#include <bits/stdc++.h>
#include <ext/numeric>
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

template <typename T>
void print(vector<T> &array) {
    for (auto &it : array) {
        cout << it << " ";
    }
    cout << "\n";
}

signed main() {
    fastio;
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<pair<int, int>> sorted;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sorted.push_back({a[i], i});
        }

        sort(all(sorted));
        // print(a);
        // for (auto &it : sorted) {
        //     cout << it.first << " ";
        // }
        // cout << "\n";

        int diffs = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] != sorted[i].first) {
                if (abs(i - sorted[i].second) == k) {
                    continue;
                } else {
                    diffs++;
                }
                swap(a[i], a[sorted[i].second]);
            }
        }
        // if (diffs <= 1) {
        cout << diffs << "\n";
        // }else {
        //     cout << -1 << "\n";
        // }
    }

    return 0;
}