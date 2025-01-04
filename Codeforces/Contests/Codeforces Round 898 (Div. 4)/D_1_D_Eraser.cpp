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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cnt = 0;
        int start = 0;
        int end = 0;
        while ((end = s.find('B', start)) != s.npos && (start < n)) {
            for (int i = 0; i < k; i++) {
                if (end + i >= n) {
                    break;
                }
                s[end + i] = 'W';
            }
            cnt++;
            start = end + 1;
        }
        cout << cnt << "\n";
    }

    return 0;
}