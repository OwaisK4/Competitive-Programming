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
#define MOD 1000000007
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
        vector<int> a(n), b(n), positions(n, -1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        sort(all(a), greater<int>());
        sort(all(b), greater<int>());

        // print(a);
        // print(b);
        int i = 0, j = 0;
        while (i < n && j < n) {
            if (a[i] > b[j]) {
                i++;
            } else {
                positions[j] = i;
                j++;
            }
        }
        while (j < n) {
            positions[j] = i;
            j++;
        }
        // print(positions);
        int ways = 1;
        for (int i = 0; i < n; i++) {
            positions[i] = max(0LL, positions[i] - i);
            ways *= positions[i];
            ways %= MOD;
        }
        cout << ways << "\n";
    }

    return 0;
}