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
    if (n <= 4 || n % 2 != 0) {
        cout << 0;
        return 0;
    }

    int mid = n / 2;
    if (mid % 2 == 0) {
        mid -= 2;
    } else {
        mid -= 1;
    }

    int answer = mid / 2;
    cout << answer;

    return 0;
}