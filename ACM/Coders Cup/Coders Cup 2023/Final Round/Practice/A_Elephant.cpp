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
    int x;
    cin >> x;

    vector<int> coins = {5, 4, 3, 2, 1};
    int i = 0;
    int cnt = 0;
    while (x > 0 && i < coins.size()) {
        if (x - coins[i] >= 0) {
            x -= coins[i];
            cnt++;
        } else {
            i++;
        }
    }
    cout << cnt;

    return 0;
}