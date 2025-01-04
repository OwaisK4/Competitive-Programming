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
        int n, a, b;
        cin >> n >> a >> b;
        int mid = n / 2;
        vector<int> array(n, 0);
        array[0] = a;
        if (n % 2 == 0)
            array[mid] = b;
        else
            array[mid + 1] = b;
        int k = n;
        for (int i = 0; i < n; i++) {
            if (k == a || k == b) {
                k--;
                i--;
            }
            if (array[i] == 0) {
                array[i] = k--;
            }
        }
        int minimum = INT_MAX;
        int maximum = INT_MIN;
        for (int i = 0; i < mid; i++) {
            minimum = min(minimum, array[i]);
        }
        for (int i = mid; i < n; i++) {
            maximum = max(maximum, array[i]);
        }
        if (minimum == a && maximum == b) {
            print(array);
        } else {
            cout << -1 << "\n";
        }
        // print(array);
    }

    return 0;
}