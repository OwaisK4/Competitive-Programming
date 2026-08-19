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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        int a_sum = accumulate(all(a), 0);
        int b_sum = accumulate(all(b), 0);
        if (a_sum != b_sum) {
            cout << -1 << "\n";
            continue;
        }
        // int i = 0, j = 0, k = 0;
        vector<int> smaller, bigger;
        for (int i = 0; i < n; i++) {
            if (a[i] != b[i]) {
                while (a[i] < b[i]) {
                    smaller.push_back(i + 1);
                    a[i]++;
                }
                while (a[i] > b[i]) {
                    bigger.push_back(i + 1);
                    a[i]--;
                }
            }
        }
        cout << smaller.size() << "\n";
        for (int i = 0; i < smaller.size(); i++) {
            cout << bigger[i] << " " << smaller[i] << "\n";
        }
        // print(smaller);
        // print(bigger);
    }

    return 0;
}