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
        int n, x, y;
        cin >> n >> x >> y;

        int lcm_x_y = ((x) / gcd(x, y)) * y;
        int total_max = n / x;
        int total_min = n / y;
        int total_common = n / lcm_x_y;

        total_max -= total_common;
        total_min -= total_common;

        int sum = 0;
        sum += (total_max) * (2 * n + (total_max - 1) * (-1)) / 2;
        sum -= ((total_min) * (total_min + 1) / 2);
        cout << sum << "\n";
    }

    return 0;
}