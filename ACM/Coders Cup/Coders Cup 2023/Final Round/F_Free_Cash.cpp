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
    map<pair<int, int>, int> mp;
    int max_cnt = 0;
    for (int i = 0; i < n; i++) {
        int h, m;
        cin >> h >> m;
        int cnt = ++mp[{h, m}];
        max_cnt = max(max_cnt, cnt);
    }
    cout << max_cnt;

    return 0;
}