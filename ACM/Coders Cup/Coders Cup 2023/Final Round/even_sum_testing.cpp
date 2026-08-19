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
    int a = 2;
    int n = 3;
    if (a % 2) {
        a++;
    }
    int total = (n - a) / 2;
    if (n % 2 == 0) {
        total++;
    }
    int even_sum = total * (2 * a + (total - 1) * 2) / 2;
    total = n - a + 1;
    int all_sum = ((total) * (a + n)) / 2;

    cout << all_sum << "\n";
    // cout << even_sum << "\n";

    return 0;
}