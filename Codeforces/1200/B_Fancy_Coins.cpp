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
    int m, k, a1, ak;
    cin >> t;
    while (t--) {
        cin >> m >> k >> a1 >> ak;
        int answer = 0;
        int coins_k = m / k;

        int coins_1 = m % k;
        if (coins_1 <= a1) {
            a1 -= coins_1;
            coins_1 = 0;
        } else {
            coins_1 -= a1;
            a1 = 0;
        }
        answer += coins_1;

        ak += (a1 / k);
        if (coins_k <= ak) {
            ak -= coins_k;
            coins_k = 0;
        } else {
            coins_k -= ak;
            ak = 0;
        }
        answer += coins_k;

        cout << answer << "\n";
    }

    // cout << answer << "\n";

    return 0;
}