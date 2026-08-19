#include <bits/stdc++.h>
#include <ext/numeric>
// #define int long long
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

// vector<vector<int>> dp;
int dp[1001][(int)1e5 + 1] = {0};
vector<pair<int, int>> a;
// map<pair<int, int>, int> mp;
// unordered_map<pair<int, int>, int> mp;

// int f(int cost, int i, int n) {
//     if (i >= n || cost <= 0) {
//         return -a[i - 1].second;
//     }
//     int take = f(cost - a[i].first, i + 1, n) + a[i].second;
//     int reject = f(cost, i + 1, n);

//     return max(take, reject);
// }

// void fill_dp() {
//     for (int i = 0; i <= 1000; i++) {
//         for (int j = 0; j <= 1e5; j++) {
//             dp[i][j] = -1;
//         }
//     }
// }

int f(int cost, int i, int n) {
    if (cost < 0) {
        return -a[i - 1].second;
    }
    if (i >= n) {
        return dp[i][cost] = 0;
    }

    if (dp[i][cost] != 0) {
        return dp[i][cost];
    }
    // if (mp.count({i, cost}) != 0) {
    //     return mp[{i, cost}];
    // }

    int take = f(cost - a[i].first, i + 1, n) + a[i].second;
    int reject = f(cost, i + 1, n);

    return dp[i][cost] = max(take, reject);
    // return mp[{i, cost}] = max(take, reject);
}

signed main() {
    fastio;
    int n, x;
    cin >> n >> x;
    // fill_dp();
    // dp.assign(n + 1, vector<int>(n + 1, -1));
    // dp.assign(1000, vector<int>(1e5, -1));
    a.assign(n, {0, 0});
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }

    cout << f(x, 0, n);

    return 0;
}