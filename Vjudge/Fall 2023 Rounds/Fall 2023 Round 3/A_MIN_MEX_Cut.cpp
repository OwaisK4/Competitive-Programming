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
        string s;
        cin >> s;
        int n = s.size();
        if (count(all(s), '0') == n) {
            cout << 1 << "\n";
            continue;
        }
        if (count(all(s), '1') == n) {
            cout << 0 << "\n";
            continue;
        }
        if (count(all(s), '1') == 1 && (s[0] == '1' || s[n - 1] == '1')) {
            cout << 1 << "\n";
            continue;
        }
        if (count(all(s), '1') == 2 && (s[0] == '1' && s[n - 1] == '1')) {
            cout << 1 << "\n";
            continue;
        }
        if (s[0] == '1' && s[n - 1] == '1') {
            int start = 0, end = n - 1;
            while (s[start] == '1')
                start++;
            while (s[end] == '1')
                end--;
            bool flag = true;
            for (int i = start; i <= end; i++) {
                if (s[i] == '1') {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << 1 << "\n";
            } else {
                cout << 2 << "\n";
            }
            continue;
        }
        if (count(all(s), '0') == 1) {
            cout << 1 << "\n";
            continue;
        }

        int flag = 0;
        char a = s[0];
        for (int i = 0; i < n; i++) {
            if (a != s[i]) {
                flag++;
            }
            a = s[i];
        }
        if (flag == 1) {
            cout << 1 << "\n";
        } else {
            cout << 2 << "\n";
        }
    }

    return 0;
}