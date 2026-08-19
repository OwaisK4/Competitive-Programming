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
    map<int, int> prefix_sums;
    int sum = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum == x) {
            cnt++;
        }
        if (prefix_sums.contains(sum - x)) {
            cnt += prefix_sums[sum - x];
            // cnt++;
        }
        prefix_sums[sum]++;
    }
    cout << cnt;

    return 0;
}