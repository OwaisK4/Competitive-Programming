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
        vector<int> a(n), prefix(n + 1);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // int xor_total = 0;
        // for (int i = 0; i < n; i++) {
        //     prefix[i + 1] = (prefix[i] ^ a[i]);
        //     xor_total ^= prefix[i + 1];
        // }
        // // prefix.erase(prefix.begin());
        // print(prefix);
        // cout << xor_total << "\n";
        // cout << (prefix[n - 1] ^ prefix[2]) << "\n";
    }

    return 0;
}