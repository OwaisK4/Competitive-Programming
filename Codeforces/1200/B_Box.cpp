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
        int n;
        cin >> n;
        vector<int> q(n), p(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> q[i];
        }

        vector<bool> used(n, false);
        vector<int> missing_indexes;
        for (int i = 0; i < n; i++) {
            if (!used[q[i] - 1]) {
                p[i] = q[i];
                used[q[i] - 1] = true;
            } else {
                missing_indexes.push_back(i);
            }
        }
        vector<int> unused;
        for (int i = 0; i < n; i++) {
            if (!used[i]) {
                unused.push_back(i);
            }
        }

        for (int i = 0; i < missing_indexes.size() && i < unused.size(); i++) {
            p[missing_indexes[i]] = unused[i] + 1;
        }

        bool valid = true;
        int maximum = p[0];
        for (int i = 0; i < n; i++) {
            maximum = max(maximum, p[i]);
            if (q[i] != maximum) {
                valid = false;
                break;
            }
        }
        if (!valid) {
            cout << -1 << "\n";
            continue;
        }
        print(p);
    }

    return 0;
}