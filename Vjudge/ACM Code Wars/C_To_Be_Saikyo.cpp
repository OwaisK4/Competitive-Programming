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
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int P1 = a[0];

    sort(all(a));
    if (P1 == a[n - 1]) {
        if (count(all(a), P1) == 1) {
            cout << 0;
        } else {
            cout << 1;
        }
        return 0;
    }

    int x = a[n - 1] - P1 + 1;
    cout << x;

    return 0;
}