#include <bits/stdc++.h>
#define int long long
#define all(a) a.begin(), a.end()
#define vi vector<int>
#define vii vector<pair<int, int>>
#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
using namespace std;

template <typename T>
void print(vector<T> array) {
    for (auto it : array) {
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
        vector<int> p(n), q(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        if (n == 1) {
            cout << -1 << "\n";
            continue;
        }
        q.assign(all(p));
        set<int> s;
        for (int i = 0; i < n; i++) {
            for (int k = 1; k <= n; k++) {
                if (q[i] != k && !s.count(k)) {
                    q[i] = k;
                    s.insert(k);
                    break;
                }
            }
        }
        if (p[n - 1] == q[n - 1]) {
            swap(q[n - 1], q[n - 2]);
        }
        // print(q);
        for (auto it : q) {
            cout << it << " ";
        }
        cout << "\n";
    }

    return 0;
}