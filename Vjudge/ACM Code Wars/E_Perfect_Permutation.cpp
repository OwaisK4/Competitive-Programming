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
        vector<int> a(n);
        iota(all(a), 1);

        if (n % 2 == 0) {
            int bit = 1;
            for (int i = 0; i < n; i++) {
                cout << a[i + bit] << " ";
                bit = bit * (-1);
            }
        } else {
            for (int i = 1; i < n; i++) {
                cout << a[i] << " ";
            }
            cout << 1 << "\n";
        }
    }

    return 0;
}