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
    freopen("/home/owaisk4/Win_backup/Speed Programming/Codeforces/input.txt", "r", stdin);
    freopen("/home/owaisk4/Win_backup/Speed Programming/Codeforces/text_file.txt", "w", stdout);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        int odds = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            odds += a[i] & 1;
        }

        // cout << odds << "\n";
        if (odds < k) {
            cout << "NO\n";
            continue;
        }
        odds -= (k - 1);
        if (odds % 2 == 0) {
            cout << "NO\n";
            continue;
        }
        vector<int> segments;
        for (int i = 0, cnt = 0; i < n && cnt < k; i++) {
            if (a[i] & 1) {
                segments.push_back(i + 1);
                cnt++;
            }
        }
        cout << "YES\n";
        for (int i = 0; i < k - 1; i++) {
            cout << segments[i] << " ";
        }
        cout << n << "\n";
    }

    return 0;
}