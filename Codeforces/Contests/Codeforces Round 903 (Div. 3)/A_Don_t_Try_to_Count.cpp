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
        int n, m;
        cin >> n >> m;
        string x, s;
        cin >> x >> s;

        // if (x == s) {
        //     cout << 0 << "\n";
        //     continue;
        // }

        int cnt = 0;
        bool found = false;
        for (int i = 0; i < n; i++) {
            int j = 0;
            int k = i;
            cnt = 0;
            int reach = 1;
            int mul = 1;
            found = false;
            while (true) {
                if (s[j] != x[k]) {
                    break;
                }
                j++;
                k++;
                if (j == m) {
                    found = true;
                    break;
                }
                if (k == n) {
                    k = 0;
                    reach--;
                    if (reach == 0) {
                        reach = mul;
                        mul *= 2;
                        cnt++;
                    }
                }
            }
            if (found) {
                break;
            }
        }
        if (found) {
            cout << cnt << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}