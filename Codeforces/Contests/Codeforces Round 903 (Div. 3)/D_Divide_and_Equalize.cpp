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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<int, int> factors;
        for (int i = 0; i < n; i++) {
            int value = a[i];
            int k;
            for (k = 2; (k * k) <= a[i];) {
                if (value % k == 0) {
                    value /= k;
                    factors[k]++;
                } else {
                    k++;
                }
            }
            if (value > 1) {
                factors[value]++;
            }
        }

        bool valid = true;
        for (auto &[key, value] : factors) {
            if (value != n && value % n != 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}