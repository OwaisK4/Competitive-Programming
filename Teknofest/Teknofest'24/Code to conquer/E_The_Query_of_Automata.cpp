#include <bits/stdc++.h>
using namespace std;
signed main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        string s, t;
        cin >> s >> t;
        int star = s.find('*', 0);
        if (star == s.npos) {
            if (s == t) {
                cout << "YES";
            } else {
                cout << "NO";
            }
            return 0;
        }

        int i = 0, j = 0;
        while (i < star && j < m) {
            if (s[i] != t[j]) {
                break;
            }
            i++;
            j++;
        }
        int k = n - 1;
        int l = m - 1;
        while (k > star && l >= 0) {
            if (s[k] != t[l]) {
                break;
            }
            k--;
            l--;
        }
        if (i == k && i == star && (l - j >= -1)) {
            cout << "YES";
        } else {
            cout << "NO";
        }
    }
    return 0;
}