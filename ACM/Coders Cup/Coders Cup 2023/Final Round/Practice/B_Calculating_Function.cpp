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

    int odd_sum = 0;
    int even_sum = 0;

    odd_sum = (n * (2 + (n - 1) * 2)) / 2;
    even_sum = (n * (0 + (n - 1) * 2)) / 2;

    int answer = even_sum - odd_sum;
    // cout << answer;
    cout << even_sum;

    return 0;
}