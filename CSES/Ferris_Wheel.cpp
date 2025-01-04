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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int i = 0, j = n - 1;
    int cnt = 0;
    while (i <= j) {
        if (a[i] + a[j] <= x) {
            cnt++;
            i++;
            j--;
        } else {
            cnt++;
            j--;
        }
    }
    cout << cnt << "\n";

    return 0;
}