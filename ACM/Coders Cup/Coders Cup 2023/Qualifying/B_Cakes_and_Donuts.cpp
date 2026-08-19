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

vector<int> dp(101);

signed main() {
    fastio;
    int N;
    cin >> N;
    dp[0] = 1;
    for (int i = 1; i < 101; i++) {
        if ((i - 4) >= 0) {
            dp[i] |= dp[i - 4];
        }
        if ((i - 7) >= 0) {
            dp[i] |= dp[i - 7];
        }
    }
    if (dp[N]) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}