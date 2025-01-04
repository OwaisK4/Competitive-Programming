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
        int total_power = 0;
        int maximum = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                int k = 0;
                while (a[i] > 1 && a[i] % 2 == 0) {
                    k++;
                    a[i] /= 2;
                }
                total_power += k;
            }
            maximum = max(maximum, a[i]);
        }
        int sum = 0;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (!flag && a[i] == maximum) {
                flag = true;
            } else if (flag || a[i] != maximum) {
                sum += a[i];
            }
        }
        // print(a);
        // cout << "Total power = " << total_power << "\n";
        sum += (pow(2, total_power) * maximum);
        // sum = pow(2, total_power);
        cout << sum << "\n";
    }

    return 0;
}